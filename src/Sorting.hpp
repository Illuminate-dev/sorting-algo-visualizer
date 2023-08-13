#ifndef SORTING_HPP
#define SORTING_HPP

#include "SortItem.hpp"
#include <SFML/Audio.hpp>
#include <queue>

class Sorting {
public:
  Sorting();
  virtual void sort(std::vector<SortItem> &nums) {}

  void stop();
  bool isRunning();

protected:
  int wait_time;
  bool is_running;
  sf::SoundBuffer buffer;
  // sf::Sound sound;
  std::queue<sf::Sound> sounds;
  void play_sound(int index);
  void run_sound(std::vector<SortItem> &nums);
};

#endif // !SORTING_HPP
