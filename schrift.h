/* This file is part of libschrift.
 *
 * � 2019, 2020 Thomas Oltmann
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE. */

#ifndef SCHRIFT_H
#define SCHRIFT_H 1

#ifdef __cplusplus
extern "C" {
#endif

#include <assert.h>
#include <errno.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if defined(_MSC_VER)
# define restrict __restrict
#endif

#if defined(_WIN32)
# define WIN32_LEAN_AND_MEAN 1
# include <windows.h>
#else
# include <fcntl.h>
# include <sys/mman.h>
# include <sys/stat.h>
# include <unistd.h>
#endif

#define SFT_DOWNWARD_Y    0x01
#define SFT_RENDER_IMAGE  0x02
#define SFT_CATCH_MISSING 0x04

	/* Deprecated. Use SFT_RENDER_IMAGE instead (Only the name has changed). */
#define SFT_CHAR_IMAGE 0x02

	struct SFT_Font {
		const uint8_t* memory;
		unsigned long size;
#if defined(_WIN32)
		HANDLE mapping;
#endif
		int source;

		uint_least16_t unitsPerEm;
		int_least16_t locaFormat;
		uint_least16_t numLongHmtx;
	};
	typedef struct SFT_Font SFT_Font;

	struct SFT
	{
		SFT_Font* font;
		double xScale;
		double yScale;
		double x;
		double y;
		unsigned int flags;
	};

	struct SFT_Char
	{
		uint8_t* image;
		double advance;
		int x;
		int y;
		int width;
		int height;
	};

	/* libschrift uses semantic versioning. */
	const char* sft_version(void);

	SFT_Font* sft_loadmem(const void* mem, unsigned long size);
	SFT_Font* sft_loadfile(const char* filename);
	void sft_freefont(SFT_Font* font);

	int sft_linemetrics(const struct SFT* sft, double* ascent, double* descent, double* gap);
	int sft_kerning(const struct SFT* sft, unsigned long leftChar, unsigned long rightChar, double kerning[2]);
	int sft_char(const struct SFT* sft, unsigned long charCode, struct SFT_Char* chr);

#ifdef __cplusplus
}
#endif

#endif