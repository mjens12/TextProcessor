#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "logic.h"
/*https://www.cs.bu.edu/teaching/c/file-io/intro/
 https://arduino.stackexchange.com/questions/3774/how-can-i-declare-an-array-of-variable-size-globally */

int main(int argc, char *argv[]) {
	char inBuffer[100] = "";
	char *inBufferTemp;
	char *outBuffer;
	char *temp;
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
				outBuffer = calloc(width + 1, sizeof(char));
				temp = calloc(width + 1, sizeof(char));
				printf("--Formatting text to a width of %d characters.--\n", width);
			}
		} else {
			fprintf(stderr,
					"You forgot to enter -w as the command line argument!");
		}
	} else {
		fprintf(stderr,
				"You have not entered the correct number of command line arguments!");
	}

	fgets(inBuffer, 100, stdin);

	// https://stackoverflow.com/questions/23192362/strtok-affects-the-input-buffer
	// copies inBuffer to a temp array so that strtok doesn't modify the original array
	inBufferTemp = calloc(strlen(inBuffer) + 1, sizeof(char));

	strcpy(inBufferTemp, inBuffer);

	while (strchr(inBufferTemp, '\n') != NULL) {
		char *ptr = strchr(inBufferTemp, '\n');
		*ptr = 0;
	}
	bool moreToParse = true;
	temp = strtok(inBufferTemp, " ");

	int count = 0;

	while (strlen(outBuffer) <= width) {

		while (lineLength <= (width - strlen(temp)) - 1) {

			//Handles newline char in token

			if (strchr(temp, '\n') != NULL) {
				char *ptr = strchr(temp, '\n');
				*ptr = 0;
			}
			lineLength = lineLength + strlen(temp) + 1;
			strcat(outBuffer, temp);
			strcat(outBuffer, " ");
			temp = strtok(NULL, " ");

			//printf(outBuffer);

			if (!temp) {
				if (!moreToParse) {
					break;
				}
				fgets(inBuffer, 100, stdin);
				strcpy(inBufferTemp, inBuffer);
				temp = strtok(inBufferTemp, " ");
			}
		}

		//Need to figure out how to include lines between paragraphs
		lineLength = 0;

		strcat(outBuffer, "\n");
		printf("%s", outBuffer);
		//printf("OUTBUFFER PRINTED");

		//printf("--The Line Above is %lu Chars--\n", strlen(outBuffer));
		//printf("\n%d\n", strlen(outBuffer));

		//printf("TEMP: %s\n", temp);
		//printf("IBUFFER: %s\n", inBuffer);
		//printf("OBUFFER: %s\n", outBuffer);

		strcpy(outBuffer, "");

		count = count + 1;

		//if (moreToParse) == 1) {
		//break;
		//}

		//printf("%d", count);
		if (count == 35) {
			break;
		}
		if (moreToParse == false) {
			break;
		}
		if (feof(stdin)) {
			moreToParse = false;
		}

	}

//Not stopping when the EOF is reached
	/*
	 * 1. While there is room in the outbuffer, parse input and add it
	 * 2. If the next input would overflow the outbuffer, print and flush outbuffer
	 * 3. Make sure strtok has input to read at all times
	 *
	 */

	free(temp);
	free(outBuffer);
	free(inBufferTemp);
	return (1);
}

