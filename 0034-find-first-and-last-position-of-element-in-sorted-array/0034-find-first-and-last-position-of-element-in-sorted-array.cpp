class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = firstOcc(nums, target);
        if (first == -1)
            return {-1, -1};
        int last = lastOcc(nums, target);
        return {first, last};
    }
    int firstOcc(vector<int>& nums, int target) {
        int s = 0, e = nums.size() - 1;
        int left = -1;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (nums[mid] == target) {
                left = mid;
                e = mid - 1;
            } else if (nums[mid] > target) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
            
        }
        return left;
    }
    int lastOcc(vector<int>& nums, int target) {
        int s = 0, e = nums.size() - 1;
        int right = -1;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (nums[mid] == target) {
                right = mid;
                s = mid + 1;  // Move right to find the last occurrence
            } else if (nums[mid] < target) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        return right;
    }
};