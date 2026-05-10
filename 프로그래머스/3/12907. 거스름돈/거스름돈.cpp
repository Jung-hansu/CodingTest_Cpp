#include <vector>
using namespace std;

const int P = 1'000'000'007;

int solution(int n, vector<int> money) {
    int dp[100'001]{}; // dp[i]: 거스름돈이 i원일 때 가능한 거스름 방법의 개수

    dp[0] = 1;
    for (const int coin : money) {
        for (int change = coin; change <= n; change++) {
            dp[change] = (dp[change] + dp[change - coin]) % P;
        }
    }
    return dp[n];
}