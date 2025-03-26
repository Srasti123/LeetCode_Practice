class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                nums.push_back(grid[i][j]);
            }
        }
        for (int num : nums) {
            if ((num - nums[0]) % x != 0) {
                return -1; 
            }
        }
        sort(nums.begin(), nums.end());
        int median = nums[nums.size() / 2];  
        int operations = 0;
        for (int num : nums) {
            operations += abs(num - median) / x;
        }
        
        return operations;
    }
};
        
    