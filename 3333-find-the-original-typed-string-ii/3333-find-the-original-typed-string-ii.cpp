class Solution {
private:
    const int mod = 1e9 + 7;

public:
    int possibleStringCount(string word, int k) {
        vector<int> groups;
        int i = 0, n = word.size();
        while (i < n) {
            int j = i;
            while (j < n && word[j] == word[i]) j++;
            groups.push_back(j - i);
            i = j;
        }

        int G = groups.size();
        if (k <= G) {
            long long total = 1;
            for (int g : groups) total = (total * g) % mod;
            return total;
        }

        vector<int> dp(k, 0);
        dp[0] = 1;

        for (int g : groups) {
            vector<int> newDp(k, 0);
            long long windowSum = 0;

            for (int len = 0; len < k; ++len) {
                if (len > 0) windowSum = (windowSum + dp[len - 1]) % mod;
                if (len > g) windowSum = (windowSum - dp[len - g - 1] + mod) % mod;

                newDp[len] = windowSum;
            }
            dp = newDp;
        }

        long long invalid = 0;
        for (int len = G; len < k; ++len) {
            invalid = (invalid + dp[len]) % mod;
        }

        long long totalWays = 1;
        for (int g : groups) totalWays = (totalWays * g) % mod;

        return (totalWays - invalid + mod) % mod;
    }
};