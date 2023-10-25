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
  MapCell* cell = map->getCell(location);
  moveToCell(cell, cell);
}

void Robot::displayStatus() const {
  cout << "Robot at " << location->x << ", " << location->y << " ("
       << gold << " gold)";
}

bool Robot::move(Direction direction) {
  switch (direction) {
    case Direction::NORTH:
      return moveToCell(
              map->getCell(location),
              map->getCell(new Location{location->x, location->y - 1}));
    case Direction::SOUTH:
      return moveToCell(
              map->getCell(location),
              map->getCell(new Location{location->x, location->y + 1}));
    case Direction::EAST:
      return moveToCell(
              map->getCell(location),
              map->getCell(new Location{location->x + 1, location->y}));
    case Direction::WEST:
      return moveToCell(
              map->getCell(location),
              map->getCell(new Location{location->x - 1, location->y}));
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

bool Robot::moveToCell(MapCell* oldCell, MapCell* newCell) {
  if (!newCell->occupied() && !newCell->isOutOfBounds()) {
    if (newCell->hasGold()) {
      gold++;
      newCell->removeGold();
    }

    location->x = newCell->xLocation;
    location->y = newCell->yLocation;
    oldCell->vacate();
    newCell->enter();
    return true;
  }

  return false;
}
