#include <string.h>

// Function that removes newlines from each token
void rmNL(char* input) {
	if (strchr(input, '\n') != NULL) {
		char *ptr = strchr(input, '\n');
		*ptr = 0;
	}
}
