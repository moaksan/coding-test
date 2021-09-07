#include <bits/stdc++.h>

using namespace std;

bool check(vector<vector<vector<int>>>& bp){
    for(int x=0;x<bp.size();x++){
        for(int y=0;y<bp.size();y++){
            if(bp[x][y][0]==1){
                if(!(y==0 || bp[x][y][1] || (bp[x-1][y][1] && x-1>=0) || (bp[x][y-1][0] && y-1>=0))){
                    return false;
                }
            }
            if(bp[x][y][1]==1){
                if(!((bp[x][y-1][0] && y-1>=0)|| (bp[x+1][y-1][0] && x+1<bp.size() && y-1>=0)|| ((bp[x-1][y][1] && x-1>=0) && (bp[x+1][y][1] && x+1<bp.size())))){
                    return false;
                }
            }
        }
    }
    return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame){
    vector<vector<int>> answer;
    vector<vector<vector<int>>> bp(n+1, vector<vector<int>>(n+1, vector<int>(2,0)));
    
    for(int i=0;i<build_frame.size();i++){
        int x=build_frame[i][0];
        int y=build_frame[i][1];
        int cate=build_frame[i][2];
        
        if(build_frame[i][3]==1){
            bp[x][y][cate]=1;
            if(!check(bp))
                bp[x][y][cate]=0;
        }
        if(build_frame[i][3]==0){
            bp[x][y][cate]=0;
            if(!check(bp))
                bp[x][y][cate]=1;
        }
    }
    
    for(int i=0;i<bp.size();i++){
        for(int j=0;j<bp[0].size();j++){
            if(bp[i][j][0]==1)
                answer.push_back({i, j, 0});
            if(bp[i][j][1]==1)
                answer.push_back({i, j, 1});
        }
    }
    
    
    return answer;
}
