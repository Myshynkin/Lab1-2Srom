#include<iostream>
#include <string>
#include "Bignumber.h"
using namespace std;
string imput(int n) 
{
	string first, second, perator;
	if (n == 1) {
		cout << "Enter the first number:";
		cin >> first;
		return first;
	}
	if (n == 2) {
		cout << "Enter the second number:";
		cin >> second;
		return second;
	}
	if (n == 3) {
		cout << "Enter the operator(+,-,*,/,^,%)";
		cin >> perator;
		return perator;
	}
}
void Program()
{
	string a_number, b_number, _operator;
	while (true)
	{
		Bignumber C("0");
		a_number = imput (1);
		_operator = imput(3);
		b_number = imput (2);
		Bignumber A(a_number), B(b_number);
		if (_operator == "+")
		{
			C = A + B;
			C.incons();
			cout << '\n';
		}
		else if (_operator == "-")
		{
			C = A - B;
			C.incons();
			cout << '\n';
		}
		else if (_operator == "*")
		{
			C = A * B;
			C.incons();
			cout << '\n';
		}
		else if (_operator == "/")
		{
			C = A / B;
			C.incons();
			cout << '\n';
		}
		else if (_operator == "%")
		{
			C = A % B;
			C.incons();
			cout << '\n';
		}
		else if (_operator == "^")
		{
			C = A ^ B;
			C.incons();
			cout << '\n';
		}
		else
		{
			cout<<"Error"<< '\n';
		}
		
	}

}