#include "testharness.h"
#include "prettyprint.h"
#include <bits/stdc++.h>
#include <thread>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BinaryTree {
public:
    // Encodes a tree to a single string.
    static string serialize(TreeNode* root) {
        ostringstream ss;
        serialize(root, ss);
        return ss.str();
    }
    static void serialize(TreeNode* root, ostringstream& ss) {
        if (!root) ss << "# ";
        else {
            ss << root->val << ' ';
            serialize(root->left, ss);
            serialize(root->right, ss);
        }
    }

    // Decodes your encoded data to tree.
    static TreeNode* deserialize(string data) {
        istringstream ss(data);
        return deserialize(ss);
    }
    
    static TreeNode* deserialize(istringstream& ss) {
        string s;
        ss >> s;
        if (s == "#") return 0;
        else {
            TreeNode* root = new TreeNode(stoi(s));
            root->left = deserialize(ss);
            root->right = deserialize(ss);
            return root;
        }
    }
};

class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() : endOfWord(false) {}
    map<char, unique_ptr<TrieNode>> children;
    bool endOfWord;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    Trie(string data) {
        root = deserialize(data);
    }
    virtual ~Trie() { delete root; }

    // Inserts a word into the trie.
    virtual void insert(string word) {
        TrieNode* node = root;
        for (auto c : word) {
            if (!node->children.count(c))
                node->children[c] = unique_ptr<TrieNode>(new TrieNode());
            node = node->children[c].get();
        }
        node->endOfWord = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) const {
        TrieNode* node = root;
        for (auto c : word) {
            if (!node->children.count(c)) return false;
            node = node->children[c].get();
        }
        return node->endOfWord;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (auto c : prefix) {
            node = node->children[c].get();
            if (!node) return false;
        }
        return true;
    }

    string serialize() { return serialize(root); }

    static string serialize(TrieNode* root) {
        string str;
        for (const auto &p : root->children) {
            str += '<';
            str += p.first;
            str += serialize(p.second.get());
            str += '>';
        }
        return str;
    }

    static TrieNode* deserialize(string data) {
        // Write your code here
        TrieNode* r = new TrieNode();
        stack<TrieNode*> s;
        s.push(r);
        int i=0;
        while (i < data.length()) {
            if (data[i] == '>') s.pop(), i++;
            else {
                if (data[i] == '<') i++;
                else s.pop();
                TrieNode* n = new TrieNode();
                s.top()->children[data[i++]] = unique_ptr<TrieNode>(n);
                s.push(n);
            }
        }
        return r;
    }

    TrieNode* root;
};

class SuffixTree : public Trie
{
public:
    virtual void insert(string word) {
        for (auto i=0; i<word.length(); i++) {
            Trie::insert(word.substr(i));
        }
    }

    vector<string> searchSubstring(string word) {
        vector<string> res;
        searchSubstring(root, word, "", res);
        return res;
    }

private:
    void searchSubstring(TrieNode* node, string word, string str, vector<string>& strs) {
        if (!node) return;
        if (word.empty()) {
            if (node->endOfWord) strs.push_back(str);
            for (const auto& child : node->children) {
                searchSubstring(child.second.get(), word, str+child.first, strs);
            }
        } else {
            if (!node->children.count(word[0])) return;
            searchSubstring(node->children[word[0]].get(), word.substr(1), 
                            str+word[0], strs);
        }
    }
};