#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();        
        int m=heights[0].size();
        if(n==1&&m==1)return 0;
        int min_ef=0;
        int ti[]={-1,0,1,0};
        int tj[]={0,1,0,-1};
        int px=-1,py=-1;
        priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > pq;
        pq.push({0,{0,0}});
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        dist[0][0]=0;
        while(!pq.empty()){
            auto it=pq.top();pq.pop();
            int diff=it.first;
            int x=it.second.first;
            int y=it.second.second;            
            if(x==n-1&&y==m-1)return diff;
            for(int i=0;i<4;i++){
                int tx=x+ti[i];
                int ty=y+tj[i];
                if(tx>=0&&ty>=0&&tx<n&&ty<m){
                    int newdiff=max(abs(heights[x][y]-heights[tx][ty]),diff);
                    if(newdiff<dist[tx][ty]){
                        dist[tx][ty]=newdiff;
                        pq.push({newdiff,{tx,ty}});
                    }
                }
            }
        }
        return min_ef;
    }
};
int main()
{
    vector<vector<int>> heights = {{1, 2, 2}, {3, 8, 2}, {5, 3, 5}};
    Solution obj;
    int ans = obj.MinimumEffort(heights);
    cout << ans;
    cout << endl;
    return 0;
}
