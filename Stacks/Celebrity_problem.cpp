#include <iostream>
#include <stack>
#include <vector>

using namespace std;

bool knows(int a, int b, vector<vector<int>>& matrix) {
    return matrix[a][b] == 1;
}

int findCelebrity(int n, vector<vector<int>>& matrix) {
    stack<int> s;

    for (int i = 0; i < n; i++) {
        s.push(i);
    }

    while (s.size() > 1) {
        int a = s.top(); s.pop();
        int b = s.top(); s.pop();

        if (knows(a, b, matrix)) {
            s.push(b);
        } else {
            s.push(a);
        }
    }

    int candidate = s.top();
    s.pop();

    for (int i = 0; i < n; i++) {
        if (i != candidate) {
            if (knows(candidate, i, matrix) || !knows(i, candidate, matrix)) {
                return -1;
            }
        }
    }

    return candidate;
}

int main() {
    vector<vector<int>> matrix = {
        {0, 1, 0},
        {0, 0, 0},
        {0, 1, 0}
    };

    int n = matrix.size();

    int celebrity = findCelebrity(n, matrix);

    if (celebrity == -1) {
        cout << "No celebrity found!" << endl;
    } else {
        cout << "Celebrity is person " << celebrity << endl;
    }

    return 0;
}
