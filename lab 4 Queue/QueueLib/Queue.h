#include <vector>
#include <iostream>

using namespace std;

const size_t MAX_QUEUE_SIZE = 100000000;





template<typename T>
class TVectorQueue
{
protected:

  int head;
  int tail;
  vector<T> mem;

public:

  TVectorQueue();
  TVectorQueue(const TVectorQueue<T>& p);
  TVectorQueue(TVectorQueue<T>&& p);
  ~TVectorQueue();

  int Size() const;
  void Push(const T& val);
  
  T Pop();
  T Top();
  
  bool isEmpty() const noexcept;
  bool isFull() const noexcept;

  void repack();
};





template<typename T>
inline TVectorQueue<T>::TVectorQueue() : head(0), tail(0)
{
}

template<typename T>
inline TVectorQueue<T>::TVectorQueue(const TVectorQueue<T>& p)
{
  head = p.head;
  tail = p.tail;
  for (auto& i : p.mem)
  {
    mem.push_back(i);
  }
}

template<typename T>
inline TVectorQueue<T>::TVectorQueue(TVectorQueue<T>&& p)
{
  head = p.head;
  tail = p.tail;
  mem = p.mem;

  p.mem = nullptr;
  p.tail = 0;
  p.head = 0;
}

template<typename T>
inline TVectorQueue<T>::~TVectorQueue()
{
  if (head != 0 && tail != 0) mem.clear();
  head = 0;
  tail = 0;
}

template<typename T>
inline int TVectorQueue<T>::Size() const
{
  return tail - head;
}

template<typename T>
inline void TVectorQueue<T>::Push(const T& val)
{
  if (isFull()) throw "Queue is full";
  mem.push_back(val);
  tail++;
}

template<typename T>
inline T TVectorQueue<T>::Pop()
{
  if (head == tail) throw "Error: head == tail";
  return mem[head++];
}

template<typename T>
inline T TVectorQueue<T>::Top()
{
  if (isEmpty()) throw "Error";
  return mem[head];
}


template<typename T>
inline bool TVectorQueue<T>::isEmpty() const noexcept
{
  if (head == tail) return true;
  return false;
}


template<typename T>
inline bool TVectorQueue<T>::isFull() const noexcept
{
  if (Size() == MAX_QUEUE_SIZE) return true;
  return false;
}



template<typename T>
inline void TVectorQueue<T>::repack()
{
  if (Size() != 0)
  {

    vector<T> tmp;
    for (int i = head; i < tail; i++)
    {
      tmp.push_back(mem[i]);
    }
    mem.clear();
    mem = tmp;
    tail -= head;
    head = 0;
  }
}
