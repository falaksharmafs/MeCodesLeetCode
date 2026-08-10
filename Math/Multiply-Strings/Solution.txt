class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0"||num2=="0")
          return "0";
        int m = num1.size();
        int n = num2.size();

        vector<int>result(m+n,0);

        for(int i = m-1; i >=0;i--){
            for(int j = n-1;j>=0;j--){

                int a= num1[i]-'0';
                int b = num2[j]-'0';

                int mult = a * b;

                int pos = i+j+1;

                int sum = mult + result[pos];

                result[pos]= sum % 10;
                result[pos-1]+=sum/10;

            }
        }  

        string answer;

        for(int digit : result){
            if(answer.empty()&&digit == 0)
             continue;
            answer +=char(digit + '0'); 

        }
        return answer;
        
    }
};