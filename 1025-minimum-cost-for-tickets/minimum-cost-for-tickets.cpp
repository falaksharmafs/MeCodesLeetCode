class Solution {
public:
    int t[366];
    int solve(int i,vector<int>& days, vector<int>& costs){
        if(i>=days.size()){
            return 0;
        }
        if(t[i] != -1){
            return t[i];
        }
        int one = costs[0]+solve(i+1,days,costs);
        
        int j = i;
        while(j< days.size() && days[j] <= days[i]+6){
            j++;
        }
        int seven = costs[1]+solve(j,days,costs);

        int k = i;
        while(k< days.size() && days[k] <= days[i]+29){
            k++;
        }
        int thirty = costs[2]+solve(k,days,costs);

        return t[i] = min({thirty,seven,one});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {

        memset(t,-1,sizeof(t));
        return solve(0,days,costs);
        
    }
};