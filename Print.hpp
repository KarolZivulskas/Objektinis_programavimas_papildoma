#pragma once

#include <math.h>

#include <iomanip>
#include <map>
#include <string>
#include <vector>

#include "File.hpp"
#include "Data.hpp"

namespace Print {
	void crossReference(map<string, WordData>&, int, const string&);
	void urls(vector<string>&, const string&);
	void wordCound(map<string, WordData>&, const string&);
};