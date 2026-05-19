// #include <vector>
// #include <deque>
// using namespace std;
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;   // stores indices --it always keep max element at front-VVVIP
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) { //TRAVERS the arr

            // Remove indices outside the current window
            while (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // Remove smaller elements from the back
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();  //useless hai smaller values 
            }

            // Add current index
            dq.push_back(i); 

            // Start adding answers once window size becomes k
            if (i >= k - 1) {
                ans.push_back(nums[dq.front()]);  //final ans me store hogi value
            }
        }

        return ans;
    }
};

//---------TLE Code Here -----------

// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {

//         vector<int> ans;

//         for (int i = 0; i <= nums.size() - k; i++) {

//             int maxi = nums[i];

//             for (int j = i; j < i + k; j++) {

//                 maxi = max(maxi, nums[j]);
//             }

//             ans.push_back(maxi);
//         }

//         return ans;
//     }
// };
