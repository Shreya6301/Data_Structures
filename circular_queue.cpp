#include <iostream>
using namespace std;

class CircularQueue {
    int* arr;
    int currSize, capacity;
    int frontIndex, rear; // renamed 'front' to 'frontIndex'

public:
    CircularQueue(int size) {
        capacity = size;
        arr = new int[capacity];
        currSize = 0;
        frontIndex = 0;
        rear = -1;
    }

    ~CircularQueue() {
        delete[] arr;
    }

    void push(int data) {
        if (currSize == capacity) {
            cout << "Circular queue is full\n";
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = data;
        currSize++;
    }

    void pop() {
        if (empty()) {
            cout << "Circular queue is empty\n";
            return;
        }
        frontIndex = (frontIndex + 1) % capacity;
        currSize--;
    }

    int Front() { // renamed from 'front()'
        if (empty()) {
            cout << "Circular queue is empty\n";
            return -1;
        }
        return arr[frontIndex];
    }

    bool empty() {
        return currSize == 0;
    }

    void printArr() {
        if (empty()) {
            cout << "Circular queue is empty\n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = 0; i < currSize; i++) {
            int idx = (frontIndex + i) % capacity;
            cout << arr[idx] << " ";
        }
        cout << endl;
    }
};

int main() {
    CircularQueue cq(3);
    cq.push(1);
    cq.push(4);
    cq.push(8);
    cq.pop();
    cq.push(9);
    cq.printArr();

    while (!cq.empty()) { // FIXED: use !cq.empty()
        cout << cq.Front() << " ";
        cq.pop();
    }
    cout << endl;
    return 0;
}
