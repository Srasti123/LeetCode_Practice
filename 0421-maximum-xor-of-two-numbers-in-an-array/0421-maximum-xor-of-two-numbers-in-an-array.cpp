class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int maxXOR = 0;
        int n = nums.size();
        for (int i=0; i<n; i++){
            for (int j=i+1; j<n; j++){
                maxXOR = max(maxXOR,nums[i]^nums[j]);
            }
        }
        return maxXOR;
        
    }
};