#include "SortItem.hpp"
#include "visualizer.hpp"
#include <SFML/Graphics.hpp>

const sf::Color SortItem::DEFAULT_COLOR = sf::Color::White;

SortItem::SortItem() {
  this->value = 0;
  this->color = DEFAULT_COLOR;
}

void SortItem::set_color(sf::Color color) { this->color = color; }

void SortItem::reset_color() { this->color = DEFAULT_COLOR; }

sf::RectangleShape SortItem::to_rectangle() {
  sf::RectangleShape rectangle(sf::Vector2f(Visualizer::REC_WIDTH, value));
  rectangle.setFillColor(color);
  return rectangle;
}
