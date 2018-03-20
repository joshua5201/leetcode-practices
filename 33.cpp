/* 33. Search in Rotated Sorted Array
 * link: https://leetcode.com/problems/search-in-rotated-sorted-array/description/
 * status: AC
 * 2018.3.20
 */

class Solution {
public:
    int b_search(vector<int>& nums, int target, int left, int right)
    {
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            
            if (nums[mid] > target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        if (nums[left] == target) {
            return left;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) 
    {
        if (nums.size() == 0) {
            return -1;
        }
        int left = 0, right = nums.size();
        int fake_target = nums[0];
        if (fake_target == target) {
            return 0;
        }
        
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] < fake_target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        int pivot = left;
        int ans;
        if (pivot > 0) {
            ans = b_search(nums, target, 0, pivot);
            if (ans != -1) {
                return ans;
            }
        }
        if (pivot < nums.size()) {
            ans = b_search(nums, target, pivot, nums.size());
            if (ans != -1) {
                return ans;
            }
        }
        return -1;
    }
};
