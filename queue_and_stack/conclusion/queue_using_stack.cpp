//
// Created by Leo Chen on 2023/12/10.
//

#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
private:
    stack<int> inStack;
    stack<int> outStack;

    void in2out(){
        while (!inStack.empty()){
            outStack.push(inStack.top());
            inStack.pop();
        }
    };


public:
    MyQueue() {
    }

    void push(int x) {
        inStack.push(x);
    }

    int pop() {
        if (!outStack.empty()){
            in2out();
        }
        int x = outStack.top();
        outStack.pop();
        return x;
    }

    int peek() {
        if (!outStack.empty()){
            in2out();
        }
        return outStack.top();
    }

    bool empty() {
        return inStack.empty() && outStack.empty();
    }
};


/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
