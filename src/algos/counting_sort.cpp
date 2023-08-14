#include "counting_sort.hpp"
#include "../SortItem.hpp"
#include <thread>

CountingSort::CountingSort(int sleep_time) { wait_time = sleep_time; }

void CountingSort::sort(std::vector<SortItem> &nums) {
  is_running = true;

  int size = nums.size();

  int max_idx = 0;
  int min_idx = 0;
  for (int i = 1; i < size; i++) {
    if (!is_running) {
      return;
    }
    nums[i].set_color(sf::Color::Blue);
    if (nums[max_idx] < nums[i]) {
      nums[max_idx].reset_color();
      max_idx = i;
      nums[i].set_color(sf::Color::Red);
    }
    if (nums[min_idx] > nums[i]) {
      nums[min_idx].reset_color();
      min_idx = i;
      nums[i].set_color(sf::Color::Green);
    }
    play_sound(nums[i].value);
    std::this_thread::sleep_for(std::chrono::milliseconds(wait_time));
    if (i != max_idx && i != min_idx)
      nums[i].reset_color();
  }

  nums[max_idx].reset_color();
  nums[min_idx].reset_color();

  int min = nums[min_idx].value;
  int max = nums[max_idx].value;

  int range = max - min + 1;

  std::vector<int> count(range);

  for (int i = 0; i < size; i++) {
    if (!is_running) {
      return;
    }
    count[nums[i].value - min]++;
    nums[i].set_color(sf::Color::Blue);
    play_sound(nums[i].value);
    std::this_thread::sleep_for(std::chrono::milliseconds(wait_time));
  }

  int j = 0;
  for (int i = 0; i < range; i++) {
    if (!is_running) {
      return;
    }
    while (count[i] > 0) {
      nums[j].value = i + min;
      nums[j].set_color(sf::Color::Red);
      play_sound(nums[j].value);
      std::this_thread::sleep_for(std::chrono::milliseconds(wait_time));
      count[i]--;
      j++;
    }
  }

  run_sound(nums);

  is_running = false;
}
