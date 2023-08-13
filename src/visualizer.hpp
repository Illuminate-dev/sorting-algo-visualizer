#ifndef VISUALIZER_HPP
#define VISUALIZER_HPP
#include "SortItem.hpp"
#include "Sorting.hpp"
#include <SFML/Graphics.hpp>
#include <memory>

class Visualizer {
public:
  static const int HEIGHT = 600;
  static const int WIDTH = 1600;
  static const int REC_WIDTH = 10;
  sf::RenderWindow window;
  std::vector<SortItem> nums;
  Visualizer();
  void run();

private:
  std::unique_ptr<Sorting> sorting_algo;
  void display_rectangles(sf::RenderWindow &window);
  void start_sort();
};

#endif
