#ifndef SORTITEM_HPP
#define SORTITEM_HPP

#include <SFML/Graphics.hpp>

class SortItem {
public:
  int value;
  sf::Color color;
  static const sf::Color DEFAULT_COLOR;
  SortItem();
  SortItem(int value);
  void set_color(sf::Color color);
  void reset_color();
  friend bool operator<(const SortItem &lhs, const SortItem &rhs);
  friend bool operator>(const SortItem &lhs, const SortItem &rhs);
};

#endif // !SORTITEM_HPP
