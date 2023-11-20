#ifndef S03_Fun_Monads_helper_
#define S03_Fun_Monads_helper_

#include <functional>
#include <type_traits>

#include <string>
#include <string_view>
#include <vector>

#include <iostream>
#include <cstdint>
#include <cassert>

//------------------------------------------------------------------------------------------------------------------------------

template <typename C, typename NVT> struct rebind;
template <typename VT, typename... Args, template <typename...> typename C, typename NVT>
struct rebind<C<VT, Args...>, NVT> {
    using type = C<NVT, typename rebind<Args, NVT>::type...>;
    template<typename ... Ts> using templ = C<Ts...>;
};

//------------------------------------------------------------------------------------------------------------------------------

template<typename ... Args> auto dbg(Args&& ... args) -> void { 
    (std::cerr << ... << std::forward<Args>(args)) << "\n";
}

//------------------------------------------------------------------------------------------------------------------------------

template<typename T> auto ssize(std::vector<T> const& v) { return static_cast<int>(v.size()); }
template<typename T> auto output(std::string_view msg, std::vector<T> const& v) -> void {
    std::cout << msg << " [";    
    for (auto i = 0, e = ssize(v); i < e; ++i) { 
        std::cout << v[i] << ((i+1 < e) ? ", " : "]\n"); 
    }
}
template<typename T> auto output(std::string_view msg, T const& t) -> void { std::cout << msg << t << "\n";  }

//------------------------------------------------------------------------------------------------------------------------------
// trim

inline auto to_view(char const* b, char const* e) -> std::string_view {
	assert(b <= e && "invalid string range");
	return std::string_view{b, static_cast<std::string_view::size_type>(e - b)};
}
inline auto ltrim_view(std::string_view sv) -> std::string_view {
	const auto ns = [](char c) { return !std::isspace(c); };
	return to_view(std::find_if(sv.begin(), sv.end(), ns), sv.end());
}
inline auto rtrim_view(std::string_view sv) -> std::string_view {
	const auto ns = [](char c) { return !std::isspace(c); };
	return to_view(sv.begin(), std::find_if(sv.rbegin(), sv.rend(), ns).base());
}
inline auto trim_view(std::string_view sv) -> std::string_view {
	return rtrim_view(ltrim_view(sv));
}
inline auto trimmed(std::string_view sv) -> std::string { return std::string{trim_view(sv)}; }

//------------------------------------------------------------------------------------------------------------------------------
#endif
