#include "PathFinder.h"

void PathFinder::init(void) {
  for (uint32_t i = 0; i < MAP_SIZE; i++) {
    for (uint32_t j = 0; j < MAP_SIZE; j++) {
      map[i][j].number = 0xff;
      // インデックス記録
      map[i][j].index.upper = i;
      map[i][j].index.lower = j;

      map[i][j].wall.top = 0;
      map[i][j].wall.bottom = 0;
      map[i][j].wall.right = 0;
      map[i][j].wall.left = 0;
#ifdef __CLEAR_MAP__
      map[i][j].setWall(debug_map[i][j]);
#else
      /*        外周の壁        */
      // 上の壁
      if (i == 0) {
        map[i][j].wall.top = 1;
        // 角のマス
        if (j == 0) {
          map[i][j].wall.left = 1;
        } else if (j == MAP_SIZE - 1) {
          map[i][j].wall.right = 1;
        }
        // 下の壁
      } else if (i == MAP_SIZE - 1) {
        map[i][j].wall.bottom = 1;
        // 角のマス
        if (j == 0) {
          map[i][j].wall.left = 1;
        } else if (j == MAP_SIZE - 1) {
          map[i][j].wall.right = 1;
        }
        // 左の壁
      } else if (j == 0) {
        map[i][j].wall.left = 1;
        // 右の壁
      } else if (j == MAP_SIZE - 1) {
        map[i][j].wall.right = 1;
        // それ以外は壁なし
      } else {
      }
#endif
    }
  }
}

void PathFinder::printMap(const Index& mouse_pos,
                          const uint8_t mouse_dir) const {
  for (uint32_t i = 0; i < MAP_SIZE; i++) {
    for (uint32_t j = 0; j < MAP_SIZE; j++) {
      if (map[i][j].wall.top == 1) {
        printf(" ----- ");
      } else {
        printf("       ");
      }
    }
    putchar('\n');
    // for (uint32_t j = 0; j < sizeof(map[0]) / sizeof(map[0][0]); j++) {
    //   if (map[i][j].wall.left == 1) {
    //     putchar('|');
    //   } else {
    //     putchar(' ');
    //   }
    //   if (map[i][j].flags.is_goal == 0) {
    //     printf("   %d ", map[i][j].flags.enqueued);
    //   } else {
    //     printf(" G %d ", map[i][j].flags.enqueued);
    //   }
    //   if (map[i][j].wall.right == 1) {
    //     putchar('|');
    //   } else {
    //     putchar(' ');
    //   }
    // }
    // putchar('\n');
    for (uint32_t j = 0; j < MAP_SIZE; j++) {
      if (map[i][j].wall.left == 1) {
        putchar('|');
      } else {
        putchar(' ');
      }
      if (i == mouse_pos.upper && j == mouse_pos.lower) {
        switch (mouse_dir) {
          case 0x01:
            printf("%c", '^');
            break;
          case 0x02:
            printf("%c", '>');
            break;
          case 0x04:
            printf("%c", 'v');
            break;
          case 0x08:
            printf("%c", '<');
            break;
          default:
            break;
        }
        printf("%03d%c", map[i][j].number, 'M');
      } else {
        printf(" %03d ", map[i][j].number);
      }
      if (map[i][j].wall.right == 1) {
        putchar('|');
      } else {
        putchar(' ');
      }
    }
    putchar('\n');
    // for (uint32_t j = 0; j < sizeof(map[0]) / sizeof(map[0][0]); j++)
    // printf("(%02d %02d)", map[i][j].index.upper, map[i][j].index.lower);
    // putchar('\n');
    for (uint32_t j = 0; j < sizeof(map[0]) / sizeof(map[0][0]); j++) {
      if (map[i][j].wall.bottom == 1) {
        printf(" ----- ");
      } else {
        printf("       ");
      }
    }
    putchar('\n');
  }
}

void PathFinder::setTileNum(Tile& target) {
  Tile* arround = 0;
  uint8_t minimum_num = 255;

  if (target.flags.is_goal == 1) {
    target.number = 0;
    return;
  }

  /*        check top tile        */
  if (target.index.upper - 1 >= 0) {
    arround = &map[target.index.upper - 1][target.index.lower];  // top
#ifndef __IGNORE_WALL__
    if ((target.wall.top == 0 && arround->wall.bottom == 0) &&
        minimum_num > arround->number)
      minimum_num = arround->number;
#else
    if (minimum_num > arround->number)
      minimum_num = arround->number;
#endif
  }

  /*        check bottom tile       */
  if (target.index.upper + 1 < 16) {
    arround = &map[target.index.upper + 1][target.index.lower];  // bottom
#ifndef __IGNORE_WALL__
    if ((target.wall.bottom == 0 && arround->wall.top == 0) &&
        minimum_num > arround->number)
      minimum_num = arround->number;
#else
    if (minimum_num > arround->number)
      minimum_num = arround->number;
#endif
  }

  /*        check right tile        */
  if (target.index.lower + 1 < 16) {
    arround = &map[target.index.upper][target.index.lower + 1];  // right
#ifndef __IGNORE_WALL__
    if ((target.wall.right == 0 && arround->wall.left == 0) &&
        minimum_num > arround->number)
      minimum_num = arround->number;
#else
    if (minimum_num > arround->number)
      minimum_num = arround->number;
#endif
  }

  /*        check left tile       */
  if (target.index.lower - 1 >= 0) {
    arround = &map[target.index.upper][target.index.lower - 1];  // left
#ifndef __IGNORE_WALL__
    if ((target.wall.left == 0 && arround->wall.right == 0) &&
        minimum_num > arround->number)
      minimum_num = arround->number;
#else
    if (minimum_num > arround->number)
      minimum_num = arround->number;
#endif
  }

  target.number = minimum_num + 1;
}

void PathFinder::setGoal(const uint8_t upper, const uint8_t lower) {
  Index index = {upper, lower};
  Tile& tile = getTileOnMap(upper, lower);
  tile.flags.is_goal = 1;
  tile.number = 0;
  goals[goal_length++] = index;
}

void PathFinder::setWalls(const Index& position, const Walls& walls) {
  getTileOnMap(position.upper, position.lower).setWall(walls);
}

void PathFinder::resetNum(void) {
  for (uint8_t i = 0; i < MAP_SIZE; i++) {
    for (uint8_t j = 0; j < MAP_SIZE; j++) {
      map[i][j].number = 0xff;
    }
  }
}

void PathFinder::resetGoals(void) {
  resetNum();
  for (uint8_t i = 0; i < goal_length; i++) {
    map[goals[i].upper][goals[i].lower].flags.is_goal = 0;
  }
  goal_length = 0;
}

uint32_t PathFinder::getGoalLen(void) const {
  return goal_length;
}

Tile& PathFinder::getTileOnMap(uint8_t upper, uint8_t lower) {
  return map[upper][lower];
}

uint32_t PathFinder::getGoals(const Index* ret_val) const {
  ret_val = goals;
  return goal_length;
}