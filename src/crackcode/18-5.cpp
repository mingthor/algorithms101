#include "../../util/common.h"
//! design a mechanism to make sure A -> B -> C are executed in order

mutex mtx;
condition_variable cv;
int which = 0;

class Foo {
public:
    void bar(int id) {
        ths.emplace_back(&Foo::print, this, id);
    }

    void print(int id) {
        unique_lock<mutex> lk(mtx);
        cv.wait(lk, [&id]{ return id == which; });
        for (int i=0; i<30; i++) {
            cout << id << " is executing " << endl;
            this_thread::sleep_for(chrono::milliseconds(10));
        }
        which++;
        cv.notify_all();
    }
    void join() {
        for (auto &t : ths) {
            t.join();
        }
    }
private:
    vector<thread> ths;
};

int main()
{
    Foo f;
    f.bar(0);
    f.bar(1);
    f.bar(2);
    f.join();
    return 0;
}