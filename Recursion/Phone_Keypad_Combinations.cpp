#include <bits/stdc++.h>
using namespace std;

void solve(string digits, string output, int index, vector<string> &mapping, vector<string> &ans) {
    // Base case: if we processed all digits
    if (index >= digits.length()) {
        ans.push_back(output);
        return;
    }

    int number = digits[index] - '0';
    string value = mapping[number];

    // Explore all possible letters for current digit
    for (int i = 0; i < value.length(); i++) {
        output.push_back(value[i]);
        solve(digits, output, index + 1, mapping, ans);
        output.pop_back(); // backtrack
    }
}

vector<string> letterCombinations(string digits) {
    vector<string> ans;
    if (digits.length() == 0) return ans;

    vector<string> mapping(10);
    mapping[2] = "abc";
    mapping[3] = "def";
    mapping[4] = "ghi";
    mapping[5] = "jkl";
    mapping[6] = "mno";
    mapping[7] = "pqrs";
    mapping[8] = "tuv";
    mapping[9] = "wxyz";

    string output = "";
    solve(digits, output, 0, mapping, ans);
    return ans;
}

int main() {
    string digits;
    cout << "Enter digits (2-9): ";
    cin >> digits;

    vector<string> combinations = letterCombinations(digits);

    cout << "\nPossible letter combinations:\n";
    for (auto s : combinations)
        cout << s << " ";
    cout << endl;

    return 0;
}
