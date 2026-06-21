#include <vector>
using namespace std;

int solution(vector<int> stickers)
{
    if (stickers.size() == 1) {
        return stickers.front();
    }
    
    vector<int> dp0(stickers.size() + 1); // 0번 인덱스부터 시작(맨 앞 패딩)
    vector<int> dp1(stickers.size() + 1); // 1번 인덱스부터 시작(맨 앞 패딩)
    int sz = stickers.size();
    
    dp0[1] = stickers[0];
    dp1[2] = stickers[1];
    for (int i = 3; i <= sz; i++) {
        dp0[i] = max(dp0[i - 2], dp0[i - 3]) + stickers[i - 1];
        dp1[i] = max(dp1[i - 2], dp1[i - 3]) + stickers[i - 1];
    }
    return max(max(dp0[sz - 2], dp0[sz - 1]), max(dp1[sz - 1], dp1[sz]));
}