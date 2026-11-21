
#include <iostream>
using namespace std;

class WindowBox {
private:
    int width;
    int height;

public:
    WindowBox() {
        width = 0;
        height = 0;
    }

    WindowBox& setWidth(int w) {
        width = w;
        return *this;
    }

    WindowBox& setHeight(int h) {
        height = h;
        return *this;
    }

    void display() {
        cout << "Window: "
             << width << " x " << height << endl;
    }
};

int main() {
    WindowBox box;

    box.setWidth(800).setHeight(600);

    box.display();

    return 0;
}
