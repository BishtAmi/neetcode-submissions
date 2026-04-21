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
        vector<int> start,end;
        for(auto x:intervals)
        {
            start.push_back(x.start);
            end.push_back(x.end);
        }
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        int i=1,j=0,n=start.size(),ans=0,cnt=1;
        ans=n>=1?1:0;
        while(i<n&&j<n)
        {
            //cout<<i<<" "<<j<<"\n";
            if(start[i]<end[j])
            {
                cnt++;
                i++;
            }
            else 
            {
                j++;
                cnt--;
            }
            ans=max(ans,cnt);
        } 
       return ans;
    }
};
