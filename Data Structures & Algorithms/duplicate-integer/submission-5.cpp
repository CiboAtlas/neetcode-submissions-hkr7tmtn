class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> seen; // create a hash set

        for(int i = 0; i < nums.size(); i++) { // iterate through the number array
            int num = nums[i]; // create a variable to hold the value of the index

            if(seen.count(num)) { // if we've seen this value in the set return true
                return true;
            }
            seen.insert(num); // if not insert it into the hash set
        }

        return false; // if we iterate through all and find no duplicates, return false
    }
};