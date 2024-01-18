/*** BEGIN file-header ***/
#include "config.h"
#include "glib-enumtypes.h"
#include <glib/glib-object.h>

G_GNUC_BEGIN_IGNORE_DEPRECATIONS

/*** END file-header ***/

/*** BEGIN file-tail ***/

G_GNUC_END_IGNORE_DEPRECATIONS

/*** END file-tail ***/

/*** BEGIN file-production ***/
/* enumerations from "@filename@" */

/*** END file-production ***/

/*** BEGIN value-header ***/
GType
g_unicode_type_get_type (void)
{
  static GType static_g_define_type_id = 0;

  if (g_once_init_enter_pointer (&static_g_define_type_id))
    {
      static const GUnicodeType values[] = {
/*** END value-header ***/

/*** BEGIN value-production ***/
        { G_UNICODE_CONTROL, "G_UNICODE_CONTROL", "control" },
        { G_UNICODE_FORMAT, "G_UNICODE_FORMAT", "format" },
        { G_UNICODE_UNASSIGNED, "G_UNICODE_UNASSIGNED", "unassigned" },
        { G_UNICODE_PRIVATE_USE, "G_UNICODE_PRIVATE_USE", "private-use" },
        { G_UNICODE_SURROGATE, "G_UNICODE_SURROGATE", "surrogate" },
        { G_UNICODE_LOWERCASE_LETTER, "G_UNICODE_LOWERCASE_LETTER", "lowercase-letter" },
        { G_UNICODE_MODIFIER_LETTER, "G_UNICODE_MODIFIER_LETTER", "modifier-letter" },
        { G_UNICODE_OTHER_LETTER, "G_UNICODE_OTHER_LETTER", "other-letter" },
        { G_UNICODE_TITLECASE_LETTER, "G_UNICODE_TITLECASE_LETTER", "titlecase-letter" },
        { G_UNICODE_UPPERCASE_LETTER, "G_UNICODE_UPPERCASE_LETTER", "uppercase-letter" },
        { G_UNICODE_SPACING_MARK, "G_UNICODE_SPACING_MARK", "spacing-mark" },
        { G_UNICODE_ENCLOSING_MARK, "G_UNICODE_ENCLOSING_MARK", "enclosing-mark" },
        { G_UNICODE_NON_SPACING_MARK, "G_UNICODE_NON_SPACING_MARK", "non_spacing-mark" },
        { G_UNICODE_DECIMAL_NUMBER, "G_UNICODE_DECIMAL_NUMBER", "decimal-number" },
        { G_UNICODE_LETTER_NUMBER, "G_UNICODE_LETTER_NUMBER", "letter-number" },
        { G_UNICODE_OTHER_NUMBER, "G_UNICODE_OTHER_NUMBER", "other-number" },
        { G_UNICODE_CONNECT_PUNCTUATION, "G_UNICODE_CONNECT_PUNCTUATION", "connect-punctuation" },
        { G_UNICODE_DASH_PUNCTUATION, "G_UNICODE_DASH_PUNCTUATION", "dash-punctuation" },
        { G_UNICODE_CLOSE_PUNCTUATION, "G_UNICODE_CLOSE_PUNCTUATION", "close-punctuation" },
        { G_UNICODE_FINAL_PUNCTUATION, "G_UNICODE_FINAL_PUNCTUATION", "final-punctuation" },
        { G_UNICODE_INITIAL_PUNCTUATION, "G_UNICODE_INITIAL_PUNCTUATION", "initial-punctuation" },
        { G_UNICODE_OTHER_PUNCTUATION, "G_UNICODE_OTHER_PUNCTUATION", "other-punctuation" },
        { G_UNICODE_OPEN_PUNCTUATION, "G_UNICODE_OPEN_PUNCTUATION", "open-punctuation" },
        { G_UNICODE_CURRENCY_SYMBOL, "G_UNICODE_CURRENCY_SYMBOL", "currency-symbol" },
        { G_UNICODE_MODIFIER_SYMBOL, "G_UNICODE_MODIFIER_SYMBOL", "modifier-symbol" },
        { G_UNICODE_MATH_SYMBOL, "G_UNICODE_MATH_SYMBOL", "math-symbol" },
        { G_UNICODE_OTHER_SYMBOL, "G_UNICODE_OTHER_SYMBOL", "other-symbol" },
        { G_UNICODE_LINE_SEPARATOR, "G_UNICODE_LINE_SEPARATOR", "line-separator" },
        { G_UNICODE_PARAGRAPH_SEPARATOR, "G_UNICODE_PARAGRAPH_SEPARATOR", "paragraph-separator" },
        { G_UNICODE_SPACE_SEPARATOR       , "G_UNICODE_SPACE_SEPARATOR", "space-separator" },
/*** END value-production ***/

/*** BEGIN value-tail ***/
        { 0, NULL, NULL }
      };
      GType g_define_type_id =
        g_unicode_type_register_static (g_intern_static_string ("GUnicodeTypeEnum"), values);
      g_once_init_leave_pointer (&static_g_define_type_id, g_define_type_id);
    }

  return static_g_define_type_id;
}

/*** END value-tail ***/
