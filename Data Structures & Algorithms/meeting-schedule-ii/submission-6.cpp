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
        vector<int> a,b;
        for(auto interval:intervals)
        {
            a.push_back(interval.start);
            b.push_back(interval.end);
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int n = a.size();
        int i = 1 , j = 0 , cnt = 1, ans = min(1,n);
        while(i<n && j<n)
        {
            if(a[i] < b[j])
            {
                cnt++;
                i++;
            }
            else 
            {
                cnt--;
                j++;
            }
            ans = max(ans,cnt);
        }
        return ans;
    }
};
