#include <bits/stdc++.h>
using namespace std;

int dp[1000] = {0};

int fact(int n) {
   if (n >= 0) {
      dp[0] = 1;
      for (int i = 1; i <= n; ++i) {
         dp[i] = i * dp[i - 1];
      }
      return dp[n];
   }
   return 0;
}

int main() {
   int n;
   cin>>n;
   if(n==0) cout<<"0"<<endl;
   else cout<<fact(n)<<endl;
   return 0;
}