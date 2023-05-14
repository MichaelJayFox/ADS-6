// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T, int size>
class TPQueue {
   private:
    uint64_t first;
    uint64_t last;
    uint64_t cnt;
    T * arr;
   public:
    TPQueue() :first(0), last(0), cnt(0) {
        arr = new T[size];
    }
    bool isEmpty() const {
      return 0 == cnt;
    }
    bool isFull() const {
      return size == cnt;
    }
  void push(const T& value) {
    if(isFull() ) {
      throw std::string("String is Full");
    } else {
            uint64_t l = last;
            for (uint64_t i = last; i > first; i--) {
                if (arr[i - 1].prior < value.prior) {
                    l = i - 1;
                    arr[i % size] = arr[i - 1];
                }
            }
            arr[l % size] = value;
            cnt++;
            last++;
        }
    }
  const T& pop() {
        if (isEmpty()) {
            throw std::string("String is Empty!");
        } else {
            cnt--;
            return arr[first++ % size];
        }
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
