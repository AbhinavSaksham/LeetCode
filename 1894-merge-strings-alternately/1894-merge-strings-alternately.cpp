class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string merged_string;
        int i = 0, j = 0;
        
        while (i < word1.length() || j < word2.length()) {
            if (i < word1.length()) {
                merged_string += word1[i];
                i++;
            }
            
            if (j < word2.length()) {
                merged_string += word2[j];
                j++;
            }
        }
        
        return merged_string;
    }
};
