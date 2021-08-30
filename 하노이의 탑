#include <string>
#include <vector>

using namespace std;

void rec(vector<vector<int>> &answer, int n, vector<int> target){
    if(n==1){
        answer.push_back(target);
        return;
    }
    
    int a;
    for(int i=1;i<=3;i++){
        if(i!=target[0] && i!=target[1])
            a=i;
    }
    
    rec(answer, n-1, {target[0], a});
    answer.push_back(target);
    rec(answer, n-1, {a, target[1]});
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    vector<int> target={1,3};
    
    rec(answer, n, target);
    
    return answer;
}
