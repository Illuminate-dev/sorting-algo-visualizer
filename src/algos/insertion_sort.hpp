#ifndef INSERTION_SORT_HPP

#define INSERTION_SORT_HPP

#include "../Sorting.hpp"

class InsertionSort : public Sorting {
public:
  InsertionSort(int sleep_time);
  void sort(std::vector<SortItem> &nums) override;
};

#endif // INSERTION_SORT_HPP
