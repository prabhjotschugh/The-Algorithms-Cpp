#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {
    stack<int> s;
    for (int asteroid : asteroids) {
        bool destroyed = false;
        while (!s.empty() && asteroid < 0 && s.top() > 0) {
            if (s.top() < -asteroid) {
                s.pop();
                continue;
            } else if (s.top() == -asteroid) {
                s.pop();
            }
            destroyed = true;
            break;
        }
        if (!destroyed) {
            s.push(asteroid);
        }
    }
    vector<int> result;
    while (!s.empty()) {
        result.push_back(s.top());
        s.pop();
    }
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    vector<int> asteroids = {5, 10, -5};
    vector<int> result = asteroidCollision(asteroids);
    for (int asteroid : result) {
        cout << asteroid << " ";
    }
    cout << endl;
    return 0;
}
