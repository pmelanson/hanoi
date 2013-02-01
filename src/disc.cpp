#include "../disc.hpp"

disc_c::disc_c(unsigned size_) : size(size_) {}

disc_c::~disc_c() {
	delete next;	//so I only have to delete head to delete the entire list
}
