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
  // gets rid of the top line
  getline(cin, line);
  for (int i = 1; i < HEIGHT - 1; i++) {
    getline(cin, line);
    for (int k = 0; k < line.length(); ++k) {
      switch (line.at(k)) {
        case '#':
          cells[k][i] = new MapCell(k, i, MapCell::CellType::PIT);
          break;
        case '*':
          cells[k][i] = new MapCell(k, i, MapCell::CellType::GOLD);
          break;
        case 'O':
          cells[k][i] = new MapCell(k, i, MapCell::CellType::ROBOT);
          break;
        default:
          break;
      }
    }
  }
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
