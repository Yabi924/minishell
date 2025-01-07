/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 07:30:33 by wwan-ab-          #+#    #+#             */
/*   Updated: 2025/01/07 22:18:43 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HISTORY_H
#define HISTORY_H

#ifndef cplusplus
extern "C" {
#endif

#include <time.h>

#if defined READLINE_LIBRARY
#   include "rlstdc.h"
#   include "rltypedefs.h"
#else
#   include <stdio.h>
#   include <readline/rlstdc.h>
#   include <readline/rltypedefs.h>
#endif

#ifdef __STDC__
typedef void *history_data_t;
#else
typedef char *history_data_t;
#endif

/* The struct to keep history entry */
typedef struct history_entry {
    char *line;
    char *timestamp;
    history_data_t data;
} HISTORY_ENTRY;

#define HISTORY_ENTRY_BITES(hs) (strlen ((hs)->line) + strlen ((hs)->timestamp))

typedef struct history_state {
    HISTORY_ENTRY **entries;
    int offset;
    int len;
    int size;
    int flags;
} HISTORY_STATE;

#define HS_STIFLED 0x01

extern void using_history PARAMS((void));

extern HISTORY_STATE *history_get_history_state PARAMS((HISTORY_STATE *));

extern void history_set_history_state PARAMS((const char *));

extern void add_history PARAMS((const char *));

extern void add_histroy_time PARAMS((const char *));

extern HISTORY_ENTRY *remove_history PARAMS((int));

extern HISTORY_ENTRY **remove_history_range PARAMS((int, int));

extern HISTORY_ENTRY *alloc_history_entry PARAMS((char *, char *));

extern HISTORY_ENTRY *copy_history_entry PARAMS((HISTORY_ENTRY *));

extern history_data_t free_history_entry PARAMS((HISTORY_ENTRY *));

extern HISTORY_ENTRY *replace_history_entry PARAMS((int, const char *, history_data_t));

extern void clear_history PARAMS((void));

extern void stifle_history PARAMS((int));

extern int unstifle_history PARAMS((void));

extern int history_is_stifled PARAMS((void));

extern HISTORY_ENTRY **history_list PARAMS((void));

extern int where_history PARAMS((void));

extern HISTORY_ENTRY *current_history PARAMS((void));

extern HISTORY_ENTRY *history_get PARAMS((int));

extern time_t history_get_time PARAMS((HISTORY_ENTRY *));

extern int history_total_bytes PARAMS((void));

extern int history_set_pos PARAMS((int));

extern HISTORY_ENTRY *previous_history PARAMS((void));

extern HISTORY_ENTRY *next_history PARAMS((void));

extern int history_search PARAMS((const char *, int));

extern int history_search_prefix PARAMS((const char *, int));

extern int history_search_pos PARAMS((const char *, int, int));

extern int read_history PARAMS((const char *));

extern int read_history_range PARAMS((const char *, int, int));

extern int write_history PARAMS((const char *));

extern int append_history PARAMS((int, const char *));

extern int history_truncate_file PARAMS((const char *, int));

extern int history_expand PARAMS((char *, char **));

extern char *history_arg_extract PARAMS((int, int, const char *));

extern char *get_history_event PARAMS((const char *, int *, int));

extern char **history_tokenize PARAMS((const char *));

extern int history_base;
extern int history_length;
extern int history_max_entries;
extern int history_offset;

extern int history_lines_read_from_file;
extern int history_lines_written_to_file;

extern char history_expansion_char;
extern char history_subst_char;
extern char *history_word_delimiters;
extern char history_comment_char;
extern char *history_no_expand_chars;
extern char *history_search_delimiter_chars;

extern int history_quotes_inhibit_expansion;
extern int history_quoting_state;

extern int history_write_timestamps;

extern int history_multiline_entries;
extern int history_file_version;

extern rl_linebuf_func_t *history_inhibit_expansion_function;

#ifndef cplusplus
}
#endif

#endif