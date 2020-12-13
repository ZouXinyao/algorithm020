class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        vector<int> x({0, 1, 0, -1});
        vector<int> y({1, 0, -1, 0});
        vector<int> loc(2, 0);
        int idx = 0;
        set<pair<int, int>> obSet;
        for(vector<int> ob : obstacles) {
            obSet.insert(make_pair(ob[0], ob[1]));
        }
        int maxDet = 0;
        for(int i = 0; i < commands.size(); i++) {
            if(commands[i] == -1) idx = (idx + 1) % 4;
            else if(commands[i] == -2) idx = (idx + 3) % 4;
            else {
                for(int j = 0; j < commands[i]; j++) {
                    if(obSet.find(make_pair(loc[0] + x[idx], loc[1] + y[idx])) != obSet.end()) break;
                    loc[0] = loc[0] + x[idx];
                    loc[1] = loc[1] + y[idx];
                    maxDet = max(maxDet, loc[0] * loc[0] + loc[1] * loc[1]);
                }
            }
        }
        return maxDet;
    }
};