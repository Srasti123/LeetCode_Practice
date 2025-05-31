class Solution {
public:
    int snakesAndLadders(std::vector<std::vector<int>>& board) {
        int n = board.size();
        std::queue<int> q;
        std::vector<bool> visited(n * n + 1, false);

        q.push(1);
        visited[1] = true;
        int moves = 0;

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                int curr = q.front();
                q.pop();

                if (curr == n * n) {
                    return moves;
                }

                for (int next = curr + 1; next <= std::min(curr + 6, n * n); ++next) {
                    int row = (next - 1) / n;
                    int col = (next - 1) % n;
                    
                    if (row % 2 == 1) {
                        col = n - 1 - col;
                    }
                    
                    int target = board[n - 1 - row][col] != -1 ? board[n - 1 - row][col] : next;
                    if (!visited[target]) {
                        visited[target] = true;
                        q.push(target);
                    }
                }
            }
            moves++;
        }

        return -1;
    }
};
