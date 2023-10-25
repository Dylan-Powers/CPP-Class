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
  static const char PIT_CHAR = '#';
  static const char GOLD_CHAR = '*';
  static const char ROBOT_CHAR = 'R';

  enum class CellType {
      EMPTY = 0,
      PIT,
      GOLD,
      ROBOT
  };

  MapCell(int x, int y, CellType type);
  MapCell(int x, int y, CellType type, char emptyChar);
  // true if pit at this location
  bool hasPit();
  // true if gold at this location
  bool hasGold();
  bool isRobot() const;
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

    int xLocation;
    int yLocation;
private:
    CellType cellType;
  char emptyChar;
  bool hasRobot;
};

#endif /* CELL_H_ */
