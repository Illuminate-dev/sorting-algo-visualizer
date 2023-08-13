#include "merge_sort.hpp"
#include <iostream>
#include <thread>

MergeSort::MergeSort(int sleep_time) { wait_time = sleep_time; }

void MergeSort::_merge(std::vector<SortItem> &nums, int l, int m, int r) {
  nums[m].set_color(sf::Color::Green);

  int l1 = m - l + 1;

  int l2 = r - m;

  std::vector<SortItem> left;
  std::vector<SortItem> right;

  for (int i = 0; i < l1; i++) {
    left.push_back(nums[l + i]);
  }

  for (int i = 0; i < l2; i++) {
    right.push_back(nums[m + 1 + i]);
  }

  int j = 0;
  int k = 0;

  while (j < l1 && k < l2) {
    if (!is_running) {
      return;
    }
    left[j].set_color(sf::Color::Red);
    right[k].set_color(sf::Color::Red);
    if (left[j] < right[k]) {
      play_sound(left[j].value);
      std::this_thread::sleep_for(std::chrono::milliseconds(wait_time));
      nums[l + j + k] = left[j];
      j++;
    } else {
      play_sound(right[k].value);
      std::this_thread::sleep_for(std::chrono::milliseconds(wait_time));
      nums[l + j + k] = right[k];
      k++;
    }
  }

  while (j < l1) {
    if (!is_running) {
      return;
    }
    left[j].set_color(sf::Color::Red);
    play_sound(left[j].value);
    std::this_thread::sleep_for(std::chrono::milliseconds(wait_time));
    nums[l + j + k] = left[j];
    j++;
  }

  while (k < l2) {
    if (!is_running) {
      return;
    }
    right[k].set_color(sf::Color::Red);
    play_sound(right[k].value);
    std::this_thread::sleep_for(std::chrono::milliseconds(wait_time));
    nums[l + j + k] = right[k];
    k++;
  }
}

void MergeSort::_merge_sort(std::vector<SortItem> &nums, int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;

    nums[m].set_color(sf::Color::Green);

    _merge_sort(nums, l, m);
    _merge_sort(nums, m + 1, r);

    nums[m].reset_color();

    _merge(nums, l, m, r);
  }
}

void MergeSort::sort(std::vector<SortItem> &nums) {
  int size = nums.size();

  is_running = true;

  _merge_sort(nums, 0, size - 1);

  run_sound(nums);

  is_running = false;
}
