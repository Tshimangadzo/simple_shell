#include "shell.h"

char * * split_line(char * line) {
	int buffsize = 1024, position = 0;
	char * * tokens = malloc(buffsize * sizeof(char * ));
	char * token;
	int  TK_BUFF_SIZE;
	if (!tokens) {
		fprintf(stderr, "%sdash: Allocation error%s\n", TIME, STARTAGAIN);
		exit(EXIT_FAILURE);
	}
	token = _strtok(line, TOK_DELIM);
	while (token != NULL) {
		tokens[position] = token;
		position++;
		if (position >= buffsize) {
			buffsize += TK_BUFF_SIZE;
			tokens = realloc(tokens, buffsize * sizeof(char * ));

			if (!tokens) {
	fprintf(stderr, "%sdash: Allocation error%s\n", TIME, STARTAGAIN);
	exit(EXIT_FAILURE);
			}
		}

		token = _strtok(NULL, TOK_DELIM);
	}

	tokens[position] = NULL;

	return tokens;
}
