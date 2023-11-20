# include "03x_helper.hpp"

//---------------------------------------------------------------------
// Maybe Monad

template<typename T>
struct Maybe {
    static const Maybe Not;
    using type = T;
    explicit operator T() { assert(engaged_); return box_; } 

    Maybe() : box_{} {}
    Maybe(type boxed) : box_{boxed}, engaged_{true} {}

    auto has_value() const -> bool { return engaged_; }

    private:
        type box_;
        bool engaged_ = false;
};
template<typename T> const Maybe<T> Maybe<T>::Not = Maybe<T>{};

//---------------------------------------------------------------------
// helper (unwarp operation, sometimes called `just`)

template<typename M> using wrapped_t = typename M::type;
template<typename M> auto unwrap(M m) -> wrapped_t<M> {
    return static_cast<wrapped_t<M>>(m);
}

template<typename M> auto unwrap_or_default(M m) -> wrapped_t<M> {
    if (!m.has_value()) { return wrapped_t<M>{}; }
    return static_cast<wrapped_t<M>>(m);
}

//---------------------------------------------------------------------
// Maybe constructor

template<typename T> auto unit(T t) -> Maybe<T> {
    return Maybe<T>{t};
}

//----------------------
// Maybe bind

template<typename F>
struct and_then_t {
    F fn;
    
    template<typename MT>
    friend auto operator|(MT in, and_then_t at) -> MT {
        if (!in.has_value()) {
            return MT::Not;
        } 

        return at.fn(unwrap(in));
    }
};
template<typename F> 
auto and_then(F&& f) -> and_then_t<std::decay_t<F>> { return {std::forward<F>(f)}; }

//----------------------
// Maybe do notation
template<typename T, typename ... F> 
auto Maybe_do(T t, F&& ... f) { 
    return (unit(t) | ... | and_then(std::forward<F>(f))); 
}




//----------------------
// Example

struct Image{
    Image(std::string c = "") : data_{std::move(c)} {}

    auto operator+(std::string_view sv) -> Image const&  { data_ += sv; return *this; }
    void draw() const { std::cout << "Image: " << data_ << "\n"; }

    auto contains(std::string_view sv) const -> bool {
        return data_.contains(sv);
    }

    auto cropped() -> Image {
        return Image{trimmed(data_)};
    }

    private:
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


auto make_cat_meme(Image img) -> Image {
    return unwrap_or_default    ( unit(img) 
                                | and_then(crop_cat)
                                | and_then(add_bowtie)
                                | and_then(add_sparkly_eyes)
                                | and_then(shrink)
                                | and_then(add_rainbow)
                                );













    // return unwrap_or_default    ( Maybe_do  ( img
    //                             , crop_cat                  // `,`  translates to  `| and_then` 
    //                             , add_bowtie
    //                             , add_sparkly_eyes
    //                             , shrink
    //                             , add_rainbow
    //                             ));
}

int main() {
    auto meme = make_cat_meme(Image{"   A cat   "});
    meme.draw();

    auto nocat = make_cat_meme(Image{"  A dog   "});
    nocat.draw();
}
