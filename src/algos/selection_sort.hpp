#ifndef SELECTION_SORT_HPP

#define SELECTION_SORT_HPP

#include "../Sorting.hpp"

class SelectionSort : public Sorting {
public:
  SelectionSort(int sleep_time);
  void sort(std::vector<SortItem> &nums) override;
};

#endif // !SELECTION_SORT_HPP
