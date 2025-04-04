#ifndef PARTICIPANT_H
#define PARTICIPANT_H
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"


#include <string>

class Participant {
public:
    int id;
    std::string fullName;
	std::string country;
    int ranking;
    int timestamp;
    Participant* next;

    Participant(std::string fullName, std::string country, int id, int ranking, int timestamp);
};

#endif