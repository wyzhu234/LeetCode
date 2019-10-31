#include "common.h"

#include <mutex>


class Foo {
public:
    Foo() {
        f_mutex.lock();
        s_mutex.lock();
    }

    void first(function<void()> printFirst) {

        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        f_mutex.lock();
    }

    void second(function<void()> printSecond) {
        f_mutex.lock();
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        s_mutex.unlock();
    }

    void third(function<void()> printThird) {
        s_mutex.lock();
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        s_mutex.unlock();
    }

private:
    mutex f_mutex, s_mutex;
};