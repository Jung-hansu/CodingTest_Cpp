#include <vector>
using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    answer.reserve(numbers.size());
    for (long long num : numbers) {
        if ((num & 1) == 0) {
            // 맨 앞 비트가 0인 경우: +1
            num += 1;
        } else {
            // 나머지 경우: 0인 비트 중 가장 낮은 자리수 비트 1로 변경, 그 아래자리 비트 0으로 변경
            num += 1LL << (__builtin_ctzll(~num) - 1);
        }
        answer.push_back(num);
    }
    return answer;
}