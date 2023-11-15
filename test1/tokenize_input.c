#include "MFheader.h"
/*
*
*
*/
char** tokenize_input(char *buf, char *delim) {
	char **tokens = NULL;
	char *token;
	int argc = 0;
	int i = 0;
	char *buf_copy = strdup(buf);

	/* Count the number of tokens*/
	token = strtok(buf_copy, delim);
	while (token) {
		token = strtok(NULL, delim);
		argc++;
	}

	/* Allocate memory for tokens*/
	tokens = malloc(sizeof(char*) * (argc + 1));

	/* Tokenize and copy tokens*/
	token = strtok(buf, delim);
	while (token) {
		tokens[i] = strdup(token);
		i++;
		token = strtok(NULL, delim);
	}
	tokens[i] = NULL;

	free(buf_copy);
	return tokens;
}
