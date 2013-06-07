/* Copyright 2013 Cody P Schafer
 *
 * See the AGPLv3 for the rights granted.
 * No warranty.
 */

#include <string.h>
#include <stdio.h>

static const int map [][10] = {
	{ 6, 7, 4, 5, 0, 1, 8, 9, 8, 9 },
	{ 2, 3, 0, 1, 8, 9, 6, 7, 0, 1 },
	{ 0, 1, 8, 9, 4, 5, 2, 3, 2, 3 },
	{ 8, 9, 0, 1, 2, 3, 4, 5, 0, 1 },
	{ 6, 7, 8, 9, 2, 3, 4, 5, 8, 9 },
	{ 9, 8, 1, 0, 5, 4, 7, 6, 7, 6 },
	{ 5, 4, 3, 2, 1, 0, 9, 8, 7, 6 },
	{ 1, 0, 3, 2, 5, 4, 7, 6, 3, 2 },
};

static int decode_password(const char *in, char *out)
{
	int i;
	for (i = 0; i < 8; i++) {
		int c = in[i];
		if ('0' > c || c > '9')
			return -1;

		out[i] = map[7 - i][c - '0'] + '0';
	}

	out[i] = '\0';
	return 0;
}

int main(int argc, char **argv)
{
	if (argc != 2) {
		printf("usage: %s <code printed after failed hd password entry>\n",
				argv[0]);
		return -1;
	}

	size_t l = strlen(argv[1]);
	if (l != 8) {
		fprintf(stderr, "error: code must be 8 digits\n");
		return -1;
	}


	char out[9];
	int r =	decode_password(argv[1], out);
	if (r) {
		fprintf(stderr, "error: invalid code, all characters must be digits.\n");
		return -1;
	}

	puts(out);

	return 0;
}
