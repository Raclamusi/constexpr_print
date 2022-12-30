// ==========
// constexpr_print
// ==========
//
// Copyright (c) 2022 Raclamusi
//
// This library is released under the MIT License, see https://github.com/Raclamusi/constexpr_print/blob/main/LICENSE .
//


// __INCLUDE_LEVEL__ マクロが使用可能である必要がある。
#ifndef __INCLUDE_LEVEL__
# error __INCLUDE_LEVEL__ must be available
#endif

// このファイルはソースファイルから直接インクルードされなければならない。
// つまり、 __INCLUDE_LEVEL__ が 1 でなければならない。
#if not defined(INCLUDING_CONSTEXPR_PRINT) && __INCLUDE_LEVEL__ != 1
# error this file must be included directly from the source file
#endif


// インクルードガード
// 再帰インクルードが終了するまではインクルードをガードしない。
#ifndef INCLUDED_CONSTEXPR_PRINT


#if __INCLUDE_LEVEL__ == 1

// インクルード中であることを示すフラグ
#define INCLUDING_CONSTEXPR_PRINT

// トークンの文字列化
#define CONSTEXPR_PRINT_TOSTR2(...)  #__VA_ARGS__
#define CONSTEXPR_PRINT_TOSTR(...)  CONSTEXPR_PRINT_TOSTR2(__VA_ARGS__)

// 1行の最大文字数
#ifndef CONSTEXPR_PRINT_COLUMNS
# define CONSTEXPR_PRINT_COLUMNS  80
#endif

// タブサイズ
#ifndef CONSTEXPR_PRINT_TABSIZE
# define CONSTEXPR_PRINT_TABSIZE  4
#endif

#include <string_view>
#include <array>
#include <tuple>
#include <utility>
#include <type_traits>
#include <cstddef>

