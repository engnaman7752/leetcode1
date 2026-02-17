class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;

        for(int hour = 0; hour < 12; hour++) {
            for(int min = 0; min < 60; min++) {

                if(__builtin_popcount(hour) + 
                   __builtin_popcount(min) == turnedOn) {

                    string t = to_string(hour);
                    string m = (min < 10 ? "0" : "") + to_string(min);
                    ans.push_back(t + ":" + m);
                }
            }
        }
        return ans;
    }
};
