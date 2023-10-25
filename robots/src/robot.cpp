/*
 * robot.cpp
 *
 *      Author: Dylan Powers
 */

#include "robot.h"
#include "map.h"
using namespace std;

Robot::Robot(Map* map, int startx, int starty) :
    location(new Location{startx, starty}),
    gold(0),
    map(map) {
  map->moveRobot(*location);
}

void Robot::displayStatus() const {
  cout << "Robot at " << location->x << ", " << location->y << " ("
       << gold << " gold)" << endl;
}

bool Robot::move(Direction direction) {
  switch (direction) {
    case Direction::NORTH:
      if (location->y > 0) {
        location->y--;
        map->moveRobot(*location);
        return true;
      }
      return false;
    case Direction::SOUTH:
      if (location->y < Map::HEIGHT - 1) {
        location->y++;
        map->moveRobot(*location);
        return true;
      }
      return false;
    case Direction::EAST:
      if (location->x < Map::WIDTH - 1) {
        location->x++;
        map->moveRobot(*location);
        return true;
      }
      return false;
    case Direction::WEST:
      if (location->x > 0) {
        location->x--;
        map->moveRobot(*location);
        return true;
      }
      return false;
    default:
      return false;
  }
}

bool Robot::move(const string& commands) {
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
