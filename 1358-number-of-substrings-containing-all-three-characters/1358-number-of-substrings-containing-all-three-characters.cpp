class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char, int> charCount;  // Stores counts of 'a', 'b', 'c'
        int left = 0, totalSubstrings = 0;
        for (int right = 0; right < s.length(); right++) {
            charCount[s[right]]++;  // Expand window by adding right character

            // Check if the window contains at least one 'a', 'b', and 'c'
            while (charCount['a'] > 0 && charCount['b'] > 0 && charCount['c'] > 0) {
                totalSubstrings += (s.length() - right); // Count all substrings ending from right to end of s
                charCount[s[left]]--; // Shrink window from the left
                left++; // Move left pointer
            }
        }
        return totalSubstrings;
    }
};

