/* 777. Swap Adjacent in LR String
 * link: https://leetcode.com/problems/swap-adjacent-in-lr-string/description/
 * status: AC
 * 2018.3.20
 */

class Solution {
public:
    bool canTransform(string s, string t)
    {
        int i = 0, j = 0;
        while (1) {
            while (i < s.size() && s[i] == 'X') {
                i++;
            }
            while (j < t.size() && t[j] == 'X') {
                j++;
            }
            if (i >= s.size() && j >= t.size()) {
                return true;
            }
            if (i >= s.size() || j >= t.size()) {
                return false;
            }
            if (s[i] != t[j]) {
                return false;
            }
            if (s[i] == 'L' && i < j) {
                return false;
            }
            if (s[i] == 'R' && i > j) {
                return false;
            }
            i++;
            j++;
        }
    }
};
