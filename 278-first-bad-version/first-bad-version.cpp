// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:

    typedef long long ll;
    int firstBadVersion(int n) {

        ll l =1;
        ll r = n;
        while(l<r){
            ll mid = l + (r-l)/2;
            if(isBadVersion(mid)){
                r = mid;
            }else{
                l = mid+1;
            }
        }
        return l;
    }
};