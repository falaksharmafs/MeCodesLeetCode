class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {

        int n = grid.size();
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));

        dist[0][0] = grid[0][0];

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;

        pq.push({grid[0][0],{0,0}});

        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};


        while(!pq.empty()){

            auto top = pq.top();

            pq.pop();

            int time = top.first;
            int r = top.second.first;
            int c = top.second.second;


            if(r==n-1 && c == n-1){
                return time;
            }

            
            //else we gonna explore all directions

            for(int k = 0; k < 4; k++){
                int nr = r+dr[k];
                int nc = c + dc[k];

                if(nr>=n || nr<0 ||nc>=n||nc<0){
                    continue;
                }

                int newTime = max(time,grid[nr][nc]);

                if(newTime < dist[nr][nc]){
                    dist[nr][nc]= newTime;
                    pq.push({newTime,{nr,nc}});
                }
            }
        }
        
        return -1;
    }
};