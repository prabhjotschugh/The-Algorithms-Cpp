#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isValid(const string &s) {
    if (s.size() > 3 || s.empty() || (s[0] == '0' && s.size() > 1) || stoi(s) > 255) {
        return false;
    }
    return true;
}

void backtrack(const string &s, int start, int part, string current, vector<string> &result) {
    if (part == 4 && start == s.size()) {
        result.push_back(current);
        return;
    }
    if (part == 4 || start == s.size()) {
        return;
    }

    for (int len = 1; len <= 3 && start + len <= s.size(); ++len) {
        string segment = s.substr(start, len);
        if (isValid(segment)) {
            string newCurrent = current + segment + (part == 3 ? "" : ".");
            backtrack(s, start + len, part + 1, newCurrent, result);
        }
    }
}

vector<string> restoreIpAddresses(const string &s) {
    vector<string> result;
    if (s.size() > 12) {
        return result;
    }
    backtrack(s, 0, 0, "", result);
    return result;
}

int main() {
    string s;
    cout << "Enter the string: ";
    cin >> s;
    vector<string> ips = restoreIpAddresses(s);
    cout << "Valid IP addresses are:" << endl;
    for (const string &ip : ips) {
        cout << ip << endl;
    }
    return 0;
}
