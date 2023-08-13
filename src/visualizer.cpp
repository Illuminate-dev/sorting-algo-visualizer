#include "visualizer.hpp"
#include "SortItem.hpp"
#include "algos/bubble_sort.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <thread>

void Visualizer::display_rectangles(sf::RenderWindow &window) {
  for (int i = 0; i < WIDTH / REC_WIDTH; i += 1) {
    int h = nums[i].value;
    sf::RectangleShape rec(sf::Vector2f(REC_WIDTH, h));
    rec.setFillColor(nums[i].color);
    rec.setPosition(i * REC_WIDTH, HEIGHT - h);
    window.draw(rec);
  }
}

Visualizer::Visualizer() {
  window.create(sf::VideoMode(WIDTH, HEIGHT), "Sorting Visualizer");

  nums.clear();

  for (int i = 0; i < WIDTH / REC_WIDTH; i += 1) {
    nums.push_back(SortItem(rand() % HEIGHT));
  }
}

void Visualizer::run() {
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
      else if (event.type == sf::Event::KeyPressed) {
        switch (event.key.code) {
        case sf::Keyboard::Space:
          std::thread(&Visualizer::start_sort, this).detach();
          break;
        case sf::Keyboard::Escape:
          window.close();
          break;
        default:
          break;
        }
      }
    }

    window.clear(sf::Color::Black);
    display_rectangles(window);
    window.display();
  }
}

void Visualizer::start_sort() {
  BubbleSort bubble_sort(100);
  bubble_sort.sort(nums);
}
