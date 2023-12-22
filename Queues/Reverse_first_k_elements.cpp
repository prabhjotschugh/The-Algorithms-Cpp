#include <iostream>
#include <queue>
#include <stack>

using namespace std;

void reverseFirstKElements(queue<int>& q, int k) {
    stack<int> s;
    for (int i = 0; i < k; ++i) {
        s.push(q.front());
        q.pop();
    }
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }
    for (int i = 0; i < q.size() - k; ++i) {
        q.push(q.front());
        q.pop();
    }
}

int main() {
    queue<int> q;
    for (int i = 1; i <= 5; ++i) {
        q.push(i);
    }
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    for (int i = 1; i <= 5; ++i) {
        q.push(i);
    }

    int k = 3;
    reverseFirstKElements(q, k);

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
