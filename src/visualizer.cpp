#include "visualizer.hpp"
#include "SortItem.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>

void Visualizer::display_rectangles(sf::RenderWindow &window,
                                    SortItem rectangles[]) {
  for (int i = 0; i < WIDTH / REC_WIDTH; i += 1) {
    sf::RectangleShape rec = rectangles[i].to_rectangle();
    rec.setPosition(i * REC_WIDTH, HEIGHT - rectangles[i].value);
    window.draw(rec);
  }
}

Visualizer::Visualizer() {
  window.create(sf::VideoMode(WIDTH, HEIGHT), "Sorting Visualizer");

  for (int i = 0; i < WIDTH / REC_WIDTH; i += 1) {
    if (i == 20) {
      rectangles[i].set_color(sf::Color::Red);
    }
    rectangles[i].value = rand() % HEIGHT;
    std::cout << rectangles[i].value << std::endl;
  }
}

void Visualizer::run() {
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
      else if (event.type == sf::Event::KeyPressed &&
               event.key.code == sf::Keyboard::Escape) {
        window.close();
      }
    }

    window.clear(sf::Color::Black);
    display_rectangles(window, rectangles);
    window.display();
  }
}
