#include <bits/stdc++.h>

using namespace std;

int solution(string word, vector<string> pages) {
    int answer = 0;
    string address[20];
    int basic[20]={0};
    int linknum[20]={0};
    unordered_map<string, vector<int>> map;
        
    for(int i=0;i<pages.size();i++){
        int n=pages[i].find("<meta");
        int m=pages[i].find("content", n);
        int l1=pages[i].find("\"", m);
        int l2=pages[i].find("\"", l1+1);
        string tmp=pages[i].substr(l1+1, l2-l1-1);
        address[i]=tmp;
        
        int body=pages[i].find("<body", l2);
        
        for(int k=0;k<pages[i].size();k++){
            if(pages[i][k]>='A' && pages[i][k]<='Z'){
                pages[i][k]+='a'-'A';
            }
        }
        for(int k=0;k<word.size();k++)
            word[k]=tolower(word[k]);
        
        ssize_t found;
        int j=0;
        while((found=pages[i].find(word, j)) != string::npos){
            if(!isalpha(pages[i][found-1]) && !isalpha(pages[i][found+word.size()])){
                basic[i]++;
            }
            j=found+word.size();
        }
        
        j=0;
        while((found=pages[i].find("<a href", j)) != string::npos){
            int l1=pages[i].find("\"", found);
            int l2=pages[i].find("\"", l1+1);
            string tmp=pages[i].substr(l1+1, l2-l1-1);
            map[tmp].push_back(i); 
            linknum[i]++;
            j=l2;
        }
    }
    
    float maxmatpoint=-1;
    for(int i=0;i<pages.size();i++){
        float linkpoint=0; 
        
        for(int j=0;j<map[address[i]].size();j++){
            int tmp=map[address[i]][j];
            linkpoint+=(float)basic[tmp]/(float)linknum[tmp];
        }
        float matpoint=basic[i]+linkpoint;
        
        if(matpoint>maxmatpoint){
            maxmatpoint=matpoint;
            answer=i;
        }
    }
    
    
    return answer;
}
