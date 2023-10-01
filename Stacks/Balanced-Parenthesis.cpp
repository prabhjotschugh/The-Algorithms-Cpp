#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isBalanced(string expression) {
    stack<char> s;
    for (char bracket : expression) {
        if (bracket == '(' || bracket == '[' || bracket == '{') {
            s.push(bracket);
        } else if (!s.empty() &&
                   ((bracket == ')' && s.top() == '(') ||
                    (bracket == ']' && s.top() == '[') ||
                    (bracket == '}' && s.top() == '{'))) {
            s.pop();
        } else {
            return false;
        }
    }
    return s.empty();
}

int main() {
    string expression = "{[()]}";
    bool balanced = isBalanced(expression);
    if (balanced) {
        cout << "The expression is balanced." << endl;
    } else {
        cout << "The expression is not balanced." << endl;
    }
    return 0;
}
