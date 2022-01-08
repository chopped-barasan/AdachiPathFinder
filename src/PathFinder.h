#pragma once

#include <string.h>
#include <iostream>
#include "types.h"

// #define __DEBUG__
// #define __IGNORE_WALL__

#ifdef __DEBUG__
#include "debug_map.h"
#endif

class PathFinder {
 protected:
  constexpr static uint32_t MAP_SIZE = 16;
  Tile map[16][16] = {0};
  Index goals[4] = {0};
  uint32_t goal_length = 0;

  void setTileNum(Tile&);

 public:
  PathFinder(){};
  ~PathFinder(){};

  void init(void);
  void setGoal(const uint8_t, const uint8_t);
  void setWalls(const Index&, const Walls&);
  void resetNum(void);
  void resetGoals(void);
  Tile& getTileOnMap(uint8_t upper, uint8_t lower);
  uint32_t getGoalLen(void) const;
  uint32_t getGoals(const Index*) const;

  void printMap(const Index&, const uint8_t) const;

  virtual void updateMap(void) = 0;
};