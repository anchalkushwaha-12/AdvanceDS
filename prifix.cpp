#include <bits/stdc++.h>
using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/' || op == '%') return 2;
    if (op == '^') return 3;
    return 0;
}

bool isRightAssociative(char op) {
    return op == '^';
}

int main() {
    char op;

    cout << "Enter operator: ";
    cin >> op;

    cout << "Precedence: " << precedence(op) << endl;

    if (isRightAssociative(op))
        cout << "Right Associative" << endl;
    else
        cout << "Left Associative" << endl;

    return 0;
}