#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            unordered_map<int,int>numMap;
            for(int i=0;i<nums.size();i++){
                int complement=target-nums[i];
                if(numMap.find(complement)!=numMap.end()){
                    return{numMap[complement],i};
                }
                numMap[nums[i]]=i;
            }
            return {};
            
    }
};

int main() {
    Solution sol; 

    vector<int> nums = {2, 7, 11, 15}; // Input array
    int target = 9; // Target sum

    vector<int> result = sol.twoSum(nums, target);
    if (!result.empty()) {
        cout << "Indices: " << result[0] << ", " << result[1] << endl;
    } else {
        cout << "No solution found." << endl;
    }

    return 0;
}