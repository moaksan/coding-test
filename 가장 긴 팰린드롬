#include <iostream>
#include <string>
using namespace std;
int solution(string s)
{
    int answer=0;
    int maxlen1=0, maxlen2=0;
    
    for(int i=0;i<s.size()-1;i++){
        int j=0;
        while(s[i-j]==s[i+1+j] && i-j>=0 && i+1+j<s.size()){
            j++;
        }
        maxlen2=max(2*j, maxlen2);
    }
    
    for(int i=0;i<s.size();i++){
        int j=1;
        while(s[i-j]==s[i+j] && i-j>=0 && i+j<s.size()){
            j++;
        }
        maxlen1=max(2*(j-1)+1, maxlen1);
    }
    
    return max(maxlen1, maxlen2);
}
