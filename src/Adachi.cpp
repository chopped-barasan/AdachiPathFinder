#include "Adachi.h"

void Adachi::appendAroundTile(Tile& target) {
  Tile* arround;

  /*        check top tile        */
  if (target.index.upper - 1 >= 0) {
    // arround = &map[target.index.upper - 1][target.index.lower];  // top
    arround = &getTileOnMap(target.index.upper - 1, target.index.lower);  // top
#ifndef __IGNORE_WALL__
    if (arround->flags.enqueued != update_count &&
        (target.wall.top == 0 && arround->wall.bottom == 0) &&
        arround->flags.is_goal == 0) {
      arround->flags.enqueued = update_count;
      queue.enqueue(arround->index);
    }
#else
    if (arround->flags.enqueued != update_count &&
        arround->flags.is_goal == 0) {
      arround->flags.enqueued = 1;
      queue.enqueue(arround->index);
    }
#endif
  }
  /*        check bottom tile       */
  if ((uint32_t)target.index.upper + 1 < MAP_SIZE) {
    // arround = &map[target.index.upper + 1][target.index.lower];  // bottom
    arround = &getTileOnMap(target.index.upper + 1,
                            target.index.lower);  // bottom
#ifndef __IGNORE_WALL__
    if (arround->flags.enqueued != update_count &&
        (target.wall.bottom == 0 && arround->wall.top == 0) &&
        arround->flags.is_goal == 0) {
      arround->flags.enqueued = update_count;
      queue.enqueue(arround->index);
    }
#else
    if (arround->flags.enqueued != update_count &&
        arround->flags.is_goal == 0) {
      arround->flags.enqueued = update_count;
      queue.enqueue(arround->index);
    }
#endif
  }
  /*        check right tile        */
  if ((uint32_t)target.index.lower + 1 < MAP_SIZE) {
    arround =
        &getTileOnMap(target.index.upper, target.index.lower + 1);  // right
#ifndef __IGNORE_WALL__
    if (arround->flags.enqueued != update_count &&
        (target.wall.right == 0 && arround->wall.left == 0) &&
        arround->flags.is_goal == 0) {
      arround->flags.enqueued = update_count;
      queue.enqueue(arround->index);
    }
#else
    if (arround->flags.enqueued != update_count &&
        arround->flags.is_goal == 0) {
      arround->flags.enqueued = update_count;
      queue.enqueue(arround->index);
    }
#endif
  }
  /*        check left tile       */
  if (target.index.lower - 1 >= 0) {
    arround =
        &getTileOnMap(target.index.upper, target.index.lower - 1);  // left
#ifndef __IGNORE_WALL__
    if (arround->flags.enqueued != update_count &&
        (target.wall.left == 0 && arround->wall.right == 0) &&
        arround->flags.is_goal == 0) {
      arround->flags.enqueued = update_count;
      queue.enqueue(arround->index);
    }
#else
    if (arround->flags.enqueued != update_count &&
        arround->flags.is_goal == 0) {
      arround->flags.enqueued = update_count;
      queue.enqueue(arround->index);
    }
#endif
  }
}

void Adachi::updateMap(void) {
  //   Index goals[4];
  //   uint32_t goal_length = getGoals(goals);

  update_count = update_count == 0 ? 1 : 0;

  for (uint8_t i = 0; i < goal_length; i++) {
    queue.enqueue(goals[i]);
    // map[goals[i].upper][goals[i].lower].flags.enqueued = update_count;
    getTileOnMap(goals[i].upper, goals[i].lower).flags.enqueued = update_count;
  }

  while (!queue.isEmpty()) {
    Index target;
    queue.dequeue(target);
    Tile& tile = getTileOnMap(target.upper, target.lower);

    setTileNum(tile);
    appendAroundTile(tile);
  }
}

bool Adachi::TileQueue::enqueue(Index& target) {
  if (num < LENGTH) {
    queue[(head + num) % LENGTH] = target;
    num++;
    return true;
  } else {
    return false;
  }
}

bool Adachi::TileQueue::dequeue(void) {
  if (num > 0) {
    head = (head + 1) % LENGTH;
    num--;
    return true;
  } else {
    return false;
  }
}

bool Adachi::TileQueue::dequeue(Index& output) {
  if (num > 0) {
    output = queue[head];
    head = (head + 1) % LENGTH;
    num--;
    return true;
  } else {
    return false;
  }
}

#ifdef __DEBUG__
void Adachi::TileQueue::printQueue(PathFinder& parents) const {
  for (uint32_t i = 0; i < LENGTH; i++) {
    if ((head + num <= LENGTH && head <= i && i < head + num) ||
        (head + num > LENGTH && (head <= i || i < (head + num) % LENGTH))) {
      // printf("%3d ", parents.map[queue[i].upper][queue[i].lower].number);
      printf("%3d:%-3d ", queue[i].upper, queue[i].lower);
    } else {
      printf("%3c ", '.');
    }
  }
  putchar('\n');
}
#endif