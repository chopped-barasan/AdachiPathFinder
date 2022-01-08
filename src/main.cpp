// #define __DEBUG__          // PCと実機で動作が違う部分
// #define __IGNORE_WALL__    // 壁を無視するモード
// #define __CLEAR_MAP__      // 最初から迷路が全探索されている状態

#include <iomanip>
#include <iostream>
#include "Adachi.h"
#include "Mouse.h"
#include "types.h"

int main(void) {
  // Map map;

  // map.init();

  // map.setGoal(7, 7);
  // map.setGoal(7, 8);
  // map.setGoal(8, 7);
  // map.setGoal(8, 8);
  // map.updateMap();
  // map.printMap();

  // putchar('\n');

  // map.resetGoals();
  // map.setGoal(15, 0);
  // map.updateMap();
  // map.printMap();

  Adachi map;
  Mouse mouse;
  Walls walls;
  int8_t cmd = 'w';
  int8_t message[50] = "mouse and go!";

  map.init();

  map.setGoal(7, 7);
  map.setGoal(7, 8);
  map.setGoal(8, 7);
  map.setGoal(8, 8);

  map.updateMap();
  walls = mouse.detectWalls();
  map.setWalls(mouse.getPosition(), walls);

  while (true) {
    system("clear");
    if (cmd != '\n') {
      printf("input command : %c\n", cmd);
    } else {
      printf("input command : enter\n");
    }
    printf("%s\n", message);
    map.updateMap();
    mouse.printMouse();
    map.printMap(mouse.getPosition(), mouse.getDirection());

    if (cmd == 'q') {
      goto END;
    }

    printf("\ninput : ");
    cmd = getchar();
    while (getchar() != '\n')
      ;

    switch (cmd) {
      case 'w':
        bool result;
        result = mouse.march();
        walls = mouse.detectWalls();
        map.setWalls(mouse.getPosition(), walls);
        if (result) {
          strcpy((char*)message, "mouse and go!");
        } else {
          strcpy((char*)message, "there is wall on front of me.");
        }
        break;
      case 'a':
        mouse.rotateMouse(false);
        break;
      case 'd':
        mouse.rotateMouse(true);
        break;
      case 'r':
        mouse.restartMouse();
        strcpy((char*)message, "restart mouse!");
        break;
      case 'q':
        strcpy((char*)message, "quit!");
        break;
      default:
        strcpy((char*)message, "invalid command.");
        break;
    }
  }

END:
  return 0;
}