#ifndef FT_RETRO_PLAYER_H
# define FT_RETRO_PLAYER_H

#include "AProperties.h++"
#include "Enemy.h++"
#include "shot.h++"

class Player : public AProperties {

public:

	Player( void );
	~Player( void );

	void 	move( int, int );
	void	draw( void );
	int		checkEnemCollision( Enemy *enemies );
};


#endif //FT_RETRO_PLAYER_H
