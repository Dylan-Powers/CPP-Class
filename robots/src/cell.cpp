/*
 * cell.cpp
 *
 *      Author: Dylan Powers
 */

#include "cell.h"

MapCell::MapCell(int x, int y, CellType type) {
  xLocation = x;
  yLocation = y;
  cellType = type;
  hasRobot = false;
}

bool MapCell::hasPit() {
  return cellType == CellType::PIT;
}

bool MapCell::hasGold() {
  return cellType == CellType::GOLD;
}

void MapCell::removeGold() {
  cellType = CellType::EMPTY;
}

bool MapCell::occupied() {
  return hasRobot || hasPit();
}

char MapCell::display() {
  if (hasRobot) {
    return ROBOT_CHAR;
  } else if (hasPit()) {
    return PIT_CHAR;
  } else if (hasGold()) {
    return GOLD_CHAR;
  } else {
    return EMPTY_CHAR;
  }
}

void MapCell::enter() {
  hasRobot = true;
}

void MapCell::vacate() {
  hasRobot = false;
}
