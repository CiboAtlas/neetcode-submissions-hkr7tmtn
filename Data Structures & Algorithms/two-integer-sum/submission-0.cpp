class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp; // hash map stores the values and index the same

        for(int i = 0; i < nums.size(); i++) { // initialize the hashmap
            mp[nums[i]] = i;
        }
        

        for(int i = 0; i < nums.size(); i++) { // loop through the nums array
            int diff = target - nums[i]; // we subtract target - the current index we are at
            if(mp.count(diff) && mp[diff] != i) { // check to see if the key is in the map first and that it isn't in the current index were at
                return {i, mp[diff]};
            }
        }

        return {}; // return the pair
    
    }
};
