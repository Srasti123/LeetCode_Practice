class Solution {
public:
    int countAtMostK(vector<int>& nums, int k) {
        if (k < 0) return 0; // No valid subarrays if k < 0
        int left = 0, count = 0;
        
        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] % 2 != 0) k--;  // Decrease `k` if an odd number is found
            
            while (k < 0) {  // If we have more than `k` odd numbers, move `left`
                if (nums[left] % 2 != 0) k++;  
                left++; 
            }
            
            count += (right - left + 1);  // Count valid subarrays ending at `right`
        }
        
        return count;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return countAtMostK(nums, k) - countAtMostK(nums, k - 1);
    }
};

