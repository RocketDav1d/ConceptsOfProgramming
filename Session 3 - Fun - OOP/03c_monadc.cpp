# include "03x_helper.hpp"

//---------------------------
// helper (unwarp operation)

template<typename T, class = void>  struct  inner_type_or_identity                                      { using type = T; };
template<typename T>                struct  inner_type_or_identity<T, std::void_t<typename T::type>>    { using type = typename T::type; };
template<typename M>                using   wrapped_t   = typename inner_type_or_identity<M>::type;
template<typename M>                auto    unwrap(M m) -> wrapped_t<M>                                 { return static_cast<wrapped_t<M>>(m); }

//----------------------------
// helper (monad ctor)

template<template<typename> typename M, typename T>     auto unit(T t)      -> M<T>  { return M<T>{t}; }
template<template<typename> typename M, typename T>     auto unit(M<T> t)   -> M<T>  { return t; }


//----------------------------
// helper (monad marker type)
template<typename T>
struct Maybe {
    inline static const Maybe Not = Maybe{};
    using type = T;
    using monad_type = Maybe;
    using value_type = T;
    explicit operator T() { assert(engaged_); return box_; } 

    explicit Maybe()            : box_{} {}
    explicit Maybe(type boxed)  : box_{boxed}, engaged_{true} {}

    auto has_value() const -> bool { return engaged_; }

    template<typename Fn> static auto binder(Maybe in, Fn fn) {
        using return_type = decltype(unit<Maybe>(fn(unwrap(std::declval<T>()))));
        if (!in.has_value()) {
            return return_type::Not;
        } 

        return unit<Maybe>(fn(unwrap(in)));
    }

    private:
        friend auto operator<<(std::ostream& os, Maybe const& m) -> std::ostream& {
            if (m.engaged_)     { os << m.box_; } 
                           else { os << "⊥"; }
            return os;
        }
        type box_;
        bool engaged_ = false;
};


template<typename T>
struct List {
    using type = T;
    using value_type = typename T::value_type;
    using monad_type = List;
    explicit operator T() { return box_; } 

    List() : box_{} {}
    List(type boxed) : box_{boxed} {}

    auto begin() const { return box_.begin(); }
    auto end() const { return box_.end(); }

    template<typename Fn> static auto binder(List in, Fn fn) {
        using rt = decltype(fn(std::declval<value_type>()));
        using rlist = typename rebind<type, rt>::type;
        rlist out{};
        out.reserve(in.box_.size());

        for (auto const& e : in) {
            out.push_back(fn(e));
        }
 
        return unit<List>(out);    
    }

    private:
        type box_;
};


template< template<typename> typename M1
        , template<typename> typename M2
        > 
struct Combined {
template<typename T>
struct Monad {
    using monad_type        = M1<T>;
    using value_type        = typename monad_type::value_type;
    using type              = typename monad_type::type;

    explicit operator T()   { return static_cast<T>(box_); } 


    Monad()                 : box_{} {}
    Monad(value_type value) : box_{unit<M1>(value)} {}
    Monad(monad_type boxed) : box_{boxed} {}

    template<typename Fn> static auto binder(Monad in, Fn fn) {
        struct adfn {
            using m2    = M2<wrapped_t<value_type>>;
            using m2_vt = wrapped_t<m2>;
            
            Fn fn_;
            auto operator()(m2_vt a) { return m2::binder(unit<M2>(a), fn_); }
            auto operator()(m2 a) { return m2::binder(unit<M2>(a), fn_); }
        };

        return Combined<M1, M2>::make_monad(monad_type::binder(in.box_, adfn{fn}));
    }

    private:
        monad_type box_;
};
template<typename T> static auto make_monad(T t) -> Monad<wrapped_t<T>> { return Monad<wrapped_t<T>>(t); }
};

//----------------------
// Monadic ctor (convenience aliases)

template<typename T>                                    auto list(T t)          { return unit<List>(t); }
template<typename T>                                    auto maybe(T t)         { return unit<Maybe>(t); }

template< template<typename> typename M1
        , template<typename> typename M2
        , typename T
        >                                               auto combine(T t)       { return unit<Combined<M1, M2>::template Monad>(t); }

//------------------------------------------------------------------------------------------------------------------------------
// Monadic bind

