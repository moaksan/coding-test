#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a, vector<int> b) {
    int answer = 1234567890;
    int c,d, e=0;
    for(int i=0; i<a.size(); i++){
        c = a[i];
        d = b[i];
        e += c*d;
    }
    answer = e;
    return answer;
}
