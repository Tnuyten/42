/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 21:32:09 by tnuyten           #+#    #+#             */
/*   Updated: 2023/09/15 17:09:53 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>

using std::cout;
using std::cerr;
using std::endl;

using std::string;
using std::stack;
using std::isdigit;

int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
int divide(int a, int b) { return a / b; }

int rpn(string expression) {
	stack<int> s;
	string operations = "+-*/";
	int(*op_func[])(int, int) = {add, subtract, multiply, divide};
	size_t pos;

	for (char token: expression) {
		if (token == ' ')
			continue;
		else if ((pos = operations.find(token)) != string::npos && s.size() >= 2) {
			int v2 = s.top(); s.pop();
			int v1 = s.top(); s.pop();
			s.push(op_func[pos](v1, v2)); // Apply the operation to the top two numbers and push the result back on the stack
			cout << v1 << " " << token << " " << v2 << " = " << s.top() << endl; //Shows the intermediate steps
		}
		else if (isdigit(token)) {
			token -= 48; //ascii to number.
			s.push(token);
		}
		else {
			cout << "Error" << endl;
			exit(EXIT_FAILURE);
		}
	}

	if (s.size() != 1) {
		cout << "Error" << endl;
		exit(EXIT_FAILURE);
	}

	return s.top();
}

int main(int argc, char** argv) {
	if (argc != 2) {
		cerr << "Usage: ./RPN \"[expression]\"" << endl;
		return 1;
	}

	cout << rpn(argv[1]) << endl;

	return 0;
}