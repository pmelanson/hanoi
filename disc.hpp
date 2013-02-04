#ifndef DISC_HPP
#define DISC_HPP

class disc_c {
private:

public:

	unsigned	size;
	disc_c		*next;
	const int	col;

	void		draw	(unsigned x, unsigned y) const;

	disc_c		(unsigned size_, disc_c *next_);
	~disc_c		();
};


#endif	//DISC_HPP

