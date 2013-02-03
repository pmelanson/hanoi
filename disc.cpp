#include "disc.hpp"

#include "globals.hpp"
#include <iostream>
using std::cout;
using std::endl;

disc_c::disc_c(unsigned size_) : size(size_), next(0x0) {
	if(debug) cout << "CONSTRUCTING " << size << "->" << next << endl;
}
disc_c::disc_c(unsigned size_, disc_c *next_) : size(size_), next(next_) {
	if(debug) cout << "CONSTRUCTING " << size << "->" << next << endl;
}

disc_c::~disc_c() {
	if(debug) cout << this << " IS DELETING";
}
