
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& a, vector<int>& newi) {
        vector<vector<int>> res;
        bool inserted = false;
        int n = a.size();

        // Step 1: Insert newi at correct position
        for (int i = 0; i < n; i++) {
            if (!inserted && a[i][0] >= newi[0]) {
                res.push_back(newi);
                inserted = true;
            }
            res.push_back(a[i]);
        }

        if (!inserted) {
            res.push_back(newi);
        }

        // Step 2: Merge intervals
        vector<vector<int>> ans;

        if (res.empty()) return ans;

        int st1 = res[0][0];
        int ed1 = res[0][1];

        for (int i = 1; i < res.size(); i++) {
            int st2 = res[i][0];
            int ed2 = res[i][1];

            if (ed1 >= st2) {
                st1 = min(st1, st2);
                ed1 = max(ed1, ed2);
            } else {
                ans.push_back({st1, ed1});
                st1 = st2;
                ed1 = ed2;
            }
        }

        ans.push_back({st1, ed1});
        return ans;
    }
};
