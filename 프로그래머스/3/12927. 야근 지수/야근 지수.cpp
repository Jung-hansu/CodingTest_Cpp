#include <algorithm>
#include <vector>
using namespace std;

long long solution(int n, vector<int> works) {
    sort(works.begin(), works.end());
    vector<int> sum(works.size());
    
    sum[0] = works[0];
    for (int i = 1; i < sum.size(); i++) {
        sum[i] = sum[i - 1] + works[i];
    }
    
    if (sum.back() <= n) {
        return 0;
    }
    
    int prevSp = works.size() - 1, prevSpent = 0;
    for (int criteria = works.back(); criteria >= 0; criteria--) {
        int sp = upper_bound(works.begin(), works.end(), criteria) - works.begin();
        int spent = sum.back() - sum[sp - 1] - (works.size() - sp) * criteria;
        
        if (spent > n) {
            for (int i = sp; i < works.size(); i++) {
                works[i] = criteria + 1;
            }
            n -= prevSpent;
            break;
        }
        prevSp = sp;
        prevSpent = spent;
    }
    
    long long ans = 0;
    for (int i = works.size() - 1; i >= 0; i--) {
        int tmp = works[i] - (n-- > 0);
        ans += 1LL * tmp * tmp;
    }
    return ans;
}