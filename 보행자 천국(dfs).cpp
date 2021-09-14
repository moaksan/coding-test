#include <bits/stdc++.h>

using namespace std;

int MOD = 20170805;
int rec[500][500][2];

int dfs(int x, int y, vector<vector<int>> city_map, bool direction){
    int sum=0;
    if(x<0 || x>=city_map[0].size() || y<0 || y>=city_map.size())
        return 0;
    if(x==city_map[0].size()-1 && y==city_map.size()-1)
        return 1;
    if(rec[y][x][direction]!=0)
        return rec[y][x][direction];
    
    if(city_map[y][x]==0){
        sum+=dfs(x+1, y, city_map, false);
        sum+=dfs(x, y+1, city_map, true);
    }
    if(city_map[y][x]==1)
        return 0;
    if(city_map[y][x]==2){
        if(direction==false)
            sum+=dfs(x+1, y, city_map, false);
        else
            sum+=dfs(x, y+1, city_map, true);
    }
    rec[y][x][direction]=sum;
    
    return sum;
}

int solution(int m, int n, vector<vector<int>> city_map) {
    int answer = 0;
    int x=0, y=0;
    bool direction=false;
    
    answer=dfs(x, y, city_map, direction)%MOD;
    
    return answer;
}
