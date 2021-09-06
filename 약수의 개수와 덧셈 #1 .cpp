#include <bits/stdc++.h>

using namespace std;

int yak(int num){
    int n=0;
    for(int i=1; i<= num; i++){
        if(num % i == 0)
            n++;
    }
    return n;
}

int solution(int left, int right) {
    int answer = 0;
    int num =0;
    for(int i= left; i<=right; i++){
        if(yak(i)%2 ==0) answer += i;
        else answer -= i;
    }
    return answer;
}
