class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();

        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));

        priority_queue<pair<pair<int,int>,pair<int,int>>, vector<pair<pair<int,int>,pair<int,int>>>, greater<pair<pair<int,int>,pair<int,int>>>>pq;

        pq.push({{0,2},{0,0}});
        dist[0][0] = 0;

        while(!pq.empty()){
            int time = pq.top().first.first;
            int turn = pq.top().first.second;
            int row = pq.top().second.first;
            int col = pq.top().second.second;

            pq.pop();

            int drow[] = {0,1,0,-1};
            int dcol[] = {-1,0,1,0};

            for(int i=0;i<4;i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow >= 0 && ncol >=0 && nrow <n && ncol < m){
                    int turn_time = (turn == 2)? 1:2;
                    int new_time = time;

                    if(new_time < moveTime[nrow][ncol]) 
                        new_time = moveTime[nrow][ncol];

                    new_time += turn_time;

                    if(nrow == n-1 && ncol == m-1) return new_time;

                    if(new_time < dist[nrow][ncol]){
                        dist[nrow][ncol] = new_time;
                        pq.push({{new_time,turn_time},{nrow,ncol}});
                    }
                }
            }
        }
        return 0;
    }
};