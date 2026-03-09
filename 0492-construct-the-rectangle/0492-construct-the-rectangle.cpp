class Solution {
public:
    vector<int> constructRectangle(int area) {
        for(int width = sqrt(area); width >= 1; width--) {
            int length = area / width;
            if(length * width == area) {
                return {length, width};
            }
        }    
        return {};
    }
};