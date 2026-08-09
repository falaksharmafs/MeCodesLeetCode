class Solution {
public:
    typedef long long ll;
    bool isPerfectSquare(int num) {
        
        ll l = 1;
        ll r = num;
        while(l<=r){
            ll mid = l + (r-l)/2;

            if(mid*mid==num){
                return true;
            }else if(mid*mid < num){
                l = mid + 1;
            }else{
                r = mid-1;
            }
        }
        return 0;
    }
};