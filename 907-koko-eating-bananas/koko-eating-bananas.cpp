class Solution {
public:
    typedef long long ll;
    bool check(vector<int>&piles,int h , ll mid){

        ll minHours = 0 ;
        for(ll pile : piles){
            minHours += ceil((double)pile/mid);
        }
        return minHours<= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {

        ll l = 1;
        ll r = *max_element(piles.begin(),piles.end());

        ll ans = INT_MAX;

        

        while(l<=r){
            ll mid = l + (r-l)/2;
            if(check(piles,h,mid)){
               ans = mid;
               r = mid-1; 
           }else{
            l = mid+1;
           }
        }
        return ans;
    }
};