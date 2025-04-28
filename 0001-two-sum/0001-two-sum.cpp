class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp; // value -> index

    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];

        if (mp.find(complement) != mp.end()) {
            return {mp[complement], i}; // Found pair
        }

        mp[nums[i]] = i; // Store the current number with its index
    }
    return {}; 
}
};