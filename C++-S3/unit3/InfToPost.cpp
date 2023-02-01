#include <iostream>
#include <stack>
#include <string>
using namespace std;

class InfixToPostfix {
    public:
        bool isOperator(char c);
        int priority(char c);
        string convert(string infix);
};

bool InfixToPostfix::isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '$');
}

int InfixToPostfix::priority(char c) {
    if (c == '$') return 3;
    else if (c == '*' || c == '/') return 2;
    else if (c == '+' || c == '-') return 1;
    else return 0;
}

string InfixToPostfix::convert(string infix) {
    stack<char> s;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {
        if (infix[i] == ' ' || infix[i] == ',') continue;
        else if (isOperator(infix[i])) {
            while (!s.empty() && priority(s.top()) >= priority(infix[i])) {
                postfix += s.top();
                s.pop();
            }
            s.push(infix[i]);
        } else if (infix[i] == '(') {
            s.push(infix[i]);
        } else if (infix[i] == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop();
        } else {
            postfix += infix[i];
        }
    }

    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

int main() {
    InfixToPostfix converter;
    string infix;
    cout << "Enter an infix arithmetic expression: ";
    getline(cin, infix);

    string postfix = converter.convert(infix);
    cout << "Postfix expression: " << postfix << endl;
    return 0;
}