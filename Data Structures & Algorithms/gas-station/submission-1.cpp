class Solution {
   public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        
        for (int startIndex = 0; startIndex < n; startIndex++) {
            bool poss = true;
            int tank = 0;
            for (int i = startIndex, j = 0; j < n; j++, i++) {
                tank += gas[i % n] - cost[i % n];
                if (tank < 0) {
                    poss = false;
                    break;
                }
            }
            if (poss) return startIndex;
        }
        return -1;
    }
};
/*
 */