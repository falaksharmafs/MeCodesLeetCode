class Solution {
public:
    typedef long long ll;

    bool ispossible(vector<int>& ranks, int cars,ll mid){
        ll carsFixed = 0;
        int n = ranks.size();
        for(int i = 0; i<n ; i++){
            carsFixed += sqrt(mid/ranks[i]);
        }

        return carsFixed >= cars;


    }
    long long repairCars(vector<int>& ranks, int cars) {

        int n = ranks.size();

        ll l = 1;
        int maxR = *max_element(begin(ranks),end(ranks));
        ll r = 1ll * maxR * cars * cars;

        ll result = INT_MAX;
        while(l <=r){
            ll mid = l + (r-l)/2;

            if(ispossible(ranks,cars,mid)==true){
                result = mid;
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        return result;
        
    }
};