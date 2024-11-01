/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

/* Copyright (C) 2018-2024 Hans Petter Jansson
 *
 * This file is part of Chafa, a program that shows pictures on text terminals.
 *
 * Chafa is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Chafa is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Chafa.  If not, see <http://www.gnu.org/licenses/>. */

#define UNICODE_UNDEF 0

typedef struct
{
    gint c;
    gunichar u;
}
CodeMap;

/* It's better to keep a single entry per line, since it leaves room for annotation.
 * Also, maintaining tabular layouts is a pita even when we don't have out-there
 * Unicode characters messing up the formatting. */
static const CodeMap cp437_codes [] =
{
    { 0x20, 0x0020 }, /* SPACE */
    { 0x21, 0x0021 }, /* EXCLAMATION MARK */
    { 0x22, 0x0022 }, /* QUOTATION MARK */
    { 0x23, 0x0023 }, /* NUMBER SIGN */
    { 0x24, 0x0024 }, /* DOLLAR SIGN */
    { 0x25, 0x0025 }, /* PERCENT SIGN */
    { 0x26, 0x0026 }, /* AMPERSAND */
    { 0x27, 0x0027 }, /* APOSTROPHE */
    { 0x28, 0x0028 }, /* LEFT PARENTHESIS */
    { 0x29, 0x0029 }, /* RIGHT PARENTHESIS */
    { 0x2a, 0x002a }, /* ASTERISK */
    { 0x2b, 0x002b }, /* PLUS SIGN */
    { 0x2c, 0x002c }, /* COMMA */
    { 0x2d, 0x002d }, /* HYPHEN-MINUS */
    { 0x2e, 0x002e }, /* FULL STOP */
    { 0x2f, 0x002f }, /* SOLIDUS */
    { 0x30, 0x0030 }, /* DIGIT ZERO */
    { 0x31, 0x0031 }, /* DIGIT ONE */
    { 0x32, 0x0032 }, /* DIGIT TWO */
    { 0x33, 0x0033 }, /* DIGIT THREE */
    { 0x34, 0x0034 }, /* DIGIT FOUR */
    { 0x35, 0x0035 }, /* DIGIT FIVE */
    { 0x36, 0x0036 }, /* DIGIT SIX */
    { 0x37, 0x0037 }, /* DIGIT SEVEN */
    { 0x38, 0x0038 }, /* DIGIT EIGHT */
    { 0x39, 0x0039 }, /* DIGIT NINE */
    { 0x3a, 0x003a }, /* COLON */
    { 0x3b, 0x003b }, /* SEMICOLON */
    { 0x3c, 0x003c }, /* LESS-THAN SIGN */
    { 0x3d, 0x003d }, /* EQUALS SIGN */
    { 0x3e, 0x003e }, /* GREATER-THAN SIGN */
    { 0x3f, 0x003f }, /* QUESTION MARK */
    { 0x40, 0x0040 }, /* COMMERCIAL AT */
    { 0x41, 0x0041 }, /* LATIN CAPITAL LETTER A */
    { 0x42, 0x0042 }, /* LATIN CAPITAL LETTER B */
    { 0x43, 0x0043 }, /* LATIN CAPITAL LETTER C */
    { 0x44, 0x0044 }, /* LATIN CAPITAL LETTER D */
    { 0x45, 0x0045 }, /* LATIN CAPITAL LETTER E */
    { 0x46, 0x0046 }, /* LATIN CAPITAL LETTER F */
    { 0x47, 0x0047 }, /* LATIN CAPITAL LETTER G */
    { 0x48, 0x0048 }, /* LATIN CAPITAL LETTER H */
    { 0x49, 0x0049 }, /* LATIN CAPITAL LETTER I */
    { 0x4a, 0x004a }, /* LATIN CAPITAL LETTER J */
    { 0x4b, 0x004b }, /* LATIN CAPITAL LETTER K */
    { 0x4c, 0x004c }, /* LATIN CAPITAL LETTER L */
    { 0x4d, 0x004d }, /* LATIN CAPITAL LETTER M */
    { 0x4e, 0x004e }, /* LATIN CAPITAL LETTER N */
    { 0x4f, 0x004f }, /* LATIN CAPITAL LETTER O */
    { 0x50, 0x0050 }, /* LATIN CAPITAL LETTER P */
    { 0x51, 0x0051 }, /* LATIN CAPITAL LETTER Q */
    { 0x52, 0x0052 }, /* LATIN CAPITAL LETTER R */
    { 0x53, 0x0053 }, /* LATIN CAPITAL LETTER S */
    { 0x54, 0x0054 }, /* LATIN CAPITAL LETTER T */
    { 0x55, 0x0055 }, /* LATIN CAPITAL LETTER U */
    { 0x56, 0x0056 }, /* LATIN CAPITAL LETTER V */
    { 0x57, 0x0057 }, /* LATIN CAPITAL LETTER W */
    { 0x58, 0x0058 }, /* LATIN CAPITAL LETTER X */
    { 0x59, 0x0059 }, /* LATIN CAPITAL LETTER Y */
    { 0x5a, 0x005a }, /* LATIN CAPITAL LETTER Z */
    { 0x5b, 0x005b }, /* LEFT SQUARE BRACKET */
    { 0x5c, 0x005c }, /* REVERSE SOLIDUS */
    { 0x5d, 0x005d }, /* RIGHT SQUARE BRACKET */
    { 0x5e, 0x005e }, /* CIRCUMFLEX ACCENT */
    { 0x5f, 0x005f }, /* LOW LINE */
    { 0x60, 0x0060 }, /* GRAVE ACCENT */
    { 0x61, 0x0061 }, /* LATIN SMALL LETTER A */
    { 0x62, 0x0062 }, /* LATIN SMALL LETTER B */
    { 0x63, 0x0063 }, /* LATIN SMALL LETTER C */
    { 0x64, 0x0064 }, /* LATIN SMALL LETTER D */
    { 0x65, 0x0065 }, /* LATIN SMALL LETTER E */
    { 0x66, 0x0066 }, /* LATIN SMALL LETTER F */
    { 0x67, 0x0067 }, /* LATIN SMALL LETTER G */
    { 0x68, 0x0068 }, /* LATIN SMALL LETTER H */
    { 0x69, 0x0069 }, /* LATIN SMALL LETTER I */
    { 0x6a, 0x006a }, /* LATIN SMALL LETTER J */
    { 0x6b, 0x006b }, /* LATIN SMALL LETTER K */
    { 0x6c, 0x006c }, /* LATIN SMALL LETTER L */
    { 0x6d, 0x006d }, /* LATIN SMALL LETTER M */
    { 0x6e, 0x006e }, /* LATIN SMALL LETTER N */
    { 0x6f, 0x006f }, /* LATIN SMALL LETTER O */
    { 0x70, 0x0070 }, /* LATIN SMALL LETTER P */
    { 0x71, 0x0071 }, /* LATIN SMALL LETTER Q */
    { 0x72, 0x0072 }, /* LATIN SMALL LETTER R */
    { 0x73, 0x0073 }, /* LATIN SMALL LETTER S */
    { 0x74, 0x0074 }, /* LATIN SMALL LETTER T */
    { 0x75, 0x0075 }, /* LATIN SMALL LETTER U */
    { 0x76, 0x0076 }, /* LATIN SMALL LETTER V */
    { 0x77, 0x0077 }, /* LATIN SMALL LETTER W */
    { 0x78, 0x0078 }, /* LATIN SMALL LETTER X */
    { 0x79, 0x0079 }, /* LATIN SMALL LETTER Y */
    { 0x7a, 0x007a }, /* LATIN SMALL LETTER Z */
    { 0x7b, 0x007b }, /* LEFT CURLY BRACKET */
    { 0x7c, 0x007c }, /* VERTICAL LINE */
    { 0x7d, 0x007d }, /* RIGHT CURLY BRACKET */
    { 0x7e, 0x007e }, /* TILDE */
    { 0x80, 0x00c7 }, /* LATIN CAPITAL LETTER C WITH CEDILLA */
    { 0x81, 0x00fc }, /* LATIN SMALL LETTER U WITH DIAERESIS */
    { 0x82, 0x00e9 }, /* LATIN SMALL LETTER E WITH ACUTE */
    { 0x83, 0x00e2 }, /* LATIN SMALL LETTER A WITH CIRCUMFLEX */
    { 0x84, 0x00e4 }, /* LATIN SMALL LETTER A WITH DIAERESIS */
    { 0x85, 0x00e0 }, /* LATIN SMALL LETTER A WITH GRAVE */
    { 0x86, 0x00e5 }, /* LATIN SMALL LETTER A WITH RING ABOVE */
    { 0x87, 0x00e7 }, /* LATIN SMALL LETTER C WITH CEDILLA */
    { 0x88, 0x00ea }, /* LATIN SMALL LETTER E WITH CIRCUMFLEX */
    { 0x89, 0x00eb }, /* LATIN SMALL LETTER E WITH DIAERESIS */
    { 0x8a, 0x00e8 }, /* LATIN SMALL LETTER E WITH GRAVE */
    { 0x8b, 0x00ef }, /* LATIN SMALL LETTER I WITH DIAERESIS */
    { 0x8c, 0x00ee }, /* LATIN SMALL LETTER I WITH CIRCUMFLEX */
    { 0x8d, 0x00ec }, /* LATIN SMALL LETTER I WITH GRAVE */
    { 0x8e, 0x00c4 }, /* LATIN CAPITAL LETTER A WITH DIAERESIS */
    { 0x8f, 0x00c5 }, /* LATIN CAPITAL LETTER A WITH RING ABOVE */
    { 0x90, 0x00c9 }, /* LATIN CAPITAL LETTER E WITH ACUTE */
    { 0x91, 0x00e6 }, /* LATIN SMALL LIGATURE AE */
    { 0x92, 0x00c6 }, /* LATIN CAPITAL LIGATURE AE */
    { 0x93, 0x00f4 }, /* LATIN SMALL LETTER O WITH CIRCUMFLEX */
    { 0x94, 0x00f6 }, /* LATIN SMALL LETTER O WITH DIAERESIS */
    { 0x95, 0x00f2 }, /* LATIN SMALL LETTER O WITH GRAVE */
    { 0x96, 0x00fb }, /* LATIN SMALL LETTER U WITH CIRCUMFLEX */
    { 0x97, 0x00f9 }, /* LATIN SMALL LETTER U WITH GRAVE */
    { 0x98, 0x00ff }, /* LATIN SMALL LETTER Y WITH DIAERESIS */
    { 0x99, 0x00d6 }, /* LATIN CAPITAL LETTER O WITH DIAERESIS */
    { 0x9a, 0x00dc }, /* LATIN CAPITAL LETTER U WITH DIAERESIS */
    { 0x9b, 0x00a2 }, /* CENT SIGN */
    { 0x9c, 0x00a3 }, /* POUND SIGN */
    { 0x9d, 0x00a5 }, /* YEN SIGN */
    { 0x9e, 0x20a7 }, /* PESETA SIGN */
    { 0x9f, 0x0192 }, /* LATIN SMALL LETTER F WITH HOOK */
    { 0xa0, 0x00e1 }, /* LATIN SMALL LETTER A WITH ACUTE */
    { 0xa1, 0x00ed }, /* LATIN SMALL LETTER I WITH ACUTE */
    { 0xa2, 0x00f3 }, /* LATIN SMALL LETTER O WITH ACUTE */
    { 0xa3, 0x00fa }, /* LATIN SMALL LETTER U WITH ACUTE */
    { 0xa4, 0x00f1 }, /* LATIN SMALL LETTER N WITH TILDE */
    { 0xa5, 0x00d1 }, /* LATIN CAPITAL LETTER N WITH TILDE */
    { 0xa6, 0x00aa }, /* FEMININE ORDINAL INDICATOR */
    { 0xa7, 0x00ba }, /* MASCULINE ORDINAL INDICATOR */
    { 0xa8, 0x00bf }, /* INVERTED QUESTION MARK */
    { 0xa9, 0x2310 }, /* REVERSED NOT SIGN */
    { 0xaa, 0x00ac }, /* NOT SIGN */
    { 0xab, 0x00bd }, /* VULGAR FRACTION ONE HALF */
    { 0xac, 0x00bc }, /* VULGAR FRACTION ONE QUARTER */
    { 0xad, 0x00a1 }, /* INVERTED EXCLAMATION MARK */
    { 0xae, 0x00ab }, /* LEFT-POINTING DOUBLE ANGLE QUOTATION MARK */
    { 0xaf, 0x00bb }, /* RIGHT-POINTING DOUBLE ANGLE QUOTATION MARK */
    { 0xb0, 0x2591 }, /* LIGHT SHADE */
    { 0xb1, 0x2592 }, /* MEDIUM SHADE */
    { 0xb2, 0x2593 }, /* DARK SHADE */
    { 0xb3, 0x2502 }, /* BOX DRAWINGS LIGHT VERTICAL */
    { 0xb4, 0x2524 }, /* BOX DRAWINGS LIGHT VERTICAL AND LEFT */
    { 0xb5, 0x2561 }, /* BOX DRAWINGS VERTICAL SINGLE AND LEFT DOUBLE */
    { 0xb6, 0x2562 }, /* BOX DRAWINGS VERTICAL DOUBLE AND LEFT SINGLE */
    { 0xb7, 0x2556 }, /* BOX DRAWINGS DOWN DOUBLE AND LEFT SINGLE */
    { 0xb8, 0x2555 }, /* BOX DRAWINGS DOWN SINGLE AND LEFT DOUBLE */
    { 0xb9, 0x2563 }, /* BOX DRAWINGS DOUBLE VERTICAL AND LEFT */
    { 0xba, 0x2551 }, /* BOX DRAWINGS DOUBLE VERTICAL */
    { 0xbb, 0x2557 }, /* BOX DRAWINGS DOUBLE DOWN AND LEFT */
    { 0xbc, 0x255d }, /* BOX DRAWINGS DOUBLE UP AND LEFT */
    { 0xbd, 0x255c }, /* BOX DRAWINGS UP DOUBLE AND LEFT SINGLE */
    { 0xbe, 0x255b }, /* BOX DRAWINGS UP SINGLE AND LEFT DOUBLE */
    { 0xbf, 0x2510 }, /* BOX DRAWINGS LIGHT DOWN AND LEFT */
    { 0xc0, 0x2514 }, /* BOX DRAWINGS LIGHT UP AND RIGHT */
    { 0xc1, 0x2534 }, /* BOX DRAWINGS LIGHT UP AND HORIZONTAL */
    { 0xc2, 0x252c }, /* BOX DRAWINGS LIGHT DOWN AND HORIZONTAL */
    { 0xc3, 0x251c }, /* BOX DRAWINGS LIGHT VERTICAL AND RIGHT */
    { 0xc4, 0x2500 }, /* BOX DRAWINGS LIGHT HORIZONTAL */
    { 0xc5, 0x253c }, /* BOX DRAWINGS LIGHT VERTICAL AND HORIZONTAL */
    { 0xc6, 0x255e }, /* BOX DRAWINGS VERTICAL SINGLE AND RIGHT DOUBLE */
    { 0xc7, 0x255f }, /* BOX DRAWINGS VERTICAL DOUBLE AND RIGHT SINGLE */
    { 0xc8, 0x255a }, /* BOX DRAWINGS DOUBLE UP AND RIGHT */
    { 0xc9, 0x2554 }, /* BOX DRAWINGS DOUBLE DOWN AND RIGHT */
    { 0xca, 0x2569 }, /* BOX DRAWINGS DOUBLE UP AND HORIZONTAL */
    { 0xcb, 0x2566 }, /* BOX DRAWINGS DOUBLE DOWN AND HORIZONTAL */
    { 0xcc, 0x2560 }, /* BOX DRAWINGS DOUBLE VERTICAL AND RIGHT */
    { 0xcd, 0x2550 }, /* BOX DRAWINGS DOUBLE HORIZONTAL */
    { 0xce, 0x256c }, /* BOX DRAWINGS DOUBLE VERTICAL AND HORIZONTAL */
    { 0xcf, 0x2567 }, /* BOX DRAWINGS UP SINGLE AND HORIZONTAL DOUBLE */
    { 0xd0, 0x2568 }, /* BOX DRAWINGS UP DOUBLE AND HORIZONTAL SINGLE */
    { 0xd1, 0x2564 }, /* BOX DRAWINGS DOWN SINGLE AND HORIZONTAL DOUBLE */
    { 0xd2, 0x2565 }, /* BOX DRAWINGS DOWN DOUBLE AND HORIZONTAL SINGLE */
    { 0xd3, 0x2559 }, /* BOX DRAWINGS UP DOUBLE AND RIGHT SINGLE */
    { 0xd4, 0x2558 }, /* BOX DRAWINGS UP SINGLE AND RIGHT DOUBLE */
    { 0xd5, 0x2552 }, /* BOX DRAWINGS DOWN SINGLE AND RIGHT DOUBLE */
    { 0xd6, 0x2553 }, /* BOX DRAWINGS DOWN DOUBLE AND RIGHT SINGLE */
    { 0xd7, 0x256b }, /* BOX DRAWINGS VERTICAL DOUBLE AND HORIZONTAL SINGLE */
    { 0xd8, 0x256a }, /* BOX DRAWINGS VERTICAL SINGLE AND HORIZONTAL DOUBLE */
    { 0xd9, 0x2518 }, /* BOX DRAWINGS LIGHT UP AND LEFT */
    { 0xda, 0x250c }, /* BOX DRAWINGS LIGHT DOWN AND RIGHT */
    { 0xdb, 0x2588 }, /* FULL BLOCK */
    { 0xdc, 0x2584 }, /* LOWER HALF BLOCK */
    { 0xdd, 0x258c }, /* LEFT HALF BLOCK */
    { 0xde, 0x2590 }, /* RIGHT HALF BLOCK */
    { 0xdf, 0x2580 }, /* UPPER HALF BLOCK */
    { 0xe0, 0x03b1 }, /* GREEK SMALL LETTER ALPHA */
    { 0xe1, 0x00df }, /* LATIN SMALL LETTER SHARP S */
    { 0xe2, 0x0393 }, /* GREEK CAPITAL LETTER GAMMA */
    { 0xe3, 0x03c0 }, /* GREEK SMALL LETTER PI */
    { 0xe4, 0x03a3 }, /* GREEK CAPITAL LETTER SIGMA */
    { 0xe5, 0x03c3 }, /* GREEK SMALL LETTER SIGMA */
    { 0xe6, 0x00b5 }, /* MICRO SIGN */
    { 0xe7, 0x03c4 }, /* GREEK SMALL LETTER TAU */
    { 0xe8, 0x03a6 }, /* GREEK CAPITAL LETTER PHI */
    { 0xe9, 0x0398 }, /* GREEK CAPITAL LETTER THETA */
    { 0xea, 0x03a9 }, /* GREEK CAPITAL LETTER OMEGA */
    { 0xeb, 0x03b4 }, /* GREEK SMALL LETTER DELTA */
    { 0xec, 0x221e }, /* INFINITY */
    { 0xed, 0x03c6 }, /* GREEK SMALL LETTER PHI */
    { 0xee, 0x03b5 }, /* GREEK SMALL LETTER EPSILON */
    { 0xef, 0x2229 }, /* INTERSECTION */
    { 0xf0, 0x2261 }, /* IDENTICAL TO */
    { 0xf1, 0x00b1 }, /* PLUS-MINUS SIGN */
    { 0xf2, 0x2265 }, /* GREATER-THAN OR EQUAL TO */
    { 0xf3, 0x2264 }, /* LESS-THAN OR EQUAL TO */
    { 0xf4, 0x2320 }, /* TOP HALF INTEGRAL */
    { 0xf5, 0x2321 }, /* BOTTOM HALF INTEGRAL */
    { 0xf6, 0x00f7 }, /* DIVISION SIGN */
    { 0xf7, 0x2248 }, /* ALMOST EQUAL TO */
    { 0xf8, 0x00b0 }, /* DEGREE SIGN */
    { 0xf9, 0x2219 }, /* BULLET OPERATOR */
    { 0xfa, 0x00b7 }, /* MIDDLE DOT */
    { 0xfb, 0x221a }, /* SQUARE ROOT */
    { 0xfc, 0x207f }, /* SUPERSCRIPT LATIN SMALL LETTER N */
    { 0xfd, 0x00b2 }, /* SUPERSCRIPT TWO */
    { 0xfe, 0x25a0 }, /* BLACK SQUARE */

    { -1, 0 }
};
