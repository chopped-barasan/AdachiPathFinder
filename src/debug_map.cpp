#include "debug_map.h"

unsigned char debug_map[16][16][4] = {

    {{1, 0, 0, 1},    // 0 0
     {1, 1, 1, 0},    // 0 1
     {1, 0, 0, 1},    // 0 2
     {1, 0, 1, 0},    // 0 3
     {1, 0, 1, 0},    // 0 4
     {1, 0, 1, 0},    // 0 5
     {1, 0, 1, 0},    // 0 6
     {1, 0, 1, 0},    // 0 7
     {1, 0, 1, 0},    // 0 8
     {1, 0, 1, 0},    // 0 9
     {1, 0, 1, 0},    // 0 a
     {1, 0, 1, 0},    // 0 b
     {1, 0, 0, 0},    // 0 c
     {1, 1, 0, 0},    // 0 d
     {1, 0, 0, 1},    // 0 e
     {1, 1, 0, 0}},   // 0 f
    {{0, 0, 0, 1},    // 1 0
     {1, 0, 1, 0},    // 1 1
     {0, 1, 1, 0},    // 1 2
     {1, 0, 0, 1},    // 1 3
     {1, 0, 0, 0},    // 1 4
     {1, 0, 1, 0},    // 1 5
     {1, 0, 1, 0},    // 1 6
     {1, 0, 1, 0},    // 1 7
     {1, 0, 1, 0},    // 1 8
     {1, 0, 1, 0},    // 1 9
     {1, 0, 1, 0},    // 1 a
     {1, 1, 0, 0},    // 1 b
     {0, 1, 1, 1},    // 1 c
     {0, 1, 0, 1},    // 1 d
     {0, 1, 0, 1},    // 1 e
     {0, 1, 0, 1}},   // 1 f
    {{0, 0, 0, 1},    // 2 0
     {1, 1, 1, 0},    // 2 1
     {1, 0, 0, 1},    // 2 2
     {0, 1, 1, 0},    // 2 3
     {0, 1, 0, 1},    // 2 4
     {1, 0, 0, 1},    // 2 5
     {1, 0, 1, 0},    // 2 6
     {1, 0, 0, 0},    // 2 7
     {1, 0, 1, 0},    // 2 8
     {1, 0, 0, 0},    // 2 9
     {1, 0, 1, 0},    // 2 a
     {0, 0, 1, 0},    // 2 b
     {1, 1, 0, 0},    // 2 c
     {0, 0, 1, 1},    // 2 d
     {0, 1, 1, 0},    // 2 e
     {0, 1, 0, 1}},   // 2 f
    {{0, 1, 0, 1},    // 3 0
     {1, 0, 1, 1},    // 3 1
     {0, 0, 0, 0},    // 3 2
     {1, 0, 1, 0},    // 3 3
     {0, 1, 1, 0},    // 3 4
     {0, 1, 0, 1},    // 3 5
     {1, 0, 1, 1},    // 3 6
     {0, 0, 0, 0},    // 3 7
     {1, 1, 1, 0},    // 3 8
     {0, 1, 0, 1},    // 3 9
     {1, 0, 0, 1},    // 3 a
     {1, 1, 0, 0},    // 3 b
     {0, 0, 0, 1},    // 3 c
     {1, 0, 1, 0},    // 3 d
     {1, 1, 0, 0},    // 3 e
     {0, 1, 0, 1}},   // 3 f
    {{0, 1, 0, 1},    // 4 0
     {1, 0, 1, 1},    // 4 1
     {0, 0, 0, 0},    // 4 2
     {1, 1, 1, 0},    // 4 3
     {1, 0, 0, 1},    // 4 4
     {0, 1, 1, 0},    // 4 5
     {1, 0, 1, 1},    // 4 6
     {0, 0, 0, 0},    // 4 7
     {1, 1, 1, 0},    // 4 8
     {0, 0, 1, 1},    // 4 9
     {0, 1, 1, 0},    // 4 a
     {0, 1, 0, 1},    // 4 b
     {0, 1, 0, 1},    // 4 c
     {1, 0, 1, 1},    // 4 d
     {0, 1, 0, 0},    // 4 e
     {0, 1, 0, 1}},   // 4 f
    {{0, 1, 0, 1},    // 5 0
     {1, 0, 0, 1},    // 5 1
     {0, 0, 1, 0},    // 5 2
     {1, 1, 0, 0},    // 5 3
     {0, 0, 1, 1},    // 5 4
     {1, 1, 0, 0},    // 5 5
     {1, 0, 1, 1},    // 5 6
     {0, 0, 0, 0},    // 5 7
     {1, 1, 1, 0},    // 5 8
     {1, 0, 0, 1},    // 5 9
     {1, 1, 0, 0},    // 5 a
     {0, 1, 0, 1},    // 5 b
     {0, 0, 1, 1},    // 5 c
     {1, 1, 0, 0},    // 5 d
     {0, 1, 0, 1},    // 5 e
     {0, 1, 0, 1}},   // 5 f
    {{0, 1, 0, 1},    // 6 0
     {0, 0, 0, 1},    // 6 1
     {1, 0, 1, 0},    // 6 2
     {0, 0, 1, 0},    // 6 3
     {1, 1, 0, 0},    // 6 4
     {0, 1, 0, 1},    // 6 5
     {1, 0, 1, 1},    // 6 6
     {0, 0, 0, 0},    // 6 7
     {1, 0, 1, 0},    // 6 8
     {0, 1, 1, 0},    // 6 9
     {0, 1, 0, 1},    // 6 a
     {0, 0, 1, 1},    // 6 b
     {1, 1, 0, 0},    // 6 c
     {0, 1, 0, 1},    // 6 d
     {0, 1, 0, 1},    // 6 e
     {0, 1, 0, 1}},   // 6 f
    {{0, 1, 0, 1},    // 7 0
     {0, 0, 1, 1},    // 7 1
     {1, 0, 1, 0},    // 7 2
     {1, 1, 0, 0},    // 7 3
     {0, 1, 0, 1},    // 7 4
     {0, 0, 1, 1},    // 7 5
     {1, 1, 0, 0},    // 7 6
     {0, 0, 0, 1},    // 7 7
     {1, 1, 0, 0},    // 7 8
     {1, 0, 0, 1},    // 7 9
     {0, 1, 1, 0},    // 7 a
     {1, 1, 0, 1},    // 7 b
     {0, 1, 0, 1},    // 7 c
     {0, 1, 0, 1},    // 7 d
     {0, 1, 0, 1},    // 7 e
     {0, 1, 0, 1}},   // 7 f
    {{0, 1, 0, 1},    // 8 0
     {1, 0, 0, 1},    // 8 1
     {1, 0, 1, 0},    // 8 2
     {0, 1, 1, 0},    // 8 3
     {0, 1, 0, 1},    // 8 4
     {1, 0, 0, 1},    // 8 5
     {0, 1, 1, 0},    // 8 6
     {0, 0, 1, 1},    // 8 7
     {0, 1, 1, 0},    // 8 8
     {0, 0, 1, 1},    // 8 9
     {1, 1, 0, 0},    // 8 a
     {0, 0, 1, 1},    // 8 b
     {0, 1, 0, 0},    // 8 c
     {0, 1, 0, 1},    // 8 d
     {0, 1, 0, 1},    // 8 e
     {0, 1, 0, 1}},   // 8 f
    {{0, 1, 0, 1},    // 9 0
     {0, 0, 1, 1},    // 9 1
     {1, 0, 1, 0},    // 9 2
     {1, 1, 0, 0},    // 9 3
     {0, 0, 1, 1},    // 9 4
     {0, 0, 1, 0},    // 9 5
     {1, 1, 0, 0},    // 9 6
     {1, 0, 0, 1},    // 9 7
     {1, 1, 0, 0},    // 9 8
     {1, 0, 0, 1},    // 9 9
     {0, 1, 1, 0},    // 9 a
     {1, 0, 0, 1},    // 9 b
     {0, 1, 1, 0},    // 9 c
     {0, 1, 0, 1},    // 9 d
     {0, 1, 0, 1},    // 9 e
     {0, 1, 0, 1}},   // 9 f
    {{0, 1, 0, 1},    // a 0
     {1, 0, 0, 1},    // a 1
     {1, 0, 1, 0},    // a 2
     {0, 1, 1, 0},    // a 3
     {1, 0, 0, 1},    // a 4
     {1, 1, 0, 0},    // a 5
     {0, 0, 1, 1},    // a 6
     {0, 1, 1, 0},    // a 7
     {0, 0, 1, 1},    // a 8
     {0, 1, 1, 0},    // a 9
     {1, 1, 0, 1},    // a a
     {0, 1, 0, 1},    // a b
     {1, 0, 1, 1},    // a c
     {0, 1, 0, 0},    // a d
     {0, 1, 0, 1},    // a e
     {0, 1, 0, 1}},   // a f
    {{0, 1, 0, 1},    // b 0
     {0, 0, 0, 1},    // b 1
     {1, 0, 1, 0},    // b 2
     {1, 0, 1, 0},    // b 3
     {0, 1, 1, 0},    // b 4
     {0, 1, 0, 1},    // b 5
     {1, 0, 0, 1},    // b 6
     {1, 0, 0, 0},    // b 7
     {1, 0, 1, 0},    // b 8
     {1, 1, 0, 0},    // b 9
     {0, 0, 1, 1},    // b a
     {0, 1, 0, 0},    // b b
     {1, 0, 0, 1},    // b c
     {0, 1, 1, 0},    // b d
     {0, 1, 0, 1},    // b e
     {0, 1, 0, 1}},   // b f
    {{0, 1, 0, 1},    // c 0
     {0, 0, 0, 1},    // c 1
     {1, 1, 0, 0},    // c 2
     {1, 0, 0, 1},    // c 3
     {1, 1, 0, 0},    // c 4
     {0, 0, 1, 1},    // c 5
     {0, 1, 1, 0},    // c 6
     {0, 0, 1, 1},    // c 7
     {1, 0, 1, 0},    // c 8
     {0, 1, 0, 0},    // c 9
     {1, 0, 0, 1},    // c a
     {0, 1, 1, 0},    // c b
     {0, 1, 0, 1},    // c c
     {1, 1, 0, 1},    // c d
     {0, 1, 0, 1},    // c e
     {0, 1, 0, 1}},   // c f
    {{0, 1, 0, 1},    // d 0
     {0, 1, 0, 1},    // d 1
     {0, 0, 1, 1},    // d 2
     {0, 1, 1, 0},    // d 3
     {0, 0, 0, 1},    // d 4
     {1, 0, 0, 0},    // d 5
     {1, 1, 1, 0},    // d 6
     {1, 0, 0, 1},    // d 7
     {1, 1, 0, 0},    // d 8
     {0, 0, 1, 1},    // d 9
     {0, 0, 1, 0},    // d a
     {1, 1, 0, 0},    // d b
     {0, 1, 0, 1},    // d c
     {0, 0, 0, 1},    // d d
     {0, 1, 1, 0},    // d e
     {0, 1, 0, 1}},   // d f
    {{0, 1, 0, 1},    // e 0
     {0, 1, 0, 1},    // e 1
     {1, 1, 0, 1},    // e 2
     {1, 1, 0, 1},    // e 3
     {0, 1, 1, 1},    // e 4
     {0, 0, 1, 1},    // e 5
     {1, 0, 1, 0},    // e 6
     {0, 1, 1, 0},    // e 7
     {0, 0, 1, 1},    // e 8
     {1, 0, 1, 0},    // e 9
     {1, 0, 1, 0},    // e a
     {0, 0, 1, 0},    // e b
     {0, 1, 1, 0},    // e c
     {0, 1, 0, 1},    // e d
     {1, 0, 1, 1},    // e e
     {0, 1, 0, 0}},   // e f
    {{0, 1, 1, 1},    // f 0
     {0, 0, 1, 1},    // f 1
     {0, 0, 1, 0},    // f 2
     {0, 0, 1, 0},    // f 3
     {1, 0, 1, 0},    // f 4
     {1, 0, 1, 0},    // f 5
     {1, 0, 1, 0},    // f 6
     {1, 0, 1, 0},    // f 7
     {1, 0, 1, 0},    // f 8
     {1, 0, 1, 0},    // f 9
     {1, 0, 1, 0},    // f a
     {1, 0, 1, 0},    // f b
     {1, 0, 1, 0},    // f c
     {0, 0, 1, 0},    // f d
     {1, 0, 1, 0},    // f e
     {0, 1, 1, 0}}};  // f f

