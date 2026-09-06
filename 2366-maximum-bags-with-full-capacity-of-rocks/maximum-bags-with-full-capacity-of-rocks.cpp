class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int ad) {

        int n = capacity.size();

        vector<int>diff(n);

        for(int i = 0; i < n ; i++){
            diff[i] = capacity[i]-rocks[i];
        }

        sort(begin(diff),end(diff));
        
        int ans = 0;

        for(int x : diff){
            if(x <= ad){
                ad -= x;
                ans++;
            }
            else{
                break;
            }
        }

        return ans;
    }
};