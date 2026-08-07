class Solution {
public:
    bool isposs(vector<vector<int>>& tasks,int mid){
        for(auto &task : tasks){
            int actual = task[0];
            int minn = task[1];

            if(minn > mid){
                return false;
            }
            mid -=actual;
        }
        return true;
    }
    int minimumEffort(vector<vector<int>>& tasks) {

        int n = tasks.size();
        int l = 0;
        int r = 1e9;

        int result = INT_MAX;

        auto lamda = [](auto &task1,auto &task2){
            int diff1 = task1[1]-task1[0];
            int diff2 = task2[1]-task2[0];
            return diff1 > diff2;
        };

        sort(begin(tasks),end(tasks),lamda);

        while(l<=r){
            int mid = l + (r-l)/2;

            if(isposs(tasks,mid)){
                result = mid;
                r=mid-1;
            }else{
                l = mid+1;
            }
        }
        return result;
        
    }
};