class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        priority_queue<int, vector<int>, greater<int>> freeRooms;
        for (int i = 0; i < n; ++i) freeRooms.push(i);

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> busy;
        vector<int> count(n, 0);

        for (auto& meeting : meetings) {
            long long start = meeting[0], end = meeting[1];
            long long duration = end - start;

            while (!busy.empty() && busy.top().first <= start) {
                freeRooms.push(busy.top().second);
                busy.pop();
            }

            if (!freeRooms.empty()) {
                int room = freeRooms.top(); freeRooms.pop();
                busy.push({end, room});
                count[room]++;
            } else {
                auto [endTime, room] = busy.top(); busy.pop();
                busy.push({endTime + duration, room});
                count[room]++;
            }
        }

        int maxMeetings = 0, answer = 0;
        for (int i = 0; i < n; ++i) {
            if (count[i] > maxMeetings) {
                maxMeetings = count[i];
                answer = i;
            }
        }
        return answer;
    }
};