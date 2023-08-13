#include "SortItem.hpp"
#include "visualizer.hpp"
#include <SFML/Graphics.hpp>

const sf::Color SortItem::DEFAULT_COLOR = sf::Color::White;

SortItem::SortItem() {
  this->value = 0;
  this->color = DEFAULT_COLOR;
}

SortItem::SortItem(int value) {
  this->value = value;
  this->color = DEFAULT_COLOR;
}

void SortItem::set_color(sf::Color color) { this->color = color; }

void SortItem::reset_color() { this->color = DEFAULT_COLOR; }

bool operator<(const SortItem &lhs, const SortItem &rhs) {
  return lhs.value < rhs.value;
}

bool operator>(const SortItem &lhs, const SortItem &rhs) {
  return lhs.value > rhs.value;
}
