#ifndef FT_RETRO_SHOT_H
# define FT_RETRO_SHOT_H

#include "AProperties.h++"
#include "Enemy.h++"

class Shot : public AProperties {

public:

	Shot( void );
	~Shot( void );

	bool	getVisible( void );
	void	setVisible( bool );

	void 	move( int, int );
	void	draw( void );

	void checkShotCollision( Enemy *enemies );

private:

	bool _visible;
};


#endif //FT_RETRO_SHOT_H
