#include "Sorting.hpp"
#include "visualizer.hpp"
#include <SFML/Audio.hpp>

Sorting::Sorting() {
  wait_time = 0;
  is_running = false;
  buffer.loadFromFile("res/note_temp.wav");
  sound.setBuffer(buffer);
}

bool Sorting::isRunning() { return is_running; }

void Sorting::stop() { is_running = false; }

void Sorting::play_sound(int v) {
  float pitch = v / (Visualizer::HEIGHT / 2.0);
  sound.setPitch(pitch);
  sound.play();
}
