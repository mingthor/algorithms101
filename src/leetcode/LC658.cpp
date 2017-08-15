#include "../../util/common.h"

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        if (k >= arr.size()) return arr;
        vector<int> res;
        auto biter = arr.begin();
        auto eiter = arr.begin()+k;
        while (eiter != arr.end() && x-*biter > *eiter-x) 
            ++biter, ++eiter;
        
        res.insert(res.end(), biter, eiter);
        return res;
    }
};

TEST(Solution, findClosestElements)
{
    vector<int> arr({1,2,3,4,5});
    vector<int> res = findClosestElements(arr, 4, 3);
    ASSERT_EQ(res, vector<int>({1,2,3,4}));

    res = findClosestElements(arr, 4, -1);
    ASSERT_EQ(res, vector<int>({1,2,3,4}));

    res = findClosestElements(arr, 7, -1);
    ASSERT_EQ(res, vector<int>({1,2,3,4,5}));
}

int main()
{
    RunAllTests();
    return 0;
}