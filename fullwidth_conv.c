#include <stdio.h>
#include <stdint.h>
#include <string.h>

void writesuper(char c)
{
	char const * supers[] = {
		"ᵃ", "ᵇ", "ᶜ", "ᵈ", "ᵉ", "ᶠ", "ᵍ", "ʰ", "ⁱ",
		"ʲ", "ᵏ", "ˡ", "ᵐ", "ⁿ", "ᵒ", "ᵖ", "ᵠ", "ʳ",
		"ˢ", "ᵗ", "ᵘ", "ᵛ", "ʷ", "ˣ", "ʸ", "ᶻ"
	};
	if ('A' <= c && c <= 'Z') {
		c += 'a' - 'A';
	}
	if ('a' <= c && c <= 'z') {
		fputs(supers[c - 'a'], stdout);
	}
	else {
		putchar(c);
	}
}

// write fullwidth version of ascii character to stdout in UTF-8 encoding.
void writefw(char c)
{
	uint16_t delta = 0xFF01u - '!';

	// ideographic space
	if (c == ' ') {
		putchar(0xE3);putchar(0x80);putchar(0x80);
	}
	// ASCII range
	else if (c >= '!' && c <= '~') {
		uint16_t fw = delta + c;
		putchar(0xE0 | (fw >> 12));
		putchar(0x80 | (0x3F & (fw >> 6)));
		putchar(0x80 | (0x3F & fw));
		// variant selector - fullwidth zero with short diagonal stroke
		if (c == '0') {
			putchar(0xEF);putchar(0xB8);putchar(0x80);
		}
		// variant selector - centered form
		else if (c == '!' || c == ',' || c == '.' || c == ':' || c == ';' || c == '?') {
			putchar(0xEF);putchar(0xB8);putchar(0x81);
		}
	}
	// passthrough all else
	else {
		putchar(c);
	}
}

enum style {
	FULLWIDTH = 0,
	SUPER,
};

typedef void (*conv_fn)(char);
conv_fn converters[] = {
	writefw,
	writesuper,
};

int main(int argc, char *argv[])
{
	int w, c;

	enum style style;
	if (argc > 1 && strcmp(argv[1], "--super") == 0) {
		style = SUPER;
		w = 2;
	}
	else {
		style = FULLWIDTH;
		w = 1;
	}

	for (; w < argc; ++w) {
		char const *s = argv[w];
		while ((c = *s++) != '\0') {
			converters[style](c);
		}
		if (w < (argc - 1)) {
			putchar(' ');
			if (style == FULLWIDTH) {
				putchar(' ');
			}
		}
	}
}
