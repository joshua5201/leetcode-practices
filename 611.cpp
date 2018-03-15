/* 611. Valid Triangle Number
 * link: https://leetcode.com/problems/valid-triangle-number/description/
 * status: AC
 * 2018.03.14
 */

class Solution {
public:
    int upper_bound_index(const vector<int>& nums, int i, int j) 
    {
        const int len = nums.size();
        int left = j + 1;
        int right = len;
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] >= nums[i] + nums[j]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return right;
    }
    int triangleNumber(vector<int>& nums) 
    {
        std::sort(nums.begin(), nums.end());
        const int len = nums.size();
        int count = 0;
        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j < len; j++) {
                int k = upper_bound_index(nums, i, j);
                count += (k - j - 1);
            }
        }
        return count;
    }
};

