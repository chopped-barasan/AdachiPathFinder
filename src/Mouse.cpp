#include "Mouse.h"

Mouse::Mouse() {
  direction = 0x01;
  position.lower = 0;
  position.upper = 15;
}

bool Mouse::march(void) {
  bool ret_val = false;
  switch (direction) {
    case 0x01:
#ifndef __IGNORE_WALL__
      if (walls.top == 0 && position.upper > 0) {
        position.upper--;
        ret_val = true;
      }
#else
      position.upper--;
      ret_val = true;
#endif
      break;
    case 0x02:
#ifndef __IGNORE_WALL__
      if (walls.right == 0 && position.lower < 16 - 1) {
        position.lower++;
        ret_val = true;
      }
#else
      position.lower++;
      ret_val = true;
#endif
      break;
    case 0x04:
#ifndef __IGNORE_WALL__
      if (walls.bottom == 0 && position.upper < 16 - 1) {
        position.upper++;
        ret_val = true;
      }
#else
      position.upper++;
      ret_val = true;
#endif
      break;
    case 0x08:
#ifndef __IGNORE_WALL__
      if (walls.left == 0 && position.lower > 0) {
        position.lower--;
        ret_val = true;
      }
#else
      position.lower--;
      ret_val = true;
#endif
      break;
    default:
      break;
  }

  return ret_val;
}

void Mouse::rotateMouse(bool right = true) {
  if (right) {
    if (direction == 0x08) {
      direction = 0x01;
    } else {
      direction <<= 1;
    }
  } else {
    if (direction == 0x01) {
      direction = 0x08;
    } else {
      direction >>= 1;
    }
  }
}

void Mouse::printDir(void) const {
  switch (direction) {
    case 0x01:
      puts("top!");
      break;
    case 0x02:
      puts("right!");
      break;
    case 0x04:
      puts("bottom!");
      break;
    case 0x08:
      puts("left!");
      break;
    default:
      puts("error!");
      break;
  }
}

void Mouse::printPos(void) const {
  printf("pos %02d:%02d\n", position.upper, position.lower);
}

void Mouse::printMouse(void) const {
  printDir();
  printPos();
}

Index Mouse::getPosition(void) const {
  return position;
}

uint8_t Mouse::getDirection(void) const {
  return direction;
}

Walls Mouse::detectWalls(void) {
  Walls ret_val = {0};

#ifdef __DEBUG__
  uint8_t* walls = debug_map[position.upper][position.lower];

  ret_val.top = walls[0];
  ret_val.right = walls[1];
  ret_val.bottom = walls[2];
  ret_val.left = walls[3];

  this->walls = ret_val;

  return ret_val;
#endif

  return ret_val;
}

void Mouse::restartMouse(void) {
  direction = 0x01;
  position.lower = 0;
  position.upper = 15;
}