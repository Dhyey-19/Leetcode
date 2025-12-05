class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        // Using Queue

        // int time = 0;
        // queue<pair<int, int>> q; // {index, tickets_needed}
        // for (int i = 0; i < tickets.size(); ++i) {
        //     q.push({i, tickets[i]});
        // }
        // int idx = 0, val = 0;
        // while (true) {
        //     idx = q.front().first;
        //     val = q.front().second;
        //     val--;
        //     q.pop();
        //     time++;
        //     if (val) {
        //         q.push({idx, val});
        //         continue;
        //     }
        //     if(idx == k) {
        //         break;
        //     }
        // }
        // return time;

        // Optimal - Using Array
        int target = tickets[k];
        int time = 0;
        for(int i = 0; i < tickets.size(); i++) {
            if(i <= k) {
                time += min(tickets[i], target);
            } else {
                time += min(tickets[i], target - 1);
            }
        }
        return time;
    }
};