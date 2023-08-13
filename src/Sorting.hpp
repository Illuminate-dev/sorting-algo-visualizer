#ifndef SORTING_HPP
#define SORTING_HPP

#include "SortItem.hpp"

class Sorting {
public:
  Sorting();
  virtual void sort(std::vector<SortItem> &nums) {}

protected:
  int wait_time;
};

#endif // !SORTING_HPP
