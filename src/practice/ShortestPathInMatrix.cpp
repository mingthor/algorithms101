//! Shortest path in a Binary Maze
//! Given a MxN matrix where each element can either be 0 or 1. 
//! We need to find the shortest path between a given source cell to a destination cell. 
//! The path can only be created out of a cell if its value is 1.
//! Expected time complexity is O(MN).
#include "../../util/common.h"

struct Point {
    int x;
    int y;
    Point(int c, int r) : x(c), y(r) {}
    bool operator==(const Point& other) {
        return x == other.x && y == other.y;
    }
    bool operator!=(const Point& other) { return ! (*this == other); }
};

class BinaryMaze
{
    vector<Point> findShortestPath(vector<vector<int>> &maze, Point src, Point dst) {
        if (maze.empty()) return {};
        int m = maze.size(), n = maze[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        queue<Point> q;
        q.push(src);
        while (!q.empty()) {
            Point p = q.front();
            q.pop();
            visited[p.y][p.x] = true;
            if (p == dst) return backtrace(maze, src, dst);
            int d[] = {-1, 1, 0, 0};
            for (int i=0; i<4; i++) {
                int r = p.y + d[i];
                int c = p.x + d[4-i];
                if (r < 0 || r >= m || c < 0 || c >= n) continue;
                if (visited[r][c] || maze[r][c] == 0) continue;
                q.emplace(r, c);
                maze[r][c] = maze[p.y][p.x] + 1;
            }
        }
    }
    vector<Point> backtrace(vector<vector<int>> &maze, Point src, Point dst) {
        vector<Point> path;
        Point current = dst;
        int d[] = {-1, 1, 0, 0};
        while (current != src) {
            path.push_back(current);
            for (int i=0; i<4; i++) {
                int r = current.y + d[i];
                int c = current.x + d[4-i];
                if (r < 0 || r >= maze.size() || c < 0 || c >= maze[0].size()) continue;
                if (maze[r][c] == maze[current.y][current.x] - 1) {
                    current = Point(c, r);
                    break;
                }
            }
        }
        reverse(path.begin(), path.end());
        return path;
    }
};