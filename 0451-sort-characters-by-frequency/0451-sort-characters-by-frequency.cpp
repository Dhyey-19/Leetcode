class Solution {
public:

    static bool srt(pair <char,int> a,pair<char,int> b){
        if(a.second > b.second) return true;
        if(a.second < b.second) return false;

        return a.first > b.first;
    }
    string frequencySort(string s) {
        if(s.size() <= 2) return s;

        unordered_map <char,int> frq;
        for(int i=0; i<s.size(); i++){
            frq[s[i]]++;
        }

        vector<pair<char,int>> v(frq.begin(), frq.end());

        sort(v.begin(), v.end(), srt);

        s = "";
        for( auto p : v){
            s.append(p.second, p.first);
        } 
        return s;
    }
};