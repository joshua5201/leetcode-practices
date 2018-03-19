/* 165. Compare Version Numbers
 * link: https://leetcode.com/problems/compare-version-numbers/description/
 * status: ac
 * 2018.3.20
 */

class Solution {
public:
    int findNextDot(string str, int pos)
    {
        for (int i = pos; i < str.size(); i++) {
            if (str[i] == '.') {
                return i;
            }
        }
        return str.size();
    }
    int compareVersion(string version1, string version2)
    {
        int x = 0, y = 0;
        while (x < version1.size() || y < version2.size()) {
            int sub1 = 0, sub2 = 0;
            int dot1, dot2;
            if (x < version1.size()) {
                dot1 = findNextDot(version1, x);
                sub1 = std::stoi(version1.substr(x, dot1 - x));
            }
            if (y < version2.size()) {
                dot2 = findNextDot(version2, y);
                sub2 = std::stoi(version2.substr(y, dot2 - y));
            }
            if (sub1 > sub2) {
                return 1;
            }
            if (sub2 > sub1) {
                return -1;
            }

            if (x < version1.size()) {
                x = dot1 + 1;
            }
            if (y < version2.size()) {
                y = dot2 + 1;
            }
        }
        return 0;
    }
};
