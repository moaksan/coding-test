#include <bits/stdc++.h>

using namespace std;

int stoi_time(string a){
    int h=stoi(a.substr(0,2))*3600;
    int m=stoi(a.substr(3,2))*60;
    int s=stoi(a.substr(6,2));
    
    return h+m+s;
}

string itos_time(int a){
    string res="";
    int h=a/3600;
    int m=(a%3600)/60;
    int s=a%60;
    
    if(h<10) res+="0";
    res+=to_string(h)+":";
    if(m<10) res+="0";
    res+=to_string(m)+":";
    if(s<10) res+="0";
    res+=to_string(s);
    
    return res;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    int ad[360001]={0};
    
    for(int i=0;i<logs.size();i++){
        int s=stoi_time(logs[i].substr(0,8));
        int e=stoi_time(logs[i].substr(9,8));
        for(int j=s;j<e;j++){
            ad[j]++;
        } 
    }
    
    int idx=0;
    long long sum=0; long long maxsum=0;
    int n=stoi_time(play_time);
    int len=stoi_time(adv_time);
    for(int i=0;i<len;i++)
        sum+=ad[i];
    maxsum=sum;
    
    for(int i=len;i<n;i++){
        sum-=ad[i-len];
        sum+=ad[i];
        if(sum>maxsum){
            maxsum=sum;
            idx=i-len+1;
        }
    }
    
    answer=itos_time(idx);
    
    return answer;
}
