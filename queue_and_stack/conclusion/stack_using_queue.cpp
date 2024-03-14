//
// Created by Leo Chen on 2023/12/11.
//

#include <queue>

using namespace std;

class MyStack {
private:
    queue<int> main_queue, sub_queue;
    int curr_size;
public:
    MyStack() {
        curr_size = 0;
    }

    void push(int x) {
        curr_size++;
        sub_queue.push(x);

        while(!main_queue.empty()){
            sub_queue.push(main_queue.front());
            main_queue.pop();
        }

        queue<int> q = main_queue;
        main_queue = sub_queue;
        sub_queue = q;
    }

    int pop() {
        if (main_queue.empty()){
            return -1;
        }
        curr_size--;
        int x = main_queue.front();
        main_queue.pop();
        return x;
    }

    int top() {
        if(main_queue.empty()){
            return -1;
        }
        return main_queue.front();
    }

    bool empty() {
        return main_queue.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */