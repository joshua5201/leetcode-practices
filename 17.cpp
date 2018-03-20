/* 17. Letter Combinations of a Phone Number
 * link: https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 * status: AC
 * 2018.3.21
 */

class Solution {
public:
    string letter_map[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) 
    {
        if (digits.size() == 0) {
            vector<string> empty;
            return empty;
        }
        queue<string> que;
        que.push(string(""));
        for (int i = 0; i < digits.size(); i++) {
            vector<string> last_results;
            while (!que.empty()) {
                last_results.push_back(que.front());
                que.pop();
            }
            string next_letters = letter_map[digits[i] - '0'];
            for (int j = 0; j < last_results.size(); j++) {
                for (int k = 0; k < next_letters.size(); k++) {
                    string res = last_results[j];
                    res.append(next_letters.substr(k, 1));
                    que.push(res);
                }
            }
            last_results.clear();
        }
        vector<string> final_results;
        while (!que.empty()) {
            final_results.push_back(que.front());
            que.pop();
        }
        return final_results;
    }
};
