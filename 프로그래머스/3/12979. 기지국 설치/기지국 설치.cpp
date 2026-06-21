#include <vector>
#include <cmath>
using namespace std;

int getNeededStations(const pair<int, int> &range, int w) {
    if (range.first >= range.second) return 0;
    return (int)ceil((range.second - range.first) / (w * 2.0 + 1.0));
}

int solution(int n, vector<int> stations, int w)
{
    pair<int, int> range{1, 1}; // 전파가 닿지 않는 범위
    int cnt = 0;
    
    // 각 station 앞 비전파구역 확인
    for (const int station : stations) {
        range.second = max(1, station - w);
        cnt += getNeededStations(range, w);
        range.first = station + w + 1;
    }
    
    // 마지막 비전파구역 확인
    range.second = n + 1;
    cnt += getNeededStations(range, w);
    
    return cnt;
}