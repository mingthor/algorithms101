//! Google Phone Interview
//! 题目是模拟投票的记录板。每一张选票有投票的日期和候选人的ID。要求实现三个methods
//! 1）给选票的array和一个时间t，问截至到t为止（t之后的选票先不管），谁得票最多。
//! 2）给选票的array和一个时间t还有人数x，问截至到t为止（t之后的选票先不管），得票最多的x个人是谁
//! 3）给选票的array和候选人id的array，问有没有一个时间，得票最多的候选人和给定的候选人的array是一致的，人头对上就行，不考虑先后顺序
#include "../../util/common.h"

struct Ballot {
    int time;
    int id;
};

class BallotBulletin
{
public:
    int getTopCandidate(vector<Ballot> ballots, int t) {
        int res = -1;
        unordered_map<int, int> votingMap;
        for (auto item : ballots) {
            if (item.time <= t) {
                votingMap[item.id]++;
                if (res == -1 || votingMap[item.id] > votingMap[res])
                res = item.id;
            }
        }
        return res;
    }

    //! get top x candidates up to t time point
    vector<int> getTopCandidates(vector<Ballot> ballots, int t, int x) {
        unordered_map<int, int> voteMap;
        for (auto b : ballots) {
            if (b.time <= t) voteMap[b.id]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (auto p : voteMap) {
            pq.emplace(p.second, p.first);
            if (pq.size() > x) pq.pop();
        }
        vector<int> res;
        while (!pq.empty()) {
            res.push_back(pq.top().first);
            pq.pop();
        }
        return res;
    }

    //! whether there is a time point that top candidates match our guess
    bool matchTopCandidates(vector<Ballot> ballots, vector<int> guess) {
        map<int, unordered_map<int, int>> timeTopMap;
        for (auto b : ballots) timeTopMap[b.time][b.id]++;
        unordered_map<int, int> statsMap;
        for (auto m : timeTopMap) {
            for (auto p : m.second) {
                statsMap[p.first] += p.second;
            }
            unordered_map<int, bool> matchMap;
            for (auto g : guess) matchMap[g] = true;
            int mismatch = guess.size();

            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> topk;
            for (auto p : statsMap) {
                if (topk.empty() || p.second >= topk.top().first) {
                    topk.emplace(p.second, p.first);
                    if (matchMap.count(p.first)) {
                        matchMap[p.first] = false;
                        mismatch--;
                    }
                }
                if (topk.size() > guess.size()) {
                    auto b = topk.top();
                    topk.pop();
                    if (matchMap.count(b.second)) {
                        matchMap[p.second] = true;
                        mismatch++;
                    }
                }
                if (mismatch == 0) return true;
            }
        }
        return false;
    }
};

int main()
{
    RunAllTests();
    return 0;
}