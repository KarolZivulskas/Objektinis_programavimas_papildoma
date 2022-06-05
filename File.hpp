#pragma once

#include <fstream>
#include <sstream>
#include <string>

using namespace std;

namespace File {
	bool exists(const string&);
	stringstream getBuffer(const string&);
	void saveBuffer(const string&, stringstream&);
};