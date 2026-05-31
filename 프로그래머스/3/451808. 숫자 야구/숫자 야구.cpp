#include <array>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

extern string submit(int);

int convertToInt(const array<int, 4> &n) {
    return n[0] * 1000 + n[1] * 100 + n[2] * 10 + n[3];
}

pair<int, int> getClue(const array<int, 4> &n) {
    string clue = submit(convertToInt(n));
    return {clue[0] - '0', clue[3] - '0'};
}

// 직접 만든 submit 함수
pair<int, int> getLocalClue(const array<int, 4> &tmpAns, const array<int, 4> &n) {
    int strike = 0, ball = 0;
    int bits = 0;

    for (int i = 0; i < 4; i++) {
        bits |= (1 << tmpAns[i]);
    }

    for (int i = 0; i < 4; i++) {
        if (bits & (1 << n[i])) {
            if (n[i] == tmpAns[i]) strike++;
            else ball++;
        }
    }

    return {strike, ball};
}

vector<array<int, 4>> getCandidates() {
    vector<array<int, 4>> candidates;

    candidates.reserve(3024);
    for (int i = 1; i <= 9; i++) {
        for (int j = 0; j <= 9; j++) {
            if (i == j) continue;
            for (int k = 0; k <= 9; k++) {
                if (i == k || j == k) continue;
                for (int l = 0; l <= 9; l++) {
                    if (i == l || j == l || k == l) continue;
                    candidates.push_back({i, j, k, l});
                }
            }
        }
    }
    return candidates;
}

void filterCandidates(vector<array<int, 4>> &candidates, const array<int, 4> &num) {
    vector<array<int, 4>> filtered;
    filtered.reserve(candidates.size());

    auto [s, b] = getClue(num);
    for (const auto &candidate : candidates) {
        auto [tmpS, tmpB] = getLocalClue(candidate, num);
        if (s == tmpS && b == tmpB) {
            filtered.push_back(candidate);
        }
    }
    candidates = move(filtered);
}

int solution(int n) {
    vector<array<int, 4>> allNumbers = getCandidates();
    vector<array<int, 4>> candidates = allNumbers;

    while (candidates.size() > 1) {
        int minWorst = 10000;
        array<int, 4> bestNum = allNumbers.front();
        bool bestIsCandidate = false;

        // 전체 가능한 후보 중에서 질문 선택
        for (const auto &query : allNumbers) {
            int resCnt[25]{}; // s * 5 + b
            int worst = 0;

            // 현재 가능한 정답 후보들이 submit 결과에 대해 어떻게 나뉘는지 기록
            for (const auto &candidate : candidates) {
                auto [s, b] = getLocalClue(candidate, query);
                resCnt[s * 5 + b]++;
            }

            // 나뉜 결과 중 최댓값 선택
            for (int k = 0; k < 25; k++) {
                worst = max(worst, resCnt[k]);
            }

            bool queryIsCandidate =
                find(candidates.begin(), candidates.end(), query) != candidates.end();

            // 최악의 경우 후보 수가 가장 적은 질문 선택
            // 동률이면 실제 정답 후보 안에 있는 질문 우선 선택
            if (worst < minWorst ||
                (worst == minWorst && queryIsCandidate && !bestIsCandidate)) {
                minWorst = worst;
                bestNum = query;
                bestIsCandidate = queryIsCandidate;
            }
        }
        filterCandidates(candidates, bestNum);
    }
    return convertToInt(candidates.front());
}