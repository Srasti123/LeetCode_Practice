class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size(), n = grid[0].size();
        int k = queries.size();
        vector<int> answer(k, 0);
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        vector<pair<int, int>> queryIndices;
        for (int i = 0; i < k; i++) {
            queryIndices.push_back({queries[i], i});
        }
        sort(queryIndices.begin(), queryIndices.end());

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> minHeap;
        minHeap.push({grid[0][0], {0, 0}});
        visited[0][0] = true;
        
        int count = 0;
        int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (auto [qVal, qIndex] : queryIndices) {
            while (!minHeap.empty() && minHeap.top().first < qVal) {
                auto [cellVal, pos] = minHeap.top();
                minHeap.pop();
                count++;
                int x = pos.first, y = pos.second;
                for (auto [dx, dy] : directions) {
                    int nx = x + dx, ny = y + dy;
                    if (nx >= 0 && ny >= 0 && nx < m && ny < n && !visited[nx][ny]) {
                        minHeap.push({grid[nx][ny], {nx, ny}});
                        visited[nx][ny] = true;
                    }
                }
            }
            answer[qIndex] = count;
        }
        return answer;
    }
};
        
    