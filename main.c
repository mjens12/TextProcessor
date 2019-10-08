#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
				outBuffer = calloc(width+1, sizeof(char));
				temp = malloc(sizeof(char) * width);
				printf("Formatting text to a width of %d characters.\n", width);
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

	// https://stackoverflow.com/questions/23192362/strtok-affects-the-input-buffer
	// copies inBuffer to a temp array so that strtok doesn't modify the original array
    inBufferTemp = calloc(strlen(inBuffer)+1, sizeof(char));

    strcpy(inBufferTemp, inBuffer);

    temp = strtok(inBufferTemp," ");

    while (temp && (lineLength <= (width - strlen(temp)))){
		lineLength = lineLength + strlen(temp) + 1;
		strcat(outBuffer, temp);
		strcat(outBuffer, " ");
		temp = strtok(NULL, " ");
		printf("%s\n", outBuffer);
	}
    if(!temp){
    	fgets(inBuffer, 100, stdin);
        strcpy(inBufferTemp, inBuffer);

    }

	printf(outBuffer);

	free(temp);
	free(outBuffer);
	free(inBufferTemp);

	return (1);
}
