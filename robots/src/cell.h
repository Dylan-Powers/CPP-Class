/*
 * cell.h
 *
 *      Author: [TODO]
 */

#ifndef CELL_H_
#define CELL_H_

// Tracks the contents of a particular cell on the map.
// Is there gold at this location, is it occupied by a robot,
// is there a pit there? Each cell needs to track
// where it is on the grid (x, y) and the type of
// object at that location. The provided methods are suggestions;
// feel free to add/remove as needed.
class MapCell {
public:
  static const char EMPTY_CHAR = ' ';
  static const char PIT_CHAR = '#';
  static const char GOLD_CHAR = '*';
  static const char ROBOT_CHAR = 'O';

  enum class CellType {
      EMPTY = 0,
      PIT,
      GOLD,
      ROBOT
  };

  MapCell(int x, int y, CellType type);
  // true if pit at this location
  bool hasPit();
  // true if gold at this location
  bool hasGold();
  // remove the gold at this location
  void removeGold();
  // is this location occupied by something that the robot
  //   cannot move over?
  bool occupied();
  // return the character to display for this location
  char display();
  // robot enters location
  void enter();
  // robot leaves location
  void vacate();

private:
  int xLocation, yLocation;
  CellType cellType;
  bool hasRobot;
};

#endif /* CELL_H_ */