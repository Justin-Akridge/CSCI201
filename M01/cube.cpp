#include "cube.h"
#include <string>

cube::cube() {
  length = 0;
  width = 0;
  height = 0;
  color = "";
}

cube::cube(int setLength, int setWidth, int setHeight, std::string setColor) {
  length = setLength;
  width = setWidth;
  height = setHeight;
  color = setColor;
}

int cube::getLength() const {
  return length;
}

int cube::getWidth() const {
  return width;
}

int cube::getHeight() const {
  return height;
}

std::string cube::getColor() const {
  return color;
}

void cube::setLength(int& setLength) {
  length = setLength;
}

void cube::setWidth(int& setWidth) {
  width = setWidth;
}

void cube::setHeight(int& setHeight) {
  height = setHeight;
}

void cube::setColor(std::string& setColor) {
  color = setColor;
}

int cube::calculateVolume(int x, int y, int z) {
  return x * y * z;
}
