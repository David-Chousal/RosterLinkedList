/*
 * CSEN 79 Lab - RosterLList Main Test
 * Tests the linked list implementation of Roster
 */
#include <cstddef>
#include <fstream>
#include <string>
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "person.h"
#include "roster.h"
#include "rosterllist.h"

using namespace std;
using namespace csen79;


int main(int argc, char **argv) {
	// If there's a filename, send it to testRoster using std::cin
	std::ifstream inputFile;
	std::streambuf *origCin = nullptr;
	if (argc > 1) {
		inputFile.open(argv[1]);
		if (!inputFile.fail()) {
			origCin = std::cin.rdbuf();
			std::cin.rdbuf(inputFile.rdbuf());
		}
	}

	// I/O test (if there's a file)
	if (origCin != nullptr) {
		RosterLList r;
		r.testRoster();
		std::cin.rdbuf(origCin);
		inputFile.close();
	}

	// Programmatic tests
	RosterLList rlist;
	const int numToInsert = 100;
	
	// Insert elements
	for (int i = 0; i < numToInsert; ++i) {
		Person p(static_cast<Person::ID_t>(20000000 + i), 
		         "First" + std::to_string(i), 
		         "Last" + std::to_string(i));
		rlist.insert(p);
	}

	// Count elements
	int count = 0;
	for (auto it = rlist.begin(); it != rlist.end(); ++it)
		++count;
	std::cout << "[TEST] count after inserts: " << count << std::endl;

	// Erase some and recount
	rlist.erase(static_cast<Person::ID_t>(20000001));
	rlist.erase(static_cast<Person::ID_t>(20000050));
	rlist.erase(static_cast<Person::ID_t>(20000099));
	count = 0;
	for (auto it = rlist.begin(); it != rlist.end(); ++it)
		++count;
	std::cout << "[TEST] count after erases: " << count << std::endl;

	// Edge cases
	RosterLList emptyList;
	emptyList.erase(99999999);  // should not crash
	Person single(30000001, "Solo", "Person");
	emptyList.insert(single);
	emptyList.erase(30000001);
	std::cout << "[TEST] edge cases: PASSED" << std::endl;

	return EXIT_SUCCESS;
}
 