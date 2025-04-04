#include <iomanip>  // For setw()
#include <cstdlib>  // For system()
#include <limits>   // For clearing input buffer
#include <iostream>
#include "Participant.h"

Participant::Participant(std::string fullName, std::string country, int id, int ranking, int timestamp)
    : fullName(fullName), country(country), id(id), ranking(ranking), timestamp(timestamp), next(nullptr) {}

