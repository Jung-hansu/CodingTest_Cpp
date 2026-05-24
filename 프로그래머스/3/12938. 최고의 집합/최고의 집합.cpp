#include <vector>
using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    
    if (s >= n) {
        int cnt = 0, div = s / n;
        for (int left = s; cnt < n && left != (div + 1) * (n - cnt); left -= div) {
            answer.push_back(div);
            cnt++;
        }
        while (cnt < n) {
            answer.push_back(div + 1);
            cnt++;
        }
    } else {
        answer.push_back(-1);        
    }
    return answer;
}