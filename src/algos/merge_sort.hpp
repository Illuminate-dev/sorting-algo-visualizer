#ifndef MERGE_SORT_HPP
#define MERGE_SORT_HPP

#include "../Sorting.hpp"

class MergeSort : public Sorting {
public:
  MergeSort(int sleep_time);
  void sort(std::vector<SortItem> &nums) override;

private:
  void _merge(std::vector<SortItem> &nums, int l, int m, int r);
  void _merge_sort(std::vector<SortItem> &nums, int l, int r);
};

#endif // !MERGE_SORT_HPP
