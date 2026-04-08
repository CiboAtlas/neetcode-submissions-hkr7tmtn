class Solution {
public:
    int BSearch(int l, int r, vector<int>&nums, int target) {
        if(l > r) return - 1; // if left pointer is past right point, there's no values left to look for
        int m = l + (r - l) / 2;

        if(nums[m] == target) return m; // if the middle index is the target return index
        
        if(nums[m] < target) {
            return BSearch(m + 1, r, nums, target); // if the middle index is less than the target, search right space
        } else {
            return BSearch(l, m - 1, nums, target); // if the middle index is greater than the target, search left space
        }
    }

    int search(vector<int>& nums, int target) {
        return BSearch(0, nums.size() - 1, nums, target);    
    }
};
