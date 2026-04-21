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
#include<bits/stdc++.h>
class Solution {
public:
    static bool cmp(const Interval &a,const Interval &b)
    {
        return a.start<b.start;
    }
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        int end=-1;
        for(int i=0;i<intervals.size();i++)
        {
           if(end==-1)
           {
             end=intervals[i].end;
           }
           else if(end>intervals[i].start) return false;
           else end=max(end,intervals[i].end);
        }
        return true;
    }

};
