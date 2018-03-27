/// @file unittest.h
/// @brief templates pour le test unitaire
#ifndef UNITEST_H
#define UNITEST_H

#include <iostream>
#include <string>

template <typename T>
void assertEquals(const T& expr, const T& resultatAttendu, const std::string& s) {
	std::cout << "Test " << s;
	if (expr == resultatAttendu)
		std::cout << " a reussi\n";
	else {	std::cout << " a ECHOUE ###\n";
			std::cout << "|" << expr << "| = |" << resultatAttendu << "|" << std::endl;
	}
}

void assertEqualsDouble(double x, double y, double precision,const std::string&s);
void assertTrue(bool, const std::string&);
void assertFalse(bool, const std::string&);

#endif