template<typename Fn>
struct and_then_t {
    Fn fn;
    template<typename MT> friend auto operator|(MT in, and_then_t at) { return MT::binder(in, at.fn); }
};
template<typename Fn> auto and_then(Fn&& fn) -> and_then_t<std::decay_t<Fn>> { return {std::forward<Fn>(fn)}; }

//------------------------------------------------------------------------------------------------------------------------------
// Monadic do notation

template<typename MT, typename ... F> auto Do(MT t, F&& ... f) { return (t | ... | and_then(std::forward<F>(f))); }

//------------------------------------------------------------------------------------------------------------------------------
// Example

auto square(int i)      -> int          { return i * i; }
auto add1point1(int i)  -> float        { return i + 1.1; }
auto even(int i)        -> Maybe<int>   { return (i%2==0) ? maybe(i) : Maybe<int>::Not; }

auto quadric(std::vector<int> input) -> std::vector<Maybe<float>> {

    return unwrap( Do( combine<List, Maybe>   ( input )
                                            , square
                                            , even
                                            , add1point1
                                            ));
}

void test_combined() {
    auto numbers = std::vector{1, 2, 3, 4, 5}; 
    auto quadrics = quadric(numbers);

    output("input: ", numbers);
    output("output:", quadrics);
}


//------------------------------------------------------------------------------------------------------------------------------

auto single_quadric(int input) -> Maybe<float> {
    return Do( maybe    ( input )
                        , square
                        , even
                        , add1point1
                        );
}


void test_maybe() {
    auto i1 = single_quadric(4); 
    output("sq1 ", i1);
    auto i2 = single_quadric(5); 
    output("sq2 ", i2);
}

//------------------------------------------------------------------------------------------------------------------------------
// More Cats

struct Image{
    Image(std::string c = "") : data_{std::move(c)} {}

    auto operator+(std::string_view sv) -> Image const&  { data_ += sv; return *this; }
    void draw() const { std::cout << *this; }

    auto contains(std::string_view sv) const -> bool {
        return data_.contains(sv);
    }

    auto cropped() -> Image {
        return Image{trimmed(data_)};
    }

    private:
        friend auto operator<<(std::ostream& os, Image const& m) -> std::ostream& {
            os << "Image: '" << m.data_ << "'\n";
            return os;
        }
        std::string data_;
};
auto crop_cat(Image img)            -> Maybe<Image> { 
    if (!img.contains("cat")) {
        return Maybe<Image>::Not;
    }

    return Maybe<Image>{img.cropped()}; 
}
auto add_bowtie(Image img)          -> Maybe<Image> { 
    return Maybe<Image>{ img + " with cute bowtie "}; 
}
auto add_sparkly_eyes(Image img)    -> Maybe<Image> { 
    return Maybe<Image>{ img + " sparkle sparkle little eye "}; 
}
auto shrink(Image img)              -> Maybe<Image> { 
    return Maybe<Image>{img}; 
}
auto add_rainbow(Image img)         -> Maybe<Image> { 
    return Maybe<Image>{ img + " RAINBOW "}; 
}

auto make_cat_memes(std::vector<Image> imgs) -> std::vector<Maybe<Image>> {
    return unwrap   (combine<List, Maybe>(imgs)
                    | and_then(crop_cat)
                    | and_then(add_bowtie)
                    | and_then(add_sparkly_eyes)
                    | and_then(shrink)
                    | and_then(add_rainbow)
                    );
}

void test_cats() {

    auto in = std::vector<Image>    { Image{"    cat  "}
                                                        , Image{"   dog  "}
                                                        , Image{" tubby cat  "}
                                                        , Image{" ginger cat "}
                                                        , Image{" kitty cat"}};
    auto out = make_cat_memes(in);

    output("input :", in);
    output("output:", out);
}



//------------------------------------------------------------------------------------------------------------------------------

int main() {
    test_maybe();
    test_combined();
    test_cats();
}

//------------------------------------------------------------------------------------------------------------------------------
// --- compile --- only tests

void  test_int() {
    [[maybe_unused]] auto c = combine<List, Maybe>(std::vector<int>{}) | and_then(even); 
}

void  test_int_two_steps() {
    [[maybe_unused]] auto c = combine<List, Maybe>(std::vector<int>{}) | and_then(even) | and_then(square); 
}

void test_maybe_int() {
    [[maybe_unused]] auto c = combine<List, Maybe>(std::vector<Maybe<int>>{}) | and_then(even); 
}
