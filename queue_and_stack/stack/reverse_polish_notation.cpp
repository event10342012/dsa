//
// Created by Leo Chen on 2023/10/8.
//

#include <string>
#include <vector>
#include <stack>
#include <set>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> stack;
        set<string> operators{"+", "-", "*", "/"};

        for (string s: tokens) {
            if (operators.find(s) == operators.end()) {
                stack.push(stoi(s));
            } else {
                int b = stack.top();
                stack.pop();
                int a = stack.top();
                stack.pop();

                int sum{0};
                if (s == "+"){
                    sum = a + b;
                }else if (s == "-"){
                    sum = a - b;
                }else if (s == "*"){
                    sum = a * b;
                }else if(s == "/"){
                    sum = a / b;
                }
                stack.push(sum);
            }
        }
        return stack.top();
    }
};