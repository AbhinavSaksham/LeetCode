class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {

        //priority_queue<pair<int,int>, greater<int>> pq;
        //priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        priority_queue<pair<int,int>> pq;

        for (int i = 0; i < arr.size(); i++)
        {
            
            pq.push({abs(arr[i] - x), arr[i]});

            if (pq.size() > k){
            pq.pop();  // 1,2,3,4 ||| 5
            }
        }

        vector<int> ans;

        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};

//[3-1, 3-2, 3-3, 3-4, 3-5, 3-6]
//[2,1,0,1,2, 3]
//[(1,2) , (2,1), (3,0) , (4,1), (5,2)]