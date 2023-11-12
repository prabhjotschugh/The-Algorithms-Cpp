#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int largestRectangleArea(vector<int>& heights) {
    stack<int> s;
    int maxArea = 0;

    for (int i = 0; i <= heights.size(); ++i) {
        while (!s.empty() && (i == heights.size() || heights[i] < heights[s.top()])) {
            int h = heights[s.top()];
            s.pop();
            int w = s.empty() ? i : i - s.top() - 1;
            maxArea = max(maxArea, h * w);
        }
        s.push(i);
    }

    return maxArea;
}

int main() {
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    int result = largestRectangleArea(heights);

    cout << "Maximum area of the histogram: " << result << endl;

    return 0;
}
￼Enter
