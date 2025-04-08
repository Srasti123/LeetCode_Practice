class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int operations = 0;
        int i = 0;
        int n = nums.size();
        while (i < n) {
            unordered_set<int> seen;
            bool hasDuplicate = false;
            for (int j = i; j < n; ++j) {
                if (seen.count(nums[j])) {
                    hasDuplicate = true;
                    break;
                }
                seen.insert(nums[j]);
            }
            if (!hasDuplicate) break;
            i += 3;
            operations++;
        }
        return operations;
    }
};
        
    