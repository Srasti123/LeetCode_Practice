class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, maxLength = 0, zeroCount = 0;
        for (int right = 0; right < nums.size(); right++) {
            //If we encounter a zero, increment zeroCount
            if(nums[right] == 0){
                zeroCount++;
            }
            //If there are more zeroes than allowed, shrink the window from left
            while(zeroCount > k){
                if(nums[left] == 0){
                    zeroCount--; //Reduce zero count
                }
                left++; //Move left pointer
            }
            //Update max length of valid window 
            maxLength = max(maxLength, right-left+1);
        }
        return maxLength;
        
    }
};