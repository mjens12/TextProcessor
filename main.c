#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "logic.h"
/*https://www.cs.bu.edu/teaching/c/file-io/intro/
https://arduino.stackexchange.com/questions/3774/how-can-i-declare-an-array-of-variable-size-globally */

int main(int argc, char *argv[]) {
	char inBuffer[100] = "";
	char *temp;
	char *outBuffer;
	int width = 0;
	int lineLength = 0;

	/*Arg error handling */
	if (argc == 3) {
		if (strcmp(argv[1], "-w") == 0) {
			if (atoi(argv[2]) == 0) {
				fprintf(stderr,
						"The width command line parameter is not a number!");
			} else {
				width = atoi(argv[2]);
				outBuffer = malloc(sizeof(char) * width);
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

	fgets(inBuffer, 100, stdin);

	printf("%s", inBuffer);

	temp = strtok(inBuffer, " ");

	strcpy(outBuffer, temp);

	while (temp){
		printf("%s", temp);
		strcat(temp, " ");
		lineLength = lineLength + strlen(temp);
		strcat(outBuffer, temp);
		strcpy(temp, strtok(NULL, " "));
	}

	strcpy(outBuffer, temp);

	printf(outBuffer);

	free(outBuffer);

	return (1);
}
