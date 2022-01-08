#pragma once

#include <iostream>

struct Index {
  uint8_t upper : 4;
  uint8_t lower : 4;
};

struct Walls {
  uint8_t reserve : 4;
  uint8_t top : 1;
  uint8_t right : 1;
  uint8_t bottom : 1;
  uint8_t left : 1;
};

class Tile {
 public:
  uint8_t number = 0;
  Index index = {0};
  Walls wall = {0};
  struct Flags {
    uint8_t enqueued : 1;
    uint8_t is_goal : 1;
    uint8_t reserve : 6;
  } flags = {0};

#ifdef __DEBUG__
  void printNum(void) {
    printf("upper : %d, lower : %d number : %d\n", index.upper, index.lower,
           number);
  }
#endif

  void setWall(const Walls&);
  void setWall(const uint8_t*);
};