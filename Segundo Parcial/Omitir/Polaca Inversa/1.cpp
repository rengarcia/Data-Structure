/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS

Fecha de creacion:07/12/2019		Fecha de modificacion:08/12/2019
*/
//infijo_posfijo
#include<bits/stdc++.h>
#include<iostream>
#include<stack>
#include<string>
#include<string.h>
using namespace std;

//declaracion de resolucion de posfijo

int EvaluatePostfix(string expression);
int PerformOperation(char operation, int operand1, int operand2);
bool IsOperator(char C);
bool IsNumericDigit(char C);

//fin declaracion

//funciones de resolucion prefijo

bool isOperand(char c)
{
	return isdigit(c);
}

double evaluatePrefix(string exprsn)
{
	stack<double> Stack;

	for (int j = exprsn.size() - 1; j >= 0; j--) {

		if (isOperand(exprsn[j]))
			Stack.push(exprsn[j] - '0');

		else {

			double o1 = Stack.top();
			Stack.pop();
			double o2 = Stack.top();
			Stack.pop();

			switch (exprsn[j]) {
			case '+':
				Stack.push(o1 + o2);
				break;
			case '-':
				Stack.push(o1 - o2);
				break;
			case '*':
				Stack.push(o1 * o2);
				break;
			case '/':
				Stack.push(o1 / o2);
				break;
			}
		}
	}

	return Stack.top();
}

//fin de resolucion prefijo

int prec(char c)
{
	if(c == '^')
	return 3;
	else if(c == '*' || c == '/')
	return 2;
	else if(c == '+' || c == '-')
	return 1;
	else
	return -1;
}

int getPriority(char C)
{
	if (C == '-' || C == '+')
		return 1;
	else if (C == '*' || C == '/')
		return 2;
	else if (C == '^')
		return 3;
	return 0;
}

bool isOperator(char c)
{
	return (!isalpha(c) && !isdigit(c));
}

string infixToPostfix(string infix)
{
	infix = '(' + infix + ')';
	int l = infix.size();
	stack<char> char_stack;
	string output;

	for (int i = 0; i < l; i++) {

		if (isalpha(infix[i]) || isdigit(infix[i]))
			output += infix[i];

		else if (infix[i] == '(')
			char_stack.push('(');

		else if (infix[i] == ')') {

			while (char_stack.top() != '(') {
				output += char_stack.top();
				char_stack.pop();
			}

			char_stack.pop();
		}

		else {

			if (isOperator(char_stack.top())) {
				while (getPriority(infix[i])
				<= getPriority(char_stack.top())) {
					output += char_stack.top();
					char_stack.pop();
				}

				char_stack.push(infix[i]);
			}
		}
	}
	return output;
}

string infixToPrefix(string infix)
{
	int l = infix.size();

	reverse(infix.begin(), infix.end());

	for (int i = 0; i < l; i++) {

		if (infix[i] == '(') {
			infix[i] = ')';
			i++;
		}
		else if (infix[i] == ')') {
			infix[i] = '(';
			i++;
		}
	}

	string prefix = infixToPostfix(infix);

	reverse(prefix.begin(), prefix.end());

	return prefix;
}

int main()
{
	int option = 0;
	string expression, aux;
	do{
		cout<<"Escoja una opcion: "<<endl<<"1. infijo a posfijo."<<endl<<"2. infijo a prefijo"<<endl<<"--> ";
		cin>>option;
		switch(option){
			case 1:
				cout<<"Ingrese la expresion en infijo: ";
				cin>>expression;
				//getline(cin, expression);
				aux = infixToPrefix(expression);
				cin.ignore();
				cout<<"Posfija: "<<endl<<infixToPostfix(expression)<<endl;
				cout<<"Resultado: "<<evaluatePrefix(aux)<<endl;
				break;
			case 2:
				cout<<"Ingrese la expresion en infijo: ";
				cin>>expression;
				aux = infixToPrefix(expression);
				cin.ignore();
				cout<<"Prefija: "<<endl<<aux<<endl;
				cout<<"resultado: "<<evaluatePrefix(aux)<<endl;
				break;
		}
	}while(option != 3);

	return 0;
}
//desarrollo de posfijo

int EvaluatePostfix(string expression)
{
	stack<int> S;

	for(int i = 0;i< expression.length();i++) {

		if(expression[i] == ' ' || expression[i] == ',') continue;

		else if(IsOperator(expression[i])) {
			int operand2 = S.top(); S.pop();
			int operand1 = S.top(); S.pop();
			int result = PerformOperation(expression[i], operand1, operand2);
			S.push(result);
		}
		else if(IsNumericDigit(expression[i])){
			int operand = 0;
			while(i<expression.length() && IsNumericDigit(expression[i])) {
				operand = (operand*10) + (expression[i] - '0');
				i++;
			}
			i--;
			S.push(operand);
		}
	}
	return S.top();
}

bool IsNumericDigit(char C)
{
	if(C >= '0' && C <= '9') return true;
	return false;
}

bool IsOperator(char C)
{
	if(C == '+' || C == '-' || C == '*' || C == '/')
		return true;

	return false;
}

int PerformOperation(char operation, int operand1, int operand2)
{
	if(operation == '+') return operand1 +operand2;
	else if(operation == '-') return operand1 - operand2;
	else if(operation == '*') return operand1 * operand2;
	else if(operation == '/') return operand1 / operand2;

	else cout<<"Unexpected Error \n";
	return -1;
}

//fin desarrollo resolucion de posfijo
