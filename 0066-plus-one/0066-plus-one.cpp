class Solution {
public:
    vector<int> plusOne(vector<int>& v) {
        for (int i = v.size()-1; i >= 0; i--) {
            if (v[i] < 9) {
                v[i]++;
                return v;
            }
            v[i] = 0;
        }
        v.insert(v.begin(), 1);
        return v;
    }
};