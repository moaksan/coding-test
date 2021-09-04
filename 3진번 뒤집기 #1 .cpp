#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> three;
    int j=0;
    int i=1;
    while(n!=0){
        j = n % 3;
        n = n /3;
        three.push_back(j);
        i = i*3;
    }
    for(int w=0; w<three.size(); w++){
        i = i/3;
        answer += three[w] * i;
    }
    return answer;
}
