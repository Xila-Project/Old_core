#include "be_string.h"
#include "be_object.h"

be_define_const_str(, "", 2166136261u, 0, 0, &be_const_str_as);
be_define_const_str(_X2Etest_var, ".test_var", 3611137359u, 0, 9, &be_const_str_Hello);
be_define_const_str(Hello, "Hello", 4116459851u, 0, 5, &be_const_str_class);
be_define_const_str(as, "as", 1579491469u, 67, 2, &be_const_str_true);
be_define_const_str(break, "break", 3378807160u, 58, 5, &be_const_str_bytes);
be_define_const_str(bytes, "bytes", 1706151940u, 0, 5, &be_const_str_continue);
be_define_const_str(class, "class", 2872970239u, 57, 5, &be_const_str_elif);
be_define_const_str(continue, "continue", 2977070660u, 59, 8, &be_const_str_def);
be_define_const_str(def, "def", 3310976652u, 55, 3, &be_const_str_do);
be_define_const_str(do, "do", 1646057492u, 65, 2, &be_const_str_else);
be_define_const_str(elif, "elif", 3232090307u, 51, 4, &be_const_str_init);
be_define_const_str(else, "else", 3183434736u, 52, 4, &be_const_str_except);
be_define_const_str(end, "end", 1787721130u, 56, 3, &be_const_str_if);
be_define_const_str(except, "except", 950914032u, 69, 6, &be_const_str_false);
be_define_const_str(false, "false", 184981848u, 62, 5, &be_const_str_for);
be_define_const_str(for, "for", 2901640080u, 54, 3, &be_const_str_import);
be_define_const_str(if, "if", 959999494u, 50, 2, &be_const_str_try);
be_define_const_str(import, "import", 288002260u, 66, 6, &be_const_str_nil);
be_define_const_str(init, "init", 380752755u, 0, 4, &be_const_str_raise);
be_define_const_str(nil, "nil", 228849900u, 63, 3, NULL);
be_define_const_str(raise, "raise", 1593437475u, 70, 5, &be_const_str_return);
be_define_const_str(return, "return", 2246981567u, 60, 6, &be_const_str_static);
be_define_const_str(static, "static", 3532702267u, 71, 6, NULL);
be_define_const_str(true, "true", 1303515621u, 61, 4, NULL);
be_define_const_str(try, "try", 2887626766u, 68, 3, &be_const_str_var);
be_define_const_str(var, "var", 2317739966u, 64, 3, &be_const_str_while);
be_define_const_str(while, "while", 231090382u, 53, 5, NULL);


/* weak strings */

static const bstring* const m_string_table[] = {
    (const bstring *)&be_const_str_break,
    (const bstring *)&be_const_str_,
    (const bstring *)&be_const_str_end,
    (const bstring *)&be_const_str__X2Etest_var
};

static const struct bconststrtab m_const_string_table = {
    .size = 4,
    .count = 27,
    .table = m_string_table
};
