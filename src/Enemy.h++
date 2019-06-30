#ifndef FT_RETRO_ENEMY_H
# define FT_RETRO_ENEMY_H

#include "AProperties.h++"

class Enemy : public AProperties {

public:

	Enemy( void );
	~Enemy( void );

	void	move( int, int );
	void	draw( void );

	bool			getVisible( void );
	void 			setVisible( bool );

private:

	bool		_visible;
};


#endif //FT_RETRO_ENEMY_H
