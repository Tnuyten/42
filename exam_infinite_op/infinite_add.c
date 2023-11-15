#include <stdio.h>
#include <inttypes.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

uintmax_t ft_strlen(char *str) {
	uintmax_t count = 0;
	while (*str) {
		str++;
		count ++;
	}
	return count;
}

int is_digit(char a) {
	if (a >= '0' && a <= '9')
		return 1;
	return 0;
}

void verify(char *str) {
	while (*str) {
		if (!is_digit(*str) && *str != '-') {
			write(1, "NaN\n\0", 5);
			exit(EXIT_FAILURE);
		}
		str++;
	}
}

// 1: a is bigger. 0: equal -1: b is bigger
uintmax_t compare(char *a, char *b) {
	uintmax_t alen = ft_strlen(a);
	uintmax_t blen = ft_strlen(b);

	if (alen > blen)
		return 1;
	else if (blen > alen)
		return -1;
	else {
		uintmax_t i = 0;
		while (i < alen) {
			if (a[i] > b[i])
				return 1;
			else if (a[i] < b[i])
				return -1;
			i++;
		}
	}

	return 0;
}

uintmax_t ft_max(uintmax_t a, uintmax_t b)
{
	if (a > b)
		return a;
	return b;
}

void display(char *res) {
	// Skip leading zeroes.
	while (*res == '0' && *(res + 1) != '\0') {
		res++;
	}
	while (*res != '\0') {
		char letter = *res;
		write(1, &letter, 1);
		res++;
	}
	write(1, "\n", 2);
}

void bzero(void *mem, size_t size) {
	memset(mem, '\0', size);
}

// if both positive		 , just add
// if a positive, b negative, if b is larger, swap. Then subtract.
// if a negative, b positive, if b is larger, swap. Then subtract.
// if both negative		 , print minus, skip minusses, just add

// subtract: 
char *subtract(char *s1, char *s2) { // a - b. abs(a) must be larger than or equal to abs(b).
	uintmax_t s1len = ft_strlen(s1);
	uintmax_t s2len = ft_strlen(s2);
	uintmax_t reslen = ft_max(s1len, s2len); // no +1 needed, number will not grow in size. 
	char* res = malloc(reslen + 1); //+1 for null terminator
	bzero(res, reslen + 1);

	int carry = 0;
	for (uintmax_t i = 0; i < reslen; i++) {
		char a = i < s1len ? s1[s1len - i - 1] - '0' : 0;
		char b = i < s2len ? s2[s2len - i - 1] - '0' : 0;
		char subtracted = a - b + carry;

		if (subtracted < 0) {
			subtracted = 10 + subtracted;
			carry = -1;
		}
		else {
			carry = 0;
		}
		res[reslen - i - 1] = subtracted + '0';
	}

	return res;
}

char *add(char *s1, char *s2) {
	uintmax_t s1len = ft_strlen(s1);
	uintmax_t s2len = ft_strlen(s2);
	uintmax_t reslen = ft_max(s1len, s2len) + 1; // + 1 because the answer can at most be 1 larger than the largest input
	char* res = malloc(reslen + 1); //+1 for null terminator
	bzero(res, reslen + 1);

	int carry = 0;

	for (uintmax_t i = 0; i < reslen; i++) {
		int a = i < s1len ? s1[s1len - i - 1] - '0' : 0;
		int b = i < s2len ? s2[s2len - i - 1] - '0' : 0;
		int added = a + b + carry;

		if (added > 9) {
			added = added % 10;
			carry = 1;
		}
		else {
			carry = 0;
		}
		res[reslen - i - 1] = added + '0';
	}

	return res;
}

int just_zero(char *str) {
	if (*str == '-' && *str != '\0')
		str++;
	while (*str == '0' && *str != '\0')
		str++;
	if (*str != '\0')
		return 0;
	return 1;
}

int main(int argc, char **argv) {
	if (argc != 3)
		exit(EXIT_FAILURE);

	char *s1 = argv[1]; verify(s1);
	char *s2 = argv[2]; verify(s2);

	char *res = NULL;

	int s1neg = 0;
	int s2neg = 0;

	if (*s1 == '-') {
		if (!just_zero(s1))
			s1neg = 1;
		s1++;
	}
	if (*s2 == '-') {
		if(!just_zero(s2))
			s2neg = 1;
		s2++;
	}

	if (!s1neg && !s2neg) { // Both positive
		res = add(s1, s2);
	}
	else if (s1neg && s2neg) { // Both negative
		write(1, "-", 1);
		res = add(s1, s2);
	}
	else { // -a + b or -b + a
		if (compare(s1, s2) == -1ul) { // if abs(a) is smaller than abs(b), swap them.
			char *temp = s1;
			s1 = s2;
			s2 = temp;
			int negtemp = s1neg; //Also swap record of negativity.
			s1neg = s2neg;
			s2neg = negtemp;
		}
		if (s1neg) { // -Big + Small == -(+Big - Small) Answer is always negative
			write(1, "-", 1);
			res = subtract(s1, s2);
		}
		if (s2neg) { // +B - S Answer is always positive
			res = subtract(s1, s2);
		}
	}

	display(res);
	free(res);
}
