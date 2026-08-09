class Solution {
public:
    typedef long long ll;
    int mySqrt(int n) {

        if(n < 2) return n;

        ll l = 1;
        ll r = n;
        ll result = 1;

        while(l <= r){
            ll mid = l + (r-l)/2;

            if(mid*mid <= n){
                result = mid;
                l = mid+1;
            }else{
                r = mid-1;
            }
        }

        return result;

    }
};