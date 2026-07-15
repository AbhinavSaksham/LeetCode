class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;

        //int i = 0;
        //int n = intervals.size();
        sort(intervals.begin(), intervals.end()); //nlogn
        ans.push_back(intervals[0]);

       for (int i = 1; i < intervals.size(); i++) { //0(n)

            // Overlap
            if (intervals[i][0] <= ans.back()[1]) {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }

            // No overlap
            else {

                ans.push_back(intervals[i]);
            }
       }
       return ans;
    }
};


// class Solution {
// public:
//     vector<vector<int>> merge(vector<vector<int>>& intervals) {

//         vector<vector<int>> ans;

//         // Sort intervals by starting point
//         sort(intervals.begin(), intervals.end());

//         // Put first interval in answer
//         ans.push_back(intervals[0]);

//         for(int i = 1; i < intervals.size(); i++) {

//             // Current interval
//             int start = intervals[i][0];
//             int end = intervals[i][1];

//             // Last interval in answer
//             int lastEnd = ans.back()[1];

//             // Overlapping intervals
//             if(start <= lastEnd) {

//                 ans.back()[1] =
//                 max(lastEnd, end);
//             }
//             else {

//                 // Non-overlapping
//                 ans.push_back(intervals[i]);
//             }
//         }

//         return ans;
//     }
// };