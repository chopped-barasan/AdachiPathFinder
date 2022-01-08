#pragma once

#include <iostream>
#include "types.h"

// #define __DEBUG__

#ifdef __DEBUG__
#include "debug_map.h"
#endif

class Mouse {
 private:
  uint8_t direction;
  Index position;
  Walls walls;

 public:
  Mouse();

  bool march(void);
  void rotateMouse(bool);
  void printDir(void) const;
  void printPos(void) const;
  void printMouse(void) const;
  Index getPosition(void) const;
  uint8_t getDirection(void) const;
  Walls detectWalls(void);
  void restartMouse(void);
};