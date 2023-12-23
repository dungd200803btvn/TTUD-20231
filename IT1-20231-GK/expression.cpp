#include <iostream>
#include <stack>
#include <string>
#include <cstdlib>

using namespace std;

const int MOD = 1000000007;

int evaluateExpression(const string& expression) {
    stack<int> operands;
    stack<char> operators;

    for (size_t i = 0; i < expression.length(); ++i) {
        char c = expression[i];
        if (isdigit(c)) {
            int num = c - '0';
            while (i + 1 < expression.length() && isdigit(expression[i + 1]))
                num = num * 10 + (expression[++i] - '0');
            operands.push(num % MOD);
        } else if (c == '+') {
            // Ki?m tra xem có nhi?u hõn 1 d?u c?ng liên ti?p không
            if (i + 1 < expression.length() && expression[i + 1] == '+') {
                cout << "NOT_CORRECT" << endl;
                exit(0);
            }
            operators.push(c);
        } else {
            cout << "NOT_CORRECT" << endl;
            exit(0);
        }
    }

    int result = 0;
    while (!operands.empty() && !operators.empty()) {
        result = (result + operands.top()) % MOD;
        operands.pop();
        operators.pop();
    }

    if (!operands.empty()) {
        result = (result + operands.top()) % MOD;
        operands.pop();
    }

    // Ki?m tra xem d?u '+' có ? ð?u ho?c cu?i bi?u th?c không
    if (!operators.empty() || (expression.back() == '+')) {
        cout << "NOT_CORRECT" << endl;
        exit(0);
    }

    return result;
}

int main() {
    string expression;
    getline(cin, expression);

    int result = evaluateExpression(expression);
    cout << result << endl;

    return 0;
}

