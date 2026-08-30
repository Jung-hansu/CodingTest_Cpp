#include <cmath>
#include <vector>
using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> arr;
    
    arr.reserve(right - left + 1);
    for (long long i = left; i <= right; i++) {
        arr.push_back(max(i / n, i % n) + 1);
    }
    return arr;
}