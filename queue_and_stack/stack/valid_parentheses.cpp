//
// Created by Leo Chen on 2023/10/7.
//


#include <string>
#include <map>
#include <stack>

using namespace std;


class ValidParentheses {
public:
    bool isValid(string s) {
        map<char, char> parentheses;
        parentheses['}'] = '{';
        parentheses[')'] = '(';
        parentheses[']'] = '[';

        stack<char> stack;

        for (char c: s) {
            if(stack.empty()){
                stack.push(c);
            }else if (stack.top() == parentheses[c]){
                stack.pop();
            }else{
                stack.push(c);
            }
        }
        return stack.empty();
    }
};

