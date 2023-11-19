#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    // Creating a min-heap
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Inserting elements into the heap
    minHeap.push(3);
    minHeap.push(1);
    minHeap.push(4);
    minHeap.push(1);
    minHeap.push(5);

    // Accessing the top element (minimum in this case)
    cout << "Top element: " << minHeap.top() << endl;

    // Removing the top element
    minHeap.pop();

    // Accessing the new top element
    cout << "Top element after pop: " << minHeap.top() << endl;

    return 0;
}
