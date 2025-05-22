class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), q = queries.size();
        vector<vector<int>> starts(n);
        for (auto &qr : queries)
            starts[qr[0]].push_back(qr[1]);

        priority_queue<int> avail;  
        priority_queue<int, vector<int>, greater<int>> active;  
        int chosen = 0;
        for (int i = 0; i < n; ++i) {
            for (int r : starts[i])
                avail.push(r);
            while (!active.empty() && active.top() < i)
                active.pop();
            int need = nums[i] - (int)active.size();
            while (need-- > 0) {
                while (!avail.empty() && avail.top() < i)
                    avail.pop();
                if (avail.empty())
                    return -1;
                active.push(avail.top());
                avail.pop();
                ++chosen;
            }
        }
        return q - chosen;
    }
};