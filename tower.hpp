#ifndef TOWER_HPP
#define TOWER_HPP

#include "globals.hpp"


class disc_c;

class tower_c {
private:

	disc_c		*head;
	unsigned	length;

public:

	void		push	(unsigned var);
	unsigned	pop		(),
				peek	() const;
	unsigned	operator[](unsigned n) const;

	void		draw	(unsigned x);

	tower_c				();
	tower_c				(unsigned n);
	~tower_c			();
};


#endif	//TOWER_HPP

