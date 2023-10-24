/*
402. Remove K Digits
Difficulty: Medium
Link: https://leetcode.com/problems/remove-k-digits/description/

Given string num representing a non-negative integer num, and an integer k,
return the smallest possible integer after removing k digits from num.

Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.

Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain 
leading zeroes.

Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.

*/

#include<bits/stdc++.h>
using namespace std;

string removeKdigits(string num, int k) {
	// Remove first k characters which start decreasing order
    deque<char> q;
    int rem = k;
    for(auto c: num) {
        while(q.size() and rem and q.back() > c) q.pop_back(), rem--;
        q.push_back(c); 
    }
    // If k characters not removed and double ended queue still contain digits
    while(rem and q.size()) {
        q.pop_back();
        rem--;
    }
    // Store final number
    string final;
    while(q.size()) {
        if(!(final.empty() and q.front() == '0')) final.push_back(q.front());
        q.pop_front();
    }
    // If final empty, put final as 0
    if(final == "") final = "0";
    return final;
}

int main() {
	string s;
	cout<<"Enter Number: ";
	cin>>s;
	int k;
	cout<<"Enter K: ";
	cin>>k;

	cout<<"Smallest Number after removing K Digits: "<<removeKdigits(s, k)<<"\n";
	return 0;
}

/*
How To Run
1. Run: g++ Remove-K-Digits.cpp -o remove-k
2. Run: ./remove-k
*/