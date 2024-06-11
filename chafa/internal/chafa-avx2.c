/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

/* Copyright (C) 2018-2023 Hans Petter Jansson
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

#include "config.h"

#include <emmintrin.h>
#include <immintrin.h>
#include "chafa.h"
#include "internal/chafa-private.h"

gint
calc_error_avx2 (const ChafaPixel *pixels, const ChafaColorPair *color_pair,
                 const guint32 *sym_mask_u32)
{
    __m256i err_8x_u32 = { 0 };
    const gint32 *e = (gint32 *) &err_8x_u32;
    __m128i fg_4x_u32, bg_4x_u32;
    __m256i fg_4x_u64, bg_4x_u64;
    const __m256i *pixels_8x_p = (const __m256i *) pixels;
    const __m256i *sym_mask_8x_p = (const __m256i *) sym_mask_u32;
    gint i;

    fg_4x_u32 = _mm_set1_epi32 (CHAFA_COLOR8_U32 (color_pair->colors [CHAFA_COLOR_PAIR_FG]));
    fg_4x_u64 = _mm256_cvtepu8_epi16 (fg_4x_u32);

    bg_4x_u32 = _mm_set1_epi32 (CHAFA_COLOR8_U32 (color_pair->colors [CHAFA_COLOR_PAIR_BG]));
    bg_4x_u64 = _mm256_cvtepu8_epi16 (bg_4x_u32);

    for (i = 0; i < CHAFA_SYMBOL_N_PIXELS / 8; i++)
    {
        __m256i pixels_8x, sym_mask_8x;
        __m256i p0, m0, fg0, bg0, d0;
        __m256i p1, m1, fg1, bg1, d1;

        pixels_8x = _mm256_loadu_si256 (pixels_8x_p);
        pixels_8x_p++;

        sym_mask_8x = _mm256_loadu_si256 (sym_mask_8x_p);
        sym_mask_8x_p++;

        p0 = _mm256_cvtepu8_epi16 (_mm256_extracti128_si256 (pixels_8x, 0));
        m0 = _mm256_cvtepi8_epi16 (_mm256_extracti128_si256 (sym_mask_8x, 0));
        fg0 = _mm256_and_si256 (m0, _mm256_sub_epi16 (fg_4x_u64, p0));
        bg0 = _mm256_andnot_si256 (m0, _mm256_sub_epi16 (bg_4x_u64, p0));
        d0 = _mm256_or_si256 (fg0, bg0);
        d0 = _mm256_mullo_epi16 (d0, d0);
        d0 = _mm256_add_epi32 (_mm256_cvtepu16_epi32 (_mm256_extracti128_si256 (d0, 0)),
                               _mm256_cvtepu16_epi32 (_mm256_extracti128_si256 (d0, 1)));

        p1 = _mm256_cvtepu8_epi16 (_mm256_extracti128_si256 (pixels_8x, 1));
        m1 = _mm256_cvtepi8_epi16 (_mm256_extracti128_si256 (sym_mask_8x, 1));
        fg1 = _mm256_and_si256 (m1, _mm256_sub_epi16 (fg_4x_u64, p1));
        bg1 = _mm256_andnot_si256 (m1, _mm256_sub_epi16 (bg_4x_u64, p1));
        d1 = _mm256_or_si256 (fg1, bg1);
        d1 = _mm256_mullo_epi16 (d1, d1);
        d1 = _mm256_add_epi32 (_mm256_cvtepu16_epi32 (_mm256_extracti128_si256 (d1, 0)),
                               _mm256_cvtepu16_epi32 (_mm256_extracti128_si256 (d1, 1)));

        err_8x_u32 = _mm256_add_epi32 (err_8x_u32, d0);
        err_8x_u32 = _mm256_add_epi32 (err_8x_u32, d1);
    }

    return e [0] + e [1] + e [2] + e [4] + e [5] + e [6];
}