namespace detail {
    template <class STR_GETTER>
    constexpr void constexpr_print_impl(STR_GETTER str_getter) {
        constexpr std::size_t tab_size = (CONSTEXPR_PRINT_TABSIZE);
        constexpr std::size_t columns = (CONSTEXPR_PRINT_COLUMNS);
        constexpr std::string_view str = str_getter();
        constexpr auto col = [=] {
            std::array<std::size_t, str.size()> col;
            std::size_t x = 0;
            for (std::size_t i = 0; i < col.size(); ++i) {
                if (x >= columns) {
                    col[i] = columns;
                    x = 0;
                }
                else {
                    col[i] = x;
                }
                if (str[i] == '\b') {
                    if (x > 0) --x;
                }
                else if (str[i] == '\t') x = (x + tab_size) / tab_size * tab_size;
                else if (str[i] == '\n') x = 0;
                else if (str[i] == '\r') x = 0;
                else if (str[i] >= 0x20) ++x;
            }
            return col;
        }();

        constexpr std::tuple printers{

#endif  // __INCLUDE_LEVEL__ == 1

            [](auto char_getter) {
                constexpr char c = char_getter();
                if constexpr (c == '\x00') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\""); }
                else if constexpr (c == '\x01') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x01\""); }
                else if constexpr (c == '\x02') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x02\""); }
                else if constexpr (c == '\x03') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x03\""); }
                else if constexpr (c == '\x04') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x04\""); }
                else if constexpr (c == '\x05') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x05\""); }
                else if constexpr (c == '\x06') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x06\""); }
                else if constexpr (c == '\x07') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x07\""); }
                else if constexpr (c == '\x08') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x08\""); }
                else if constexpr (c == '\x09') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x09\""); }
                else if constexpr (c == '\x0a') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x0a\""); }
                else if constexpr (c == '\x0b') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x0b\""); }
                else if constexpr (c == '\x0c') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x0c\""); }
                else if constexpr (c == '\x0d') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x0d\""); }
                else if constexpr (c == '\x0e') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x0e\""); }
                else if constexpr (c == '\x0f') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x0f\""); }
                else if constexpr (c == '\x10') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x10\""); }
                else if constexpr (c == '\x11') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x11\""); }
                else if constexpr (c == '\x12') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x12\""); }
                else if constexpr (c == '\x13') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x13\""); }
                else if constexpr (c == '\x14') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x14\""); }
                else if constexpr (c == '\x15') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x15\""); }
                else if constexpr (c == '\x16') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x16\""); }
                else if constexpr (c == '\x17') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x17\""); }
                else if constexpr (c == '\x18') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x18\""); }
                else if constexpr (c == '\x19') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x19\""); }
                else if constexpr (c == '\x1a') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x1a\""); }
                else if constexpr (c == '\x1b') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x1b\""); }
                else if constexpr (c == '\x1c') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x1c\""); }
                else if constexpr (c == '\x1d') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x1d\""); }
                else if constexpr (c == '\x1e') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x1e\""); }
                else if constexpr (c == '\x1f') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x1f\""); }
                else if constexpr (c == '\x20') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x20\""); }
                else if constexpr (c == '\x21') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x21\""); }
                else if constexpr (c == '\x22') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x22\""); }
                else if constexpr (c == '\x23') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x23\""); }
                else if constexpr (c == '\x24') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x24\""); }
                else if constexpr (c == '\x25') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x25\""); }
                else if constexpr (c == '\x26') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x26\""); }
                else if constexpr (c == '\x27') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x27\""); }
                else if constexpr (c == '\x28') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x28\""); }
                else if constexpr (c == '\x29') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x29\""); }
                else if constexpr (c == '\x2a') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x2a\""); }
                else if constexpr (c == '\x2b') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x2b\""); }
                else if constexpr (c == '\x2c') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x2c\""); }
                else if constexpr (c == '\x2d') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x2d\""); }
                else if constexpr (c == '\x2e') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x2e\""); }
                else if constexpr (c == '\x2f') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x2f\""); }
                else if constexpr (c == '\x30') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x30\""); }
                else if constexpr (c == '\x31') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x31\""); }
                else if constexpr (c == '\x32') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x32\""); }
                else if constexpr (c == '\x33') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x33\""); }
                else if constexpr (c == '\x34') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x34\""); }
                else if constexpr (c == '\x35') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x35\""); }
                else if constexpr (c == '\x36') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x36\""); }
                else if constexpr (c == '\x37') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x37\""); }
                else if constexpr (c == '\x38') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x38\""); }
                else if constexpr (c == '\x39') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x39\""); }
                else if constexpr (c == '\x3a') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x3a\""); }
                else if constexpr (c == '\x3b') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x3b\""); }
                else if constexpr (c == '\x3c') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x3c\""); }
                else if constexpr (c == '\x3d') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x3d\""); }
                else if constexpr (c == '\x3e') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x3e\""); }
                else if constexpr (c == '\x3f') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x3f\""); }
                else if constexpr (c == '\x40') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x40\""); }
                else if constexpr (c == '\x41') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x41\""); }
                else if constexpr (c == '\x42') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x42\""); }
                else if constexpr (c == '\x43') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x43\""); }
                else if constexpr (c == '\x44') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x44\""); }
                else if constexpr (c == '\x45') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x45\""); }
                else if constexpr (c == '\x46') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x46\""); }
                else if constexpr (c == '\x47') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x47\""); }
                else if constexpr (c == '\x48') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x48\""); }
                else if constexpr (c == '\x49') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x49\""); }
                else if constexpr (c == '\x4a') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x4a\""); }
                else if constexpr (c == '\x4b') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x4b\""); }
                else if constexpr (c == '\x4c') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x4c\""); }
                else if constexpr (c == '\x4d') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x4d\""); }
                else if constexpr (c == '\x4e') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x4e\""); }
                else if constexpr (c == '\x4f') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x4f\""); }
                else if constexpr (c == '\x50') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x50\""); }
                else if constexpr (c == '\x51') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x51\""); }
                else if constexpr (c == '\x52') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x52\""); }
                else if constexpr (c == '\x53') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x53\""); }
                else if constexpr (c == '\x54') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x54\""); }
                else if constexpr (c == '\x55') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x55\""); }
                else if constexpr (c == '\x56') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x56\""); }
                else if constexpr (c == '\x57') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x57\""); }
                else if constexpr (c == '\x58') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x58\""); }
                else if constexpr (c == '\x59') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x59\""); }
                else if constexpr (c == '\x5a') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x5a\""); }
                else if constexpr (c == '\x5b') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x5b\""); }
                else if constexpr (c == '\x5c') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x5c\""); }
                else if constexpr (c == '\x5d') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x5d\""); }
                else if constexpr (c == '\x5e') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x5e\""); }
                else if constexpr (c == '\x5f') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x5f\""); }
                else if constexpr (c == '\x60') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x60\""); }
                else if constexpr (c == '\x61') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x61\""); }
                else if constexpr (c == '\x62') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x62\""); }
                else if constexpr (c == '\x63') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x63\""); }
                else if constexpr (c == '\x64') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x64\""); }
                else if constexpr (c == '\x65') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x65\""); }
                else if constexpr (c == '\x66') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x66\""); }
                else if constexpr (c == '\x67') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x67\""); }
                else if constexpr (c == '\x68') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x68\""); }
                else if constexpr (c == '\x69') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x69\""); }
                else if constexpr (c == '\x6a') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x6a\""); }
                else if constexpr (c == '\x6b') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x6b\""); }
                else if constexpr (c == '\x6c') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x6c\""); }
                else if constexpr (c == '\x6d') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x6d\""); }
                else if constexpr (c == '\x6e') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x6e\""); }
                else if constexpr (c == '\x6f') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x6f\""); }
                else if constexpr (c == '\x70') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x70\""); }
                else if constexpr (c == '\x71') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x71\""); }
                else if constexpr (c == '\x72') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x72\""); }
                else if constexpr (c == '\x73') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x73\""); }
                else if constexpr (c == '\x74') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x74\""); }
                else if constexpr (c == '\x75') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x75\""); }
                else if constexpr (c == '\x76') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x76\""); }
                else if constexpr (c == '\x77') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x77\""); }
                else if constexpr (c == '\x78') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x78\""); }
                else if constexpr (c == '\x79') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x79\""); }
                else if constexpr (c == '\x7a') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x7a\""); }
                else if constexpr (c == '\x7b') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x7b\""); }
                else if constexpr (c == '\x7c') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x7c\""); }
                else if constexpr (c == '\x7d') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x7d\""); }
                else if constexpr (c == '\x7e') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x7e\""); }
                else if constexpr (c == '\x7f') { if (not std::is_constant_evaluated()) asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x7f\""); }
            },

#if __INCLUDE_LEVEL__ < CONSTEXPR_PRINT_COLUMNS
# include __FILE__
#endif

#if __INCLUDE_LEVEL__ == 1

        };

        [] { if (not std::is_constant_evaluated()) asm(".print \"\""); }();
        [=]<std::size_t... I>(std::index_sequence<I...>) {
            ([=] {
                constexpr char c = str[I];
                constexpr std::size_t x = col[I];
                if constexpr (x >= columns) [] {
                    if (not std::is_constant_evaluated()) asm(".print \"\"");
                }();
                std::get<x % columns>(printers)([=] { return c; });
            }(), ...);
        }(std::make_index_sequence<str.size()>{});
    }
}  // namespace detail

#define constexpr_print(s)  detail::constexpr_print_impl([=]() constexpr { return  std::string_view(s); })

#undef INCLUDING_CONSTEXPR_PRINT
#define INCLUDED_CONSTEXPR_PRINT

#endif  // __INCLUDE_LEVEL__ == 1


#endif  // INCLUDED_CONSTEXPR_PRINT
