#ifndef FT_RETRO_SKY_H
# define FT_RETRO_SKY_H

#include "AProperties.h++"

class Sky : public AProperties {

public:

    Sky();
    ~Sky();

	bool	getVisible( void );
	void	setVisible( bool );

    void move( int, int );
	void draw( void );

private:

	bool 	_visible;
};


#endif //FT_RETRO_SKY_H
