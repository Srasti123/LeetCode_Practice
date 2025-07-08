class Solution {
public:
    int binarySearch(vector<vector<int>>& events, int currEnd, int low) {
        int left = low, right = events.size() - 1;
        int ans = events.size();
        while (left <= right) {
            int mid = (left + right) / 2;
            if (events[mid][0] > currEnd) {
                ans = mid;
                right = mid - 1;
            } 
            else {
                left = mid + 1;
            }
        }
        return ans;
    }
    int solvemem(vector<vector<int>>& events, int i, int k,vector<vector<int>> &dp) {
        if (i >= events.size() || k == 0)
            return 0;
        
        if(dp[i][k] != -1){
            return dp[i][k];
        }

        int skip = solvemem(events, i + 1, k,dp);

        int nextIndex = binarySearch(events, events[i][1], i + 1);
        int take = events[i][2] + solvemem(events, nextIndex, k - 1,dp);

        return dp[i][k] = max(skip, take);
    }

    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
       vector<vector<int>> dp(events.size()+1,vector<int>(k+1,-1));
       return solvemem(events,0,k,dp);
    }
};