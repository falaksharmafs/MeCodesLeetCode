class Solution {
public:
    int t[501][501];

    int solve(vector<int>& piles, int i, int j) {

        if (i > j)
            return 0;

        if (t[i][j] != -1)
            return t[i][j];

        int takei = piles[i] +
                    min(solve(piles, i + 2, j),
                        solve(piles, i + 1, j - 1));

        int takej = piles[j] +
                    min(solve(piles, i, j - 2),
                        solve(piles, i + 1, j - 1));

        return t[i][j] = max(takei, takej);
    }

    bool stoneGame(vector<int>& piles) {

        memset(t, -1, sizeof(t));

        int sum = accumulate(piles.begin(), piles.end(), 0);

        int alice = solve(piles, 0, piles.size() - 1);

        return alice > sum / 2;
    }
};