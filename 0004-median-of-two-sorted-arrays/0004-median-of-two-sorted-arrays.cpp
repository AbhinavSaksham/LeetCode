class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        vector<int> newarr;

        // Add nums1
        for (int i = 0; i < nums1.size(); i++) {
            newarr.push_back(nums1[i]);
        }
        // Add nums2
        for (int i = 0; i < nums2.size(); i++) {
            newarr.push_back(nums2[i]);
        }

        // Sort merged array
        sort(newarr.begin(), newarr.end());

        int n = newarr.size();

        // If odd length
        if (n % 2 != 0) {

            int mid = n / 2;
            return newarr[mid];
        }

        // If even length
        else {

            int mid1 = n / 2; //2nd mid value 
            int mid2 = mid1 - 1; 

            return (newarr[mid1] + newarr[mid2]) / 2.0;
        }
    }
};