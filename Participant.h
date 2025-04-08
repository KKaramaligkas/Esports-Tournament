#ifndef PARTICIPANT_H
#define PARTICIPANT_H
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"

#include <string>

// H klash tou participant
class Participant {
public:
    int id; // Xexoristo id gia ton participant
    std::string fullName; // Plires Onoma participant
    std::string country; // Xwra tou participant
    int ranking; // Rank tou participant
    int timestamp; // Timestamp gia thn eggrafh tou participant
    Participant* next; // Pointer ston epomeno participant ths listas

    // O constructor pou kanei initialize ton participant
    Participant(std::string fullName, std::string country, int id, int ranking, int timestamp);
};

#endif