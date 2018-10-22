/*
 ============================================================================
 Name        : main.c
 Author      : Mick Campittelli
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	char in[BUFSIZ], out[BUFSIZ];
	int input, a, c, g, t;
	FILE *fileIn, *fileOut;

	//prompt user for file input and file output
	printf("Enter input filename:\n");
	gets(in);
	fileIn = fopen(in, "r");

	printf("Enter output filename:\n");
	gets(out);
	fileOut = fopen(out, "w");

	// reads input file character by character until EOF, counting the number of A,C,T, and G's
	while ((input = fgetc(fileIn)) != EOF) {
		if (input == '\n') {
			fprintf(fileOut, "%d %d %d %d\n", a, c, g, t);
			a = 0;
			c = 0;
			g = 0;
			t = 0;
		}
		switch (input) {
		case 'A':
			a++;
			break;
		case 'C':
			c++;
			break;
		case 'G':
			g++;
			break;
		case 'T':
			t++;
			break;
		}
	}

	fclose(fileIn);
	fclose(fileOut);
	printf("Complete\n");

	return EXIT_SUCCESS;
}
