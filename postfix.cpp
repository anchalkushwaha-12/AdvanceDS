#include <bits/stdc++.h>
using namespace std;

int precedence(char op) {
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/' || op == '%') return 2;
    if(op == '^') return 3;
    return 0;
}

bool isRightAssociative(char op) {
    return op == '^';
}

string infixToPostfix(string exp) {
    stack<char> st;
    string result = "";

    for(char c : exp) {
        if(isalnum(c)) {
            // Operand goes directly to result
            result += c;
        } else if(c == '(') {
            st.push(c);
        } else if(c == ')') {
            while(!st.empty() && st.top() != '(') {
                result += st.top();
                st.pop();
            }
            st.pop(); // remove '('
        } else { // Operator
            while(!st.empty() && 
                  (precedence(st.top()) > precedence(c) || 
                  (!isRightAssociative(c) && precedence(st.top()) == precedence(c)))) {
                if(st.top() == '(') break;
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    // Pop remaining operators
    while(!st.empty()) {
        result += st.top();
        st.pop();
    }

    return result;
}

int main() {
    string Q;
    cout << "Enter infix expression: ";
    cin >> Q;

    string P = infixToPostfix(Q);
    cout << "Postfix expression: " << P << endl;

    return 0;
}
