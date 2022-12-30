# constexpr_print

constexpr_print は C++20 でコンパイル時に出力するためのライブラリです。

GCC でのみ動作します。
また、ANSIエスケープシーケンスに対応したターミナルでコンパイルする必要があります。

```c++
#include "constexpr_print.hpp"

#include <iostream>
#include <array>
#include <string_view>
#include <algorithm>
#include <concepts>

template <std::unsigned_integral T>
constexpr std::size_t digits(T x) {
    std::size_t d = 1;
    while (x /= 10) ++d;
    return d;
}

template <std::size_t N>
struct fizzbuzz {
    static constexpr std::size_t size =
        fizzbuzz<N - 1>::size + (
            N % 15 == 0 ? 9 :
            N % 3 == 0 || N % 5 == 0 ? 5 :
            digits(N) + 1
        );
    static constexpr std::array<char, size> data = [] {
        using namespace std::literals::string_view_literals;
        std::array<char, size> data;
        auto it = std::ranges::copy(fizzbuzz<N - 1>::data, data.begin()).out;
        if (N % 15 == 0) std::ranges::copy("FizzBuzz\n"sv, it);
        else if (N % 3 == 0) std::ranges::copy("Fizz\n"sv, it);
        else if (N % 5 == 0) std::ranges::copy("Buzz\n"sv, it);
        else {
            auto it = data.rbegin();
            *it++ = '\n';
            auto n = N;
            do *it++ = '0' + n % 10;
            while (n /= 10);
        }
        return data;
    }();
    static constexpr std::string_view value{ data.data(), size };
};

template <>
struct fizzbuzz<0> {
    static constexpr std::size_t size = 0;
    static constexpr std::array<char, size> data {};
    static constexpr std::string_view value{ data.data(), size };
};

int main() {
    constexpr_print("It's compile time!");
    constexpr_print(fizzbuzz<100>::value);

    std::cout << "It's runtime!\n";
    std::cout << fizzbuzz<100>::value;
}
```

```console
$ g++ -std=c++20 sample.cpp -o sample
It's compile time!
1
2
Fizz
4
Buzz
︙

$ ./sample
It's runtime!
1
2
Fizz
4
Buzz
︙

$ 
```
