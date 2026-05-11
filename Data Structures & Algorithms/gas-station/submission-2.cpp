class Solution {
   public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int maxi = INT_MIN, startIndex = 0;
        int n = gas.size();
        for (int i = 0; i < n; i++) {
            int curCost = cost[i] + cost[(i + 1) % n];
            int curGas = gas[i] + gas[(i + 1) % n];
            if(maxi <= curGas - curCost && cost[i] < gas[i])
            {
                maxi = curGas - curCost;
                startIndex = i;
            }
        }
        cout<<startIndex<<"\n";
        int tank = 0;
        for (int i = startIndex, j = 0; j < n; j++, i++) {
            tank += gas[i % n] - cost[i % n];
            if (tank < 0) return -1;
        }
        return startIndex;
    }
};
/*
 */