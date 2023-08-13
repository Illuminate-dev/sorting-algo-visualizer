#include "insertion_sort.hpp"
#include <thread>

InsertionSort::InsertionSort(int sleep_time) { wait_time = sleep_time; }

void InsertionSort::sort(std::vector<SortItem> &nums) {
  int size = nums.size();

  is_running = true;

  for (int i = 1; i < size; i++) {
    SortItem key = nums[i];
    key.set_color(sf::Color::Red);
    int j = i - 1;

    while (key < nums[j] && j >= 0) {
      if (!is_running) {
        key.reset_color();
        return;
      }

      nums[j].set_color(sf::Color::Red);

      play_sound(nums[j].value);

      std::this_thread::sleep_for(std::chrono::milliseconds(wait_time));

      nums[j].reset_color();

      nums[j + 1] = nums[j];
      j--;
    }
    key.reset_color();
    nums[j + 1] = key;
  }

  run_sound(nums);

  is_running = false;
}
