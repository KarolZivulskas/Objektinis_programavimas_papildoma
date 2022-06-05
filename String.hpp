#pragma once

#include <regex>
#include <string>

using namespace std;

namespace String {
	bool isURL(const string&);
	string removeNonWordCharacters(const string&);
	string toLowerCase(string&);
};