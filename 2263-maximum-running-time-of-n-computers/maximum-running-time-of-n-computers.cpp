class Solution {
public:
    typedef long long ll;
    bool check(int n, vector<int>& batteries,ll mid){

        ll total = 0;
        for(ll battery : batteries){
            total += min(mid,battery);
        }
        return total >= mid * n;
    }
    long long maxRunTime(int n, vector<int>& batteries) {

        ll totalBattery = 0;
        for(ll battery : batteries){
            totalBattery += battery;
        }
        ll l = 0;
        ll r = totalBattery/n;

        ll ans = 0;

        while(l <= r){
            ll mid = l + (r-l)/2;
            if(check(n,batteries,mid)){
                ans = mid;
                l = mid+1;
            }else{
                r = mid-1;
            }
        }

        return ans;
    }
};