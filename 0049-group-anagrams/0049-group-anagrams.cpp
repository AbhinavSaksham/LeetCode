
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> output; //stores final string
        unordered_map<string, vector<string>> mp;  //sorted str and list 

        for (auto s : strs)
        { 
            string temp = s;
            sort(s.begin(), s.end());
            mp[s].push_back(temp);
        }
        for (auto &vec : mp){
            output.push_back(vec.second);
        }
        return output;
    }
};