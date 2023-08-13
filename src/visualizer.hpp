#ifndef VISUALIZER_HPP
#define VISUALIZER_HPP
#include "SortItem.hpp"
#include <SFML/Graphics.hpp>

class Visualizer {
public:
  static const int HEIGHT = 600;
  static const int WIDTH = 800;
  static const int REC_WIDTH = 10;
  sf::RenderWindow window;
  std::vector<SortItem> nums;
  Visualizer();
  void run();

private:
  void display_rectangles(sf::RenderWindow &window);
  void start_sort();
};

#endif
