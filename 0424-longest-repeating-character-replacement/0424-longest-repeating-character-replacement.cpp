class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> charCount;
        int left = 0, maxCount = 0, maxLength = 0;
        for (int right = 0; right < s.length(); right++) {
            charCount[s[right]]++;
            maxCount = max(maxCount, charCount[s[right]]);
            if ((right-left+1) - maxCount > k) {
                charCount[s[left]]--;
                left++;
            }
            maxLength = max(maxLength, right-left+1);
        }
        return maxLength;
    }
};