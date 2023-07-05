class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0;
        int start = 0, end = 0;
        unordered_set<char> charSet;

        while (end < s.length()) {
            if (charSet.find(s[end]) == charSet.end()) {
                charSet.insert(s[end]);
                end++;
                maxLength = max(maxLength, end - start);
            } else {
                charSet.erase(s[start]);
                start++;
            }
        }

        return maxLength;
    }
};