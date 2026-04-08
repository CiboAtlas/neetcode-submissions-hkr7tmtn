class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0; int r = nums.size() - 1; // initialize our pointers
        while(l < r) { 
            int m = l + (r - l) / 2; // computation for mid pointer in a safe way
            if(nums[m] < nums[r]) { //if middle pointer is less than the right most value
                r = m; // right pointer becomes middle
            } else { 
                l = m + 1; // left pointer goes right 1
            }
        }

        return nums[l];
    }
};
