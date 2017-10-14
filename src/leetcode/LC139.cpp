// Word Break
#include "../../util/common.h"

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> visited(s.length()+1, false);
        visited[0] = true;
        for (int i=1; i<=s.length(); i++) {
            for (int j=i-1; j>=0; j--) {
                if (visited[j] && wordSet.count(s.substr(j, i-j))) {
                    visited[i] = true;
                    break;
                }
            }
        }
        return visited[s.length()];
    }
    bool bfs(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> visited(s.length(), false);
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            if (visited[i]) continue;
            if (i == s.length()) return true;
            for (int j=i+1; j<=s.length(); j++) {
                if (wordSet.count(s.substr(i, j-i))) q.push(j);
            }
            visited[i] = true;
        }
        return false;
    }
    bool usingTrie(string s, vector<string>& wordDict) {
        Trie trie;
        for (auto w : wordDict) trie.insert(w);
        typedef pair<TrieNode*, int> Node;
        unordered_map<TrieNode*, unordered_set<int>> visited;
        queue<Node> q;
        q.emplace(trie.root, 0);
        while (!q.empty()) {
            Node n = q.front();
            q.pop();
            if (visited.count(n.first) && visited[n.first].count(n.second)) continue;
            if (n.first->endOfWord) {
                if (n.second == s.length()) return true;
                q.emplace(trie.root, n.second);
            }
            if (n.first->children.count(s[n.second]))
                q.emplace(n.first->children[s[n.second]].get(), n.second+1);
            visited[n.first].insert(n.second);
        }
        return false;
    }
};
TEST(Solution, wordBreak)
{
    vector<string> dict({"leet", "code"});
    bool res = wordBreak("leetcode", dict);
    ASSERT_TRUE(res);

    dict.clear();
    res = wordBreak("a", dict);
    ASSERT_TRUE(!res);

    dict = {"aa"};
    res = wordBreak("a", dict);
    ASSERT_TRUE(!res);
}
int main()
{
    RunAllTests();
    return 0;
}