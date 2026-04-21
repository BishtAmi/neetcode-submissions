/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(),intervals.end(),[](Interval a,Interval b)
        {
            return a.start < b.start;
        });
        map<int,int> mp;
        for(auto interval:intervals)
        {
            mp[interval.start]++;
            mp[interval.end]--;
        }
        int sum  = 0 , ans =0;
        for(auto [key,val]:mp)
        {
            sum += val;
            ans = max(ans,sum);
        }
        return ans;
    }
};
/*
0 - 1                    1 + 1 - 1 + 1 -1 -1
40 - -1
5 - 1
10 - -1
15 - 1
20 - -1
*/
