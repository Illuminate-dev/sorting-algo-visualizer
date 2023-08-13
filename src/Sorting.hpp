#ifndef SORTING_HPP
#define SORTING_HPP

#include "SortItem.hpp"

class Sorting {
public:
  Sorting();
  virtual void sort(std::vector<SortItem> &nums) {}

  void stop();
  bool isRunning();

protected:
  int wait_time;
  bool is_running;
};

#endif // !SORTING_HPP
