
#include <iostream>
using namespace std;

class Point2D {
private:
    double x, y;

public:
    Point2D(double a = 0, double b = 0) {
        x = a;
        y = b;
    }

    Point2D& setCenter(double a, double b) {
        x = a;
        y = b;
        return *this;
    }

    void display() const {
        cout << "(" << x << ", " << y << ")";
    }
};

class Circle {
private:
    Point2D centerPoint;
    double radius;

public:
    Circle() {
        radius = 1.0;
    }

    Circle& setCenter(double x, double y) {
        centerPoint.setCenter(x, y);
        return *this;
    }

    Circle& setRadius(double r) {
        if (r > 0)
            radius = r;

        return *this;
    }

    void draw() const {
        cout << "Circle Center: ";
        centerPoint.display();

        cout << "\nRadius: " << radius << endl;
    }
};

int main() {
    Circle circle;

    circle.setCenter(12, 30)
          .setRadius(7);

    circle.draw();

    return 0;
}
