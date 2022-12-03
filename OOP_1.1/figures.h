#pragma once
#include<iostream>


using namespace std;

class figures {
public:
	struct triangle {
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
};

class functions : public figures {

protected:

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

	bool is_rectangle(squere a) {
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

	bool is_paralelogram(squere a) {
		if (sqrt(pow((a.x2 - a.x1), 2) + pow((a.y2 - a.y1), 2)) == sqrt(pow((a.x2 - a.x3), 2) + pow((a.y2 - a.y3), 2))
			== sqrt(pow((a.x3 - a.x4), 2) + pow((a.y3 - a.y4), 2)) == sqrt(pow((a.x1 - a.x4), 2) + pow((a.y1 - a.y4), 2))) {
			return true;
		}
		else {
			return false;
		}
	}

	bool is_romb(squere a) {
		if (is_paralelogram(a) && is_right(triangle(a.x1,a.y1,a.x2,a.y2,(a.x2 + a.x4)/2, (a.y2 + a.y4) / 2))){
			return true;
		}
		else return false;
	}

	bool is_squere(squere a) {
		if (is_rectangle(a) && 
			(sqrt(pow((a.x2 - a.x1), 2) + pow((a.y2 - a.y1), 2)) == sqrt(pow((a.x3 - a.x2), 2) + pow((a.y3 - a.y2), 2)) 
				== sqrt(pow((a.x3 - a.x4), 2) + pow((a.y3 - a.y4), 2)) == sqrt(pow((a.x1 - a.x4), 2) + pow((a.y1 - a.y4), 2)))) {
			return true;
		}
		else return false;
	}




};

template<class T>
class list : protected figures {
public:
	
	struct node {
		T data;
		struct node *next;
		
		node(T data) {
			this->data = data;
			this->next - nullptr;
		}

	};

	node *head = nullptr;

	void add(triangle A) {
		if (head == nullptr) {
			head->data = A;
			head->next = nullptr;
		}
		else {
			node* temp = head;
			while (temp->next != nullptr) {
				temp = temp->next;
			}
			node newNode(A);
			temp->next = &newNode;

		}
	}

	void print() {
		if (head == nullptr) {
			cout << "List is empty" << endl;
		}
		else {
			node* temp = head;
			
			do {
				cout << 1;
			} while (temp->next != nullptr);

		}
	}

};

class tests: functions,figures,list<figures::triangle> {
public:

void demo() {

	triangle newTr = triangle(1, 1, 5, 1, 1, 4);

	squere newSq = squere(0, 0, 0, 5, 5, 5, 5, 0);

	pentagon newPn = pentagon(0, 8, 6, 5, 6, -1, -2, -4, -5, -3);

	add(newTr);
}

};