#include <string>
#include <vector>
#include <deque>
using namespace std;

class Matrix {
    // 행렬을 왼쪽열, 가운데행렬, 오른쪽열 세 부분으로 나누어 관리
    deque<int> left;
    deque<int> right;
    deque<deque<int>*> middle;
    vector<deque<int>> rowPool; //middle의 각 행을 포인터로 관리하기 위한 실제 객체 보관소
    int N, M;
    
    void shiftRow() {
        left.push_front(left.back());
        left.pop_back();
        
        middle.push_front(middle.back());
        middle.pop_back();
        
        right.push_front(right.back());
        right.pop_back();
    }
    
    void rotate() {
        middle.front()->push_front(left.front());
        left.pop_front();
        
        right.push_front(middle.front()->back());
        middle.front()->pop_back();
        
        middle.back()->push_back(right.back());
        right.pop_back();
        
        left.push_back(middle.back()->front());
        middle.back()->pop_front();
    }
    
public:
    Matrix(const vector<vector<int>> &mat): N(mat.size()), M(mat.front().size()) {
        rowPool.reserve(N);
        for (const auto &row : mat) {
            rowPool.push_back({});
            left.push_back(row.front());
            middle.push_back(&rowPool.back());
            for (int i = 1; i < row.size() - 1; i++) {
                middle.back()->push_back(row[i]);
            }
            right.push_back(row.back());
        }
    }
    
    void operate(const string &op) {
        if (op == "ShiftRow") {
            shiftRow();
        } else {
            rotate();
        }
    }
    
    vector<vector<int>> toVectorMatrix() {
        vector<vector<int>> ret(N, vector<int>(M));
        
        for (int i = 0; i < N; i++) {
            ret[i][0] = left[i];
            for (int j = 1; j < M - 1; j++) {
                ret[i][j] = middle[i]->at(j - 1);
            }
            ret[i][M - 1] = right[i];
        }
        return ret;
    }
};

vector<vector<int>> solution(vector<vector<int>> rc, vector<string> operations) {
    Matrix matrix(rc);
    
    for (const auto &op : operations) {
        matrix.operate(op);
    }
    return matrix.toVectorMatrix();
}