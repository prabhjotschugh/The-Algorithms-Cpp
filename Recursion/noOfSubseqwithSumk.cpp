#include<bits/stdc++.h>
using namespace std;

int subseq(int i,int n,vector<int>&arr,int curr_sum, int k){
    if(i>=n){
        if(curr_sum==k){
            return 1;
        }
        return 0;
    }
    curr_sum+=arr[i];
    int l = (subseq(i+1,n,arr,curr_sum,k));
    curr_sum -= arr[i];
    int r = (subseq(i+1,n,arr,curr_sum,k));
    
    return l+r;
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int>vec(n);
    for(int i=0; i<n; ++i)
        cin>>vec[i];
    cout<<subseq(0,n,vec,0,k);
}
