# include "03x_helper.hpp"

//----------------------------

// auto ssize(std::vector<int> const& v) { return static_cast<int>(v.size());}
// void output(std::string_view msg, std::vector<int> const& v) {
//     std::cout << msg << " [";
//     for (auto i = 0, e = ssize(v); i < e; ++i) { 
//         std::cout << v[i] << ((i+1 < e) ? ", " : "]\n"); 
//     }
// }

//----------------------------
// helper (monad marker type)

template<typename T>
struct List {
    using type = T;
    explicit operator T() { return box_; } 

    List(type boxed) : box_{boxed} {}

    auto begin() { return box_.begin(); }
    auto end() { return box_.end(); }

    private:
        type box_;
};

//---------------------------
// helper (unwarp operation)

template<typename M> using wrapped_t = typename M::type;
template<typename M> auto unwrap(M m) -> wrapped_t<M> {
    return static_cast<wrapped_t<M>>(m);
}

//----------------------
// List ctor

template<typename T> auto unit(T t) -> List<T> {
    return List<T>{t};
}

//----------------------
// List bind

template<typename F>
struct and_then_t {
    F fn;
    
    template<typename MT>
    friend auto operator|(MT in, and_then_t at) -> MT {
        for (auto& e : in) {
            e = at.fn(e);
        }

        return in;
    }
};
template<typename F> 
auto and_then(F&& f) -> and_then_t<std::decay_t<F>> { return {std::forward<F>(f)}; }

//----------------------
// List do notation
template<typename T, typename ... F> 
auto List_do(T t, F&& ... f) { 
    return (unit(t) | ... | and_then(std::forward<F>(f))); 
}




//----------------------
// Example


auto square(int i)  -> int { return i * i; }
auto add1(int i)    -> int { return i + 1; }


auto quadric(std::vector<int> input) -> std::vector<int> {
    return unwrap ( unit(input) 
                | and_then(square)
                | and_then(add1)
                );

    // return unwrap ( List_do  ( input
    //                             , square
    //                             , add1
    //                             ));
}

int main() {
    auto numbers = std::vector{1, 2, 3, 4, 5}; 
    auto quadrics = quadric(numbers);

    output("input: ", numbers);
    output("output:", quadrics);
}
