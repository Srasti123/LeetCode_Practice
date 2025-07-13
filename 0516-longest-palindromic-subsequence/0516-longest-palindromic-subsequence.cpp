class Solution {
public:
    int longestPalindromeSubseq(string s) {
    int n = s.size();
    vector<int> prev(n, 0), curr(n, 0);

    for (int i = n - 1; i >= 0; --i) {
        curr[i] = 1; 
        for (int j = i + 1; j < n; ++j) {
            if (s[i] == s[j])
                curr[j] = 2 + prev[j - 1];
            else
                curr[j] = max(prev[j], curr[j - 1]);
        }
        prev = curr;  
    }

    return prev[n - 1];
}

};