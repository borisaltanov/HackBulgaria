#include <iostream>
#include "POINT2D.HPP";
using namespace std;

point2D::point2D(int coordX = 0, int coordY = 0) {
	coordinateX = coordX;
	coordinateY = coordY;
}

int point2D::getCoordX()const {
	return coordinateX;
}

int point2D::getCoordY()const {
	return coordinateY;
}
void point2D::setCoordX(int coordX) {
	coordinateX = coordX;
}
void point2D::setCoordY(int coordY) {
	coordinateY = coordY;
}

ostream& operator<<(ostream& os, const point2D& point)
{
	os << '(' << point.getCoordX() << ", " << point.getCoordY() << ')' << endl;
	return os;
}