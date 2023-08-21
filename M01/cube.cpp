#include "cube.h"

cube::cube() {
  length = 0;
  width = 0;
  height = 0;
  color = "";
}

cube::cube(int length, int width, int height, std::string color) {
  length = length;
  width = width;
  height = height;
  color = color;
}
int cube::getLength() {
  return length;
}

int cube::getWidth() {
  return width;
}

int cube::getHeight() {
  return height;
}

std::color cube::getColor() {
  return color;
}

void cube::setLength(int& length) {
  length = length;
}

void cube::setWidth(int& width) {
  width = width;
}

void cube::setHeight(int& height) {
  height = height;
}

void cube::setColor(std::string& color) {
  color = color;
}

int calculateVolume(int, int, int) {
  return
