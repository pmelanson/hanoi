#include "tower.hpp"

#include "disc.hpp"
#include "globals.hpp"

#include <iostream>
using std::cout;
using std::endl;

void		tower_c::push(unsigned var) {
	if(debug) cout << "PUSHING " << var << "->" << head << endl;
	disc_c *disc = new disc_c(var, head);
	head = disc;
	++length;
}

unsigned	tower_c::pop() {
	if(!head) return 0;

	unsigned var = head->size;

	disc_c *temp = head;
	head = head->next;
	delete temp;

	return var;
}

unsigned	tower_c::peek() const {
	if(!head) return 0;
	return head->size;
}

unsigned	tower_c::operator[](unsigned n) const {
	if (n > length || !head) return 0;	//out of bounds

	disc_c *it = head;
	while(n && it) {
		it = it->next;
		--n;
	}

	if(!it) return 0;	//if 'it' has advanced beyond the end of the list
	return it->size;
}

tower_c::tower_c() : head(0x0), length(0) {
}

tower_c::tower_c(unsigned n) : head(0x0), length(0) {
	while(n) {
		push(n--);
	}
}

tower_c::~tower_c() {
	if(debug) cout << "DESTRUCTING TOWER\n";
	while(head) {
		disc_c *temp = head;
		head = head->next;
		delete temp;
	}
}
