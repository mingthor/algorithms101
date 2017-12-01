#include "../../util/common.h"

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        int res = 0;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        for (int i=0; i<grid.size(); i++) {
            for (int j=0; j<grid[i].size(); j++) {
                int area = 0;
                blobfill(grid, visited, i, j, area);
                res = max(res, area);
            }
        }
        return res;
    }

    void blobfill(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j, int& area) {
        if (i < 0 || i >= grid.size()) return;
        if (j < 0 || j >= grid[i].size()) return;
        if (grid[i][j] == 1 && visited[i][j] == false) {
            visited[i][j] = true;
            area += 1;
            blobfill(grid, visited, i-1, j, area);
            blobfill(grid, visited, i+1, j, area);
            blobfill(grid, visited, i, j-1, area);
            blobfill(grid, visited, i, j+1, area);
        }
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> grid({{1,0,1,0},{1,1,1,0},{0,0,1,0},{1,1,0,0}});
    int area = sol.maxAreaOfIsland(grid);
    cout<<area<<endl;
    return 0;
}