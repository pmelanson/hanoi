#ifndef TOWER_HPP
#define TOWER_HPP

#include "globals.hpp"


class disc_c;

class tower_c {
private:

	disc_c			*head;
	const unsigned	x;

	const unsigned	width,
					height;
	const int		col;
public:
	unsigned		discs;

public:

	void			push	(unsigned var);
	unsigned		pop		(),
					peek	() const;
	disc_c*			operator[](unsigned n) const;

	void			draw	(unsigned spacing);

	tower_c					(unsigned x_);
	~tower_c				();
};


#endif	//TOWER_HPP

