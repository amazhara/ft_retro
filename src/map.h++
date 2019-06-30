#ifndef FT_RETRO_MAP_H
# define FT_RETRO_MAP_H

#include "AProperties.h++"
#include "Player.h++"
#include "Enemy.h++"
#include "Sky.h++"
#include "shot.h++"
#include "EnemyShot.h++"
#include <sys/time.h>
#include <ncurses.h>
#include <stdint.h>
#include <unistd.h>

enum t_color {
	COLOR_0 = 0,
	COLOR_1,
	SCORE_PAIR,
	COLOR_3,
	LIFE_PAIR,
	COLOR_4
};

class Map {

public:

	Map( void );
	~Map();

	void		game( void );
	uint32_t	frameRate(struct timeval t1, struct timeval t2);
	void		mapInit();
	void		move( void );
	void		draw( void );
	void		placeEnemy( void );
	void		placeStars( void );
	void 		placeEnemyShot( Enemy & enem );
	void		placeShot( void );
	int		 	check( void );

private:

	bool			_running;
	Player			_player;
	Enemy			*_enemies;
	Shot			*_shots;
	EnemyShot		*_enemyShots;
	Sky				*_stars;
	int				_input;
	int				_input_tmp;
	struct timeval	_baseTime;
	struct timeval	_prevTime;
	struct timeval	_curTime;
	int				_frames;
	int 			_amountEnem;
	int 			_amountShot;
	int 			_amountEnemShots;
	int 			_amountStars;
};


#endif //FT_RETRO_MAP_H
