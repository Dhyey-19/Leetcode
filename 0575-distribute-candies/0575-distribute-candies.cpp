class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int limit = candyType.size() / 2;
        unordered_set<int> types;

        for(int c : candyType) {
            types.insert(c);
            if(types.size() == limit) {
                return limit;
            }
        }

        return types.size();
    }
};