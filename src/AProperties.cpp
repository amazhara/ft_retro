#include "AProperties.h++"

AProperties::AProperties( void ) {
	_x = 10;
	_y = 10;
	_form = "";
}

int AProperties::getX( void ) const {
	return _x;
}

int AProperties::getY( void ) const {
	return _y;
}

void AProperties::setX(int x) {
	_x = x;
}

void AProperties::setY(int y) {
	if (y < 3)
		y = 3;
	_y = y;
}

std::string AProperties::getForm( void ) const {
	return _form;
}
