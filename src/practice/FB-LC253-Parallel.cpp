
// Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};


#include "../../util/common.h"
#include <thread>

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        map<int, int> timeMap;
        for (auto i : intervals) {
            timeMap[i.start]++;
            timeMap[i.end]--;
        }
        int res = 0, sum = 0;
        for (auto p : timeMap) {
            sum += p.second;
            res = max(res, sum);
        }
        return res;
    }
};

vector<pair<int, bool>> events;
int N = 2;
vector<int> sum(N, 0), room(N, 0);

void helper(int id, int offset, int sz) {
    for (int i=0; i<sz; i++) {
        if (events[offset+i].second) sum[id]++;
        else sum[id]--;
        room[id] = max(room[id], sum[id]);
    }
}

int minMeetingRoomsMT(vector<Interval>& intervals) {
    for (auto i : intervals) {
        events.push_back(make_pair(i.start, true));
        events.push_back(make_pair(i.end, false));
    }
    sort(events.begin(), events.end());
    vector<thread> thds;
    int sz = events.size() / N;
    for (int i=0; i<N; i++) {
        thds.push_back(thread(helper, i, i * sz, sz));
    }
    cout<<"waiting for completion"<<endl;
    for (int i=0; i<N; i++) thds[i].join();
    cout<<sum<<endl;
    cout<<room<<endl;

    int res = room[0];
    for (int i=1; i<N; i++) {
        res = max(res, room[i]+sum[i-1]);
        sum[i] += sum[i-1];
    }
    return res;
}

int main()
{
    vector<Interval> intervals({{0,30},{1,3},{5,10},{13,21},{15,20}});
    int res = minMeetingRoomsMT(intervals);
    cout<<"result is "<<res <<endl;
    return 0;
}