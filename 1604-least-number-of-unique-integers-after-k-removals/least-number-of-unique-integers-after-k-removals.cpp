class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {

        unordered_map<int,int>mp;

        for(int x : arr){
            mp[x]++;
        }

        vector<int>freq;

        for(auto & x: mp){
            freq.push_back(x.second);
        }

        sort(begin(freq),end(freq));

        int ans = freq.size();

        for(int x : freq){
            if(x <= k){
                k-=x;
                ans--;
            }
            else{
                break;
            }
        }
        return ans;
    }
};