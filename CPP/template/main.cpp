#include <iostream>
#include <stack>
#include <cmath>
#include <string>
#include <cctype>
using namespace std;

stack<int> num;     // 操作数
stack<char> sig;    // 操作符

int infix_level(char a){
    if(a == '^') return 3;
    if(a == '*' || a == '/') return 2;
    if(a == '+' || a == '-') return 1;
    return 0;   // 括号
}

void infix_calc(){
    if(num.size() < 2) {
        cerr << "Error: Not enough operands" << endl;
        exit(1);
    }
    int b = num.top(); num.pop();
    int a = num.top(); num.pop(); 
    char op = sig.top(); sig.pop();
    switch(op) {
        case '+': num.push(a + b); break;
        case '-': num.push(a - b); break;
        case '*': num.push(a * b); break;
        case '/': 
            if(b == 0) {
                cerr << "Error: Division by zero" << endl;
                exit(1);
            }
            num.push(a / b); break;
        case '^': num.push(pow(a, b)); break;
    }
}

string infix(string s){
    int x = 0;    // 临时存储数字
    bool flg = false; // 是否是数字
    bool isNegative = false; // 是否是负数

    for(auto c : s) {
        if(isdigit(c)) { // 处理数字
            x = x * 10 + (c - '0');
            flg = true;
        } else if(c == '-' && !flg && (sig.empty() || sig.top() == '(' || sig.top() == ')')) { // 处理负数
            isNegative = true;
        } else {
            if(flg && !isNegative) {
                num.push(x);
                x = 0;
            } else if(flg && isNegative) {
                num.push(-x);
                x = 0;
                isNegative = false;
            }
            flg = false;
            if(c == '(') {
                sig.push(c);
            } else if(c == ')') {
                while(!sig.empty() && sig.top() != '(') {
                    infix_calc();
                }
                if(!sig.empty()) sig.pop(); // 弹出左括号
            } else {
                while(!sig.empty() && infix_level(sig.top()) >= infix_level(c) && sig.top() != '(') {
                    infix_calc();
                }
                sig.push(c);
            }
        }
    }
    if(flg && !isNegative) num.push(x); // 最后一个数字
    while(!sig.empty()) infix_calc(); // 处理剩余的运算符
    if(num.empty()) {
        cerr << "Error: No result" << endl;
        exit(1);
    }
    return to_string(num.top());
}

int main(){
    string s;
    getline(cin, s); // 使用getline以支持空格
    cout << infix(s) << endl;
}