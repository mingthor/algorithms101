#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct TrieNode {
        TrieNode() : children(26), endOfWord(false) {}
        vector<shared_ptr<TrieNode>> children;
        bool endOfWord;
    };

    string replaceWords(vector<string>& dict, string sentence) {
        // build trie
        shared_ptr<TrieNode> root = make_shared<TrieNode>();
        for (auto w : dict) {
            shared_ptr<TrieNode> current = root;
            for (auto c : w) {
                if (current->endOfWord) continue;
                if (!current->children[c-'a'])
                    current->children[c-'a'] = make_shared<TrieNode>();
                current = current->children[c-'a'];
            }
            current->endOfWord = true;
        }

        string res;
        shared_ptr<TrieNode> current = root;
        for (uint i=0; i<sentence.length(); i++) {
            if (sentence[i] == ' ') current = root; 
            else if (current && current->endOfWord) continue;
            else if (current) current = current->children[sentence[i]-'a'];
            res += sentence[i];
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<string> dict({"cat", "bat", "rat"});
    string sentence = "cattle was rattled by the battery";
    string res = sol.replaceWords(dict, sentence);
    cout<<res<<endl;
    return 0;
}
