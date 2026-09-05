class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
        
        if (n > 1 && m > 1 &&
            grid[0][1] > 1 && grid[1][0] > 1) {
            return -1;
        }

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        dist[0][0] = 0;

        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > pq;

        pq.push({0, {0, 0}});

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!pq.empty()) {

            auto top = pq.top();
            pq.pop();

            int time = top.first;
            int r = top.second.first;
            int c = top.second.second;

            if (r == n - 1 && c == m - 1) {
                return time;
            }

            for (int k = 0; k < 4; k++) {

                int nr = r + dr[k];
                int nc = c + dc[k];

         
                if (nr >= n || nr < 0 || nc >= m || nc < 0) {
                    continue;
                }

                int newTime = time + 1;

                if (newTime < grid[nr][nc]) {

                    int diff = grid[nr][nc] - time;

                    if (diff % 2 == 0) {
                        newTime = grid[nr][nc] + 1;
                    }
                    else {
                        newTime = grid[nr][nc];
                    }
                }
                if (newTime < dist[nr][nc]) {

                    dist[nr][nc] = newTime;

                    pq.push({newTime, {nr, nc}});
                }
            }
        }

        return -1;
    }
};