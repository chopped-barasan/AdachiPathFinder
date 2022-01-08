#pragma once

// #define __DEBUG__

#include "PathFinder.h"

class Adachi : public PathFinder {
 private:
  class TileQueue {
   private:
    constexpr static uint32_t LENGTH = 32;
    uint32_t head = 0;
    uint32_t num = 0;

    Index queue[LENGTH];

   public:
    TileQueue(){};
    ~TileQueue(){};

    bool enqueue(Index&);
    bool dequeue(void);
    bool dequeue(Index&);
#ifdef __DEBUG__
    void printQueue(PathFinder&) const;
#endif
    bool isEmpty(void) const { return num == 0; }
  } queue;

  constexpr static uint32_t MAP_SIZE = 16;
  uint8_t update_count = 0;

 public:
  Adachi(){};
  ~Adachi(){};
  void appendAroundTile(Tile&);
  void updateMap(void);
};