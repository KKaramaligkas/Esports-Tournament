// Esports Tournament.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "ParticipantsList.h"
#include "ConsoleUtils.h"
#include <iostream>
#include <fstream>  // Add this include directive at the top of the file
#include <sstream>
#include <algorithm>
#include <cstdlib>  // For system()
#include <limits>   // For clearing input buffer
#include <iomanip>
ParticipantsList participants;

void displayMenu() {
    std::cout << CYAN << "==== PLAYER MANAGEMENT MENU ====" << RESET << "\n";
    std::cout << GREEN << "1." << RESET << " Read players from file having the file's sort\n";
    std::cout << GREEN << "2." << RESET << " Read players sorted by ID\n";
    std::cout << GREEN << "3." << RESET << " Sort players by ranking\n";
    std::cout << GREEN << "4." << RESET << " Delete player by ID\n";
    std::cout << GREEN << "5." << RESET << " Delete all players\n";
    std::cout << GREEN << "6." << RESET << " Search player by Full Name(Name Surname)\n";
    std::cout << GREEN << "7." << RESET << " Print players\n";
    std::cout << GREEN << "8." << RESET << " Print players by timestamp\n";
    std::cout << RED << "9." << RESET << " Exit\n";
}

void readPlayersFromFile();
void clearScreen();
void pauseConsole();
void readPlayersSortedByID();
void deleteParticipantById();
void searchParticipantByFullName();

int main() {
    int choice;
    do {
        displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        clearScreen();  // Clear the screen


        switch (choice) {
        case 1: readPlayersFromFile(); break;
        case 2: readPlayersSortedByID(); break;
        case 3: participants.sortByRankingDescending(); break;
        case 4: deleteParticipantById(); break;
        case 5: participants.deleteAll(); break;
        case 6: searchParticipantByFullName(); break;
        case 7: participants.printParticipants(); break;
        case 8: participants.printByTimestamp(); break;
        case 9: std::cout << RED << "Exiting...\n" << RESET; break;
        default: std::cout << RED << "Invalid choice!\n" << RESET; pauseConsole();
        }
    } while (choice != 9);

    return 0;
}

// Erwtima 1
void readPlayersFromFile() {
    if (participants.isLoaded()) {
        std::cout << RED << "Error: The list is already loaded. Delete it first to reload." << RESET << "\n";
        return;
    }
    else {

    }

    std::string filename;
    std::cout << "Enter name of file containing player info: ";
    std::cin >> filename;

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Failed to open file.\n";
        return;
    }

    std::string line;
    while (getline(file, line)) {
        std::stringstream ss(line);
        std::string fullName, country, idStr, rankingStr, timestampStr;

        getline(ss, fullName, ',');     // Full Name
        getline(ss, idStr, ',');        // ID
        getline(ss, rankingStr, ',');   // Ranking
        getline(ss, country, ',');      // Country
        getline(ss, timestampStr);      // Timestamp

        int id = std::stoi(idStr);
        int ranking = std::stoi(rankingStr);
        int timestamp = std::stoi(timestampStr);

        Participant* p = new Participant(fullName, country, id, ranking, timestamp);
        participants.addAtEnd(p);
    }
    participants.setLoaded(true);
    std::cout << GREEN << "Players loaded successfully.\n";
}

void readPlayersSortedByID() {
    if (participants.isLoaded()) {
        std::cout << RED << "Error: The list is already loaded. Delete it first to reload." << RESET << "\n";
        return;
    }

    std::string filename;
    std::cout << "Enter name of file containing player info: ";
    std::cin >> filename;

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Failed to open file.\n";
        return;
    }

    std::string line;
    while (getline(file, line)) {
        std::stringstream ss(line);
        std::string fullName, country, idStr, rankingStr, timestampStr;

        getline(ss, fullName, ',');     // Full Name
        getline(ss, idStr, ',');        // ID
        getline(ss, rankingStr, ',');   // Ranking
        getline(ss, country, ',');      // Country
        getline(ss, timestampStr);      // Timestamp

        int id = std::stoi(idStr);
        int ranking = std::stoi(rankingStr);
        int timestamp = std::stoi(timestampStr);

        Participant* p = new Participant(fullName, country, id, ranking, timestamp);
        participants.addSortedByID(p);
    }

    participants.setLoaded(true);
    std::cout << GREEN << "Players loaded and inserted in order by ID.\n" << RESET;
}

void deleteParticipantById() {
    int id;
    std::cout << "Enter ID of the player to delete: ";
    std::cin >> id;
    participants.deleteByID(id);
    pauseConsole();  // So user sees the message
}

void searchParticipantByFullName()
{
    std::cin.ignore();  // Clear leftover newline
    std::string fullName;
    std::cout << "Enter full name (name and surname): ";
    std::getline(std::cin, fullName);
    participants.searchByFullName(fullName);
}