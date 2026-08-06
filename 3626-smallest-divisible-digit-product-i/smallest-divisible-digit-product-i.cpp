class Solution {
public:
    int smallestNumber(int n, int t) {

        while(true){
            vector<int>nums;
            int x =n;

            while(x>0){
                nums.push_back(x%10);
                x/=10;
            }

            int product = 1;
            
            for(int num :nums)
               product *= num;

        
            if(product%t==0)
              return n;   
            n++;  
        }
        
    }
};