#include "disc.hpp"

#include "globals.hpp"
#include <allegro.h>
extern BITMAP *buffer;
#include <iostream>
using std::cout;
using std::endl;


void	disc_c::draw	(unsigned x, unsigned y) const {

	rectfill(buffer,	//draw left side of disc
			x - size *20, y - 10,
			x			, y + 10,
			col);
	rectfill(buffer,	//draw right side of disc
			x			, y - 10,
			x + size *20, y + 10,
			col);


}

disc_c::disc_c(unsigned size_, disc_c *next_) : size(size_), next(next_), col(size%2 ? size * 2236928 : size * 2228224) {
	if(debug) cout << "CONSTRUCTING " << size << "->" << next << endl;
}

disc_c::~disc_c() {
	if(debug) cout << this << " IS DELETING";
}
