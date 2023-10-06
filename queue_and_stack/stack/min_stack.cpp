//
// Created by Leo Chen on 2023/10/6.
//

#include <vector>
#include <stack>

using namespace std;


class MinStack {
private:
    vector<int> data;
    stack<int> min_stack;
public:
    void push(int val) {
        if (data.size() == 0) {
            min_stack.push(val);
        } else if (val <= min_stack.top()) {
            min_stack.push(val);
        }
        data.push_back(val);
    }

    void pop() {
        if (this->top() == min_stack.top()) {
            min_stack.pop();
        }
        data.pop_back();
    }

    int top() {
        return data.back();
    }

    int getMin() {
        return min_stack.top();
    }
};


int main() {
    MinStack *obj = new MinStack();
    obj->push(0);
    obj->push(1);
    obj->push(0);
    obj->getMin();
    obj->pop();
    obj->getMin();
}
