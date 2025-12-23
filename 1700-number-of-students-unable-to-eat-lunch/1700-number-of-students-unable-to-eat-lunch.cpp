class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> st;
        for (int s : students) st.push(s);
        int i = 0, n = students.size(), rotate = 0;
        while (!st.empty() && rotate < st.size()) {
            if (st.front() == sandwiches[i]) {
                st.pop();
                i++;
                rotate = 0;
            } else {
                st.push(st.front());
                st.pop();
                rotate++;
            }
        }
        return st.size();
    }
};