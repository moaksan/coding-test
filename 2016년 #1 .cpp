#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    int month[] = {31,29,31,30,31,30,31,31,30,31,30,31};
    vector<string> day = {"THU","FRI","SAT","SUN","MON","TUE","WED"};
    int date = 0;
    for(int i=0; i<a-1;i++){
        date += month[i];
    }
    date += b;
    answer = day[date % 7];
    return answer;
}
