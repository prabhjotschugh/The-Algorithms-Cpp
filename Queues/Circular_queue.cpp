#include <iostream>
using namespace std;

class CircularQueue {
private:
    int front, rear, maxSize;
    int *arr;

public:
    CircularQueue(int size) {
        maxSize = size + 1;
        arr = new int[maxSize];
        front = rear = 0;
    }

    ~CircularQueue() {
        delete[] arr;
    }

    bool isEmpty() {
        return front == rear;
    }

    bool isFull() {
        return (rear + 1) % maxSize == front;
    }

    void enqueue(int item) {
        if (!isFull()) {
            rear = (rear + 1) % maxSize;
            arr[rear] = item;
        } else {
            cout << "Queue is full. Cannot enqueue." << endl;
        }
    }

    void dequeue() {
        if (!isEmpty()) {
            front = (front + 1) % maxSize;
        } else {
            cout << "Queue is empty. Cannot dequeue." << endl;
        }
    }

    void display() {
        int i = (front + 1) % maxSize;
        cout << "Queue: ";
        while (i != (rear + 1) % maxSize) {
            cout << arr[i] << " ";
            i = (i + 1) % maxSize;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue cq(5);

    cq.enqueue(1);
    cq.enqueue(2);
    cq.enqueue(3);
    cq.display();

    cq.dequeue();
    cq.display();

    cq.enqueue(4);
    cq.enqueue(5);
    cq.display();

    cq.enqueue(6);
    cq.dequeue();
    cq.dequeue();
    cq.dequeue();
    cq.dequeue();
    cq.display();

    return 0;
}
￼Enter
