#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP

#include "../SortItem.hpp"
#include "../Sorting.hpp"

class QuickSort : public Sorting {
public:
  QuickSort(int sleep_time);
  void sort(std::vector<SortItem> &nums) override;

private:
  void quicksort(std::vector<SortItem> &nums, int left, int right);
  int partition(std::vector<SortItem> &nums, int left, int right);
};

#endif
