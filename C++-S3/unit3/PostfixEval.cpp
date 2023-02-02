#include <iostream>
#include <stack>
#include <string>

using namespace std;

class EvaluatePostfix {
    public:
        int evaluate(string exp) {
            stack<int> s;

            // Scan all characters one by one
            for (int i = 0; exp[i]; i++) {
                // If the scanned character is an operand (number here),
                // push it to the stack.
                if (isdigit(exp[i]))
                    s.push(exp[i] - '0');

                // If the scanned character is an operator, pop two
                // elements from stack apply the operator
                else {
                    int val1 = s.top();
                    s.pop();
                    int val2 = s.top();
                    s.pop();

                    switch (exp[i]) {
                    case '+':
                        s.push(val2 + val1);
                        break;
                    case '-':
                        s.push(val2 - val1);
                        break;
                    case '*':
                        s.push(val2 * val1);
                        break;
                    case '/':
                        s.push(val2 / val1);
                        break;
                    }
                }
            }
            return s.top();
        }
};

// Driver code
int main()
{
    EvaluatePostfix e;
    string exp = "231*+9-";
    cout << e.evaluate(exp);
    return 0;
}
