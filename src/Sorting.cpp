#include "Sorting.hpp"

Sorting::Sorting() {
  wait_time = 0;
  is_running = false;
}

bool Sorting::isRunning() { return is_running; }

void Sorting::stop() { is_running = false; }
