#include "../../util/common.h"

class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        unordered_map<string, set<string>> toMap;
        for (auto p : tickets) {
            toMap[p.front()].insert(p.back());
        }
        unordered_set<string> visited;
        vector<string> path, tmp;
        stack<string> s;
        if (toMap.count("JFK")) s.push("JFK");
        while (!s.empty()) {
            string current = s.top();
            s.pop();
            if (visited.count(current)) {
                path.insert(path.end(), tmp.begin(), tmp.end());
                tmp.clear();
                
            }
            visited.insert(current);
            int neighbors = toMap[current].size();
            if (neighbors == 0 || neighbors == 1) tmp.push_back(*toMap[current].begin());
            else {
                for (auto iter=toMap[current].rbegin(); iter!=toMap[current].rend(); ++iter) {
                    s.push(*iter);
                }
            }
        }
        return path;
    }
};

TEST(Solution, itenerary)
{
    vector<pair<string, string>> tickets = {{"MUC", "LHR"},{"JFK", "MUC"},{"SFO", "SJC"},{"LHR", "SFO"}};
    vector<string> expected = {"JFK", "MUC", "LHR", "SFO", "SJC"};
    vector<string> res = findItinerary(tickets);
    ASSERT_EQ(res, expected);

    tickets = {{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}};
    expected = {"JFK","ATL","JFK","SFO","ATL","SFO"}
    res = findItinerary(tickets);
    ASSERT_EQ(res, expected);
}

int main()
{
    Solution sol;
    RunAllTests();
    return 0;
}