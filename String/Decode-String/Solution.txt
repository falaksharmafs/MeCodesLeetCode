class Solution {
public:
    string decodeString(string s) {
        stack<string>st;
        
        for(char ch : s){
            if(isdigit(ch)){
                st.push(string(1,ch));
            }else if(ch == '['){
                st.push("[");
            }else if(ch == ']'){
                
                string current = "";
                while(st.top()!="["){
                    current = st.top()+current;
                    st.pop();
                }
                st.pop();
                string num = "";
                while(!st.empty()&&isdigit(st.top()[0])){
                    num = st.top()+num;
                    st.pop();
                }
                int count = stoi(num);
                string decoded = "";

                for(int i = 0; i<count;i++){
                    decoded += current;
                }
                st.push(decoded);

            }else{
                st.push(string(1,ch));
            }
        }
        string answer = "";
        while(!st.empty()){
            answer = st.top()+answer;
            st.pop();
        }
        return answer;
        
    }
};