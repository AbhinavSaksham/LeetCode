class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        priority_queue<int, vector<int>, greater<int>> pq; //take priority queue

        for (int i = 0; i < nums.size(); i++) {

            pq.push(nums[i]);

            if (pq.size() > k) { //if queue size goes beyond k size, pop top
                pq.pop();
            }
        }

        return pq.top();
    }
};


// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {

//         sort(nums.begin(), nums.end());

//         return nums[nums.size() - k];
//     }
// };