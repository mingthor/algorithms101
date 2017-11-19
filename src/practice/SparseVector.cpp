
#include "../../util/common.h"

//! Facebook interview question, Dot product of sparse vector

template <typename T>
class SparseVector
{
public:
    SparseVector() {};
    SparseVector(const vector<T>& uncompressed) {
        for (int i=0; i<uncompressed.size(); i++) {
            if (uncompressed[i]) {
                values.push_back(uncompressed[i]);
                indices.push_back(i);
            }
        }
    }

    vector<T> toDense(int n) {
        vector<T> res;
        for (int i=0, j=0; i<n && j<n; i++) {
            if (i == indices[j]) res.push_back(values[j++]);
            else res.push_back(0);
        }
        return res;
    }

    void append(int idx, int val) { 
        values.push_back(val);
        indices.push_back(idx);
    };

    size_t nzsize() const { return values.size(); }

    SparseVector dotProduct(const SparseVector& other) { return dotProduct(*this, other); }

    static SparseVector dotProduct(const SparseVector& sv1, const SparseVector& sv2) {
        SparseVector res;
        int i=0, j=0;
        while (i < sv1.nzsize() && j < sv2.nzsize()) {
            if (sv1.indices[i] == sv2.indices[j]) {
                res.append(sv1.indices[i], sv1.values[i] * sv2.values[j]);
                i++;
                j++;
            } else if (sv1.indices[i] < sv2.indices[j]) i++;
            else j++;
        }
        return res;
    }

    bool operator==(const SparseVector& other) { 
        return values == other.values && indices == other.indices;
    }

private:
    vector<T> values;
    vector<T> indices;
};

TEST(SparseVector<int>, dotProduct)
{
    SparseVector<int> sv1({1,0,0,0,2,0});
    SparseVector<int> sv2({3,3,4,0,5,0});
    SparseVector<int> res = sv1.dotProduct(sv2);
    vector<int> expected ({3,0,0,0,10,0});
    ASSERT_EQ(res.toDense(6), expected);
}

int main()
{
    RunAllTests();
    return 0;
}