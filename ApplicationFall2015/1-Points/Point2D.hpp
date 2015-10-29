#ifndef POINT2D_HPP
#define POINT2D_HPP
using namespace std;

class point2D{
public:
	point2D(int, int);
	int getCoordX()const;
	int getCoordY()const;
	void setCoordX(int);
	void setCoordY(int);
	friend ostream& operator<<(ostream&, const point2D&);
private:
	int coordinateX, coordinateY;
};

#endif