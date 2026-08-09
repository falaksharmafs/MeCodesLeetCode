class Solution {
public:

    bool check(string &s, string &p,
               vector<int>& removable, int k) {

        vector<bool> removed(s.size(), false);

        for(int i = 0; i < k; i++) {
            removed[removable[i]] = true;
        }

        int j = 0;

        for(int i = 0; i < s.size(); i++) {

            if(removed[i])
                continue;

            if(j < p.size() && s[i] == p[j]) {
                j++;
            }

            if(j == p.size())
                return true;
        }

        return false;
    }

    int maximumRemovals(string s, string p,
                        vector<int>& removable) {

        int l = 0;
        int r = removable.size();

        int ans = 0;

        while(l <= r) {

            int mid = l + (r - l) / 2;

            if(check(s, p, removable, mid)) {

                ans = mid;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }

        return ans;
    }
};