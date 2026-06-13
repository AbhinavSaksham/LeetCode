class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        //vector<char, int> mp;
        string ans = "";

        for (int i = 0; i < words.size(); i++){

            int sum = 0;

            for(char ch : words[i]) { //get weight of curret word 

                sum += weights[ch - 'a'];
            }

            int mod = sum % 26; //get value for curr weight

            char curr = 'z' - mod; // map char from weight(mod)

            ans.push_back(curr);

        }

        return ans;
    }
};