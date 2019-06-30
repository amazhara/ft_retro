#ifndef FT_RETRO_ENEMYSHOT_H
# define FT_RETRO_ENEMYSHOT_H

#include "AProperties.h++"
#include "Enemy.h++"

class EnemyShot : public AProperties {

public:

	EnemyShot( void );
	~EnemyShot( void );

	bool	getVisible( void );
	void	setVisible( bool );

	void 	move( int, int );
	void	draw( void );

private:

	bool _visible;
};


#endif //FT_RETRO_ENEMYSHOT_H
