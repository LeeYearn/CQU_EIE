#include <iostream>
#include <cstring>
#include <stack>
#include <cmath>

std::stack<int> num;     // 操作数
std::stack<char> sig;    // 操作符

int infix_level(char a) {
    if (a == '^') return 3;
    if (a == '*' || a == '/') return 2;
    if (a == '+' || a == '-') return 1;
    return 0;   // 括号
}

void infix_calc() {
    int b = num.top(); num.pop();
    int a(left_parenthesis_count)
    {
        left_parenthesis_count--;
        s+=")";
    }

    for(auto c: s)
    if(c>='0' && c<='9'){
        x = x*10 + c-'0';
        flg=1;
    }else{
        if(flg){
            num.push(x);
            x=0;
            flg=0;
        }   // 数字入栈
        if(c=='('){
            sig.push(c);
            continue;
        }   // 左括号入栈
        if(c==')'){
            while(sig.top()!='(') 
                infix_calc();
            sig.pop();
            continue;
        }   // 右括号, 一直计算到左括号
        
        // 此时c是运算符, 且有运算级更低的, 形如 (a*b+)
        while(sig.size() && infix_level(sig.top()) >= infix_level(c)) 
            infix_calc();
        sig.push(c);
    }
    // 最后一个数字
    if(flg) num.push(x);
    // 最后一个运算符
    while(sig.size()) infix_calc(); 
    return std::to_string(num.top());
} = num.top(); num.pop(); 
    if (sig.top() == '+') num.push(a + b); 
    if (sig.top() == '-') num.push(a - b); 
    if (sig.top() == '*') num.push(a * b); 
    if (sig.top() == '/') num.push(a / b); 
    if (sig.top() == '^') num.push(pow(a, b)); 
    sig.pop();
}

std::string infix(std::string s) {
    int x = 0;    // 临时存储数字
    bool flg = false; // 是否是数字
    int left_parenthesis_count = 0; // 记录左括号的数量

    // 第一次扫描，计算左括号和右括号的数量
    for (char c : s) {
        if (c == '(') {
            left_parenthesis_count++;
        } else if (c == ')') {
            left_parenthesis_count--;
        }
    }

    // 如果还有左括号，补充右括号并结束计算
    while(left_parenthesis_count)
    {
        left_parenthesis_count--;
        s+=")";
    }

    for(auto c: s)
    if(c>='0' && c<='9'){
        x = x*10 + c-'0';
        flg=1;
    }else{
        if(flg){
            num.push(x);
            x=0;
            flg=0;
        }   // 数字入栈
        if(c=='('){
            sig.push(c);
            continue;
        }   // 左括号入栈
        if(c==')'){
            while(sig.top()!='(') 
                infix_calc();
            sig.pop();
            continue;
        }   // 右括号, 一直计算到左括号
        
        // 此时c是运算符, 且有运算级更低的, 形如 (a*b+)
        while(sig.size() && infix_level(sig.top()) >= infix_level(c)) 
            infix_calc();
        sig.push(c);
    }
    // 最后一个数字
    if(flg) num.push(x);
    // 最后一个运算符
    while(sig.size()) infix_calc(); 
    return std::to_string(num.top());
}

int main() {
    std::string s;
    std::cin >> s;
    std::cout << infix(s);
}