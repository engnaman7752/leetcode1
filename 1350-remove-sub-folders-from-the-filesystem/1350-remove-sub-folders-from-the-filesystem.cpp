class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> ans;
        map<string, int> mp;

        for (int i = 0; i < folder.size(); i++) {
            bool found = false;
            string temp;

            for (int j = 1; j < folder[i].size(); j++) {
                if (folder[i][j] == '/') {
                    temp = folder[i].substr(0, j);
                    if (mp.count(temp)) {
                        found = true;
                        break;
                    }
                }
            }

            if (!found) {
                mp[folder[i]] = 1;
                ans.push_back(folder[i]);
            }
        }

        return ans;
    }
};
