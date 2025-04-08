#include "ParticipantsList.h"
#include "ConsoleUtils.h"
#include <iostream>
#include <iomanip>
#include <set>

// edw ginontai oles oi praxeis me tous participants. exw valei ta erwthmata me tis lyseis tous sthn seira

ParticipantsList::ParticipantsList() : head(nullptr), isInitialized(false) {}
ParticipantsList::~ParticipantsList() {
	deleteAll();
}

bool ParticipantsList::isEmpty() const {
	return head == nullptr;
}

bool ParticipantsList::isLoaded() const {
	return isInitialized;
}

void ParticipantsList::setLoaded(bool value) {
	isInitialized = value;
}

void ParticipantsList::addAtEnd(Participant* newParticipant) {
	if (head == nullptr) {
		head = newParticipant;
	}
	else {
		Participant* temp = head;
		while (temp->next != nullptr) {
			temp = temp->next;
		}
		temp->next = newParticipant;
	}
}

// Erwtima 2
void ParticipantsList::addSortedByID(Participant* newPart) {
	if (head == nullptr || newPart->id < head->id) {
		newPart->next = head;
		head = newPart;
		return;
	}

	Participant* current = head;
	while (current->next != nullptr && current->next->id < newPart->id) {
		current = current->next;
	}

	newPart->next = current->next;
	current->next = newPart;
}

// Erwtima 3 edw efarmozoume bubble sort
void ParticipantsList::sortByRankingDescending() {
	if (!head || !head->next) {
		std::cout << "List has zero or one participant. No sorting needed.\n";
		return;
	}

	bool swapped;
	do {
		swapped = false;
		Participant* current = head;

		while (current->next != nullptr) {
			if (current->ranking < current->next->ranking) {
				std::swap(current->fullName, current->next->fullName);
				std::swap(current->country, current->next->country);
				std::swap(current->id, current->next->id);
				std::swap(current->ranking, current->next->ranking);
				std::swap(current->timestamp, current->next->timestamp);
				swapped = true;
			}
			current = current->next;
		}
	} while (swapped);

	std::cout << "List sorted by ranking (descending).\n";
}

// Erwtima 4
bool ParticipantsList::deleteByID(int id) {
	if (!head) {
		std::cout << "List is empty.\n";
		return false;
	}

	Participant* current = head;
	Participant* prev = nullptr;

	while (current != nullptr) {
		if (current->id == id) {
			if (prev == nullptr) {
				// Diagrafi tou prwtou node
				head = current->next;
			}
			else {
				prev->next = current->next;
			}
			std::string deletedName = current->fullName; // Store the name of the deleted participant

			delete current;
			std::cout << "Player with ID " << id << " and name " << deletedName << " deleted.\n";
			return true;
		}

		prev = current;
		current = current->next;
	}

	std::cout << "Player with ID " << id << " not found.\n";
	return false;
}

// Erwtima 5
void ParticipantsList::deleteAll() {
	Participant* current = head;
	while (current != nullptr) {
		Participant* next = current->next;
		delete current;
		current = next;
	}
	head = nullptr;
	isInitialized = false;
	std::cout << "All players deleted.\n";
}

// Erwtima 6
void ParticipantsList::searchByFullName(const std::string& fullName) const {
	if (!head) {
		std::cout << "The list is empty.\n";
		return;
	}

	Participant* current = head;
	while (current != nullptr) {
		if (current->fullName == fullName) {
			std::cout << "\nPlayer found:\n";
			std::cout << "--------------------------\n";
			std::cout << "Full Name : " << current->fullName << "\n";
			std::cout << "Country   : " << current->country << "\n";
			std::cout << "ID        : " << current->id << "\n";
			std::cout << "Ranking   : " << current->ranking << "\n";
			std::cout << "Timestamp : " << current->timestamp << "\n";
			pauseConsole();
			return;
		}
		current = current->next;
	}

	std::cout << "No player found with the name \"" << fullName << "\".\n";
	pauseConsole();
}


// Erwtima 7
void ParticipantsList::printParticipants() {
	if (head == nullptr) {
		std::cout << "The list is empty.\n";
		return;
	}

	std::cout << "\n" << YELLOW << std::setw(5) << "ID"
		<< std::setw(20) << "Name"
		<< std::setw(15) << "Country"
		<< std::setw(10) << "Ranking"
		<< std::setw(20) << "Timestamp" << RESET << "\n";
	std::cout << "----------------------------------------------\n";

	Participant* current = head;
	while (current != nullptr) {
		std::cout << std::setw(5) << current->id
			<< std::setw(20) << current->fullName
			<< std::setw(20) << current->country
			<< std::setw(10) << current->ranking
			<< std::setw(20) << current->timestamp << "\n";
		current = current->next;
	}
	pauseConsole();
}


// Erwtima 8
void ParticipantsList::printByTimestamp() const {
	if (!head) {
		std::cout << "The list is empty.\n";
		return;
	}

	std::set<const Participant*> printed;  // H printed xrhsimopoieitai gia na kratame tous hdh ektypwmenous participants

	std::cout << "\n" << YELLOW << std::setw(5) << "ID"
		<< std::setw(20) << "Name"
		<< std::setw(15) << "Country"
		<< std::setw(10) << "Ranking"
		<< std::setw(20) << "Timestamp" << RESET << "\n";
	std::cout << "--------------------------------------------------------------------------\n";

	int totalPrinted = 0;

	while (true) {
		const Participant* current = head;
		const Participant* earliest = nullptr;

		while (current != nullptr) {
			if (printed.find(current) == printed.end()) {
				if (!earliest || current->timestamp < earliest->timestamp) {
					earliest = current;
				}
			}
			current = current->next;
		}

		if (!earliest) break;  // All participants printed

		std::cout << std::setw(5) << earliest->id
			<< std::setw(20) << earliest->fullName
			<< std::setw(20) << earliest->country
			<< std::setw(10) << earliest->ranking
			<< std::setw(20) << earliest->timestamp << "\n";

		printed.insert(earliest);
		totalPrinted++;
	}

	pauseConsole();
}