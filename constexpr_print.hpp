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
                if constexpr (c == '\x00') asm(".print \"\\x1b[1F\"");
                else if constexpr (c == '\x01') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x01\"");
                else if constexpr (c == '\x02') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x02\"");
                else if constexpr (c == '\x03') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x03\"");
                else if constexpr (c == '\x04') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x04\"");
                else if constexpr (c == '\x05') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x05\"");
                else if constexpr (c == '\x06') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x06\"");
                else if constexpr (c == '\x07') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x07\"");
                else if constexpr (c == '\x08') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x08\"");
                else if constexpr (c == '\x09') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x09\"");
                else if constexpr (c == '\x0a') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x0a\"");
                else if constexpr (c == '\x0b') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x0b\"");
                else if constexpr (c == '\x0c') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x0c\"");
                else if constexpr (c == '\x0d') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x0d\"");
                else if constexpr (c == '\x0e') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x0e\"");
                else if constexpr (c == '\x0f') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x0f\"");
                else if constexpr (c == '\x10') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x10\"");
                else if constexpr (c == '\x11') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x11\"");
                else if constexpr (c == '\x12') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x12\"");
                else if constexpr (c == '\x13') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x13\"");
                else if constexpr (c == '\x14') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x14\"");
                else if constexpr (c == '\x15') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x15\"");
                else if constexpr (c == '\x16') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x16\"");
                else if constexpr (c == '\x17') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x17\"");
                else if constexpr (c == '\x18') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x18\"");
                else if constexpr (c == '\x19') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x19\"");
                else if constexpr (c == '\x1a') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x1a\"");
                else if constexpr (c == '\x1b') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x1b\"");
                else if constexpr (c == '\x1c') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x1c\"");
                else if constexpr (c == '\x1d') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x1d\"");
                else if constexpr (c == '\x1e') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x1e\"");
                else if constexpr (c == '\x1f') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x1f\"");
                else if constexpr (c == '\x20') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x20\"");
                else if constexpr (c == '\x21') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x21\"");
                else if constexpr (c == '\x22') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x22\"");
                else if constexpr (c == '\x23') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x23\"");
                else if constexpr (c == '\x24') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x24\"");
                else if constexpr (c == '\x25') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x25\"");
                else if constexpr (c == '\x26') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x26\"");
                else if constexpr (c == '\x27') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x27\"");
                else if constexpr (c == '\x28') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x28\"");
                else if constexpr (c == '\x29') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x29\"");
                else if constexpr (c == '\x2a') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x2a\"");
                else if constexpr (c == '\x2b') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x2b\"");
                else if constexpr (c == '\x2c') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x2c\"");
                else if constexpr (c == '\x2d') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x2d\"");
                else if constexpr (c == '\x2e') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x2e\"");
                else if constexpr (c == '\x2f') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x2f\"");
                else if constexpr (c == '\x30') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x30\"");
                else if constexpr (c == '\x31') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x31\"");
                else if constexpr (c == '\x32') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x32\"");
                else if constexpr (c == '\x33') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x33\"");
                else if constexpr (c == '\x34') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x34\"");
                else if constexpr (c == '\x35') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x35\"");
                else if constexpr (c == '\x36') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x36\"");
                else if constexpr (c == '\x37') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x37\"");
                else if constexpr (c == '\x38') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x38\"");
                else if constexpr (c == '\x39') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x39\"");
                else if constexpr (c == '\x3a') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x3a\"");
                else if constexpr (c == '\x3b') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x3b\"");
                else if constexpr (c == '\x3c') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x3c\"");
                else if constexpr (c == '\x3d') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x3d\"");
                else if constexpr (c == '\x3e') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x3e\"");
                else if constexpr (c == '\x3f') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x3f\"");
                else if constexpr (c == '\x40') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x40\"");
                else if constexpr (c == '\x41') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x41\"");
                else if constexpr (c == '\x42') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x42\"");
                else if constexpr (c == '\x43') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x43\"");
                else if constexpr (c == '\x44') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x44\"");
                else if constexpr (c == '\x45') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x45\"");
                else if constexpr (c == '\x46') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x46\"");
                else if constexpr (c == '\x47') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x47\"");
                else if constexpr (c == '\x48') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x48\"");
                else if constexpr (c == '\x49') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x49\"");
                else if constexpr (c == '\x4a') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x4a\"");
                else if constexpr (c == '\x4b') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x4b\"");
                else if constexpr (c == '\x4c') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x4c\"");
                else if constexpr (c == '\x4d') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x4d\"");
                else if constexpr (c == '\x4e') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x4e\"");
                else if constexpr (c == '\x4f') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x4f\"");
                else if constexpr (c == '\x50') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x50\"");
                else if constexpr (c == '\x51') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x51\"");
                else if constexpr (c == '\x52') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x52\"");
                else if constexpr (c == '\x53') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x53\"");
                else if constexpr (c == '\x54') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x54\"");
                else if constexpr (c == '\x55') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x55\"");
                else if constexpr (c == '\x56') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x56\"");
                else if constexpr (c == '\x57') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x57\"");
                else if constexpr (c == '\x58') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x58\"");
                else if constexpr (c == '\x59') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x59\"");
                else if constexpr (c == '\x5a') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x5a\"");
                else if constexpr (c == '\x5b') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x5b\"");
                else if constexpr (c == '\x5c') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x5c\"");
                else if constexpr (c == '\x5d') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x5d\"");
                else if constexpr (c == '\x5e') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x5e\"");
                else if constexpr (c == '\x5f') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x5f\"");
                else if constexpr (c == '\x60') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x60\"");
                else if constexpr (c == '\x61') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x61\"");
                else if constexpr (c == '\x62') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x62\"");
                else if constexpr (c == '\x63') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x63\"");
                else if constexpr (c == '\x64') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x64\"");
                else if constexpr (c == '\x65') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x65\"");
                else if constexpr (c == '\x66') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x66\"");
                else if constexpr (c == '\x67') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x67\"");
                else if constexpr (c == '\x68') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x68\"");
                else if constexpr (c == '\x69') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x69\"");
                else if constexpr (c == '\x6a') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x6a\"");
                else if constexpr (c == '\x6b') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x6b\"");
                else if constexpr (c == '\x6c') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x6c\"");
                else if constexpr (c == '\x6d') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x6d\"");
                else if constexpr (c == '\x6e') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x6e\"");
                else if constexpr (c == '\x6f') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x6f\"");
                else if constexpr (c == '\x70') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x70\"");
                else if constexpr (c == '\x71') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x71\"");
                else if constexpr (c == '\x72') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x72\"");
                else if constexpr (c == '\x73') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x73\"");
                else if constexpr (c == '\x74') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x74\"");
                else if constexpr (c == '\x75') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x75\"");
                else if constexpr (c == '\x76') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x76\"");
                else if constexpr (c == '\x77') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x77\"");
                else if constexpr (c == '\x78') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x78\"");
                else if constexpr (c == '\x79') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x79\"");
                else if constexpr (c == '\x7a') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x7a\"");
                else if constexpr (c == '\x7b') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x7b\"");
                else if constexpr (c == '\x7c') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x7c\"");
                else if constexpr (c == '\x7d') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x7d\"");
                else if constexpr (c == '\x7e') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x7e\"");
                else if constexpr (c == '\x7f') asm(".print \"\\x1b[1F\\x1b[" CONSTEXPR_PRINT_TOSTR(__INCLUDE_LEVEL__) "G\\x7f\"");
            },

#if __INCLUDE_LEVEL__ < CONSTEXPR_PRINT_COLUMNS
# include __FILE__
#endif

#if __INCLUDE_LEVEL__ == 1

        };

        [] { asm(".print \"\""); }();
        [=]<std::size_t... I>(std::index_sequence<I...>) {
            ([=] {
                constexpr char c = str[I];
                constexpr std::size_t x = col[I];
                if constexpr (x >= columns) [] { asm(".print \"\""); }();
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
