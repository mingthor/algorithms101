//! 输入一系列点的坐标，返回面积最小的长方形的坐标
//! 给出一系列点，返回四个点，组成面积最小的长方形
#include "../../util/common.h"

struct Point {
    int x;
    int y;
};
class MinRect {
public:
    vector<Point> findMinRect(vector<Point> &coords) {
        unordered_map<int, set<int>> xyMap;
        for (auto coord : coords) {
            xyMap[coord.x].insert(coord.y);
        }
        vector<Point> res;
        int area = INT_MAX;
        for (auto iter1=xyMap.begin(); iter1!=xyMap.end(); ++iter1) {
            for (auto iter2=next(iter1); iter2!=xyMap.end(); ++iter2) {
                auto i = iter1->second.begin();
                auto j = iter2->second.begin();
                bool found = false;
                int prevY = 0;
                int dx = abs(iter1->first - iter2->first);
                while (i!=iter1->second.end() && j!=iter2->second.end()) {
                    if (*i == *j) {
                        if (found == true) {
                            int current = (*i-prevY) * dx;
                            if (current < area) {
                                res = {{iter1->first, prevY}, {iter1->first, *i}, {iter2->first, *i}, {iter2->first, prevY}};
                            }
                        }
                        found = true;
                        prevY = *i;
                        ++iter1;
                        ++iter2;
                    } else if (*i < *j) ++iter1;
                    else ++iter2;
                }
            }
        }
    }
};

int main()
{
    MinRect mr;
    vector<Point> coords({{0, 0},{1,1},{1,3},{2,0},{2,1},{2,3}});
    vector<Point> res = mr.findMinRect(coords);
    return 0;
}