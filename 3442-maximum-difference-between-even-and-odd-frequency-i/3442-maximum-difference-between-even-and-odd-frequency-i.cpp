class Solution {
public:
    int maxDifference(string s) {
        int freq[26] = {};
        for (char c : s) freq[c - 'a']++;
        int maxOdd = -1;
        int minEven = INT_MAX;
        for (int f : freq) {
            if (f == 0) continue;
            if (f & 1) maxOdd = max(maxOdd, f);
            else minEven = min(minEven, f);
        }
        if (maxOdd == -1 || minEven == INT_MAX) return -1;
        return maxOdd - minEven;
    }
};