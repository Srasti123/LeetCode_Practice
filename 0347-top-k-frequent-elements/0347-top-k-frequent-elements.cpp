class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;
        for (int num : nums) {
          freqMap[num]++;
        }
        vector<pair<int, int>> freqVec;
        for (auto it : freqMap) {
           freqVec.push_back({it.second, it.first}); 
        }
        sort(freqVec.rbegin(), freqVec.rend()); 
        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(freqVec[i].second);
        }
        return result;
    }
};
