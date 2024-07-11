#include <iostream>
using namespace std;

int main() {
  float num1, num2;   // defining two operands
  char op;

  cout << "Enter first number: ";
  cin >> num1;

  cout << "Enter second number: ";
  cin >> num2;

  cout << "Enter operator (+, -, *, /): ";
  cin >> op;

  switch (op) {
    case '+': //addition
      cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;
      break;
    
    case '-': //subtraction
      cout << num1 << " - " << num2 << " = " << num1 - num2 << endl;
      break;
    
    case '*': //multiplication
      cout << num1 << " * " << num2 << " = " << num1 * num2 << endl;
      break;

    case '/': //division
      if (num2 != 0) {
        cout << num1 << " / " << num2 << " = " << num1 / num2 << endl;
      } else {
        cout << "Error: Division by zero is not allowed." << endl;  //defining mathematics rule.
      }
      break;

    default:
      cout << "Error: Invalid operator. Please enter +, -, *, or /." << endl;   
      break;
  }

  return 0;
}
