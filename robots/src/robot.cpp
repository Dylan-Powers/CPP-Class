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
  moveToCell(location, location);
}

void Robot::displayStatus() const {
  cout << "Robot at " << location->x << ", " << location->y << " ("
       << gold << " gold)";
}

bool Robot::move(Direction direction) {
  switch (direction) {
    case Direction::NORTH:
      return moveToCell(
              location,
              new Location{location->x, location->y - 1});
    case Direction::SOUTH:
      return moveToCell(
              location,
              new Location{location->x, location->y + 1});
    case Direction::EAST:
      return moveToCell(
              location,
              new Location{location->x + 1, location->y});
    case Direction::WEST:
      return moveToCell(
              location,
              new Location{location->x - 1, location->y});
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
  c = tolower(c);

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

bool Robot::moveToCell(Location* currentLocation, Location* newLocation) {
  MapCell* currentCell = getNewCell(currentLocation);
  MapCell* newCell = getNewCell(newLocation);

  if (!newCell->occupied()) {
    if (newCell->hasGold()) {
      gold++;
      newCell->removeGold();
    }

    location->x = newCell->xLocation;
    location->y = newCell->yLocation;
    currentCell->vacate();
    newCell->enter();
    return true;
  }

  return false;
}

MapCell *Robot::getNewCell(Robot::Location *newLocation) {
  // Wrap around if the newLocation is out of bounds
  if (newLocation->x < 0) {
    newLocation->x = Map::WIDTH - 1;
  } else if (newLocation->x >= Map::WIDTH) {
    newLocation->x = 0;
  } else if (newLocation->y < 0) {
    newLocation->y = Map::HEIGHT - 1;
  } else if (newLocation->y >= Map::HEIGHT) {
    newLocation->y = 0;
  }

  return map->getCell(newLocation);
}
