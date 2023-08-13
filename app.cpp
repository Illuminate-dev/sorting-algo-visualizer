#include <SFML/Graphics.hpp>
#include <iostream>

int HEIGHT = 600;
int WIDTH = 800;

int REC_WIDTH = 10;

void display_rectangles(sf::RenderWindow &window, int rectangles[]) {
  for (int i = 0; i < WIDTH / REC_WIDTH; i += 1) {
    sf::RectangleShape rectangle(sf::Vector2f(REC_WIDTH, rectangles[i]));
    rectangle.setFillColor(sf::Color::White);
    rectangle.setPosition(i * REC_WIDTH, HEIGHT - rectangles[i]);
    window.draw(rectangle);
  }
}

int main() {
  sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "My window");

  int rectangles[WIDTH / REC_WIDTH];

  for (int i = 0; i < WIDTH / REC_WIDTH; i += 1) {
    rectangles[i] = rand() % HEIGHT;
  }

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
  return 0;
}
