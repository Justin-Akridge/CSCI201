#ifndef cube_h
#define cube_h
#include "cube.h"
#include <string>

class cube {
public:
  cube(int, int, int, std::string);
  cube();
  int getLength() const;
  int getWidth() const;
  int getHeight() const;
  std::string getColor() const;
  void setLength(int& length);
  void setWidth(int& width);
  void setHeight(int& height);
  void setColor(std::string& color);
  int calculateVolume(int, int, int);
private:
  int length;
  int width;
  int height;
  std::string color;
};

#endif
