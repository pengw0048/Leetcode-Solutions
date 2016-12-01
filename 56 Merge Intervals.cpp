class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> ret;
        if(intervals.size()==0)return ret;
        sort(intervals.begin(),intervals.end(),[] (const Interval& lhs, const Interval& rhs) {
            return lhs.start < rhs.start;
        });
        int start=intervals[0].start,end=intervals[0].end;
        for(int i=1;i<intervals.size();i++){
            if(end<intervals[i].start){
                ret.push_back(Interval(start,end));
                start=intervals[i].start;
                end=intervals[i].end;
            }else{
                end=max(end,intervals[i].end);
            }
        }
        ret.push_back(Interval(start,end));
        return ret;
    }
};