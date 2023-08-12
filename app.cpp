#include <SFML/Graphics.hpp>
#include <iostream>

int HEIGHT = 600;
int WIDTH = 800;

int main() {
  sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "My window");

  int recWidth = 10;

  sf::RectangleShape rectangles[WIDTH / recWidth];

  for (int i = 0; i < WIDTH / recWidth; i += 1) {
    int h = i * (HEIGHT / (WIDTH / recWidth));
    rectangles[i].setSize(sf::Vector2f(recWidth, h));
    rectangles[i].setFillColor(sf::Color::White);
    rectangles[i].setPosition(i * recWidth, HEIGHT - h);
  }
  std::swap(rectangles[0], rectangles[WIDTH / recWidth - 1]);

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
    for (int i = 0; i < WIDTH / recWidth; i += 1) {
      window.draw(rectangles[i]);
    }
    window.display();
  }
  return 0;
}
