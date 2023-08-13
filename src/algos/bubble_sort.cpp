#include "bubble_sort.hpp"
#include <chrono>
#include <thread>

BubbleSort::BubbleSort(int sleep_time) { wait_time = sleep_time; }

void BubbleSort::sort(std::vector<SortItem> &nums) {
  int size = nums.size();

  is_running = true;

  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - i - 1; j++) {

      if (!is_running) {
        return;
      }

      nums[j].set_color(sf::Color::Red);
      nums[j + 1].set_color(sf::Color::Red);

      std::this_thread::sleep_for(std::chrono::milliseconds(wait_time));

      nums[j].reset_color();
      nums[j + 1].reset_color();
      if (nums[j] > nums[j + 1]) {
        std::swap(nums[j], nums[j + 1]);
      }
    }
  }
}
