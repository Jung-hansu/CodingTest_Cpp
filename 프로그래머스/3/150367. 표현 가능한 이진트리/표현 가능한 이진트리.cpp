#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool dfs(string num) {
    int len = num.length();
    
    if (len == 1) {
        return true;
    }
    if (num[len / 2] == '0') {
        return all_of(num.begin(), num.end(), [](char c) {
            return c == '0';
        });
    }
    return dfs(num.substr(0, len / 2)) && dfs(num.substr(len / 2 + 1));
}

bool isPresentable(long long number) {
    int digit = 64 - __builtin_clzll(number);
    int treeSize = (1 << (32 - __builtin_clz(digit))) - 1;
    string num = "";
    
    for (int i = 0; i < treeSize; i++) {
        num += to_string(!!(number & (1LL << i)));
    }
    return dfs(num);
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    
    answer.reserve(numbers.size());
    for (const auto number : numbers) {
        answer.push_back(isPresentable(number));
    }
    return answer;
}