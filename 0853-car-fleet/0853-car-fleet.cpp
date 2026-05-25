class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        //pos,speed [10,2 / 8,4 / 0,1 / 5,1 / 3,3]
        vector<pair<int, double>> cars; 
        int n = position.size();  

        for (int i = 0; i < n; i++) {
             //calculate time for each target time = (target-postion)/speed 
            double time = (double)(target - position[i]) / speed[i];  
            cars.push_back({position[i], time});// Store {position, time_to_reach}
        }

        sort(cars.begin(), cars.end()); //SORT WITH POSITION 

        int fleets = 0;
        double currentTime = 0;

        for (int i = n - 1; i >= 0; i--) { //// from right to left - right(finals of the race)

            double time = cars[i].second;

            // New fleet                    // 10,1         8,1    5.7  3,3.  0,12
            if (time > currentTime) {       // if (1 >0)    (1>1) (7>1) (3>7) (12>7)

                fleets++;                   //fleets = 1    NA.     2   NA      3
                currentTime = time;         //cuurtime = 1  NA      7   NA      12
            }
        }

        return fleets;
    }
};