#include "../../util/common.h"

class Typeahead {
public:
    // @param dict: A dictionary of words dict
    Typeahead(unordered_set<string> &dict) {
        // do initialize if necessary
       for (auto phrase : dict) {
           stree.insert(phrase);
       }
    }
    
    // @param str: a string
    // @return a set of words
    vector<string> search(string &str) {
        return stree.searchSubstring(str);
    }
private:
    SuffixTree stree;
};

int main()
{
    unordered_set<string> dict({"dab", "cac"});
    Typeahead ta(dict);
    string word = "a";
    vector<string> res = ta.search(word);
    cout<<res<<endl;

    dict = {"Tree", "Binary Tree Sum"};
    Typeahead ta2(dict);
    string word2 = "Tree";
    vector<string> res2 = ta2.search(word2);
    cout<<res2<<endl;
    return 0;
}