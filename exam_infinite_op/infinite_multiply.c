#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

// utility
char *skip_leading_zeroes(char *str) {
	while (*str == '0' && *(str + 1) != '\0')
		str++;
	return str;
}

void display(char *str) {
	str = skip_leading_zeroes(str);
	while (*str != '\0') {
		write(1, str++, 1);
	}
	write(1, "\n", 1);
}

int is_valid_char(char c) {
	if (isdigit(c) || c == '-')
		return 1;
	return 0;
}

int verify(char *str) {
	if (str == NULL)
		return 1;
	while (*str != '\0') {
		if (!is_valid_char(*str++))
			return 0;
	}
	return 1;
}

int just_zero(char *str) {
	if (*str == '-' && *str != '\0')
		str++;
	while (*str == '0' && *str != '\0')
		str++;
	return *str == '\0';
}

// int just_zero(char *str) {
// 	if (*str == '-' && *str != '\0')
// 		str++;
// 	while (*str == '0' && *str != '\0')
// 		str++;
// 	if (*str != '\0')
// 		return 0;
// 	return 1;
// }

void add_to_res(char *res, int pos, int toadd) {
	if (toadd > 81) {
		char *message = "Incorrect usage of this function\n";
		write(1, message, strlen(message));
		exit(EXIT_FAILURE);
	}

	if (toadd >= 10) { //if toadd > 10 (but <= 81)
		int ones = toadd % 10;
		add_to_res(res, pos, ones);

		toadd = toadd / 10;
		add_to_res(res, pos - 1, toadd);
		return;
	}

	int sum = res[pos] - '0' + toadd;
	if (sum >= 10) {
		res[pos] = '0';
		int ones = sum % 10;
		int tens = sum / 10;
		add_to_res(res, pos, ones);
		add_to_res(res, pos - 1, tens);
	}
	else {
		res[pos] = sum + '0';
	}
}

#include <stdint.h>

// Algo
char *multiply(char *s1, char *s2) {
	size_t s1len = strlen(s1);
	size_t s2len = strlen(s2);
	size_t reslen = s1len + s2len + 1;
	char *res = malloc(reslen); memset(res, '0', reslen);
	res[reslen - 1] = '\0';

	for (size_t i1 = s1len - 1; i1 != SIZE_MAX; i1--) { // Going backwards
		for (size_t i2 = s2len - 1; i2 != SIZE_MAX; i2--) { // Ditto
			char c1 = s1[i1] - '0';
			char c2 = s2[i2] - '0';
			int multiplied = c1 * c2;

			add_to_res(res, i1 + i2 + 1, multiplied);
		}
	}

	return res;
}

int main(int argc, char **argv) {
	if (argc != 3) {
		write(1, "Usage: ", 7);
		write(1, argv[0], strlen(argv[0]));
		write(1, " <num1> <num2>\n", 15);
		return 1;
	}

	char *s1 = argv[1];
	char *s2 = argv[2];
	if (!verify(s1)|| !verify(s2)) {
		write(1, "NaN\n", 4);
		return 1;
	}

	if (just_zero(s1) || just_zero(s2)) {
		write(1, "0", 1);
		return 0;
	} // If either multiplicant is a zero, the answer is just zero. Necessary to avoid writing -0, if -a * 0 or a * -0.

	int s1neg = 0, s2neg = 0;

	// Handle negative sign
	if (*s1 == '-') { 
		s1neg = 1;
		s1++;
	}
	if (*s2 == '-') {
		s2neg = 1;
		s2++;
	}
	if (s1neg ^ s2neg) { //XOR
			write(1, "-", 1);
	}

	char *res = multiply(s1, s2);
	display(res);
	free(res);
}