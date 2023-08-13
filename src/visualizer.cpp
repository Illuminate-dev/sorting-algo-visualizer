#include "visualizer.hpp"
#include "SortItem.hpp"
#include "algos/bubble_sort.hpp"
#include "algos/insertion_sort.hpp"
#include "algos/merge_sort.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <thread>

Visualizer::Visualizer() {
  window.create(sf::VideoMode(WIDTH, HEIGHT), "Sorting Visualizer");

  sorting_algo = std::make_unique<BubbleSort>((int)SLEEP_TIME);

  nums.clear();

  for (int i = 0; i < WIDTH / REC_WIDTH; i += 1) {
    nums.push_back(SortItem(rand() % HEIGHT));
  }
}

void Visualizer::display_rectangles(sf::RenderWindow &window) {
  for (int i = 0; i < WIDTH / REC_WIDTH; i += 1) {
    int h = nums[i].value;
    sf::RectangleShape rec(sf::Vector2f(REC_WIDTH, h));
    rec.setFillColor(nums[i].color);
    rec.setPosition(i * REC_WIDTH, HEIGHT - h);
    window.draw(rec);
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
          if (sorting_algo->isRunning()) {
            sorting_algo->stop();
          } else {
            std::thread(&Visualizer::start_sort, this).detach();
          }
          break;
        case sf::Keyboard::R:
          reset();
          break;
        case sf::Keyboard::I:
          sorting_algo->stop();
          std::this_thread::sleep_for(
              std::chrono::milliseconds((int)SLEEP_TIME));
          sorting_algo = std::make_unique<InsertionSort>((int)SLEEP_TIME);
          break;
        case sf::Keyboard::B:
          sorting_algo->stop();
          std::this_thread::sleep_for(
              std::chrono::milliseconds((int)SLEEP_TIME));
          sorting_algo = std::make_unique<BubbleSort>((int)SLEEP_TIME);
          break;
        case sf::Keyboard::M:
          sorting_algo->stop();
          std::this_thread::sleep_for(
              std::chrono::milliseconds((int)SLEEP_TIME));
          sorting_algo = std::make_unique<MergeSort>((int)SLEEP_TIME);
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

void Visualizer::reset() {
  if (sorting_algo->isRunning()) {
    sorting_algo->stop();
  }
  std::this_thread::sleep_for(std::chrono::milliseconds((int)SLEEP_TIME));
  nums.clear();
  for (int i = 0; i < WIDTH / REC_WIDTH; i += 1) {
    nums.push_back(SortItem(rand() % HEIGHT));
  }
}

void Visualizer::start_sort() { sorting_algo->sort(nums); }
