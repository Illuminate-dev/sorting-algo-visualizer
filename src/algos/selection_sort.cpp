#include "selection_sort.hpp"
#include "../SortItem.hpp"
#include <thread>

SelectionSort::SelectionSort(int sleep_time) { wait_time = sleep_time; }

void SelectionSort::sort(std::vector<SortItem> &nums) {
  int size = nums.size();

  is_running = true;

  for (int i = 0; i < size - 1; i++) {
    int min_idx = i;
    nums[i].set_color(sf::Color::Red);
    for (int j = i + 1; j < size; j++) {
      if (!is_running) {
        return;
      }

      nums[j].set_color(sf::Color::Red);

      play_sound(nums[j].value);

      std::this_thread::sleep_for(std::chrono::milliseconds(wait_time));

      nums[j].reset_color();

      if (nums[j] < nums[min_idx]) {
        min_idx = j;
      }
    }
    nums[i].reset_color();
    std::swap(nums[i], nums[min_idx]);
  }

  run_sound(nums);

  is_running = false;
}
