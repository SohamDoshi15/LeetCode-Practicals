#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> charcount;

        for (int i = 0; i < s.size(); i++) {
            charcount[s[i]]++;
        }

        for (int i = 0; i < s.size(); i++) {
            if (charcount[s[i]] == 1) {  // Corrected condition
                return i;
            }
        }

        return -1;
    }
};

int main() {
    Solution sol;
    string s = "loveleetcode";
    cout << "First unique character index: " << sol.firstUniqChar(s) << endl;
    return 0;
}
