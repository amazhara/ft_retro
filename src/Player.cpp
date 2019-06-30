#include "Player.h++"
#include "map.h++"

Player::Player( void ) {
	_form = "}";
}

Player::~Player( void ) {
	;
}

void Player::move( int key, int frameCount ) {
	if (!frameCount)
		return;
	if ((key == KEY_DOWN || key == 's' || key == 'S') && _y < WH)
		this->_y++;
	else if ((key == KEY_UP || key == 'w' || key == 'W') && _y > 3)
		this->_y--;
	if ((key == KEY_LEFT || key == 'a' || key == 'A') && _x > 1)
		this->_x--;
	else if ((key == KEY_RIGHT || key == 'd' || key == 'D') && _x < WW - 2)
		this->_x++;
}

void Player::draw()  {
	attron(COLOR_PAIR(2));
	mvprintw(_y, _x, _form.c_str());
	attroff(COLOR_PAIR(2));
}

int		Player::checkEnemCollision( Enemy *enemies ) {
	for (int i = 0; i < ENEMCOUNT; ++i) {
		if (enemies[i].getVisible())
			if (_x == enemies[i].getX()
				&& _y == enemies[i].getY()
				&& enemies[i].getVisible() == 1)
				return 1;
	}
	return 0;
}
