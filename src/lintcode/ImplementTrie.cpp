#include "../../util/common.h"

int main()
{
    Trie trie;
    trie.insert("lintcode");
    trie.insert("leetcode");
    bool res1 = trie.search("lint");
    bool res2 = trie.startsWith("lint");
    cout<<"res1="<<res1<<", res2="<<res2<<endl;
    string str = trie.serialize();
    cout<<"str = "<<str<<endl;

    Trie trie2("<a<b<e>><c><d<f>>>");
    string str2 = trie2.serialize();
    cout<<"str2 = "<<str2<<endl;
    return 0;
}