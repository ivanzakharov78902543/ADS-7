// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <list>
template<class T>
class TPQueue {
 private:
    std::list <T> LIST;

 public:
    T pop() {
        T elem = LIST.front();
        LIST.pop_front();
        return elem;
    }
    void push(const T& value) {
        if (LIST.empty()) {
            LIST.push_back(value);
        } else {
            bool f = true;
            for (auto iter = LIST.begin(); iter != LIST.end(); iter++) {
                if (value.prior > (*iter).prior) {
                    LIST.insert(iter, value);
                    f = false;
                    break;
            }
         }
            if (f) {
                LIST.push_back(value);
            }
        }
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
