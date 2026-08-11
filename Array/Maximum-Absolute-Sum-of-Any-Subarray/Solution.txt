class Solution {
public:
    int maxAbsoluteSum(vector<int>& a) {

        int currmax = a[0];
        int maxsum = a[0];
        int currmin = a[0];
        int minsum = a[0];

        for(int i = 1; i < a.size();i++){

            currmax = max(a[i],currmax+a[i]);
            maxsum = max(currmax,maxsum);

            currmin = min(a[i],currmin+a[i]);
            minsum = min(minsum,currmin);
        }

        return max(maxsum , abs(minsum));
        
    }
};