#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> ans1 = {1,2,3,4,5};
    vector<int> ans2 = {2,1,2,3,2,4,2,5};
    vector<int> ans3 = {3,3,1,1,2,2,4,4,5,5};
    int sco1 = 0;
    int sco2 = 0;
    int sco3 = 0;
    for(int i=0; i<answers.size();i++){
        if(answers[i] == ans1[i % 5])
            sco1++;
        if(answers[i] == ans2[i%8])
            sco2++;
        if(answers[i] == ans3[i %10])
            sco3++;
    }
    int m = max(sco1, sco2);
    m = max(m,sco3);
    if(m == sco1)
        answer.push_back(1);
    if(m==sco2)
        answer.push_back(2);
    if(m==sco3)
        answer.push_back(3);
    return answer;
}
