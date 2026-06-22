class Solution {
public:
    int maxNumberOfBalloons(string text) {

        vector<int> freq(26, 0);

        // Count frequency of every character from input string
        for(char ch : text) {
            freq[ch - 'a']++;
        }

        return min({ // Calculate how many "balloon" words can be formed 
                        //min will sort the minimum balloons which can be formed
            freq['b' - 'a'],
            freq['a' - 'a'],
            freq['l' - 'a'] / 2,
            freq['o' - 'a'] / 2,
            freq['n' - 'a']
        });
    }
};