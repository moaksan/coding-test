#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> a(n, 1);
    for(int i=0; i<lost.size(); i++){
        a[lost[i] -1] -=1;
    }
    for(int i=0; i<reserve.size(); i++){
        a[reserve[i] -1] +=1;
    }
    for(int i=0; i<n; i++){
        if(a[i]==0){
            if(i ==0){
                if(a[i+1] ==2){
                    a[i]=1;
                    a[i+1]=1;
                }
            }
            else {
                if(a[i-1]==2){
                    a[i]=1;
                    a[i-1]=1;
                }
                else if(a[i+1] ==2){
                    a[i]=1;
                    a[i+1]=1;
                }
            }
        }
    }
    for(int i=0; i<n; i++){
        if(a[i]==1 || a[i] ==2)
            answer++;
    }
    return answer;
}
