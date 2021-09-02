#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int a;
    
    a=(stations[0]-w-1);
    if(a>0)
        answer+=(a-1)/(2*w+1)+1;
    
    for(int i=0;i<stations.size()-1;i++){
        a=(stations[i+1]-stations[i])-2*w-1;
        if(a<=0) continue;
        else{
            answer+=(a-1)/(2*w+1)+1;
        }
    }
    a=(n-stations[stations.size()-1]-w);
    if(a>0)
        answer+=(a-1)/(2*w+1)+1;
    
    return answer;
}
