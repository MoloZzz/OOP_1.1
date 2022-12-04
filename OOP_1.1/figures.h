#pragma once
#include<iostream>


using namespace std;

class figures {
};

class triangle : public figures {
public:
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

class square : public figures {
public:
		double x1, y1, x2, y2, x3, y3, x4, y4;

		square(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {
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

class pentagon : public figures {
public:
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

class functions{
public:

	double get_P(triangle a) {
		return (sqrt(pow((a.x2 - a.x1), 2) + pow((a.y2 - a.y1), 2)) + sqrt(pow((a.x3 - a.x2), 2) + pow((a.y3 - a.y2), 2)) + sqrt(pow((a.x3 - a.x1), 2) + pow((a.y3 - a.y1), 2)));
	}

	double get_P(square a) {
		return (sqrt(pow((a.x2 - a.x1), 2) + pow((a.y2 - a.y1), 2)) + sqrt(pow((a.x3 - a.x2), 2) + pow((a.y3 - a.y2), 2)) + sqrt(pow((a.x3 - a.x4), 2) + pow((a.y3 - a.y4), 2)) + sqrt(pow((a.x1 - a.x4), 2) + pow((a.y1 - a.y4), 2)));
	}

	double get_P(pentagon a) {
		return (sqrt(pow((a.x2 - a.x1), 2) + pow((a.y2 - a.y1), 2)) + sqrt(pow((a.x3 - a.x2), 2) + pow((a.y3 - a.y2), 2)) + sqrt(pow((a.x3 - a.x4), 2) + pow((a.y3 - a.y4), 2)) + sqrt(pow((a.x5 - a.x4), 2) + pow((a.y5 - a.y4), 2)) + sqrt(pow((a.x5 - a.x1), 2) + pow((a.y5 - a.y1), 2)));
	}

	double get_S(square a) {
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

	bool is_right(triangle a) {
		if(    ((pow(sqrt(pow((a.x2 - a.x1), 2) + pow((a.y2 - a.y1), 2)), 2) + pow(sqrt(pow((a.x2 - a.x3), 2) + pow((a.y2 - a.y3), 2)), 2)
			== pow(sqrt(pow((a.x3 - a.x1), 2) + pow((a.y3 - a.y1), 2)), 2))) 
			|| ((pow(sqrt(pow((a.x2 - a.x3), 2) + pow((a.y2 - a.y3), 2)), 2) + pow(sqrt(pow((a.x1 - a.x3), 2) + pow((a.y1 - a.y3), 2)), 2)
				== pow(sqrt(pow((a.x2 - a.x1), 2) + pow((a.y2 - a.y1), 2)), 2))) 
			|| ((pow(sqrt(pow((a.x2 - a.x1), 2) + pow((a.y2 - a.y1), 2)), 2) + pow(sqrt(pow((a.x1 - a.x3), 2) + pow((a.y1 - a.y3), 2)), 2)
					== pow(sqrt(pow((a.x3 - a.x2), 2) + pow((a.y3 - a.y2), 2)), 2))) ) {
			return true;
		}
		else {
			return false;
		}
	}

	bool is_isosceles(triangle a) {
		if (sqrt(pow((a.x2 - a.x1), 2) + pow((a.y2 - a.y1), 2))
			== sqrt(pow((a.x3 - a.x2), 2) + pow((a.y3 - a.y2), 2))
			|| sqrt(pow((a.x2 - a.x3), 2) + pow((a.y2 - a.y3), 2))
			== sqrt(pow((a.x3 - a.x1), 2) + pow((a.y3 - a.y1), 2))
			|| sqrt(pow((a.x2 - a.x1), 2) + pow((a.y2 - a.y1), 2))
			== sqrt(pow((a.x3 - a.x1), 2) + pow((a.y3 - a.y1), 2))) {
			return true;
		}
		else false;
	}

	bool is_equilateral(triangle a) {
		if (sqrt(pow((a.x2 - a.x1), 2) + pow((a.y2 - a.y1), 2))
			== sqrt(pow((a.x3 - a.x2), 2) + pow((a.y3 - a.y2), 2))
			== sqrt(pow((a.x3 - a.x1), 2) + pow((a.y3 - a.y1), 2))) {
			return true;
		}
		else {
			return false;
		}
	}

	bool is_rectangle(square a) {
		/* 
		line1 = sqrt(pow((a.x2 - a.x1), 2) + pow((a.y2 - a.y1), 2))
		line2 = sqrt(pow((a.x2 - a.x3), 2) + pow((a.y2 - a.y3), 2))
		line3 = sqrt(pow((a.x3 - a.x4), 2) + pow((a.y3 - a.y4), 2))
		line4 = sqrt(pow((a.x4 - a.x1), 2) + pow((a.y4 - a.y1), 2))
		*/

		if ((pow(sqrt(pow((a.x2 - a.x1), 2) + pow((a.y2 - a.y1), 2)),2) + pow(sqrt(pow((a.x2 - a.x3), 2) + pow((a.y2 - a.y3), 2)),2) 
			== pow(sqrt(pow((a.x3 - a.x1), 2) + pow((a.y3 - a.y1), 2)), 2)) 
			|| (pow(sqrt(pow((a.x3 - a.x4), 2) + pow((a.y3 - a.y4), 2)), 2) + pow(sqrt(pow((a.x4 - a.x1), 2) + pow((a.y4 - a.y1), 2)), 2)
				== pow(sqrt(pow((a.x3 - a.x1), 2) + pow((a.y3 - a.y1), 2)), 2))){
			if ((sqrt(pow((a.x2 - a.x1), 2) + pow((a.y2 - a.y1), 2)) == sqrt(pow((a.x3 - a.x4), 2) + pow((a.y3 - a.y4), 2))
				&& sqrt(pow((a.x1 - a.x4), 2) + pow((a.y1 - a.y4), 2)) == sqrt(pow((a.x3 - a.x2), 2) + pow((a.y3 - a.y2), 2)))
				|| (sqrt(pow((a.x2 - a.x3), 2) + pow((a.y2 - a.y3), 2)) == sqrt(pow((a.x4 - a.x1), 2) + pow((a.y4 - a.y1), 2))
					&& sqrt(pow((a.x3 - a.x4), 2) + pow((a.y3 - a.y4), 2)) == sqrt(pow((a.x1 - a.x2), 2) + pow((a.y1 - a.y2), 2)))) {
				return true;
			}
			else return false;
			
		}
		else {
			return false;
		}
		
	}


	bool is_paralelogram(square a) {
		if (sqrt(pow((a.x2 - a.x1), 2) + pow((a.y2 - a.y1), 2)) == sqrt(pow((a.x2 - a.x3), 2) + pow((a.y2 - a.y3), 2))
			== sqrt(pow((a.x3 - a.x4), 2) + pow((a.y3 - a.y4), 2)) == sqrt(pow((a.x1 - a.x4), 2) + pow((a.y1 - a.y4), 2))) {
			return true;
		}
		else {
			return false;
		}
	}

	bool is_romb(square a) {
		if (is_paralelogram(a) && is_right(triangle(a.x1,a.y1,a.x2,a.y2,(a.x2 + a.x4)/2, (a.y2 + a.y4) / 2))){
			return true;
		}
		else return false;
	}

	bool is_squere(square a) {
		if (is_rectangle(a) && 
			(sqrt(pow((a.x2 - a.x1), 2) + pow((a.y2 - a.y1), 2)) == sqrt(pow((a.x3 - a.x2), 2) + pow((a.y3 - a.y2), 2)) 
				== sqrt(pow((a.x3 - a.x4), 2) + pow((a.y3 - a.y4), 2)) == sqrt(pow((a.x1 - a.x4), 2) + pow((a.y1 - a.y4), 2)))) {
			return true;
		}
		else return false;
	}




};

