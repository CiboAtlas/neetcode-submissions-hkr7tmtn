class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size() - 1;
        vector<int> ans;

        while (l < r) {
            int sum = numbers[l] +  numbers[r];

            // if (5 > 3)
            if(sum > target) {
                r--;
            } else if(sum < target) { // if (1 < 3)
                l++;
            } else { // if sum = target
                l = l + 1;
                r = r + 1;
                ans.push_back(l);
                ans.push_back(r);
                return ans;
            }
        }

        return ans;
    }
};
