class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>last(26,0);
        vector<int>ans;
        int n = s.length();

        for(int i = 0; i < n ; i++){
            last[s[i]-'a']=i;
        }
        int start = 0;
        int end = 0;
        for(int i = 0; i < n ; i++){
            end = max(end,last[s[i]-'a']);


            if(i == end){
                ans.push_back(end-start+1);
                start = end+1;
            }
        }

        return ans;
    }
};