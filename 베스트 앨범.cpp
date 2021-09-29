#include <bits/stdc++.h>

using namespace std;



bool cmp(tuple<int, string, int> a, tuple<int, string, int> b){
    if(genre_play[get<1>(a)]>genre_play[get<1>(b)])
        return true;
    else if(genre_play[get<1>(a)]==genre_play[get<1>(b)]){
        if(get<2>(a)>get<2>(b))
            return true;
        else
            return false;
    }
    else
        return false;
}
unordered_map<string, int> genre_play;
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    int cnt=0;
    string tmp="";
    vector<tuple<int, string, int>> a;
    
    for(int i=0;i<genres.size();i++){
        genre_play[genres[i]]+=plays[i];
        a.push_back({i, genres[i], plays[i]});
    }
    
    sort(a.begin(), a.end(), cmp);
    
    for(int i=0;i<genres.size();i++){
        if(tmp!=get<1>(a[i]))
            cnt=0;
        if(cnt>=2)
            continue;
        
        cnt++;
        tmp=get<1>(a[i]);
        
        answer.push_back(get<0>(a[i]));
    }
    
    return answer;
}
