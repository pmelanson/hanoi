#ifndef DISC_HPP
#define DISC_HPP

class disc_c {
private:

public:

	disc_c		*next;
	unsigned	size;

	void draw	(unsigned x, unsigned y);

	disc_c		(unsigned size_);
	~disc_c		();
};


#endif	//DISC_HPP

