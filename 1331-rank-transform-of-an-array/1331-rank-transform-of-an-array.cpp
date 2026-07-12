class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {

        vector<int> temp = arr;

        sort(temp.begin(), temp.end()); //sort temp array
        unordered_map<int, int> rank;
        int count = 1;

        for (int i = 0; i < temp.size(); i++) { // Assign rank to unique elements

            if (rank.count(temp[i]) == 0) {
                rank[temp[i]] = count;
                count++;
            }
        }
        
        for (int i = 0; i < arr.size(); i++) {  // Replace elements with their rank
            arr[i] = rank[arr[i]];
        }

        return arr;
    }
};