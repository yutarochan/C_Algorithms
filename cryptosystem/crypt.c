#include <stdio.h>
#include <stdlib.h>

/*
 * crypt.c
 * A simple cryptosystem encoding and decoding mechanism demonstration.
 *
 */

int main(int argc, char *argv[])
{
	int c, r;
	FILE *inputFile, *outputFile;

	if (argc < 3 || argc > 4 ||
		(inputFile = fopen(argv[1], "rb")) == NULL ||
		(outputFile = fopen(argv[2], "wb")) == NULL)
	{
		fputs("crypt parameters: inputFile outputFile [key]\n", stderr);
		return EXIT_FAILURE;
	}
	
	if (argc == 4) srand(atoi(argv[3]));
	while ((c = getc(inputFile)) != EOF)
	{
		do {
			r = rand() / ((RAND_MAX + 1U) / 256);
		} while (r >= 256);
		putc(c ^ r, outputFile);
	}

	return EXIT_SUCCESS;
}
