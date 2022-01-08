#include "types.h"

void Tile::setWall(const Walls& walls) {
  wall.top = walls.top;
  wall.right = walls.right;
  wall.bottom = walls.bottom;
  wall.left = walls.left;
}

void Tile::setWall(const uint8_t* walls) {
  wall.top = walls[0];
  wall.right = walls[1];
  wall.bottom = walls[2];
  wall.left = walls[3];
}