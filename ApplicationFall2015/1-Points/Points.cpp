#include <iostream>
#include <string>
#include "POINT2D.HPP"
using namespace std;

point2D resultCoodtinates(point2D, string);

int main() {
	int X, Y;
	cout << "Enter X coordinate: ";
	cin >> X;
	cout << "Enter Y coordinate: ";
	cin >> Y;
	point2D start(X, Y);
	string Path;
	cout << "Enter path: ";
	cin >> Path;
	cout << resultCoodtinates(start, Path);

	return 0;
}

point2D resultCoodtinates(point2D current, string path) {
	int counterWarp = 0;
	for (int i = 0; i <= path.size(); ++i) {
		switch (path[i]) {
		case '~': {
					  counterWarp++;
		}
			break;
		case '>': {
					  int tempX = current.getCoordX();
					  if (counterWarp % 2 == 0) {
						  current.setCoordX(++tempX);
						  break;
					  }
					  else {
						  current.setCoordX(--tempX);
						  break;
					  }
		}
			break;
		case '<': {
					  int tempX = current.getCoordX();
					  if (counterWarp % 2 == 0) {
						  current.setCoordX(--tempX);
						  break;
					  }
					  else {
						  current.setCoordX(++tempX);
						  break;
					  }
		}
			break;
		case '^': {
					  int tempY = current.getCoordY();
					  if (counterWarp % 2 == 0) {
						  current.setCoordY(--tempY);
						  break;
					  }
					  else {
						  current.setCoordY(++tempY);
						  break;
					  }
		}
			break;
		case 'v': {
					  int tempY = current.getCoordY();
					  if (counterWarp % 2 == 0) {
						  current.setCoordY(++tempY);
						  break;
					  }
					  else {
						  current.setCoordY(--tempY);
						  break;
					  }
		}
			break;
		}
	}
	return current;
}