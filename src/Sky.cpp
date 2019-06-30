#include "Sky.h++"

Sky::Sky() {
	_form = "*";
	_visible = false;
}

Sky::~Sky() {
	;
}

void Sky::move( int key, int frameCount ) {
	(void)key;
	if(frameCount % 1 == 0)
		_x--;
	if (_x < 0)
		_visible = false;
}

bool Sky::getVisible( void ) {
	return _visible;
}

void Sky::setVisible( bool a ) {
	_visible = a;
}

void	Sky::draw( void ) {
	attron(COLOR_PAIR(5));
	mvprintw(_y, _x, _form.c_str());
	attroff(COLOR_PAIR(5));
}
