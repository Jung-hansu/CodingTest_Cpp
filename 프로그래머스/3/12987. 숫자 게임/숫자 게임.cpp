#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B) {
    int point = 0, j = 0;
    
    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());
    for (int i = 0; i < A.size(); i++) {
        if (A[i] < B[j]) {
            j++;
            point++;
        }
    }
    return point;
}