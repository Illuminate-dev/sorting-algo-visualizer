#ifndef COUNTING_SORT_HPP
#define COUNTING_SORT_HPP

#include "../SortItem.hpp"
#include "../Sorting.hpp"

class CountingSort : public Sorting {
public:
  CountingSort(int sleep_time);
  void sort(std::vector<SortItem> &nums) override;
};

#endif
