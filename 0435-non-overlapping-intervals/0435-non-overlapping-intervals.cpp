class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end());

        int ans = 0;
        int prevEnd = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {

            // Overlap
            if (intervals[i][0] < prevEnd) {

                ans++;

                // Keep interval with smaller end
                prevEnd = min(prevEnd, intervals[i][1]);
            }

            // No overlap
            else {

                prevEnd = intervals[i][1];
            }
        }

        return ans;
    }
};