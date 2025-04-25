class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        unordered_map<int, long long> prefixCount;
        prefixCount[0] = 1;  
        long long count = 0;
        int currentPrefix = 0;
        for (int num : nums) {
            if (num % modulo == k) {
                currentPrefix++;
            }
            currentPrefix %= modulo;
            int target = (currentPrefix - k + modulo) % modulo;
            if (prefixCount.find(target) != prefixCount.end()) {
                count += prefixCount[target];
            }
            prefixCount[currentPrefix]++;
        }
        return count;
    }
};