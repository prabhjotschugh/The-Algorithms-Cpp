#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int trap(vector<int>& height) {
    int n = height.size(), waterTrapped = 0;
    stack<int> s;
    
    for (int i = 0; i < n; i++) {
        while (!s.empty() && height[i] > height[s.top()]) {
            int top = s.top();
            s.pop();
            if (s.empty()) break;
            int distance = i - s.top() - 1;
            int boundedHeight = min(height[i], height[s.top()]) - height[top];
            waterTrapped += distance * boundedHeight;
        }
        s.push(i);
    }
    return waterTrapped;
}

int main() {
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << trap(height) << endl;
    return 0;
}
