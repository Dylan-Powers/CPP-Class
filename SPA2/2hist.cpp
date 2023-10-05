// SPA 2, Fall 2023, Dylan Powers

#include <iostream>
#include <cstdint>
#include <cmath>
#include <iomanip>
using namespace std;

const uint8_t HORIZONTAL_AXIS_INTERVAL = 10;

// Method to increment the count of a specific element in an array
void addToArray(uint16_t array[], uint16_t upper_bound, uint16_t lower_bound, int num) {
  if (lower_bound <= num && num <= upper_bound) {
    array[num - lower_bound] = array[num - lower_bound] + 1;
  } else {
    cout << "Error: value " << num << " is out of range" << endl;
  }
}

// Method to read the lower bound from user input
uint16_t readLowerBound() {
  uint16_t lower_bound;
  cin >> lower_bound;
  return lower_bound;
}

// Method to read the upper bound from user input
uint16_t readUpperBound() {
  uint16_t upper_bound;
  cin >> upper_bound;
  return upper_bound;
}

// Method to read input numbers and populate an array accordingly
void readInput(uint16_t input_array[], uint16_t upper_bound, uint16_t lower_bound) {
  int input_num;
  cin >> input_num;

  while (cin) {
    addToArray(input_array, upper_bound, lower_bound, input_num);
    cin >> input_num;
  }
}

// Method to clear/reset all elements in an array to zero
void clearArray(uint16_t array[], uint16_t array_size) {
  for (uint16_t i = 0; i < array_size; ++i) {
    array[i] = 0;
  }
}

// Method to find the longest row (maximum value) in an array
uint16_t longestRow(const uint16_t array[], uint16_t array_size) {
  uint16_t longest = 0;
  for (uint16_t i = 0; i < array_size; ++i) {
    uint16_t current = array[i];
    if (current > longest) {
      longest = current;
    }
  }

  return longest;
}

// Method to calculate the width of the horizontal axis for plotting
uint16_t axisWidth(const uint16_t array[], uint16_t array_size) {
  uint16_t longest_row = longestRow(array, array_size);
  uint16_t axis_width;
  if (longest_row <= HORIZONTAL_AXIS_INTERVAL) {
    axis_width = HORIZONTAL_AXIS_INTERVAL;
  } else if (longest_row % HORIZONTAL_AXIS_INTERVAL == 0) {
    axis_width = longest_row;
  } else {
    axis_width = longest_row + HORIZONTAL_AXIS_INTERVAL - longest_row % HORIZONTAL_AXIS_INTERVAL;
  }
  return axis_width;
}

// Method to draw rows representing the data
void drawRows(const uint16_t array[], uint16_t upper_bound, uint16_t lower_bound) {
  for (int64_t i = upper_bound; i >= lower_bound; --i) {
    cout << setw(3) << i << " |";
    for (uint16_t k = 0; k < array[i - lower_bound]; ++k) {
      cout << "#";
    }
    cout << endl;
  }
}

// Method to draw the horizontal axis for plotting
void drawHorizontalAxis(uint16_t axis_width) {
  cout << "    +";
  for (uint16_t i = 0; i < ceil(axis_width / static_cast<double>(HORIZONTAL_AXIS_INTERVAL)); ++i) {
    cout << "----+----+";
  }
  cout << endl;
}

// Method to label the horizontal axis with appropriate values
void labelHorizontalAxis(uint16_t axis_width) {
  cout << "    0";
  for (uint16_t i = 1; i <= axis_width; ++i) {
    if (i % 5 == 0) {
      cout << i;
    } else if (!(i % 5 == 1 && i >= HORIZONTAL_AXIS_INTERVAL)) {
      cout << " ";
    }
  }
  cout << endl;
}

// Main program entry point
int main() {
  uint16_t lower_bound = readLowerBound();
  uint16_t upper_bound = readUpperBound();
  uint16_t input_array_size = upper_bound - lower_bound + 1;
  uint16_t input_array [input_array_size];
  clearArray(input_array, input_array_size);

  readInput(input_array, upper_bound, lower_bound);

  uint16_t axis_width = axisWidth(input_array, input_array_size);
  drawRows(input_array, upper_bound, lower_bound);
  drawHorizontalAxis(axis_width);
  labelHorizontalAxis(axis_width);
}
