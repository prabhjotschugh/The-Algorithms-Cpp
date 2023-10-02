#include <bits/stdc++.h>
using namespace std;
int distinctSubsequences(string s)
{
    int mod = 1e9 + 7;
    vector<int>dp(s.length()+1);
    dp[0]=1;
    unordered_map<char,int>mp;
    for(int i=1;i<dp.size();i++){
	dp[i]=(2*dp[i-1])%mod;
	char ch=s[i-1];
	if(mp.find(ch)!=mp.end()){
	    auto it=mp.find(ch);
	    int indx=it->second;
	    dp[i]=(dp[i]-dp[indx-1]+mod)%mod;
	}
	//dp[i] %= mod;
	mp[ch]=i;
    }
    return dp[s.size()];
}
int main()
{
  string s="abcbca";
  cout << distinctSubsequences(s);
  return 0;
}
