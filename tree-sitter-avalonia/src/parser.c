#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 37
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 29
#define ALIAS_COUNT 0
#define TOKEN_COUNT 15
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 4
#define PRODUCTION_ID_COUNT 1

enum ts_symbol_identifiers {
  anon_sym_LT = 1,
  anon_sym_GT = 2,
  anon_sym_LT_SLASH = 3,
  anon_sym_SLASH_GT = 4,
  anon_sym_EQ = 5,
  aux_sym_tag_name_token1 = 6,
  anon_sym_DQUOTE = 7,
  aux_sym_attribute_value_token1 = 8,
  anon_sym_LBRACE = 9,
  aux_sym_markup_extension_token1 = 10,
  anon_sym_RBRACE = 11,
  anon_sym_LT_BANG_DASH_DASH = 12,
  aux_sym_comment_token1 = 13,
  anon_sym_DASH_DASH_GT = 14,
  sym_document = 15,
  sym__node = 16,
  sym_element = 17,
  sym_open_tag = 18,
  sym_close_tag = 19,
  sym_empty_element = 20,
  sym_attribute = 21,
  sym_tag_name = 22,
  sym_attribute_name = 23,
  sym_attribute_value = 24,
  sym_markup_extension = 25,
  sym_comment = 26,
  aux_sym_document_repeat1 = 27,
  aux_sym_open_tag_repeat1 = 28,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_LT] = "<",
  [anon_sym_GT] = ">",
  [anon_sym_LT_SLASH] = "</",
  [anon_sym_SLASH_GT] = "/>",
  [anon_sym_EQ] = "=",
  [aux_sym_tag_name_token1] = "tag_name_token1",
  [anon_sym_DQUOTE] = "\"",
  [aux_sym_attribute_value_token1] = "attribute_value_token1",
  [anon_sym_LBRACE] = "{",
  [aux_sym_markup_extension_token1] = "markup_extension_token1",
  [anon_sym_RBRACE] = "}",
  [anon_sym_LT_BANG_DASH_DASH] = "<!--",
  [aux_sym_comment_token1] = "comment_token1",
  [anon_sym_DASH_DASH_GT] = "-->",
  [sym_document] = "document",
  [sym__node] = "_node",
  [sym_element] = "element",
  [sym_open_tag] = "open_tag",
  [sym_close_tag] = "close_tag",
  [sym_empty_element] = "empty_element",
  [sym_attribute] = "attribute",
  [sym_tag_name] = "tag_name",
  [sym_attribute_name] = "attribute_name",
  [sym_attribute_value] = "attribute_value",
  [sym_markup_extension] = "markup_extension",
  [sym_comment] = "comment",
  [aux_sym_document_repeat1] = "document_repeat1",
  [aux_sym_open_tag_repeat1] = "open_tag_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_LT] = anon_sym_LT,
  [anon_sym_GT] = anon_sym_GT,
  [anon_sym_LT_SLASH] = anon_sym_LT_SLASH,
  [anon_sym_SLASH_GT] = anon_sym_SLASH_GT,
  [anon_sym_EQ] = anon_sym_EQ,
  [aux_sym_tag_name_token1] = aux_sym_tag_name_token1,
  [anon_sym_DQUOTE] = anon_sym_DQUOTE,
  [aux_sym_attribute_value_token1] = aux_sym_attribute_value_token1,
  [anon_sym_LBRACE] = anon_sym_LBRACE,
  [aux_sym_markup_extension_token1] = aux_sym_markup_extension_token1,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [anon_sym_LT_BANG_DASH_DASH] = anon_sym_LT_BANG_DASH_DASH,
  [aux_sym_comment_token1] = aux_sym_comment_token1,
  [anon_sym_DASH_DASH_GT] = anon_sym_DASH_DASH_GT,
  [sym_document] = sym_document,
  [sym__node] = sym__node,
  [sym_element] = sym_element,
  [sym_open_tag] = sym_open_tag,
  [sym_close_tag] = sym_close_tag,
  [sym_empty_element] = sym_empty_element,
  [sym_attribute] = sym_attribute,
  [sym_tag_name] = sym_tag_name,
  [sym_attribute_name] = sym_attribute_name,
  [sym_attribute_value] = sym_attribute_value,
  [sym_markup_extension] = sym_markup_extension,
  [sym_comment] = sym_comment,
  [aux_sym_document_repeat1] = aux_sym_document_repeat1,
  [aux_sym_open_tag_repeat1] = aux_sym_open_tag_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_LT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_GT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT_SLASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SLASH_GT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_EQ] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_tag_name_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_DQUOTE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_attribute_value_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_markup_extension_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT_BANG_DASH_DASH] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_comment_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_DASH_DASH_GT] = {
    .visible = true,
    .named = false,
  },
  [sym_document] = {
    .visible = true,
    .named = true,
  },
  [sym__node] = {
    .visible = false,
    .named = true,
  },
  [sym_element] = {
    .visible = true,
    .named = true,
  },
  [sym_open_tag] = {
    .visible = true,
    .named = true,
  },
  [sym_close_tag] = {
    .visible = true,
    .named = true,
  },
  [sym_empty_element] = {
    .visible = true,
    .named = true,
  },
  [sym_attribute] = {
    .visible = true,
    .named = true,
  },
  [sym_tag_name] = {
    .visible = true,
    .named = true,
  },
  [sym_attribute_name] = {
    .visible = true,
    .named = true,
  },
  [sym_attribute_value] = {
    .visible = true,
    .named = true,
  },
  [sym_markup_extension] = {
    .visible = true,
    .named = true,
  },
  [sym_comment] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_document_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_open_tag_repeat1] = {
    .visible = false,
    .named = false,
  },
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 20,
  [21] = 21,
  [22] = 22,
  [23] = 23,
  [24] = 24,
  [25] = 25,
  [26] = 26,
  [27] = 27,
  [28] = 28,
  [29] = 29,
  [30] = 30,
  [31] = 31,
  [32] = 32,
  [33] = 33,
  [34] = 34,
  [35] = 35,
  [36] = 36,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(7);
      if (lookahead == '"') ADVANCE(14);
      if (lookahead == '-') ADVANCE(2);
      if (lookahead == '/') ADVANCE(5);
      if (lookahead == '<') ADVANCE(8);
      if (lookahead == '=') ADVANCE(12);
      if (lookahead == '>') ADVANCE(9);
      if (lookahead == '{') ADVANCE(20);
      if (lookahead == '}') ADVANCE(26);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0)
      if (('.' <= lookahead && lookahead <= ':') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(13);
      END_STATE();
    case 1:
      if (lookahead == '-') ADVANCE(27);
      END_STATE();
    case 2:
      if (lookahead == '-') ADVANCE(6);
      END_STATE();
    case 3:
      if (lookahead == '-') ADVANCE(1);
      END_STATE();
    case 4:
      if (lookahead == '<') ADVANCE(21);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(24);
      if (lookahead != 0 &&
          lookahead != '}') ADVANCE(25);
      END_STATE();
    case 5:
      if (lookahead == '>') ADVANCE(11);
      END_STATE();
    case 6:
      if (lookahead == '>') ADVANCE(36);
      END_STATE();
    case 7:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 8:
      ACCEPT_TOKEN(anon_sym_LT);
      if (lookahead == '!') ADVANCE(3);
      if (lookahead == '/') ADVANCE(10);
      END_STATE();
    case 9:
      ACCEPT_TOKEN(anon_sym_GT);
      END_STATE();
    case 10:
      ACCEPT_TOKEN(anon_sym_LT_SLASH);
      END_STATE();
    case 11:
      ACCEPT_TOKEN(anon_sym_SLASH_GT);
      END_STATE();
    case 12:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 13:
      ACCEPT_TOKEN(aux_sym_tag_name_token1);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= ':') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(13);
      END_STATE();
    case 14:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 15:
      ACCEPT_TOKEN(aux_sym_attribute_value_token1);
      if (lookahead == '!') ADVANCE(17);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(19);
      END_STATE();
    case 16:
      ACCEPT_TOKEN(aux_sym_attribute_value_token1);
      if (lookahead == '-') ADVANCE(29);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(19);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(aux_sym_attribute_value_token1);
      if (lookahead == '-') ADVANCE(16);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(19);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(aux_sym_attribute_value_token1);
      if (lookahead == '<') ADVANCE(15);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(18);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(19);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(aux_sym_attribute_value_token1);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(19);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(aux_sym_markup_extension_token1);
      if (lookahead == '!') ADVANCE(23);
      if (lookahead != 0 &&
          lookahead != '}') ADVANCE(25);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(aux_sym_markup_extension_token1);
      if (lookahead == '-') ADVANCE(30);
      if (lookahead != 0 &&
          lookahead != '}') ADVANCE(25);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(aux_sym_markup_extension_token1);
      if (lookahead == '-') ADVANCE(22);
      if (lookahead != 0 &&
          lookahead != '}') ADVANCE(25);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(aux_sym_markup_extension_token1);
      if (lookahead == '<') ADVANCE(21);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(24);
      if (lookahead != 0 &&
          lookahead != '}') ADVANCE(25);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(aux_sym_markup_extension_token1);
      if (lookahead != 0 &&
          lookahead != '}') ADVANCE(25);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(anon_sym_LT_BANG_DASH_DASH);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(anon_sym_LT_BANG_DASH_DASH);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(35);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(anon_sym_LT_BANG_DASH_DASH);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(19);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(anon_sym_LT_BANG_DASH_DASH);
      if (lookahead != 0 &&
          lookahead != '}') ADVANCE(25);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == '!') ADVANCE(33);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(35);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == '-') ADVANCE(28);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(35);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == '-') ADVANCE(32);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(35);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == '<') ADVANCE(31);
      if (lookahead == '\t' ||
          (11 <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(34);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(35);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(35);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(anon_sym_DASH_DASH_GT);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 0},
  [3] = {.lex_state = 0},
  [4] = {.lex_state = 0},
  [5] = {.lex_state = 0},
  [6] = {.lex_state = 0},
  [7] = {.lex_state = 0},
  [8] = {.lex_state = 0},
  [9] = {.lex_state = 0},
  [10] = {.lex_state = 0},
  [11] = {.lex_state = 0},
  [12] = {.lex_state = 0},
  [13] = {.lex_state = 0},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 0},
  [16] = {.lex_state = 0},
  [17] = {.lex_state = 0},
  [18] = {.lex_state = 0},
  [19] = {.lex_state = 0},
  [20] = {.lex_state = 0},
  [21] = {.lex_state = 0},
  [22] = {.lex_state = 0},
  [23] = {.lex_state = 0},
  [24] = {.lex_state = 0},
  [25] = {.lex_state = 0},
  [26] = {.lex_state = 0},
  [27] = {.lex_state = 0},
  [28] = {.lex_state = 0},
  [29] = {.lex_state = 0},
  [30] = {.lex_state = 18},
  [31] = {.lex_state = 4},
  [32] = {.lex_state = 0},
  [33] = {.lex_state = 0},
  [34] = {.lex_state = 0},
  [35] = {.lex_state = 34},
  [36] = {(TSStateId)(-1)},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [sym_comment] = STATE(0),
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_LT] = ACTIONS(1),
    [anon_sym_GT] = ACTIONS(1),
    [anon_sym_LT_SLASH] = ACTIONS(1),
    [anon_sym_SLASH_GT] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
    [aux_sym_tag_name_token1] = ACTIONS(1),
    [anon_sym_DQUOTE] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [anon_sym_LT_BANG_DASH_DASH] = ACTIONS(3),
    [anon_sym_DASH_DASH_GT] = ACTIONS(1),
  },
  [1] = {
    [sym_document] = STATE(28),
    [sym__node] = STATE(19),
    [sym_element] = STATE(11),
    [sym_open_tag] = STATE(4),
    [sym_empty_element] = STATE(11),
    [sym_comment] = STATE(1),
    [aux_sym_document_repeat1] = STATE(5),
    [ts_builtin_sym_end] = ACTIONS(5),
    [anon_sym_LT] = ACTIONS(7),
    [anon_sym_LT_BANG_DASH_DASH] = ACTIONS(3),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 9,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(7), 1,
      anon_sym_LT,
    ACTIONS(9), 1,
      anon_sym_LT_SLASH,
    STATE(2), 1,
      sym_comment,
    STATE(3), 1,
      aux_sym_document_repeat1,
    STATE(4), 1,
      sym_open_tag,
    STATE(19), 1,
      sym__node,
    STATE(21), 1,
      sym_close_tag,
    STATE(11), 2,
      sym_element,
      sym_empty_element,
  [29] = 7,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(13), 1,
      anon_sym_LT,
    STATE(4), 1,
      sym_open_tag,
    STATE(19), 1,
      sym__node,
    ACTIONS(11), 2,
      ts_builtin_sym_end,
      anon_sym_LT_SLASH,
    STATE(3), 2,
      sym_comment,
      aux_sym_document_repeat1,
    STATE(11), 2,
      sym_element,
      sym_empty_element,
  [54] = 8,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(7), 1,
      anon_sym_LT,
    ACTIONS(9), 1,
      anon_sym_LT_SLASH,
    STATE(2), 1,
      aux_sym_document_repeat1,
    STATE(14), 1,
      sym_close_tag,
    STATE(19), 1,
      sym__node,
    STATE(4), 2,
      sym_open_tag,
      sym_comment,
    STATE(11), 2,
      sym_element,
      sym_empty_element,
  [81] = 8,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(7), 1,
      anon_sym_LT,
    ACTIONS(16), 1,
      ts_builtin_sym_end,
    STATE(3), 1,
      aux_sym_document_repeat1,
    STATE(4), 1,
      sym_open_tag,
    STATE(5), 1,
      sym_comment,
    STATE(19), 1,
      sym__node,
    STATE(11), 2,
      sym_element,
      sym_empty_element,
  [107] = 6,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(20), 1,
      aux_sym_tag_name_token1,
    STATE(20), 1,
      sym_attribute,
    STATE(26), 1,
      sym_attribute_name,
    ACTIONS(18), 2,
      anon_sym_GT,
      anon_sym_SLASH_GT,
    STATE(6), 2,
      sym_comment,
      aux_sym_open_tag_repeat1,
  [128] = 8,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(23), 1,
      anon_sym_GT,
    ACTIONS(25), 1,
      anon_sym_SLASH_GT,
    ACTIONS(27), 1,
      aux_sym_tag_name_token1,
    STATE(6), 1,
      aux_sym_open_tag_repeat1,
    STATE(7), 1,
      sym_comment,
    STATE(20), 1,
      sym_attribute,
    STATE(26), 1,
      sym_attribute_name,
  [153] = 8,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_tag_name_token1,
    ACTIONS(29), 1,
      anon_sym_GT,
    ACTIONS(31), 1,
      anon_sym_SLASH_GT,
    STATE(7), 1,
      aux_sym_open_tag_repeat1,
    STATE(8), 1,
      sym_comment,
    STATE(20), 1,
      sym_attribute,
    STATE(26), 1,
      sym_attribute_name,
  [178] = 5,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(33), 1,
      anon_sym_DQUOTE,
    ACTIONS(35), 1,
      anon_sym_LBRACE,
    STATE(9), 1,
      sym_comment,
    STATE(16), 2,
      sym_attribute_value,
      sym_markup_extension,
  [195] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(39), 1,
      anon_sym_LT,
    STATE(10), 1,
      sym_comment,
    ACTIONS(37), 2,
      ts_builtin_sym_end,
      anon_sym_LT_SLASH,
  [209] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(43), 1,
      anon_sym_LT,
    STATE(11), 1,
      sym_comment,
    ACTIONS(41), 2,
      ts_builtin_sym_end,
      anon_sym_LT_SLASH,
  [223] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(12), 1,
      sym_comment,
    ACTIONS(45), 3,
      anon_sym_GT,
      anon_sym_SLASH_GT,
      aux_sym_tag_name_token1,
  [235] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(13), 1,
      sym_comment,
    ACTIONS(47), 3,
      anon_sym_GT,
      anon_sym_SLASH_GT,
      aux_sym_tag_name_token1,
  [247] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(51), 1,
      anon_sym_LT,
    STATE(14), 1,
      sym_comment,
    ACTIONS(49), 2,
      ts_builtin_sym_end,
      anon_sym_LT_SLASH,
  [261] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(15), 1,
      sym_comment,
    ACTIONS(53), 3,
      anon_sym_GT,
      anon_sym_SLASH_GT,
      aux_sym_tag_name_token1,
  [273] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(16), 1,
      sym_comment,
    ACTIONS(55), 3,
      anon_sym_GT,
      anon_sym_SLASH_GT,
      aux_sym_tag_name_token1,
  [285] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(59), 1,
      anon_sym_LT,
    STATE(17), 1,
      sym_comment,
    ACTIONS(57), 2,
      ts_builtin_sym_end,
      anon_sym_LT_SLASH,
  [299] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(63), 1,
      anon_sym_LT,
    STATE(18), 1,
      sym_comment,
    ACTIONS(61), 2,
      ts_builtin_sym_end,
      anon_sym_LT_SLASH,
  [313] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(67), 1,
      anon_sym_LT,
    STATE(19), 1,
      sym_comment,
    ACTIONS(65), 2,
      ts_builtin_sym_end,
      anon_sym_LT_SLASH,
  [327] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(20), 1,
      sym_comment,
    ACTIONS(69), 3,
      anon_sym_GT,
      anon_sym_SLASH_GT,
      aux_sym_tag_name_token1,
  [339] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(73), 1,
      anon_sym_LT,
    STATE(21), 1,
      sym_comment,
    ACTIONS(71), 2,
      ts_builtin_sym_end,
      anon_sym_LT_SLASH,
  [353] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(75), 1,
      anon_sym_LT,
    ACTIONS(77), 1,
      anon_sym_LT_SLASH,
    STATE(22), 1,
      sym_comment,
  [366] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(79), 1,
      aux_sym_tag_name_token1,
    STATE(23), 1,
      sym_comment,
    STATE(27), 1,
      sym_tag_name,
  [379] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(81), 1,
      anon_sym_LT,
    ACTIONS(83), 1,
      anon_sym_LT_SLASH,
    STATE(24), 1,
      sym_comment,
  [392] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(79), 1,
      aux_sym_tag_name_token1,
    STATE(8), 1,
      sym_tag_name,
    STATE(25), 1,
      sym_comment,
  [405] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(85), 1,
      anon_sym_EQ,
    STATE(26), 1,
      sym_comment,
  [415] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(87), 1,
      anon_sym_GT,
    STATE(27), 1,
      sym_comment,
  [425] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(89), 1,
      ts_builtin_sym_end,
    STATE(28), 1,
      sym_comment,
  [435] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(91), 1,
      anon_sym_EQ,
    STATE(29), 1,
      sym_comment,
  [445] = 3,
    ACTIONS(93), 1,
      aux_sym_attribute_value_token1,
    ACTIONS(95), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(30), 1,
      sym_comment,
  [455] = 3,
    ACTIONS(95), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(97), 1,
      aux_sym_markup_extension_token1,
    STATE(31), 1,
      sym_comment,
  [465] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(99), 1,
      anon_sym_DASH_DASH_GT,
    STATE(32), 1,
      sym_comment,
  [475] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(101), 1,
      anon_sym_DQUOTE,
    STATE(33), 1,
      sym_comment,
  [485] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(103), 1,
      anon_sym_RBRACE,
    STATE(34), 1,
      sym_comment,
  [495] = 3,
    ACTIONS(95), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(105), 1,
      aux_sym_comment_token1,
    STATE(35), 1,
      sym_comment,
  [505] = 1,
    ACTIONS(107), 1,
      ts_builtin_sym_end,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 29,
  [SMALL_STATE(4)] = 54,
  [SMALL_STATE(5)] = 81,
  [SMALL_STATE(6)] = 107,
  [SMALL_STATE(7)] = 128,
  [SMALL_STATE(8)] = 153,
  [SMALL_STATE(9)] = 178,
  [SMALL_STATE(10)] = 195,
  [SMALL_STATE(11)] = 209,
  [SMALL_STATE(12)] = 223,
  [SMALL_STATE(13)] = 235,
  [SMALL_STATE(14)] = 247,
  [SMALL_STATE(15)] = 261,
  [SMALL_STATE(16)] = 273,
  [SMALL_STATE(17)] = 285,
  [SMALL_STATE(18)] = 299,
  [SMALL_STATE(19)] = 313,
  [SMALL_STATE(20)] = 327,
  [SMALL_STATE(21)] = 339,
  [SMALL_STATE(22)] = 353,
  [SMALL_STATE(23)] = 366,
  [SMALL_STATE(24)] = 379,
  [SMALL_STATE(25)] = 392,
  [SMALL_STATE(26)] = 405,
  [SMALL_STATE(27)] = 415,
  [SMALL_STATE(28)] = 425,
  [SMALL_STATE(29)] = 435,
  [SMALL_STATE(30)] = 445,
  [SMALL_STATE(31)] = 455,
  [SMALL_STATE(32)] = 465,
  [SMALL_STATE(33)] = 475,
  [SMALL_STATE(34)] = 485,
  [SMALL_STATE(35)] = 495,
  [SMALL_STATE(36)] = 505,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_document, 0),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(25),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [11] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2),
  [13] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2), SHIFT_REPEAT(25),
  [16] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_document, 1),
  [18] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_open_tag_repeat1, 2),
  [20] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_open_tag_repeat1, 2), SHIFT_REPEAT(29),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [31] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [33] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [35] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [37] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_empty_element, 4),
  [39] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_empty_element, 4),
  [41] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__node, 1),
  [43] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__node, 1),
  [45] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tag_name, 1),
  [47] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_markup_extension, 3),
  [49] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_element, 2),
  [51] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_element, 2),
  [53] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attribute_value, 3),
  [55] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attribute, 3),
  [57] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_close_tag, 3),
  [59] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_close_tag, 3),
  [61] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_empty_element, 3),
  [63] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_empty_element, 3),
  [65] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 1),
  [67] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 1),
  [69] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_open_tag_repeat1, 1),
  [71] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_element, 3),
  [73] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_element, 3),
  [75] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_open_tag, 3),
  [77] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_open_tag, 3),
  [79] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [81] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_open_tag, 4),
  [83] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_open_tag, 4),
  [85] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [87] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [89] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [91] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attribute_name, 1),
  [93] = {.entry = {.count = 1, .reusable = false}}, SHIFT(33),
  [95] = {.entry = {.count = 1, .reusable = false}}, SHIFT(35),
  [97] = {.entry = {.count = 1, .reusable = false}}, SHIFT(34),
  [99] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [101] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [103] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [105] = {.entry = {.count = 1, .reusable = false}}, SHIFT(32),
  [107] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_comment, 3),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_avalonia(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
