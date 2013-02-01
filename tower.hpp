#ifndef TOWER_HPP
#define TOWER_HPP

class disc_c;

class tower_c {
private:

	disc_c	*head;

public:

	void	push	(disc_c *disc);
	disc_c	*pop	();

	void	draw	(unsigned x);

	tower_c			();
	~tower_c		();
};


#endif	//TOWER_HPP

