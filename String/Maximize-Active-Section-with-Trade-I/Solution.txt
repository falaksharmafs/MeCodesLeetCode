class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
         int n = s.length();

         int activecount = count(begin(s),end(s),'1');

         vector<int> inactive;

         int i =0;
         while(i < n){
            if(s[i]=='0'){
                int start = i;

                while(i <n && s[i]== '0'){
                    i++;
                }

                inactive.push_back(i - start);
            }else{
                i++;
            }
         }

         int maxpair = 0;

         for(int i = 1; i<inactive.size() ;i++){

            maxpair = max(maxpair, inactive[i]+inactive[i-1]);

            

        }
        return maxpair+activecount;
    }
};