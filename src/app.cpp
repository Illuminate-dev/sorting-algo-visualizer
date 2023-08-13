#include "visualizer.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <queue>
#include <time.h>

int main() {
  std::srand(time(NULL));
  Visualizer visualizer;
  visualizer.run();
  return 0;
}
