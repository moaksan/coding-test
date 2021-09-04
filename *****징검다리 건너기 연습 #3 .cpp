#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 0;
    vector<long long> a;
    for(int i=0; i<stones.size()-k +1; i++){
        long long w = *max_element(stones.begin() +i, stones.begin() + i +k );
        a.push_back(w);
    }
    sort(a.begin(), a.end());
    answer = (int)a[0];
    return answer;
}

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 0;
    long long m = 200000000;
    for(int i=0; i<stones.size()-k +1; i++){
        long long w = *max_element(stones.begin() +i, stones.begin() + i +k );
        m = min(w,m);
    }
    answer = (int)m;
    return answer;
}
