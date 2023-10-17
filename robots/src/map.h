/*
 * map.h
 *
 *      Author: Dylan Powers
 */

#ifndef MAP_H_
#define MAP_H_

#include "cell.h"
#include <iostream>

// Track the area the robot in which the robot moves.
// Note you will need to add declarations for the height and width.
// Add other methods and data as needed.
class Map {
public:
  static const int WIDTH = 10;
  static const int HEIGHT = 20;

  // initialize empty map
  Map();
  // read the map from cin
  void load();
  // write the full map to cout
  void write();

private:
  MapCell *cells[WIDTH][HEIGHT];
};

#endif /* MAP_H_ */