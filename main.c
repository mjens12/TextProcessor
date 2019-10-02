#include <stdio.h>
#include "logic.h"

int main(int argc, char *argv[]){
	int width = 0;
	if (strcmp(argv[1], "-w") == 0){
		width = argv[2];
	}
	/* Testing stuff */
	char next[10];
	next_word(next);
	printf("%s", next);
	printf("\ntest");
	return (1);
}
