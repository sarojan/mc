#ifndef MC__SEARCH_INTERNAL_H
#define MC__SEARCH_INTERNAL_H

/*** typedefs(not structures) and defined constants **********************************************/

#define STR_E_NOTFOUND		" Search string not found "
#define STR_E_UNKNOWN_TYPE	" Unknown search type "

/*** enums ***************************************************************************************/

typedef enum {
    COND__NOT_FOUND,
    COND__NOT_ALL_FOUND,
    COND__FOUND_CHAR,
    COND__FOUND_CHAR_LAST,
    COND__FOUND_OK,
    COND__FOUND_ERROR
} mc_search__found_cond_t;

/*** structures declarations (and typedefs of structures)*****************************************/

typedef struct mc_search_cond_struct {
    GString *str;
    GString *upper;
    GString *lower;
#if GLIB_CHECK_VERSION (2, 14, 0)
    GRegex *regex_str;
#endif
    gsize len;
    gchar *charset;
} mc_search_cond_t;

/*** global variables defined in .c file *********************************************************/

/*** declarations of public functions ************************************************************/


/* search/lib.c : */

gchar *mc_search__recode_str (const char *, gsize, const char *, const char *, gsize *);

gchar *mc_search__get_one_symbol (const char *, const char *, gsize, gboolean *);

int mc_search__get_char (mc_search_t *, const void *, gsize);

GString *mc_search__tolower_case_str (const char *, const char *, gsize);

GString *mc_search__toupper_case_str (const char *, const char *, gsize);

gboolean mc_search__regex_is_char_escaped (char *, char *);

/* search/regex.c : */

void mc_search__cond_struct_new_init_regex (const char *, mc_search_t *, mc_search_cond_t *);

gboolean mc_search__run_regex (mc_search_t *, const void *, gsize, gsize, gsize *);

/* search/normal.c : */

void mc_search__cond_struct_new_init_normal (const char *, mc_search_t *, mc_search_cond_t *);

gboolean mc_search__run_normal (mc_search_t *, const void *, gsize, gsize, gsize *);

#endif