
#include <vector>
using namespace std;

const int MOD = 1234567;

void getPascalTriangle(vector<vector<int>> &comb, int n){
    for (int i = 0; i <= n; i++) {
        comb[i][0] = comb[i][i] = 1;
        for (int j = 1; j < i; j++) {
            comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
        }
    }
}

long long solution(int n) {
    vector<vector<int>> comb(n + 1, vector<int>(n + 1, 0));
    long long answer = 0;
    int one = n % 2;
    int two = n / 2;

    getPascalTriangle(comb, n);
    while (two >= 0) {
        answer = (answer + comb[one + two][two]) % MOD;

        two -= 1;
        one += 2;
    }
    return answer;
}
