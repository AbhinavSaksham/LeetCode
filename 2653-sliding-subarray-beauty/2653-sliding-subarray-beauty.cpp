class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {

        int i = 0;
        int j = 0;

        vector<int> v;

        multiset<int> l;

        while (j < nums.size()) {

            // store negative numbers
            if (nums[j] < 0) {
                l.insert(nums[j]);
            }

            if (j - i + 1 < k) { // find window size
                j++;
            }

            else if (j - i + 1 == k) { // window size

                if (l.size() < x)
                    v.push_back(0);

                else {

                    auto it = l.begin();

                    advance(it, x - 1);

                    v.push_back(*it);
                }

                // remove outgoing element
                if (nums[i] < 0) {
                    l.erase(l.find(nums[i]));
                }

                i++;
                j++;
            }
        }

        return v;
    }
};