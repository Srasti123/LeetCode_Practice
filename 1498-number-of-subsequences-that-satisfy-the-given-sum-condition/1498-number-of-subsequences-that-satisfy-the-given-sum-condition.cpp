class Solution 
{
public:
    int numSubseq(std::vector<int>& nums, int target) 
    {
        const int MOD = 1e9 + 7;
        int n = nums.size();

        // Step 1: Sort array
        std::sort(nums.begin(), nums.end());

        // Step 2: Precompute powers of 2
        std::vector<int> powers(n, 1);
        for (int i = 1; i < n; ++i) 
        {
            powers[i] = (powers[i - 1] * 2) % MOD;
        }

        // Step 3: Two-pointer setup
        int left = 0;
        int right = n - 1;
        int result = 0;

        // Step 4: Apply two-pointer logic
        while (left <= right) 
        {
            if (nums[left] + nums[right] <= target) 
            {
                result = (result + powers[right - left]) % MOD;
                ++left;
            } 
            else 
            {
                --right;
            }
        }

        // Step 5: Return result
        return result;
    }
};