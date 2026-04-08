class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp; // create hash map

        for(int i = 0; i < nums.size(); i++) { // initialize hash map and store the values
            int find = target - nums[i];

            if(mp.find(find) != mp.end()) { // if we already found that number previously
                return {mp[find], i}; // return that first and then return whatever index were in
            }

            mp.insert({nums[i], i}); // if we haven't seen it in the map then just insert it that pair
        }


        // if we go through the whole map and haven't seen anything
        return {}; // return empty
    }
};
