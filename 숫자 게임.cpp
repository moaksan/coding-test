#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    
    sort(A.begin(), A.end(), greater<>());
    sort(B.begin(), B.end(), greater<>());
    
    int it=0;
    for(int i=0;i<A.size();i++){
        if(A[i]<B[it]){
            answer++; 
            it++;
        }
    }
    return answer;
}
