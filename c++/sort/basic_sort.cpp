//
// Created by Leo Chen on 2023/7/3.
//

#include <iostream>
#include <vector>

using namespace std;

void bubble_sort(vector<int> &arr) {
    for (int i = 0; i < arr.size(); i++) {
        int tmp{0};
        bool flag{true};
        for (int j = 1; j < arr.size(); j++) {
            if (arr[j - 1] > arr[j]) {
                tmp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = tmp;
                flag = false;
            }
        }
        if (flag)break;
    }
}

void insert_sort(vector<int> &arr) {
    // stationary
    // In-place
    for (int i = 1; i < arr.size(); i++) {
        int key{arr[i]};
        int j{i - 1};
        for (; j >= 0; j--) {
            if (key < arr[j]) {
                arr[j + 1] = arr[j];
            } else {
                break;
            }
        }
        arr[j + 1] = key;
    }
}

void selection_sort(vector<int> &arr) {
    for (int i = 0; i < arr.size(); i++) {
        int min_index{i};
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[min_index] > arr[j]) {
                min_index = j;
            }
        }

        int tmp{arr[min_index]};
        arr[min_index] = arr[i];
        arr[i] = tmp;
    }
}


int main() {
    vector<int> arr{2, 1, 4, 5, 3};
    insert_sort(arr);
    for (int x: arr) {
        cout << x << ' ';
    }
}
