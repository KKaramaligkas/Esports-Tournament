#ifndef PARTICIPANTSLIST_H
#define PARTICIPANTSLIST_H

#include "Participant.h"

class ParticipantsList {
private:
    Participant* head;
    bool isInitialized;
public:
    bool isLoaded() const;
    void setLoaded(bool value);

    ParticipantsList();
    ~ParticipantsList();

    bool isEmpty() const;
    void addAtEnd(Participant* newPart);  // insert at the end
    void addSortedByID(Participant* newPart); // insert sorted by ID //2
    void sortByRankingDescending();  // sort in-place by ranking (descending) //3
    bool deleteByID(int id); //4
    void deleteAll(); //5
    void searchByFullName(const std::string& fullName) const; //6
    void printParticipants();          // print current order //7
    void printByTimestamp() const; // print sorted by timestamp (without modifying list) //8
};

#endif
