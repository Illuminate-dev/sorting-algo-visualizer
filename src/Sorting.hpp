#ifndef SORTING_HPP
#define SORTING_HPP

#include "SortItem.hpp"

#include <SFML/Audio.hpp>

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
  sf::Sound sound;
  void play_sound(int index);
};

#endif // !SORTING_HPP
