#include <bits/stdc++.h>

using namespace std;

int parent[10000];

int findParent(int x){
    if(x==parent[x]) return x;
    else return parent[x] = findParent(parent[x]);
}

void unionParent(int a, int b){
    a=findParent(a);
    b=findParent(b);
    if(a<b) parent[b]=a;
    else parent[a]=b;
}

bool cmp(vector<int>& a, vector<int>& b){
    return a[2]<b[2];
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    sort(costs.begin(), costs.end(), cmp);
    for(int i=0;i<n;i++)
        parent[i]=i;
    
    for(int i=0;i<costs.size();i++){
        int cost=costs[i][2]; 
        int a=costs[i][0];
        int b=costs[i][1];
        
        if(findParent(a)!=findParent(b)){
            unionParent(a,b);
            answer+=cost;
        }
    }
    
    
    return answer;
}
