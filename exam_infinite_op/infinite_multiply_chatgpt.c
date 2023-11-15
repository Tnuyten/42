#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void multiply(char *s1, char *s2) {
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	int len_res = len1 + len2;
	int *result = (int *)calloc(len_res, sizeof(int));

	for (int i = len1 - 1; i >= 0; i--) {
		for (int j = len2 - 1; j >= 0; j--) {
			int product = (s1[i] - '0') * (s2[j] - '0');
			int sum = product + result[i + j + 1];
			result[i + j + 1] = sum % 10;
			result[i + j] += sum / 10;
		}
	}

	int start_index = 0;
	while (start_index < len_res - 1 && result[start_index] == 0) {
		start_index++;
	}

	for (int i = start_index; i < len_res; i++) {
		printf("%d", result[i]);
	}

	free(result);
	printf("\n");
}

int main(int argc, char **argv) {
	if (argc != 3) {
		printf("Usage: %s <number1> <number2>\n", argv[0]);
		return 1;
	}

	char *s1 = argv[1];
	char *s2 = argv[2];

	multiply(s1, s2);

	return 0;
}