class Solution {
public:
    typedef long long ll;

    ll findCost(vector<int>& nums, vector<int>& cost,int target){

        ll ans = 0;

        for(int i = 0; i < nums.size(); i++){

            ans += (ll) abs(nums[i]-target) * cost[i];
        }

        return ans;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        

        ll result = INT_MAX;

        int left = *min_element(begin(nums),end(nums));
        int right = *max_element(begin(nums),end(nums));

        while(left <= right){

            int mid = left + (right-left)/2;

            ll cost1 = findCost(nums, cost , mid);
            ll cost2 = findCost(nums,cost,mid+1);

            result = min(cost1,cost2);

            if(cost2>cost1){
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        return result == INT_MAX ? 0 : result;
    }
};