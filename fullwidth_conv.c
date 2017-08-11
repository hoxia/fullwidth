#include <stdio.h>
#include <stdint.h>

void writefw(char c)
{
	uint16_t delta = 0xFF01u - '!';

	if (c >= '!' && c <= '~') {
		uint16_t fw = delta + c;
		uint8_t utf8[3];
		putchar(0xE0 | (fw >> 12));
		putchar(0x80 | (0x3F & (fw >> 6)));
		putchar(0x80 | (0x3F & fw));
	}
	else {
		putchar(c);
	}
}

int main(int argc, char *argv[])
{
	int w, c;

	for (w = 1; w < argc; ++w) {
		char const *s = argv[w];
		while ((c = *s++) != '\0') {
			writefw(c);
		}
		if (w < (argc - 1)) {
			putchar(' ');
			putchar(' ');
		}
	}
}
