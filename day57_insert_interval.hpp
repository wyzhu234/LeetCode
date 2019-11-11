#include "common.h"

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
{
    vector<vector<int>> res;
    int n = intervals.size();
    int cur = 0;
    while (cur < n && intervals[cur][1] < newInterval[0])
    {
        res.push_back(intervals[cur]);
        ++cur;
    }
    
    while (cur < n && intervals[cur][0] <= newInterval[1])
    {
        newInterval[0] = min(newInterval[0], intervals[cur][0]);
        newInterval[1] = max(newInterval[1], intervals[cur][1]);
        ++cur;
    }

    res.push_back(newInterval);
    while (cur < n)
    {
        res.push_back(intervals[cur]);
        ++cur;
    }

    return res;
}

void test_day57()
{
    vector<vector<int>> intervals = { { 8,10 },{ 12,16 },{1,2},{3,5},{6,7} };
    sort(intervals.begin(), intervals.end());

}