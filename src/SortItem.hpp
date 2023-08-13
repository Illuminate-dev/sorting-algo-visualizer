#ifndef SORTITEM_HPP
#define SORTITEM_HPP

#include <SFML/Graphics.hpp>

class SortItem {
public:
  int value;
  sf::Color color;
  static const sf::Color DEFAULT_COLOR;
  SortItem();
  void set_color(sf::Color color);
  void reset_color();
  sf::RectangleShape to_rectangle();
};

#endif // !SORTITEM_HPP
