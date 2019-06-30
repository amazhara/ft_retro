#include "shot.h++"

Shot::Shot() {
	_visible = false;
	_form = ".";
}

Shot::~Shot() {
	;
}

void	 Shot::move( int key , int frames ) {
	(void)key;
	if(frames % 1 == 0)
		_x++;
	if (_x >= WW)
		_visible = false;
}

bool Shot::getVisible( void ) {
	return _visible;
}

void Shot::setVisible( bool a ) {
	_visible = a;
}

void 	Shot::checkShotCollision( Enemy *enemies ) {

	for (int i = 0; i < ENEMCOUNT; ++i) {
		if (enemies[i].getVisible())
			if (_x == enemies[i].getX()
				&& _y == enemies[i].getY()
				&& enemies[i].getVisible() == 1) {
					enemies[i].setVisible(false);
					this->setVisible(false);
			}
	}
}

void	Shot::draw( void ) {
	attron(COLOR_PAIR(4));
	mvprintw(_y, _x, _form.c_str());
	attroff(COLOR_PAIR(4));
}
