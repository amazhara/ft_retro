#include "EnemyShot.h++"

EnemyShot::EnemyShot() {
	_visible = false;
	_form = ".";
}

EnemyShot::~EnemyShot() {
	;
}

void	 EnemyShot::move( int key , int frames ) {
	(void)key;
	(void)frames;
	_x--;
	if (_x <= 5)
		_visible = false;
}

bool EnemyShot::getVisible( void ) {
	return _visible;
}

void EnemyShot::setVisible( bool a ) {
	_visible = a;
}

void	EnemyShot::draw( void ) {
	attron(COLOR_PAIR(3));
	mvprintw(_y, _x, _form.c_str());
	attroff(COLOR_PAIR(3));
}
