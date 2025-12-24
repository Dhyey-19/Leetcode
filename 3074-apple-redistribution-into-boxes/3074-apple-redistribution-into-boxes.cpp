class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int total = 0;
        for (int a : apple) total += a;

        sort(capacity.begin(), capacity.end(), greater<int>());

        int curr = 0, boxes = 0;
        for (int c : capacity) {
            curr += c;
            boxes++;
            if (curr >= total) break;
        }
        return boxes;
    }
};
