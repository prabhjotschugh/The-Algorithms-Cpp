#include<bits/stdc++.h>
using namespace std;
class bucket {
public:
    void dfs(int i, int j,vector<vector<int>>&image,int newColor,int*ti,int*tj){
        int oldclr=image[i][j];
        image[i][j]=newColor;
        for(int k=0;k<4;k++){
            int x=i+ti[k];
            int y=j+tj[k];
            if(x>=0&&y>=0&&x<image.size()&&y<image[0].size()&&image[x][y]==oldclr)
            dfs(x,y,image,newColor,ti,tj);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc]==newColor)return image;
        int ti[4]={-1,0,1,0};
        int tj[4]={0,1,0,-1};
        dfs(sr,sc,image,newColor,ti,tj);
        return image;
    }
};
int main(){
	vector<vector<int>>image={{1,1,1},{1,1,0},{1,0,1}};
	int new_clr=2,x=1,y=1; // (x,y) are coordinates.
	bucket b1;
	b1.floodFill(image,x,y,new_clr);
	//after flood-fill
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++)
			cout<<image[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}