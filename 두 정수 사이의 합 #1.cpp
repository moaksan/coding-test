#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    int c = min(a,b);
    int d = max(a,b);
    
    for(int i=c; i<=d; i++){
        answer += (long long)i;
    }
    return answer;
}
