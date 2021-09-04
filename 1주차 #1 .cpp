using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = -1;
    long long tmp=0;
    for(int i=1; i<=count; i++)
    {
        tmp += (long long)i* price;
    }
    tmp = tmp - (long long)money;
    if(tmp <0){
        answer = 0;
    }
    else answer = tmp;
    return answer;
}
