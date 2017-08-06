#include "../../util/common.h"

class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
       
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