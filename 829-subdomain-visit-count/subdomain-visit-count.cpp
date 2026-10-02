class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string,int>mp;

        for(string s : cpdomains){
            int space = s.find(' ');
            int count = stoi(s.substr(0,space));
            string domain = s.substr(space+1);

            while(true){
              mp[domain] += count;

              int dot = domain.find('.');

              if(dot == string::npos)
                 break;

              domain = domain.substr(dot+1);

            }
        }

        vector<string>ans;

        for(auto it : mp){
            ans.push_back(to_string(it.second)+" "+it.first);
        }

        return ans;
    }
};