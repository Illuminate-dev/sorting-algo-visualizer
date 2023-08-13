#include "Sorting.hpp"
#include "visualizer.hpp"
#include <SFML/Audio.hpp>
#include <thread>

Sorting::Sorting() {
  wait_time = 0;
  is_running = false;
  buffer.loadFromFile("res/note.wav");
  sound.setBuffer(buffer);
}

bool Sorting::isRunning() { return is_running; }

void Sorting::stop() { is_running = false; }

void Sorting::play_sound(int v) {
  float pitch = v / (Visualizer::HEIGHT / 2.0) + 0.5;
  sound.setPitch(pitch);
  sound.play();

  // while (sound.getStatus() == sf::Sound::Playing) {
  //   std::this_thread::sleep_for(std::chrono::milliseconds(1));
  // }
}

void Sorting::run_sound(std::vector<SortItem> &nums) {
  for (int i = 0; i < nums.size(); i++) {
    nums[i].set_color(sf::Color::Green);
    play_sound(nums[i].value);
    std::this_thread::sleep_for(std::chrono::milliseconds(wait_time));
    nums[i].reset_color();
  }
}
