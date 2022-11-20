#pragma once
#include<iostream>


using namespace std;


class figures {

private:

	struct triangle{
		double x1, y1, x2, y2, x3, y3;

		triangle(double x1, double y1, double x2, double y2, double x3, double y3) {
			this->x1 = x1;
			this->y1 = y1;
			this->x2 = x2;
			this->y2 = y2;
			this->x3 = x3;
			this->y3 = y3;
		}
	};

	struct squere {
		double x1, y1, x2, y2, x3, y3, x4, y4;

		squere(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {
			this->x1 = x1;
			this->y1 = y1;
			this->x2 = x2;
			this->y2 = y2;
			this->x3 = x3;
			this->y3 = y3;
			this->x4 = x4;
			this->y4 = y4;
		}
	};

	struct pentagon {
		double x1, y1, x2, y2, x3, y3, x4, y4, x5, y5;

		pentagon(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4, double x5, double y5) {
			this->x1 = x1;
			this->y1 = y1;
			this->x2 = x2;
			this->y2 = y2;
			this->x3 = x3;
			this->y3 = y3;
			this->x4 = x4;
			this->y4 = y4;
			this->x5 = x5;
			this->y5 = y5;
		}
	
	};

	double get_P(triangle a) {
		return (sqrt(pow((a.x2 - a.x1), 2) + pow((a.y2 - a.y1), 2)) + sqrt(pow((a.x3 - a.x2), 2) + pow((a.y3 - a.y2), 2)) + sqrt(pow((a.x3 - a.x1), 2) + pow((a.y3 - a.y1), 2)));
	}

	double get_P(squere a) {
		return (sqrt(pow((a.x2 - a.x1), 2) + pow((a.y2 - a.y1), 2)) + sqrt(pow((a.x3 - a.x2), 2) + pow((a.y3 - a.y2), 2)) + sqrt(pow((a.x3 - a.x4), 2) + pow((a.y3 - a.y4), 2)) + sqrt(pow((a.x1 - a.x4), 2) + pow((a.y1 - a.y4), 2)));
	}

	double get_P(pentagon a) {
		return (sqrt(pow((a.x2 - a.x1), 2) + pow((a.y2 - a.y1), 2)) + sqrt(pow((a.x3 - a.x2), 2) + pow((a.y3 - a.y2), 2)) + sqrt(pow((a.x3 - a.x4), 2) + pow((a.y3 - a.y4), 2)) + sqrt(pow((a.x5 - a.x4), 2) + pow((a.y5 - a.y4), 2)) + sqrt(pow((a.x5 - a.x1), 2) + pow((a.y5 - a.y1), 2)));
	}

	double get_S(squere a) {
		//  line1 = sqrt(pow((a.x2 - a.x1), 2) + pow((a.y2 - a.y1), 2));
		//  line2 = sqrt(pow((a.x2 - a.x3), 2) + pow((a.y2 - a.y3), 2));
		return sqrt(pow((a.x2 - a.x1), 2) + pow((a.y2 - a.y1), 2)) * sqrt(pow((a.x2 - a.x3), 2) + pow((a.y2 - a.y3), 2));
	}

	double get_S(triangle a) {
		double p = get_P(a)/2;
		return (sqrt(p*(p - sqrt(pow((a.x2 - a.x1), 2) + pow((a.y2 - a.y1), 2)))*(p - sqrt(pow((a.x3 - a.x2), 2) + pow((a.y3 - a.y2), 2)))*(p - sqrt(pow((a.x3 - a.x1), 2) + pow((a.y3 - a.y1), 2)))));

	}

	double get_S(pentagon a) {
		double line = sqrt(pow((a.x2 - a.x1), 2) + pow((a.y2 - a.y1), 2));
		return (sqrt(5 * (5 + 2 * (sqrt(5)))) * pow(line,2) / 4);
	}

public:
	void demo() {
		triangle newTr = triangle(1, 1, 5, 1, 1, 4);

		squere newSq = squere(0, 0, 0, 5, 5, 5, 5, 0);

		pentagon newPn = pentagon(0,8,6,5,6,-1,-2,-4,-5,-3);

		cout << get_S(newPn);
	}

};