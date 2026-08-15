#include <vector>
#include <algorithm>
using namespace std;

bool canGo(const vector<int> &stones, int k, int i) {
    int cnt = 0;

    for (int stone : stones) {
        // i번째 사람이 이 돌을 밟을 수 없는 경우
        if (stone < i) {
            cnt++;
            if (cnt == k){
                return false;
            }
        } else {
            cnt = 0;
        }
    }
    return true;
}

int solution(vector<int> stones, int k) {
    int l = 1, r = *max_element(stones.begin(), stones.end());

    while (l <= r) {
        int mid = (r + l) / 2;

        if (canGo(stones, k, mid)) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return r;
}