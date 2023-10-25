/*
 * robot.h
 *      Author: Dylan Powers
 */

#ifndef ROBOT_H_
#define ROBOT_H_

#include "map.h"
#include <iostream>
#include <string>

// A robot which lives on a map at a particular x and y coordinate.
class Robot {
public:
  struct Location {
    int x, y;
  };

  enum class Direction {
    NORTH = 0,
    SOUTH,
    EAST,
    WEST
  };

  Robot(Map *map, int startx, int starty);
  // display robot status in the form of "Robot at 6, 7 (1 gold)" to cout
  void displayStatus() const;
  // move robot in specified direction (e/w/s/n), returning true
  //   if was able to move in that direction
  // Warning: this method can get long - be sure to write private messages
  //   to break it up
  bool move(Direction direction);
  // move robot in a series of directions, returning true if was
  //   able to complete the list of directions
  bool move(const std::string& commands);
private:
  static Direction charToDirection(char c);

  int gold;
  Map* map;
  Location location;
};

#endif /* ROBOT_H_ */
