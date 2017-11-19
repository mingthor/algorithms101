//! 12.4 
//! You have an array with all the numbers from 1 to N, where N is at most 32,000. 
//! The array may have duplicate entries and you do not know what N is. 
//! With only 4KB of memory available, how would you print all duplicate elements in the array?
#include "../../util/common.h"

class Solution {
public:
    // bit vector
    void printDuplicates1(const vector<int>& nums) {
        vector<bool> bitvec(nums.size(), false);
        for (auto n : nums) {
            if (bitvec[n-1]) cout << n << " ";
            bitvec[n-1] = true;
        }
        cout << endl;
    }

    // using buckets
    void printDuplicates2(const vector<int> &nums) {
        for (int i=0; i<64; i++) {
            unordered_map<int, int> bucketMap;
            for (auto n : nums) {
                if ((n-1) / 64 == i) {
                    bucketMap[n] ++;
                    if (bucketMap[n] == 2) cout << n << " ";
                }
            }
        }
        cout<<endl;
    }
private:
    vector<int> testdata;
};

int main()
{

}