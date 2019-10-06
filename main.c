#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "logic.h"
/*https://www.cs.bu.edu/teaching/c/file-io/intro/
https://arduino.stackexchange.com/questions/3774/how-can-i-declare-an-array-of-variable-size-globally */

int main(int argc, char *argv[]) {
	char inBuffer[100] = "";
	int width = 0;
	/*Testing in-buffer functionality
	scanf("%s", &inBuffer); */
	/*strcpy(inBuffer, "Testing this thing"); */
	fgets(inBuffer, 100, stdin);
	printf("%s", inBuffer);

	/*Arg error handling */
	if (argc == 3) {
		if (strcmp(argv[1], "-w") == 0) {
			if (atoi(argv[2]) == 0) {
				fprintf(stderr,
						"The width command line parameter is not a number!");
			} else {
				width = atoi(argv[2]);
				char *outBuffer = malloc(sizeof(char) * width);
				printf("Formatting text with a width of %d characters.\n", width);
			}
		} else {
			fprintf(stderr,
					"You forgot to enter -w as the command line argument!");
		}
	}
	else{
		fprintf(stderr, "You have not entered the correct number of command line arguments!");
	}

	/* scanf("%s", &inBuffer); */


	/* Testing stuff */
	char next[10];
	strcpy(next, "testing!");
	printf("%s", next);
	printf("\ntest");
	return (1);
}
