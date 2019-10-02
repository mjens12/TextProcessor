#include <stdio.h>
#include "logic.h"

int main(int argc, char *argv[]){
	char next[5];
	next_word(&next);
	printf("%s", &next);
	return (1);
}
