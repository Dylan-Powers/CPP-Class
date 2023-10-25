/*
 * robot.cpp
 *
 *      Author: Dylan Powers
 */

#include "robot.h"
using namespace std;

Robot::Robot(Map* map, int startx, int starty) :
    xLocation(startx),
    yLocation(starty),
    gold(0),
    map(map) {
  map->putRobot(xLocation, yLocation);
}

void Robot::displayStatus() const {
  cout << "Robot at " << xLocation << ", " << yLocation << " ("
       << gold << " gold)" << endl;
}

bool Robot::move(Direction direction) {
  switch (direction) {
    case Direction::NORTH:
      return yLocation > 0 && yLocation--;
    case Direction::SOUTH:
      return yLocation < Map::HEIGHT - 1 && yLocation++;
    case Direction::EAST:
      return xLocation < Map::WIDTH - 1 && xLocation++;
    case Direction::WEST:
      return xLocation > 0 && xLocation--;
    default:
      return false;
  }
}

bool Robot::move(string commands) {
  bool ableToComplete = true;

  for (char command : commands) {
    if (!move(charToDirection(command))) {
      ableToComplete = false;
    }
  }

  return ableToComplete;
}

Robot::Direction Robot::charToDirection(char c) {
  switch (c) {
    case 'n':
      return Direction::NORTH;
    case 's':
      return Direction::SOUTH;
    case 'e':
      return Direction::EAST;
    case 'w':
      return Direction::WEST;
    default:
      return Direction::NORTH;
  }
}
