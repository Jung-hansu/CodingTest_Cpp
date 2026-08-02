#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    const string ROOT = "-";
    unordered_map<string, pair<string, int>> map; // <이름, <추천인, 번 돈>>
    
    // map init
    map[ROOT] = {ROOT, 0};
    for (int i = 0; i < enroll.size(); i++) {
        map[enroll[i]] = {referral[i], 0};
    }
    
    // 모든 seller에 대해 bottom-up 기록
    for (int i = 0; i < seller.size(); i++) {
        int earned = amount[i] * 100;
        
        for (auto member = seller[i]; member != ROOT && earned > 0; member = map[member].first) {
            map[member].second += earned - (earned / 10);
            earned /= 10;
        }
    }
    
    vector<int> answer(enroll.size());
    for (int i = 0; i < enroll.size(); i++) {
        answer[i] = map[enroll[i]].second;
    }
    return answer;
}