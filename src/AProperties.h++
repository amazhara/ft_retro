#ifndef FT_RETRO_PROPERTIES_H
# define FT_RETRO_PROPERTIES_H

# include <iostream>
# include <random>
# include <string>
# include <ncurses.h>

# define ENEMCOUNT 200
# define STARSCOUNT 10000
# define SHOTSCOUNT 100

# define WH 50
# define WW 100
# define MCRSEC		1000000

class AProperties {

public:

	AProperties( void );

	int 			getX() const;
	int 			getY() const;
	std::string 	getForm() const;

	void 			setX(int);
	void 			setY(int);

	virtual void move( int, int ) = 0;

protected:

	int 		_x;
	int 		_y;
	std::string	_form;

};

#endif //FT_RETRO_PROPERTIES_H
