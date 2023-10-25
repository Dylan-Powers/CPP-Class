/*
 * map.cpp
 *
 *      Author: Dylan Powers
 */

#include "map.h"
using namespace std;

Map::Map() {
  for (int i = 0; i < WIDTH; i++) {
    for (int j = 0; j < HEIGHT; j++) {
      cells[i][j] = new MapCell(i, j, MapCell::CellType::EMPTY);
    }
  }
}

void Map::load() {
  string line;
  // Flushes the top line from the input
  getline(cin, line);
  for (int i = 0; i < HEIGHT; i++) {
    getline(cin, line);
    for (unsigned k = 0; k < line.length() - 2; ++k) {
      char character = line.at(k + 1);
      switch (character) {
        case '#':
          cells[k][i] = new MapCell(k, i, MapCell::CellType::PIT);
          break;
        case '*':
          cells[k][i] = new MapCell(k, i, MapCell::CellType::GOLD);
          break;
        case ' ':
          cells[k][i] = new MapCell(k, i, MapCell::CellType::EMPTY);
          break;
        default:
          cells[k][i] = new MapCell(k, i, MapCell::CellType::EMPTY, character);
          break;
      }
    }
  }
  // Flushes the bottom line from the input
  getline(cin, line);
}

void Map::write() {
  cout << "+--------------------+" << endl;
  for (int i = 0; i < HEIGHT; i++) {
    cout << "|";
    for (int k = 0; k < WIDTH; ++k) {
      cout << cells[k][i]->display();
    }
    cout << "|" << endl;
  }
  cout << "+--------------------+" << endl;
}

MapCell* Map::getCell(Robot::Location* location) {
  return cells[location->x][location->y];
}
