class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {

        int m = flowers.size();
        int n = people.size();

        vector<int> start(m);
        vector<int> ends(m);

        for(int i = 0; i < m ; i++){
            start[i]=flowers[i][0];
            ends[i]=flowers[i][1];
        }

        sort(begin(start),end(start));
        sort(begin(ends),end(ends));

        vector<int>result(n);

        for(int i = 0; i <n ; i++){
            int time = people[i];
            

            int bloomed =upper_bound(begin(start),end(start),time) - begin(start);
            int died = lower_bound(begin(ends),end(ends),time)- begin(ends);

            result[i]= bloomed-died;
        }

        return result;

        
    }
};