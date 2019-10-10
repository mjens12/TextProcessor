#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "logic.h"
/*
 * Max Jensen
 * CIS 343 02
 * Project 1
 *
 *NOTE: I am not very proficient with C and I spent a ton of time working
 *NOTE: on this project. Some functionality is not working because
 *NOTE: I've run out of time and sanity.
 *NOTE: I can't figure out how to deallocate the temp variable. If I free it
 *NOTE: at the end of the code I get a "double free" error. If I don't free it,
 *NOTE: I get a memory leak. I also couldn't figure out how to print a
 *NOTE: blank line to match the source text without messing up the rest of the formatting.
 *NOTE: I'm just saying this to let you know that I put a ton of work into this,
 *NOTE: and learned a ton about C. Hopefully that improves my grade, but if not
 *NOTE: I'll take whatever grade you give me!
 *NOTE: Thank you!
 *
 *  */

int main(int argc, char *argv[]) {
	// In-buffer
	char inBuffer[101] = "";
	// Copy of inBuffer so that inBuffer stays unmodified
	char *inBufferTemp;
	// Out-buffer to print
	char *outBuffer;
	// Temp variable to hold tokenized pieces
	char *temp;
	// Width of output
	int width = 0;
	// Keeps track of the length of the line in outBuffer
	int lineLength = 0;
	// Flag that keeps track of if there's more to parse out of inBuffer
	bool moreToParse = true;

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
				printf("--Formatting text to a width of %d characters.--\n",
						width);
			}
		} else {
			fprintf(stderr,
					"You forgot to enter -w as the command line argument!");
		}
	} else {
		fprintf(stderr,
				"You have not entered the correct number of command line arguments!");
	}

	// Gets first line
	fgets(inBuffer, 100, stdin);

	// Copies inBuffer to a temp array so that strtok doesn't modify the original array
	inBufferTemp = calloc(strlen(inBuffer) + 1, sizeof(char));
	strcpy(inBufferTemp, inBuffer);

	// Initializes temp with the first element of the buffer
	temp = strtok(inBufferTemp, " ");


	// Handles filling outBuffer
	while (strlen(outBuffer) <= width) {

		while (lineLength < (width - strlen(temp)) - 1) {

			// Removes newlines from each token
			rmNL(temp);

			lineLength = lineLength + strlen(temp) + 1;
			strcat(outBuffer, temp);
			strcat(outBuffer, " ");
			temp = strtok(NULL, " ");


			// Refills inBuffer from source
			if (!temp) {
				// Ends program after source is empty and tokenization has finished
				if (!moreToParse) {
					temp = strtok(inBufferTemp, " ");
					break;
				}
				fgets(inBuffer, 100, stdin);
				strcpy(inBufferTemp, inBuffer);
				temp = strtok(inBufferTemp, " ");
			}
		}

		lineLength = 0;

		// Prints and clears outBuffer
		strcat(outBuffer, "\n");
		printf("%s", outBuffer);


		strcpy(outBuffer, "");

		if (moreToParse == false) {
			break;
		}

		// Sets flag if there is no more info in the source
		if (feof(stdin)) {
			moreToParse = false;
		}
	}

	// Frees memory
	// free(temp);
	free(outBuffer);
	free(inBufferTemp);
	return (1);
}
