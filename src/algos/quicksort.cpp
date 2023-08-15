#include "quicksort.hpp"
#include "../SortItem.hpp"
#include <thread>

QuickSort::QuickSort(int sleep_time) { wait_time = sleep_time; }

void QuickSort::sort(std::vector<SortItem> &nums) {
  is_running = true;

  quicksort(nums, 0, nums.size() - 1);

  run_sound(nums);

  is_running = false;
}

int QuickSort::partition(std::vector<SortItem> &nums, int left, int right) {
  int pivot_idx = (rand() % (right - left + 1)) + left;
  std::swap(nums[pivot_idx], nums[right]);

  SortItem pivot = nums[right];

  int i = left - 1;

  for (int j = left; j <= right; j++) {
    if (!is_running)
      return -1;
    nums[j].set_color(sf::Color::Red);
    play_sound(j);
    std::this_thread::sleep_for(std::chrono::milliseconds(wait_time));
    nums[j].reset_color();
    if (nums[j] < pivot) {
      i++;
      std::swap(nums[i], nums[j]);
    }
  }

  std::swap(nums[i + 1], nums[right]);

  return (i + 1);
}

void QuickSort::quicksort(std::vector<SortItem> &nums, int left, int right) {
  if (left < right) {
    int pi = partition(nums, left, right);
    if (!is_running || pi == -1)
      return;

    nums[pi].set_color(sf::Color::Green);

    quicksort(nums, left, pi - 1);
    quicksort(nums, pi + 1, right);
    nums[pi].reset_color();
  }
}
