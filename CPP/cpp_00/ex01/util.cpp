#include <string>
#include <climits>

int my_atoi(std::string s)
{
	int num = 0;
	int sign = 1;
	int digit = 1;

	for(int i = s.size() - 1; i >= 0 ; i--) {
		if(!isdigit(s[i]) && s[i] != '+' && s[i] != '-') {
			throw std::domain_error("String contains non-numeric, non-sign character.");
		}
		if(s[i] == '-') {
			sign *= -1;
			continue;
		}
		if(s[i] == '+') {
			continue;
		}

		int val = s[i] - 48;

		if(INT_MAX - val <= num)
			throw std::range_error("Given number is larger than INT_MAX");
		if(INT_MIN + val >= num)
			throw std::range_error("Given number is smaller than INT_MIN");

		num += val * digit;
		digit *= 10;
	}

	return num * sign;
}