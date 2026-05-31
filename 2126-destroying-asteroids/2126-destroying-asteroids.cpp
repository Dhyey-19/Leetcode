class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        // sort(asteroids.begin(), asteroids.end());

        // long long currMass = mass;

        // for (int asteroid : asteroids) {
        //     if (currMass < asteroid) {
        //         return false;
        //     }
        //     currMass += asteroid;
        // }

        // return true;

        // Counting Sort - O(n + 100001)
        vector<int> freq(100001);
        for (int x : asteroids)
            freq[x]++;

        long long curr = mass;
        for (int x = 1; x <= 100000; x++) {
            while (freq[x]--) {
                if (curr < x)
                    return false;
                curr += x;
            }
        }

        return true;
    }
};