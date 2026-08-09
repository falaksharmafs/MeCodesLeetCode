class Solution {
public:
    typedef long long ll;

    bool ispossible(vector<int>& time, int totalTrips,ll givenTime){

        ll actualTrips = 0;
        for(int &t : time){
            actualTrips += givenTime/t;
        }

        return actualTrips>= totalTrips;

    }

    long long minimumTime(vector<int>& time, int totalTrips) {
        int n = time.size();

        ll l = 1;
        ll r =  (ll)*min_element(begin(time),end(time)) * totalTrips;

        while(l < r){

            ll mid = l + (r-l)/2;

            if(ispossible(time,totalTrips,mid)){
                r = mid;
            }else{
                l = mid+1;

            }
        }
        return l;
    }
};