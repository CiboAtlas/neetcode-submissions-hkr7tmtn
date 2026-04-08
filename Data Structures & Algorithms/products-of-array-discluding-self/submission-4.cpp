class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> a1(len), a2(len);

        // prefix
        a1[0] = 1;
        for(int i = 1; i < nums.size(); i++) {
            a1[i] = a1[i - 1] * nums[i - 1];
        }

        // suffix
        a2[len - 1] = 1;
        for(int i = len - 2; i >= 0; i--) {
            a2[i] = a2[i + 1] * nums[i + 1];
        }

        // result
        for(int i = 0; i < len; i++) {
            nums[i] = a1[i] * a2[i]; 
        }

        return nums;
    }
};
