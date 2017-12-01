#include "../../util/common.h"

class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        vector<vector<int>> dist = grid;
        queue<pair<int, int>> q;
        for (int i=0; i<grid.size(); i++) {
            for (int j=0; j<grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    q.emplace(i, j);
                    bfs(dist, grid, q);
                    cout<<dist<<endl;
                }
            }
        }
        int res = INT_MAX;
        for (int i=0; i<dist.size(); i++) {
            for (int j=0; j<dist[0].size(); j++) {
                if (grid[i][j] == 0) res = min(res, dist[i][j]);
            }
        }
        return res;
    }
    
    void bfs(vector<vector<int>>& dist, vector<vector<int>>& grid, queue<pair<int, int>>& q) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        int d = 0;
        while (!q.empty()) {
            int sz = q.size();
            for (int k=0; k<sz; k++) {
                auto p = q.front();
                q.pop();
                if (visited[p.first][p.second]) continue;
                visited[p.first][p.second] = true;
                dist[p.first][p.second] += d;
                int i=p.first, j=p.second;
                if (i-1>=0 && visited[i-1][j]==false && grid[i-1][j]==0) q.emplace(i-1, j);
                if (i+1<grid.size() && visited[i+1][j]==false && grid[i+1][j]==0) q.emplace(i+1, j);
                if (j-1>=0 && visited[i][j-1]==false && grid[i][j-1]==0) q.emplace(i, j-1);
                if (j+1<grid[0].size() && visited[i][j+1]==false && grid[i][j+1]==0) q.emplace(i, j+1);
            }
            d++;
        }
    }
};

int main()
{
    vector<vector<int>> grid({{1,0,2,0,1},{0,0,0,0,0},{0,0,1,0,0}});
    int dist = Solution().shortestDistance(grid);
    cout<<dist<<endl;
    return 0;
}