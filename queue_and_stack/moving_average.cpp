//
// Created by Leo Chen on 2023/8/7.
//
#include <queue>

using namespace std;

class MovingAverage {
private:
    queue<int> q;
    int size;
    double average;
public:
    explicit MovingAverage(int size) : size(size), average(0) {
    }

    double next(int val) {
        int cur = 0;
        double total = average * q.size();
        if (q.size() >= size) {
            cur = q.front();
            q.pop();
        }
        q.push(val);
        average = (total - cur + val) / q.size();
        return average;
    }
};

int main(){
    MovingAverage *movingAverage = new MovingAverage(3);
    movingAverage->next(1); // return 1.0 = 1 / 1
    movingAverage->next(10); // return 5.5 = (1 + 10) / 2
    movingAverage->next(3); // return 4.66667 = (1 + 10 + 3) / 3
    movingAverage->next(5); // return 6.0 = (10 + 3 + 5) / 3
}