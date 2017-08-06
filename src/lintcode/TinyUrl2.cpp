#include "../../util/testharness.h"
#include <bits/stdc++.h>
using namespace std;

class TinyUrl2 {
public:
    TinyUrl2() { srand(time(0)); }
    /**
     * @param long_url a long url
     * @param a short key
     * @return a short url starts with http://tiny.url/
     */
     string createCustom(const string& long_url, const string& short_key) {
        // Write your code here
        if (s2lCustom.count(short_key))
            return (long_url == s2lCustom[short_key]) ? (domain+short_key) : "error";
        if (l2sCustom.count(long_url))
            return (short_key == l2sCustom[long_url]) ? (domain+short_key) : "error";
        s2lCustom[short_key] = long_url;
        l2sCustom[long_url] = short_key;
        return domain + short_key;
    }

    /**
     * @param long_url a long url
     * @return a short url starts with http://tiny.url/
     */
    string longToShort(const string& long_url) {
        // Write your code here
        if (l2sCustom.count(long_url)) return domain+l2sCustom[long_url];
        unsigned long id;
        if (url2id.count(long_url)) id = url2id[long_url];
        else {
            do { id = rand(); }
            while (id2url.count(id));
        }
        url2id[long_url] = id;
        id2url[id] = long_url;
        return domain + idToShort(id);
    }

    /**
     * @param short_url a short url starts with http://tiny.url/
     * @return a long url
     */
    string shortToLong(const string& short_url) {
        // Write your code here
        string short_key = short_url.substr(domain.length());
        if (s2lCustom.count(short_key)) return s2lCustom[short_key];
        unsigned long id = shortToId(short_key);
        if (id2url.count(id)) return id2url[id];
        return "error";
    }

    unsigned long shortToId(const string& url) {
        unsigned long id = 0;
        for (auto c : url) {
            id *= 62;
            if (c>='a' && c<='z') id += c-'a';
            else if (c>='A' && c<='Z') id += c-'A'+26;
            else id += c-'0'+52;
        }
        return id;
    }

    string idToShort(unsigned long id) {
        string url;
        for (int i=0; i<6; i++) {
            unsigned n = id % 62;
            if (n < 26) url += 'a'+n;
            else if (n < 52) url += 'A'+n-26;
            else url += '0'+n-52;
            id /= 62;
        }
        reverse(url.begin(), url.end());
        return url;
    }

private:
    unordered_map<string, unsigned long> url2id;
    unordered_map<unsigned long, string> id2url;
    unordered_map<string, string> l2sCustom;
    unordered_map<string, string> s2lCustom;
    const string domain="http://tiny.url/";
};

TEST(TinyUrl2, custom)
{
    string long_url = "http://www.leetcode.com";
    string res = createCustom(long_url, "lc");
    ASSERT_EQ(res, "http://tiny.url/lc");
    res = createCustom(long_url, "leetcode");
    ASSERT_EQ(res, "error");
    res = createCustom("http://www.google.com", "lc");
    ASSERT_EQ(res, "error");
    res = shortToLong("http://tiny.url/lc");
    ASSERT_EQ(res, "http://www.leetcode.com");
    res = longToShort("http://www.leetcode.com");
    ASSERT_EQ(res, "http://tiny.url/lc");
    ASSERT_EQ(shortToLong("http://tiny.url/lc"), "http://www.leetcode.com");
}

TEST(TinyUrl2, normal)
{
    string long_url = "http://www.google.com";
    string res = longToShort(long_url);
    ASSERT_EQ(res.length(), 22);
    res = shortToLong(res);
    ASSERT_EQ(res, "http://www.google.com");
    res = shortToLong("http://tiny.url/xxxxxx");
    ASSERT_EQ(res, "error");

    res = longToShort("http://www.facebook.com");
    ASSERT_EQ(res.length(), 22);
    res = shortToLong(res);
    ASSERT_EQ(res, "http://www.facebook.com");
}

TEST(TinyUrl2, corner)
{
    string res = createCustom("http://www.lintcode.com/p1", "000001");
    ASSERT_EQ(res, "http://tiny.url/000001");
    res = createCustom("http://www.lintcode.com/p2", "000002");
    ASSERT_EQ(res, "http://tiny.url/000002");
    res = createCustom("http://www.lintcode.com/p3", "000003");
    ASSERT_EQ(res, "http://tiny.url/000003");
    res = createCustom("http://www.lintcode.com/p4", "000004");
    ASSERT_EQ(res, "http://tiny.url/000004");
    res = longToShort("http://www.lintcode.com/problem/");
    res = shortToLong("http://tiny.url/000002");
    ASSERT_EQ(res, "http://www.lintcode.com/p2");
    res = shortToLong("http://tiny.url/000004");
    res = createCustom("http://www.facebook.com", "facebook");
    ASSERT_EQ(res, "http://tiny.url/facebook");
    res = createCustom("http://www.facebook.com", "facebook");
    ASSERT_EQ(res, "http://tiny.url/facebook");
    res = createCustom("http://www.google.com", "google");
    ASSERT_EQ(res, "http://tiny.url/google");
    res = createCustom("http://www.lintcode.com", "lc");
    ASSERT_EQ(res, "http://tiny.url/lc");
    res = shortToLong("http://tiny.url/lc");
    ASSERT_EQ(res, "http://www.lintcode.com");
    res = shortToLong("http://tiny.url/google");
    ASSERT_EQ(res, "http://www.google.com");
    res = createCustom("http://www.google.com", "google");
    ASSERT_EQ(res, "http://tiny.url/google");
    res = shortToLong("http://tiny.url/facebook");
    ASSERT_EQ(res, "http://www.facebook.com");
    res = longToShort("http://www.lintcode.com");
    res = longToShort("http://www.google.com");
    res = longToShort("http://www.facebook.com");
}

int main()
{
    RunAllTests();
    return 0;
}