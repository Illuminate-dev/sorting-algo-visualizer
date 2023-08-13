#ifndef INSERTION_SORT_HPP

#define INSERTION_SORT_HPP

#include "../Sorting.hpp"

class InsertionSort : public Sorting {
public:
  InsertionSort(int sleep_time);
  void sort(std::vector<SortItem> &nums) override;

private:
  void _merge(std::vector<SortItem> &nums, int l, int m, int r);
  void _merge_sort(std::vector<SortItem> &nums, int l, int r);
};

#endif // INSERTION_SORT_HPP
