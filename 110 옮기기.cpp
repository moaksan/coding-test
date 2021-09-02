#include <bits/stdc++.h>
using namespace std;

vector<string> solution(vector<string> s) {
    vector<string> answer;

    for(auto &k : s){
        string tmp = ""; int cnt = 0;
        for(int i=0 ; i<k.size() ; i++){
            tmp += k[i];
            if((int)tmp.size() >= 3 && tmp.substr((int)tmp.size() - 3) == "110") { cnt++; tmp.erase((int)tmp.size() - 3, 3); }
        }
        string t = ""; while(cnt--) t += "110";
        int idx; bool ok = false;
        for(int i=(int)tmp.size()-1 ; i>=0 ; i--) if(tmp[i] == '0') { idx = i; ok = true; break; }

        if(!ok) answer.push_back(t + tmp);
        else answer.push_back(tmp.substr(0, idx + 1) + t + tmp.substr(idx + 1));
    }

    return answer;
}
