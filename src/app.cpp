#include "visualizer.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>

int main() {
  std::srand(time(NULL));

  Visualizer visualizer;
  visualizer.run();
  return 0;
}
