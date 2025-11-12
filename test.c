#include <stdio.h>
#include <string.h>

int main(void) {
	char s[1024];

	/* Read a line from stdin (up to 1023 chars). */
	if (fgets(s, sizeof(s), stdin) == NULL) {
		return 0;
	}

	/* Remove trailing newline if present. */
	size_t len = strlen(s);
	if (len > 0 && s[len - 1] == '\n') {
		s[--len] = '\0';
	}

	/* Reverse the string in place. */
	for (size_t i = 0; i < len / 2; ++i) {
		char tmp = s[i];
		s[i] = s[len - 1 - i];
		s[len - 1 - i] = tmp;
	}

	/* Print the reversed string. */
	printf("%s\n\n", s);
	return 0;
}