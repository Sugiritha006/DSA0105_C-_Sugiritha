
#include <iostream>
using namespace std;

class Shape {
public:
    Shape() {
        cout << "Shape created." << endl;
    }

    virtual void render() const {
        cout << "Rendering generic shape." << endl;
    }

    virtual ~Shape() {
        cout << "Shape destroyed." << endl;
    }
};

class ComplexPolygon : public Shape {
private:
    double *vertexArray;
    int vertexCount;

public:
    ComplexPolygon(int count) {
        vertexCount = count;
        vertexArray = new double[vertexCount * 2];

        cout << "Allocated " << vertexCount
             << " vertices on heap." << endl;
    }

    void render() const override {
        cout << "Rendering polygon with "
             << vertexCount << " vertices." << endl;
    }

    ~ComplexPolygon() {
        cout << "Deallocating polygon vertex memory."
             << endl;

        delete[] vertexArray;
    }
};

int main() {
    Shape *shapePtr = new ComplexPolygon(1000);

    shapePtr->render();

    delete shapePtr;

    return 0;
}
