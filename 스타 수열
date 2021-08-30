#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> a) {
    int maxlen=0, len;
    unordered_map<int, int> m;
    unordered_map<int, bool> n;
    vector<int> tmp;
    
    for(int i=0;i<a.size();i++)
        m[a[i]]++;
    
    for(int i=0;i<a.size();i++){
        if(m[a[i]]>maxlen/2 && n[a[i]]==false){
            tmp.clear();
            int j=max(i-1,0);
            len=0;
            n[a[i]]=true;
            
            for(j;j<a.size();j++){
                if(tmp.empty())
                    tmp.push_back(a[j]);
                else{
                    if((tmp[0]==a[i] && a[j]!=a[i]) || (tmp[0]!=a[i] && a[j]==a[i])){
                        len+=2;
                        tmp.clear();
                    }
                }
            }
            maxlen=max(maxlen, len);
        }
    }
    
    return maxlen;
}