/*
    0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | a | b | c | d | e | f
-  --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
0 |       |                                               |       |
-      ---     --- --- --- --- --- --- --- --- ---
1 |           |                                   |   |   |   |   |
-      --- ---         --- --- --- --- --- ---     ---
2 |       |       |   |                               |       |   |
-      ---     ---         ---     ---     --- ---     --- ---
3 |   |               |   |           |   |       |           |   |
-      ---     --- ---     ---     ---                 ---
4 |   |           |       |           |       |   |   |       |   |
-      ---     ---     --- ---     --- --- ---         ---
5 |   |           |       |           |       |   |       |   |   |
-          ---     ---     ---     ---             ---
6 |   |               |   |               |   |       |   |   |   |
-          --- ---         ---     --- ---     ---
7 |   |           |   |       | G   G |       |   |   |   |   |   |
-      --- ---         ---                 ---
8 |   |           |   |       | G   G |       |       |   |   |   |
-          --- ---         --- --- --- ---     ---
9 |   |           |           |       |       |       |   |   |   |
-      --- ---     --- ---                 ---     ---
a |   |           |       |       |       |   |   |       |   |   |
-          --- ---         --- --- --- ---         ---
b |   |               |   |               |       |       |   |   |
-          --- --- ---             ---     ---         ---
c |   |       |       |       |           |       |   |   |   |   |
-                      --- --- --- ---         ---
d |   |   |       |           |       |           |   |       |   |
-          --- ---         ---         --- ---             ---
e |   |   |   |   |   |           |                   |   |       |
-                  --- --- --- --- --- --- --- --- ---     ---
f | S |                                                           |
-  --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
*/