//============================================================================
// Name        : appointments.cpp
// Author      : Dylan Powers
//============================================================================

#include "appointments.h"
#include <string>
#include <iostream>
// add other includes as needed here, but appointments.h must be the FIRST include

bool before(Appointment a, Appointment b) {
  return earlier(a.date(), b.date());
}

Appointment::Appointment(Date date, std::string description) : _date{date} {
  char letter = description[0];
  while (letter == ' ') {
    description.erase(0, 1);
    letter = description[0];
  }

  letter = description[description.length() - 1];
  while (letter == ' ') {
    description.pop_back();
    letter = description[description.length() - 1];
  }

  _description = description;
}


void Schedule::add(Appointment new_appointment) {
  int pos = 0;
  while (pos < numAppointments && before(appointments[pos], new_appointment)) {
    ++pos;
  }

  // do not change any of the rest of this method
  for(int i = numAppointments; i > pos; --i)
    appointments[i] = appointments[i - 1];
  if ( pos < numAppointments )
    appointments[pos] = new_appointment;
  else
    appointments[numAppointments] = new_appointment;
  ++numAppointments;
}

void Schedule::write_to_cout() const {
  for (int i = 0; i < numAppointments; ++i) {
    std::cout << appointments[i].toString() << std::endl;
  }
}
