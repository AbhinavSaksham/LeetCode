class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {

        vector<int> ans;

        for (int i = 0; i < words.size(); i++) {

            // Check if current word contains x
            for (char ch : words[i]) {

                if (ch == x) {
                    ans.push_back(i);  // store index
                    break;             // avoid adding same index twice
                }
            }
        }

        return ans;
    }
};