#include "Enemy.h++"

Enemy::Enemy( void ) {
	_form = "D";
	_visible = false;
}

Enemy::~Enemy( void ) {
	;
}

void Enemy::move( int key, int frameCount ) {
	(void)key;
	if(frameCount % 2 == 0)
		_x--;
	if (_x <= 5)
		_visible = false;
}

void	Enemy::draw( void ) {
	attron(COLOR_PAIR(1));
	mvprintw(_y, _x, _form.c_str());
	attroff(COLOR_PAIR(1));
}

bool Enemy::getVisible( void ) {
	return _visible;
}

void Enemy::setVisible( bool a ) {
	_visible = a;
}
