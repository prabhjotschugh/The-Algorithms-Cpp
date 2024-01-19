#include <iostream>
#include <queue>

using namespace std;

class StackUsingQueues {
private:
    queue<int> q1, q2;

public:
    void push(int value) {
        q2.push(value);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    void pop() {
        if (!q1.empty()) {
            q1.pop();
        }
    }

    int top() {
        if (!q1.empty()) {
            return q1.front();
        }
        return -1; // Assuming stack is not empty
    }

    bool empty() {
        return q1.empty();
    }
};

int main() {
    StackUsingQueues stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    cout << "Top element: " << stack.top() << endl;

    stack.pop();
    cout << "Top element after pop: " << stack.top() << endl;

    return 0;
}
