class Solution {
public:

        vector<int> sortArray(vector<int>& nums) {  //call merge sort fn
        mergeSort(nums, 0, nums.size() - 1);
        return nums; //return sorted arr
    }

        void mergeSort(vector<int>& nums, int low, int high) { //divide the arr

        if (low >= high) {
            return;
        }
        int mid = low + (high - low) / 2;
        // Sort left half
        mergeSort(nums, low, mid);
        // Sort right half
        mergeSort(nums, mid + 1, high);
        // Merge sorted halves
        merge(nums, low, mid, high);
    }


    void merge(vector<int>& nums, int low, int mid, int high) { //merge the arr

        vector<int> temp;

        int left = low;
        int right = mid + 1;
        // Merge two sorted halves
        while (left <= mid && right <= high) {

            if (nums[left] <= nums[right]) {
                temp.push_back(nums[left]);
                left++;
            }
            else {
                temp.push_back(nums[right]);
                right++;
            }
        }

        // Remaining left half
        while (left <= mid) {
            temp.push_back(nums[left]);
            left++;
        }
        // Remaining right half
        while (right <= high) {
            temp.push_back(nums[right]);
            right++;
        }
        // Copy back to original array
        for (int i = low; i <= high; i++) {
            nums[i] = temp[i - low];
        }
    }
};