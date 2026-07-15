class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end());

        int ans = 0;
        int prevEnd = intervals[0][1]; //2

        for (int i = 1; i < intervals.size(); i++) {

            // Overlap
            if (intervals[i][0] < prevEnd) { //2 <  2, 3<3, 1< 4

                ans++; //1

                // Keep interval with smaller end
                prevEnd = min(prevEnd, intervals[i][1]); //1
            }

            // No overlap
            else {

                prevEnd = intervals[i][1]; //3 , 4 
            }
        }

        return ans; //1
    }
};