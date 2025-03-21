class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        map<int, int> prefixSumCount; // stores frequency of prefix sum
        int currSum = 0, count = 0;
        prefixSumCount[0] = 1; // to handle case where currSum == goal
        for (int num : nums) {
            currSum += num; // calculate prefix sum
            if (prefixSumCount.find(currSum-goal) != prefixSumCount.end()) {
                count += prefixSumCount[currSum-goal];
            }
            prefixSumCount[currSum]++;
        }
        return count;
        
    }
};