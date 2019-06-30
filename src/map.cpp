#include "map.h++"

Map::Map( void ) {

	_running = 1;
	_frames  = 0;
	_amountEnem = 0;
	_amountShot = 0;
	_amountEnemShots = 0;
	_amountStars = 0;
	_input = ERR;
	_enemies = new Enemy[ENEMCOUNT];
	_shots = new Shot[SHOTSCOUNT];
	_enemyShots = new EnemyShot[SHOTSCOUNT];
	_stars = new Sky[STARSCOUNT];
	mapInit();
}

Map::~Map() {
//Destroy all entities
	endwin();
}

void	Map::mapInit() {
	initscr();
	noecho();
	cbreak();
	curs_set(FALSE);
	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE);
	start_color();
	init_pair(COLOR_0, COLOR_BLACK, COLOR_WHITE);
	init_pair(COLOR_1, COLOR_RED, COLOR_BLACK);
	init_pair(SCORE_PAIR, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(COLOR_3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(LIFE_PAIR, COLOR_GREEN, COLOR_BLACK);
	init_pair(COLOR_4, COLOR_BLUE, COLOR_BLACK);
	gettimeofday(&_prevTime, nullptr);
}

void	Map::placeEnemy( void )
{
	_amountEnem++;
	if (!_enemies[_amountEnem % ENEMCOUNT].getVisible() &&
		!(frameRate(_baseTime, _curTime) % clock() % 10))
	{
		_enemies[_amountEnem % ENEMCOUNT ].setVisible(true);
		_enemies[_amountEnem % ENEMCOUNT].setX(WW);
		_enemies[_amountEnem % ENEMCOUNT].setY((unsigned int)(clock() % (WH)));
	}
}

void	Map::placeStars( void ) {

	_amountStars++;
	if (!_stars[_amountStars % ENEMCOUNT].getVisible())
	{
		_stars[_amountStars % ENEMCOUNT ].setVisible(true);
		_stars[_amountStars % ENEMCOUNT].setX(WW);
		_stars[_amountStars % ENEMCOUNT].setY((unsigned int)(clock() % (WH)));
	}
}

void	Map::placeShot( void )
{
	_amountShot++;
	if (!_shots[_amountShot % SHOTSCOUNT].getVisible())
	{
		_shots[_amountShot % SHOTSCOUNT].setVisible(true);
		_shots[_amountShot % SHOTSCOUNT].setX(_player.getX() + 1);
		_shots[_amountShot % SHOTSCOUNT].setY(_player.getY());
	}
}

void Map::placeEnemyShot( Enemy & enem )
{
	if (!(clock() % 8) && enem.getVisible())
	{
		_amountEnemShots++;
		if (!_enemyShots[_amountEnemShots % SHOTSCOUNT].getVisible())
		{
			_enemyShots[_amountEnemShots % SHOTSCOUNT].setVisible(true);
			_enemyShots[_amountEnemShots % SHOTSCOUNT].setX(enem.getX() - 1);
			_enemyShots[_amountEnemShots % SHOTSCOUNT].setY(enem.getY());
		}
	}
}

uint32_t	Map::frameRate(struct timeval t1, struct timeval t2) {
	return (unsigned int)((t2.tv_sec * MCRSEC + t2.tv_usec) - (t1.tv_sec * MCRSEC + t1.tv_usec));
}

void	Map::move( void ) {

	for (int i = 0; i < ENEMCOUNT; i++) {
		if (_enemies[i].getVisible()){
			_enemies[i].move(0, _frames);
			if (_frames % 21 == 0)
				placeEnemyShot(_enemies[i]);
		}
	}
	for (int i = 0; i < SHOTSCOUNT; i++) {
		if (_shots[i].getVisible()){
			_shots[i].move(0, _frames);
		}
	}
	for (int i = 0; i < SHOTSCOUNT; i++) {
		if (_enemyShots[i].getVisible()){
			_enemyShots[i].move(0, _frames);
		}
	}
	for (int i = 0; i < STARSCOUNT; i++) {
		if (_stars[i].getVisible()){
			_stars[i].move( 0, _frames );
		}
	}
}

void	Map::draw( void ) {
	_player.draw();
	for (int i = 0; i < ENEMCOUNT; i++) {
		if (_enemies[i].getVisible()){
			_enemies[i].draw();
		}
	}
	for (int i = 0; i < SHOTSCOUNT; i++) {
		if (_shots[i].getVisible()){
			_shots[i].draw();
		}
	}
	for (int i = 0; i < SHOTSCOUNT; i++) {
		if (_enemyShots[i].getVisible()){
			_enemyShots[i].draw();
		}
	}
	for (int i = 0; i < STARSCOUNT; i++) {
		if (_stars[i].getVisible()){
			_stars[i].draw();
		}
	}
}

int		Map::check( void ) {
	if (_player.checkEnemCollision( _enemies ))
		return 1;
	for (int i = 0; i < SHOTSCOUNT; ++i) {
		if (_shots[i].getVisible())
			_shots[i].checkShotCollision( _enemies );
	}
	for (int i = 0; i < SHOTSCOUNT; ++i) {
		if (_enemyShots[i].getVisible())
			if (_enemyShots[ i ].getX() == _player.getX()
				&& _enemyShots[ i ].getY() == _player.getY())
				return 1;
	}
	return 0;
}

void	Map::game( void ) {

	 while (_running) {
		_input = getch();
		 if (_input == 'q' || _input == 'Q')
			 return ;
		 if (_input != ERR)
			 _input_tmp = _input;
		gettimeofday(&_curTime, nullptr);
		if (frameRate(_prevTime, _curTime) >= 40000) {
			erase();
			gettimeofday(&_prevTime, nullptr);
			if (_input_tmp == ' ')
				placeShot();
			placeEnemy();
			placeStars();
			check();
			_player.move( _input_tmp, _frames );
			move();
			draw();
			if (check())
				return;
			_prevTime = _curTime;
			_frames++;
			_input_tmp = ERR;
		}
	}
}
