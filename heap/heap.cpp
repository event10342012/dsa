//
// Created by Leo Chen on 2024/8/1.
//

#include <vector>
#include <iostream>

class MinHeap {
private:
    std::vector<int> min_heap;
    int heap_size;
    int real_size;
public:
    MinHeap(int size) {
        real_size = 0;
        heap_size = size;
        min_heap = std::vector<int>(size + 1);
        min_heap[0] = 0;
    };

    void add(int element) {
        real_size++;
        if (real_size > heap_size) {
            std::cout << "Added too many elements!" << std::endl;
            real_size--;
        }

        min_heap[real_size] = element;
        int parent = real_size / 2;
        int index = real_size;

        while (index > 1 && min_heap[parent] > min_heap[index]) {
            int tmp = min_heap[index];
            min_heap[index] = min_heap[parent];
            min_heap[parent] = tmp;
            index = parent;
            parent = index / 2;
        }
    }

    int peak() {
        return min_heap[1];
    }

    int pop() {
        if (real_size < 1) {
            return INT32_MAX;
        }

        int removed_element = min_heap[1];
        min_heap[1] = min_heap[real_size];
        real_size--;

        int index = 1;

        while (index <= real_size / 2) {
            int left = index * 2 ;
            int right = index * 2 + 1;
            if (min_heap[index] > min_heap[left] || min_heap[index] > min_heap[right]) {
                if (min_heap[left] > min_heap[right]) {
                    int tmp = min_heap[index];
                    min_heap[index] = min_heap[right];
                    min_heap[right] = tmp;
                    index = right;
                } else {
                    int tmp = min_heap[index];
                    min_heap[index] = min_heap[left];
                    min_heap[left] = tmp;
                    index = left;
                }
            } else {
                break;
            }
        }
        return removed_element;
    }
};