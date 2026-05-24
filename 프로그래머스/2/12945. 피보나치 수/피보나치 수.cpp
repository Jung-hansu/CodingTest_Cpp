using namespace std;

int solution(int n) {
    const int P = 1'234'567;
    int dp[2] = {0, 1};
    int idx = 1;
    
    if (n <= 1) {
        return n;
    }
    while (idx < n) {
        dp[(idx + 1) % 2] = (dp[(idx + 1) % 2] + dp[idx % 2]) % P;
        idx++;
    }
    return dp[idx % 2];
}