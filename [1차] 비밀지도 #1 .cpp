#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector<int> ar1;
    vector<int> ar2;
    vector<string> ar3;
    int r = 1;
    for(int i=1; i<n; i++)
        r = r*2;
    for(int i=0; i<arr1.size(); i++){
        int x = arr1[i];
        int x2 = arr2[i];
        int y = 0;
        int y2 =0;
        int w = r;
        for(int j=0; j<n; j++)
        {
            y = x / w;
            y2 = x2 /w;
            x = x % w;
            x2 = x2 % w;
            ar1.push_back(y);
            ar2.push_back(y2);
            w = w/2;
        }
    }
    for(int i=0; i< ar1.size(); i++)
    {
        if(ar1[i]==1 || ar2[i]==1)
            ar3.push_back("#");
        else ar3.push_back(" ");
    }
    for(int i=0; i<ar3.size(); i+=n){
        string s ="";
        for(int j=0; j<n; j++)
            s += ar3[i+j];
        answer.push_back(s);
    }
    return answer;
}
