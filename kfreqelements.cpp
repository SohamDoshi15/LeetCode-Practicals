#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;
        //Counting frequency of each number
        for (int num=0;num<nums.size();num++) {
            freqMap[num]++;
        }
        vector<int> result;
        // Extracting the top K elements
        while (k > 0) {
            int maxFreq = 0;
            int mostFrequentNum = 0;

            // Highest frequency
            for (auto& pair : freqMap) {
                if (pair.second > maxFreq) {
                    maxFreq = pair.second;
                    mostFrequentNum = pair.first;
                }
            }
            //Add the most frequent number to result and remove it from the map
            result.push_back(mostFrequentNum);
            freqMap.erase(mostFrequentNum);  
            k--;
        }

        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    vector<int> result = sol.topKFrequent(nums, k);
    cout << "Top " << k << " frequent elements: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}