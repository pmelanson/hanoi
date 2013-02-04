#include "tower.hpp"

#include "disc.hpp"
#include "globals.hpp"

#include <allegro.h>
extern BITMAP *buffer;

#include <iostream>
using std::cout;
using std::endl;


void		tower_c::draw(unsigned spacing) {


	rectfill(buffer,	//draw base
			x*spacing - SCREEN_W/width, SCREEN_H/1.5 + SCREEN_H/height,
			x*spacing + SCREEN_W/width, SCREEN_H/1.5 - SCREEN_H/height,
			col);
	circlefill(buffer,	//round off left side
			x*spacing - SCREEN_W/width,
			SCREEN_H/1.5,
			SCREEN_H/height,
			col);
	circlefill(buffer,	//round off right side
			x*spacing + SCREEN_W/width,
			SCREEN_H/1.5,
			SCREEN_H/height,
			col);

	for(unsigned i = 0; i < discs; ++i) {
		operator[](i)->draw(x*spacing, SCREEN_H/1.514 - (discs - i) * 25);
	}
}


void		tower_c::push(unsigned var) {
	if(debug) cout << "PUSHING " << var << "->" << head << endl;
	++discs;
	head = new disc_c(var, head);
}

unsigned	tower_c::pop() {
	if(!head) return 0;

	unsigned var = head->size;

	disc_c *temp = head;
	head = head->next;
	delete temp;
	--discs;

	return var;
}

unsigned	tower_c::peek() const {
	if(!head) return 0;
	return head->size;
}

disc_c*		tower_c::operator[](unsigned n) const {
	if (!head) return NULL;	//empty list

	disc_c *it = head;
	while(n && it->next) {
		it = it->next;
		--n;
	}

	if(n) return NULL;
	return it;
}

tower_c::tower_c(unsigned x_) : head(0x0), x(x_), width(10), height(50), col(9056000 + x * 100), discs(0) {
}

tower_c::~tower_c() {
	if(debug) cout << "DESTRUCTING TOWER\n";
	while(head) {
		disc_c *temp = head;
		head = head->next;
		delete temp;
	}
}
