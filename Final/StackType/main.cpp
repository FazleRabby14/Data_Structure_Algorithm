#include "stacktype.cpp"
#include<iostream>
using namespace std;

bool IsOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int Precedence(char c) {
    if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return 0;
}

string InfixToPostfix(string infix) {
    StackType<char> stack;
    string postfix = "";
    for (char c : infix) {
        if (isdigit(c))
            postfix += c;
        else if (c == '(') {
            stack.Push(c);
        }
        else if (c == ')') {
            while (!stack.IsEmpty() && stack.Top() != '(') {
                postfix += stack.Top();
                stack.Pop();
            }
            if (!stack.IsEmpty() && stack.Top() == '(') {
                stack.Pop();
            }
        }

        else if (IsOperator(c)) {
            while (!stack.IsEmpty() && Precedence(c) <= Precedence(stack.Top())) {
                postfix += stack.Top();
                stack.Pop();
            }
            stack.Push(c);
        }
    }

    while (!stack.IsEmpty()) {
        postfix += stack.Top();
        stack.Pop();
    }
     if (!stack.IsEmpty() && stack.Top() == '(')
        return "Invalid expression";

    return postfix;
}

string postfixToInfix(string postfix) {
    StackType<string> stack;

    for (char c : postfix) {
        if (IsOperator(c)) {
            string operand2 = stack.Top();
            stack.Pop();
            string operand1 = stack.Top();
            stack.Pop();

            string infix = "(" + operand1 + c + operand2 + ")";
            stack.Push(infix);

        } else {
            stack.Push(string(1, c));
        }
    }

    // The final infix expression will be on the top of the stack
    return stack.Top();
}

/*
int main() {
    std::string postfix = "23+4*";
    std::string infix = postfixToInfix(postfix);
    std::cout << "Infix expression: " << infix << std::endl;

    return 0;
}*/






int main()
{
    string infixExpression;
    cout << "Enter an infix expression: ";
    cin>>infixExpression;

    string postfixExpression = InfixToPostfix(infixExpression);
    cout << "Postfix expression: " << postfixExpression <<endl;

}
