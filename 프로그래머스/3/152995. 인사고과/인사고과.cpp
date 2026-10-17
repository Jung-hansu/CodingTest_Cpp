
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> scores) {
    int wanhoA = scores[0][0];
    int wanhoB = scores[0][1];
    int wanhoSum = wanhoA + wanhoB;

    sort(scores.begin(), scores.end(), [](const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0]) {
            return a[1] < b[1];
        }
        return a[0] > b[0];
    });

    int maxB = -1;
    int rank = 1;
    for (const auto &score : scores) {
        int a = score[0];
        int b = score[1];

        // 두 점수가 모두 높은 사원이 존재하면 제외
        if (b < maxB) {
            if (a == wanhoA && b == wanhoB) {
                return -1;
            }
            continue;
        }
        maxB = max(maxB, b);
        
        // 완호보다 총점이 높은 사원
        if (a + b > wanhoSum) {
            rank++;
        }
    }
    return rank;
}
