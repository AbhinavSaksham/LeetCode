class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        int slow = nums[0];
        int fast = nums[0];

        // Find meeting point
        do {

            slow = nums[slow];             // Move 1 step
            fast = nums[nums[fast]];       // Move 2 steps

        } while (slow != fast);

        // Move slow to beginning
        slow = nums[0];

        // Find duplicate
        while (slow != fast) {

            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};
// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {

//         unordered_map<int, int> freq;

//         for (int i = 0; i < nums.size(); i++) {

//             freq[nums[i]]++;

//             if (freq[nums[i]] > 1) {
//                 return nums[i];
//             }
//         }

//         return -1;
//     }
// };

// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
        
//         for (int i = 0; i < nums.size(); i++){

//             for (int j = i+1; j < nums.size(); j++){

//                 if (nums[i] == nums[j]){
//                 return nums[i];
//                 }
//             } 
//         }
//         return NULL;
//     }
// };