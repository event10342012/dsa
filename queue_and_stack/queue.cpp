//
// Created by Leo Chen on 2023/8/2.
//

#include <iostream>
#include <vector>

using namespace std;

class MyCircularQueue {
private:
    int head;
    int tail;
    int size;
    vector<int> data;
public:
    explicit MyCircularQueue(int k) : size(k) {
        head = -1;
        tail = -1;
        data.resize(k);
    }

    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }

        if (isEmpty()) {
            head = 0;
            tail = 0;
            data[tail] = value;
        } else {
            if (tail + 1 == size && head != 0) {
                tail = -1;
            }
            data[++tail] = value;
        }
        return true;
    }

    bool deQueue() {
        if (isEmpty()) {
            return false;
        }

        if (head == tail) {
            head = tail = -1;
            return true;
        }

        if (head + 1 == size) {
            head = -1;
        }
        head++;
        return true;
    }

    int Front() {
        if (isEmpty()) return -1;
        return data[head];
    }

    int Rear() {
        if (isEmpty()) return -1;
        return data[tail];
    }

    bool isEmpty() const {
        return head == -1 && tail == -1;
    }

    bool isFull() const {
        return (tail + 1 == size) && head == 0 || tail + 1 == head;
    }
};

int main() {
    MyCircularQueue myCircularQueue = *new MyCircularQueue(3);
    myCircularQueue.enQueue(1); // return True
    myCircularQueue.enQueue(2); // return True
    myCircularQueue.enQueue(3); // return True
    myCircularQueue.enQueue(4); // return False
    myCircularQueue.Rear();     // return 3
    myCircularQueue.isFull();   // return True
    myCircularQueue.deQueue();  // return True
    myCircularQueue.enQueue(4); // return True
    myCircularQueue.Rear();     // return 4
}
