/*
 * cell.cpp
 *
 *      Author: Dylan Powers
 */

#include "cell.h"
#include "map.h"

MapCell::MapCell(int x, int y, CellType type) :
    xLocation(x),
    yLocation(y),
    cellType(type),
    emptyChar(' '),
    hasRobot(type == CellType::ROBOT) {}

MapCell::MapCell(int x, int y, MapCell::CellType type, char emptyChar) :
    xLocation(x),
    yLocation(y),
    cellType(type),
    emptyChar(emptyChar),
    hasRobot(type == CellType::ROBOT) {}

bool MapCell::hasPit() {
  return cellType == CellType::PIT;
}

bool MapCell::hasGold() {
  return cellType == CellType::GOLD;
}

bool MapCell::isRobot() const {
  return hasRobot;
}

void MapCell::removeGold() {
  cellType = CellType::EMPTY;
}

bool MapCell::occupied() {
  return hasRobot || hasPit();
}

bool MapCell::isOutOfBounds() {
  return xLocation < 0 || xLocation >= Map::WIDTH ||
         yLocation < 0 || yLocation >= Map::HEIGHT;
}

char MapCell::display() {
  if (hasRobot) {
    return ROBOT_CHAR;
  } else if (hasPit()) {
    return PIT_CHAR;
  } else if (hasGold()) {
    return GOLD_CHAR;
  } else {
    return emptyChar;
  }
}

void MapCell::enter() {
  hasRobot = true;
  cellType = CellType::ROBOT;
}

void MapCell::vacate() {
  hasRobot = false;
  cellType = CellType::EMPTY;
}
