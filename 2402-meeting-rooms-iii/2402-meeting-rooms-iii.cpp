class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        vector<int> roomCount(n, 0);

        priority_queue<int, vector<int>, greater<>> freeRooms;
        for (int i = 0; i < n; ++i) freeRooms.push(i);

        using pii = pair<long long, int>;
        priority_queue<pii, vector<pii>, greater<>> ongoing;

        for (auto& m : meetings) {
            long long start = m[0], end = m[1];

            while (!ongoing.empty() && ongoing.top().first <= start) {
                freeRooms.push(ongoing.top().second);
                ongoing.pop();
            }

            if (!freeRooms.empty()) {
                int room = freeRooms.top(); freeRooms.pop();
                ongoing.push({end, room});
                roomCount[room]++;
            } else {
                auto [nextFreeTime, room] = ongoing.top(); ongoing.pop();
                long long newEnd = nextFreeTime + (end - start);
                ongoing.push({newEnd, room});
                roomCount[room]++;
            }
        }
        return max_element(roomCount.begin(), roomCount.end()) - roomCount.begin();
    }
};