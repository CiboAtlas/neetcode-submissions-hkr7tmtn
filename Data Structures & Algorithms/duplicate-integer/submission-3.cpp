class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> mp; // hash set to track the values we see in the array

        for(int i = 0; i < nums.size(); i++) { // iterate through the integer array given
            int num = nums[i]; // create num variable to hold current index value
            if(mp.count(num)) { // if that value is inside our set return true
                return true;
            }

            mp.insert(num); // if not then insert it into the set
        }

        return false; // if no value is returned more than once, then return false
    }
};