#include <iostream>
using namespace std;

/**
 * Struct to store the time, item, and amount of a single line of input
 */
struct FluidEvent {
    string time;
    string item;
    int amount = 0;
};

/*
 * Global variable used to track the current total of fluid.
 */
int fluidTotal = 0;

/**
 * Reads a single line from the input stream and returns the data in a FluidEvent
 *
 * @return FluidEvent containing the data read from the next line of the input stream.
 */
FluidEvent readLine() {
  FluidEvent fluidEvent;

  cin >> fluidEvent.time;
  cin >> fluidEvent.item;
  cin >> fluidEvent.amount;

  return fluidEvent;
}

/**
 * Adds the FluidEvent amount to the total and checks if a notification needs to be sent and sends it if so
 * @param fluidEvent
 */
void handleFluidAddEvent(FluidEvent fluidEvent) {
  fluidTotal += fluidEvent.amount;
  if (fluidTotal >= 1000) {
    cout << "after consuming " << fluidEvent.item << " at " << fluidEvent.time << ", intake exceeds output by " <<
      fluidTotal << " ml" << endl;
  }
}

/**
 * Analyzes the fluid event and determines if a notification needs to be sent and sends it if so
 * @param fluidEvent FluidEvent to process
 */
void handleFluidEvent(FluidEvent fluidEvent) {
  // If fluid has left the body
  if (fluidEvent.item == "urine" || fluidEvent.item == "bloodloss" || fluidEvent.item == "diarrhea") {
    fluidTotal -= fluidEvent.amount;
  } else {
    handleFluidAddEvent(fluidEvent);
  }
}

int main() {
  FluidEvent fluidEvent = readLine();

  while (cin) {
    handleFluidEvent(fluidEvent);
    fluidEvent = readLine();
  }

  cout << "the final fluid differential is " << fluidTotal << " ml" << endl;

  return 0;
}
