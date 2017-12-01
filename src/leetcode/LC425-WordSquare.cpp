#include "../../util/common.h"

class Solution {
public:
    struct TrieNode {
        vector<TrieNode*> children;
        
        void insert(string word) {
            if (word.empty()) return;
            if (children.empty()) children.resize(26, 0);
            if (! children[word[0]-'a'])
                children[word[0]-'a'] = new TrieNode();
            children[word[0]-'a']->insert(word.substr(1));
        }
        
        void find(string prefix, string& prepend, vector<string>& words) {
            if (children.empty()) words.push_back(prepend);
            else if (prefix.empty()) {
                for (int i=0; i<children.size(); i++) {
                    if (children[i]) {
                        prepend += 'a'+i;
                        children[i]->find("", prepend, words);
                        prepend.pop_back();
                    }
                }
            } else if (children[prefix[0]-'a']){
                prepend += prefix[0];
                children[prefix[0]-'a']->find(prefix.substr(1), prepend, words);
                prepend.pop_back();
            }
        }
    };
    vector<vector<string>> wordSquares(vector<string>& words) {
        TrieNode trie;
        for (auto w : words) trie.insert(w);
        vector<string> rows;
        vector<vector<string>> res;
        for (auto w : words) {
            rows.push_back(w);
            dfs(trie, rows, res);
            rows.pop_back();
        }
        return res;
    }
    void dfs(TrieNode& trie, vector<string>& rows, vector<vector<string>>& res) {
        if (rows.size() == rows[0].size()) res.push_back(rows);
        else {
            string prefix, str;
            for (auto w : rows) prefix += w[rows.size()];
            vector<string> candidates;
            trie.find(prefix, str, candidates);
            for (auto w : candidates) {
                rows.push_back(w);
                dfs(trie, rows, res);
                rows.pop_back();
            }
        }
    }
};

int main()
{
    Solution sol;
    vector<string> words({"abat","baba","atan","atal"});
    vector<vector<string>> res = sol.wordSquares(words);
    cout<<"how many found "<<res.size()<<endl;
    return 0;
}

