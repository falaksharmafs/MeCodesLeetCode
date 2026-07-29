class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {

        unordered_set<string> st(begin(folder),end(folder));
        vector<string>result;
        for(string &currFolder : folder){

            bool isSubfolder = false;
            string temp = currFolder;

            while(!currFolder.empty()){
                size_t position = currFolder.find_last_of('/');

                currFolder = currFolder.substr(0,position);

                if(st.find(currFolder) != st.end()){
                    isSubfolder = true;
                    break;
                }
            }

            if(!isSubfolder){
                result.push_back(temp);
            }
            
        }
        
        return result;
    }
};