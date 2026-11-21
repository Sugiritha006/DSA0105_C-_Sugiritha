
#include <iostream>
using namespace std;

class Volume {
public:
    double computeVolume(double length,
                         double width = 1.0,
                         double height = 1.0) {
        return length * width * height;
    }

    double computeVolume(double side) = delete;

    double computeCylinderVolume(double radius, double height) {
        return 3.14159 * radius * radius * height;
    }
};

int main() {
    Volume v;

    cout << "Volume of Box: "
         << v.computeVolume(5.0, 3.0, 7.0) << endl;

    cout << "Volume of Cube: "
         << v.computeVolume(5.0, 5.0, 5.0) << endl;

    cout << "Volume of Cylinder: "
         << v.computeCylinderVolume(3.0, 7.0) << endl;

    return 0;
}
