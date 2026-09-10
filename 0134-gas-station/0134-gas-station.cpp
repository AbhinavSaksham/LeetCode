class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int totalGas = 0;
        int totalCost = 0;

        int tank = 0;
        int start = 0;

        for(int i = 0; i < gas.size(); i++) {

            // Check if total gas is enough for the complete circuit
            totalGas += gas[i];
            totalCost += cost[i];

            // Gas gained/lost at current station
            tank += gas[i] - cost[i];

            // Cannot reach next station, so start from next station
            if(tank < 0) {
                start = i + 1;
                tank = 0;
            }
        }

        if(totalGas < totalCost) //Base case -  not possible 
            return -1;

        return start;
    }
};