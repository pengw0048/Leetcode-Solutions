class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> ret;
        int i=0;
        while(i<intervals.size()&&intervals[i].end<newInterval.start)
            ret.push_back(intervals[i++]);
        if(i<intervals.size()&&intervals[i].start<newInterval.start)
            newInterval.start=intervals[i].start;
        while(i<intervals.size()&&intervals[i].start<=newInterval.end){
            newInterval.end=max(newInterval.end,intervals[i].end);
            i++;
        }
        ret.push_back(newInterval);
        for(;i<intervals.size();i++)ret.push_back(intervals[i]);
        return ret;
    }
};