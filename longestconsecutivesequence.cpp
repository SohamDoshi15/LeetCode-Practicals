#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> numMap;
        int longest = 0;

        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];

            if (numMap.find(num) == numMap.end()) { 
                int left, right;

                if (numMap.count(num - 1) > 0) {
                    left = numMap[num - 1];
                } else {
                    left = 0;
                }

                if (numMap.count(num + 1) > 0) {
                    right = numMap[num + 1];
                } else {
                    right = 0;
                }

                int seqLength = left + 1 + right;

                numMap[num] = seqLength;
                numMap[num - left] = seqLength;
                numMap[num + right] = seqLength;

                if (seqLength > longest) {
                    longest = seqLength;
                }
            }
        }

        return longest;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << "Longest Consecutive Sequence: " << sol.longestConsecutive(nums) << endl;
    return 0;
}
