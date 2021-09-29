#include <bits/stdc++.h>

using namespace std;

bool v[10000]={false};
vector<string> res;

bool dfs(string start, vector<vector<string>> tickets, int cnt){
    if(cnt==tickets.size())
        return true;
    
    for(int i=0;i<tickets.size();i++){
        if(v[i]==false && start==tickets[i][0]){
            v[i]=1;
            res.push_back(tickets[i][1]);
            bool a=dfs(tickets[i][1], tickets, cnt+1);
            if(a)
                return true;
            v[i]=0;
            res.pop_back();
        }
    }
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    
    sort(tickets.begin(), tickets.end());
    
    string start="ICN";
    res.push_back(start);
    
    dfs(start, tickets, 0);
    
    answer=res;
    return answer;
}
