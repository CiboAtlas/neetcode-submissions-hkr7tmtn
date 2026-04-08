class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) // check to see if both strings are the same size first
            return false;
        
        unordered_map<char, int> scnt, tcnt; // create two hash maps to count frequency for both strings
        // key = char
        // value = frequency

        for(int i = 0; i < s.size(); i++) { // since the sizes are the same, we can just iterate with any string to check
            scnt[s[i]] = 1 + scnt[s[i]]; 
            tcnt[t[i]] = 1 + tcnt[t[i]];
        }

        return scnt == tcnt;
    }
};