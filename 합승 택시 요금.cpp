#include <bits/stdc++.h>
#define INF 1e9

using namespace std;

vector<pair<int, int>> graph[201];
bool visited[201];
int d[201];

int getSmallestNode(int n){
    int mi=INF;
    int index;
    for(int i=1;i<=n;i++){
        if(mi>d[i] && !visited[i]){
            mi=d[i];
            index=i;
        }
    }
    return index;
}

void dijkstra(int start, int n){
    for(int i=0;i<=200;i++){
        visited[i]=false;
        d[i]=INF;
    }
    
    d[start]=0;
    visited[start]=true;
    
    for(int i=0;i<graph[start].size();i++){
        d[graph[start][i].first]=graph[start][i].second;
    }
    
    for(int i=0;i<n-1;i++){
        int now=getSmallestNode(n);
        visited[now]=true;
        
        for(int j=0;j<graph[now].size();j++){
            int cost=d[now]+graph[now][j].second;
            
            if(cost<d[graph[now][j].first])
                d[graph[now][j].first]=cost;
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;
    int start;
    int total_cost;
    
    //다익스트라
    /* 
    for(int i=0;i<fares.size();i++){
        graph[fares[i][0]].push_back({fares[i][1], fares[i][2]});
        graph[fares[i][1]].push_back({fares[i][0], fares[i][2]});
    }
    
    for(int i=1;i<=n;i++){
        start=i;
        dijkstra(start, n);
        if(d[s]==INF || d[a]==INF || d[b]==INF)
            continue;
        total_cost=d[s]+d[a]+d[b];
        cout<<total_cost<<" ";
        if(total_cost<answer)
            answer=total_cost;
    }
    */
    
    //플루이드 워셜
    int graph_f[201][201];
    
    for(int i=0;i<=200;i++){
        for(int j=0;j<=200;j++){
            graph_f[i][j]=INF;
            if(i==j)
                graph_f[i][j]=0;
        }
    }
    
    for(int i=0;i<fares.size();i++){
        graph_f[fares[i][0]][fares[i][1]]=fares[i][2];
        graph_f[fares[i][1]][fares[i][0]]=fares[i][2];
    }
    
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                graph_f[i][j]=min(graph_f[i][j], graph_f[i][k]+graph_f[k][j]);
            }
        }
    }
    
    for(int i=1;i<=n;i++){
        if(graph_f[i][s]==INF || graph_f[i][a]==INF || graph_f[i][b]==INF)
            continue;
        
        answer = min(answer, graph_f[i][s]+graph_f[i][a]+graph_f[i][b]);
    }
    
    return answer;
}
