class Solution {
public:
    int change(int amount, vector<int>& coins) {
        long long n=amount;
        vector<long long> dp(n+1,0);
        dp[0]=1;
        for(int i=0;i<coins.size();i++)
        {
            for(int j=coins[i];j<=amount;j++)
            {
                if(dp[j] <= INT_MAX) dp[j]=dp[j-coins[i]]+dp[j];
            }
        }
        return dp[amount];
    }
};