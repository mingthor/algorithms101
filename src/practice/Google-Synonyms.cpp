// Google interview question
// 给一个 list， 每一个值是   一个 pair，比如 （'good', 'well'）,表示这两个词是同义词。
/**
给两个句子，问这两个句子是不是同义句，同义句的要求是对应位置的单词是同义词。
Follow up 1：
如果同义词是可以 传递的怎么办，比如 （a, b）, (b, c)， 那么 （a, c）也是同义词。
Follow up 2：
如果同义句的要求是 同义词的个数相同，不需要他们位置一样，怎么办？
*/
#include "../../util/common.h"

class SameMeaningSentence
{
public:
    // Follow up 1: using map & set
    bool sameMeaning1(const list<pair<string, string>> &synonyms, vector<string> sentence1, vector<string> sentence2) {
        unordered_map<string, set<string>> synmap;
        for (auto p : synonyms) {
            synmap[p.first].insert(p.second);
            synmap[p.second].insert(p.first);
        }
        if (sentence1.size() != sentence2.size()) return false;
        for (int i=0; i<sentence1.size(); i++) {
            if (synmap.count(sentence1[i]) == 0) return false;
            if (synmap[sentence1[i]].count(sentence2[i]) == 0) return false;
        }
        return true;
    }

    template <class T>
    class DisjointSet {
    public:
        void add(const T& val) {
            if (!parent.count(val)) {
                parent[val] = val;
                rank[val] = 0;
            }
        }
        T find(const T& val) {
            if (!parent.count(val)) return val;
            T root = parent[val];
            if (root != val)
                parent[val] = find(root);
            return root;
        }
        void merge(const T& x, const T& y) {
            T xroot = find(x);
            T yroot = find(y);
            if (rank[xroot] > rank[yroot])
                parent[yroot] = xroot;
            else if (rank[xroot] < rank[yroot])
                parent[xroot] = yroot;
            else {
                parent[xroot] = yroot;
                rank[yroot]++;
            }
        }

    private:
        unordered_map<T, T> parent;
        unordered_map<T, int> rank;
    };
    // Followup 2: union find. aka. disjoint set
    bool sameMeaning2(const list<pair<string, string>> &synonyms, vector<string> sentence1, vector<string> sentence2) {
        DisjointSet<string> ds;
        for (auto p : synonyms) {
            ds.add(p.first);
            ds.add(p.second);
            ds.merge(p.first, p.second);
        }
        unordered_map<string, int> rootCount;
        for (auto word : sentence1) {
            string root = ds.find(word);
            rootCount[root]++;
        }
        int res = 0;
        for (auto word : sentence2) {
            string root = ds.find(word);
            if (rootCount.count(root) && rootCount[root]) {
                res++;
                rootCount[root]--;
            }
        }
        return res;
    }
};

int main()
{
    
}