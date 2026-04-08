class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;

        string s2;

        for (auto& i : s) {
            if(!isalnum(i)) {
                continue;
            }

            s2 += tolower(i);
        }

        int r = s2.size() - 1;

        cout << s2 << endl;

        while(l < r) {
            if(!isalnum(s2[l])) { // if it is not a alphanumeric
                l++;   
            }

            if(!isalnum(s2[r])) { // if it is not a alphanumeric
                r--;   
            }

            if(s2[l] == s2[r]) {
                l++;
                r--;
            } else {
                return false;
            }
        }

        return true;
    }
};
