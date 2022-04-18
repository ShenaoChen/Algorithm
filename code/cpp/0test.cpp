#include <iostream>
#include <cassert>
using namespace std;
class point {
public:
	point() :x(0), y(0) {
		cout << "调用默认构造函数" << endl;
	}

	point(int x, int y) :x(x), y(y) {
		cout << "调用构造函数" << endl;
	}

	~point() { cout << "调用析构函数" << endl; }
	int getX() const { return x; }
	int getY() const { return y; }
	void move(int newX, int newY) {
		x = newX;
		y = newY;
	}

private:
	int x, y;
};
//动态数组类
class arrayofpoints {
public:
	arrayofpoints(int size) :size(size) {
		points = new point[size];
	}

	~arrayofpoints() {
		cout << "deleting..." << endl;
		// delete []points;
	}

	point &element(int index) {
		assert(index >= 0 && index < size);
		return points[index];
	}

private:
	point *points;
	int size;
};

int main()
{
	int count;
	count = 2;
	arrayofpoints pointsarray1(count);
		pointsarray1.element(0).move(5, 10);
		pointsarray1.element(1).move(15, 20);

		arrayofpoints pointsarray2 = pointsarray1;
		cout << "复制pointsarray1" << endl;
		cout << "point_0 of array2:" << pointsarray2.element(0).getX()<< "," << pointsarray2.element(0).getY() << endl;
		cout << "point_1 of array2:" << pointsarray2.element(1).getX()<< "," << pointsarray2.element(1).getY()<< endl;

		pointsarray1.element(0).move(25, 30);
		pointsarray1.element(1).move(35,40);

		cout << "pointsarray1偏移后:" << endl;
		cout << "point_0 of array2:" << pointsarray2.element(0).getX() << "," << pointsarray2.element(0).getY()<< endl;
		cout << "point_1 of array2:" << pointsarray2.element(1).getX() << "," << pointsarray2.element(1).getY()<< endl;
		return 0;
}