class Solution {
public:
    typedef long long ll;
    int maxSubarraySumCircular(vector<int>& a) {
        ll maxsum = a[0];
        ll curr = a[0];
        ll minsum = a[0];
        ll currmin = a[0];
        ll totalsum = a[0];

        for(int i = 1; i < a.size();i++){
            curr= max((ll)a[i],curr+a[i]);
            maxsum = max((ll)maxsum,curr);

            currmin = min((ll)a[i],currmin+a[i]);
            minsum = min((ll)minsum,currmin);

            totalsum += a[i];
        }
        if(maxsum<0)
           return maxsum;

        int circularsum = (ll)(totalsum - minsum);

        return max((ll)circularsum,maxsum);
        
    }
};