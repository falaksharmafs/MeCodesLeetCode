class Solution {
public:
    typedef pair<int,int> P;
    string longestDiverseString(int a, int b, int c) {
        priority_queue<P,vector<P>>pq;

        if(a>0){
            pq.push({a,'a'});

        }
        if(b>0){
            pq.push({b,'b'});
        }

        if(c>0){
            pq.push({c,'c'});
        }

        string result = "";

        while(!pq.empty()){
            int currcount = pq.top().first;
            int currchar = pq.top().second;
            pq.pop();

            if(result.length() >=2 && result[result.length()-1]==currchar && result[result.length()-2]==currchar){
                if(pq.empty()){
                    break;
                }
                int nextcount = pq.top().first;
                int nextchar = pq.top().second;
                pq.pop();

                result.push_back(nextchar);
                nextcount--;
                if(nextcount>0){
                    pq.push({nextcount,nextchar});
                }
            } else{
                result.push_back(currchar);
                currcount--;
            }

            if(currcount>0){
                pq.push({currcount,currchar});
            }
        }

        return result;

        
    }
};