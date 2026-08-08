class Solution {
public:
    string longestDiverseString(int a, int b, int c) {

        string ans = "";

        while (a > 0 || b > 0 || c > 0) {

            if (a >= b && a >= c) {

                if (ans.size() < 2 || !(ans.back() == 'a' && ans[ans.size()-2] == 'a')) {

                    ans += 'a';
                    a--;

                    if (a > 0) {
                        ans += 'a';
                        a--;
                    }
                }

                else {
                    if (b >= c && b > 0) {
                        ans += 'b';
                        b--;
                    }
                    else if (c > 0) {
                        ans += 'c';
                        c--;
                    }
                    else {
                        break;
                    }
                }
            }

            else if (b >= a && b >= c) {

                if (ans.size() < 2 || !(ans.back() == 'b' && ans[ans.size()-2] == 'b')) {

                    ans += 'b';
                    b--;

                    if (b > 0) {
                        ans += 'b';
                        b--;
                    }
                }

                else {
                    if (a >= c && a > 0) {
                        ans += 'a';
                        a--;
                    }
                    else if (c > 0) {
                        ans += 'c';
                        c--;
                    }
                    else {
                        break;
                    }
                }
            }

            else {

                if (ans.size() < 2 || !(ans.back() == 'c' && ans[ans.size()-2] == 'c')) {

                    ans += 'c';
                    c--;

                    if (c > 0) {
                        ans += 'c';
                        c--;
                    }
                }

                else {
                    if (a >= b && a > 0) {
                        ans += 'a';
                        a--;
                    }
                    else if (b > 0) {
                        ans += 'b';
                        b--;
                    }
                    else {
                        break;
                    }
                }
            }
        }

        return ans;
    }
};