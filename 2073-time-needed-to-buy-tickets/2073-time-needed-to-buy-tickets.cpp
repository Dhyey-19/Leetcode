class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int time = 0;
        queue<pair<int, int>> q; // {index, tickets_needed}
        for (int i = 0; i < tickets.size(); ++i) {
            q.push({i, tickets[i]});
        }
        int idx = 0, val = 0;
        while (true) {
            idx = q.front().first;
            val = q.front().second;
            val--;
            q.pop();
            time++;
            if (val) {
                q.push({idx, val});
                continue;
            }
            if(idx == k) {
                break;
            }
        }
        return time;
    }
};