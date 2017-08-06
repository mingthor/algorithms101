#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty() || matrix[0].empty()) return res;
        int rows = matrix.size(), cols = matrix[0].size();
        bool forward = true;
        int i=0, j=0;
        while (i < rows && j < cols) {
            res.push_back(matrix[i][j]);
            if (forward) {
                if (j+1 >= cols) i++, forward = false;
                else if (i-1 < 0) j++, forward = false;
                else i--, j++;
            } else {
                if (i+1 >= rows) j++, forward = true;
                else if (j-1 < 0) i++, forward = true;
                else i++, j--; 
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> matrix({{1,2,3},{4,5,6},{7,8,9},{10,11,12}});
    vector<int> res = sol.findDiagonalOrder(matrix);
    print(res);
    return 0;
}
