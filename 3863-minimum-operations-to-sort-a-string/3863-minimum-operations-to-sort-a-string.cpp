class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        // Already sorted
        if(is_sorted(s.begin(), s.end()))
            return 0;

        // No proper substring can change the order of two characters
        if(n == 2)
            return -1;

        char mn = *min_element(s.begin(), s.end());
        char mx = *max_element(s.begin(), s.end());

        // One operation is enough if an endpoint is already correct
        if(s[0] == mn || s[n - 1] == mx)
            return 1;

        // Three operations are needed when both extremes are unique
        // and are at the wrong ends
        if(s[0] == mx && s[n - 1] == mn) {
            int minCount = count(s.begin(), s.end(), mn);
            int maxCount = count(s.begin(), s.end(), mx);

            if(minCount == 1 && maxCount == 1)
                return 3;
        }

        return 2;
    }
};