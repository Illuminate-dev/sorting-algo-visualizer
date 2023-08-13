#ifndef BUBBLE_SORT_HPP

#define BUBBLE_SORT_HPP

#include "../Sorting.hpp"

class BubbleSort : public Sorting {
public:
  BubbleSort(int sleep_time);
  void sort(std::vector<SortItem> &nums) override;
};

#endif // BUBBLE_SORT_HPP
