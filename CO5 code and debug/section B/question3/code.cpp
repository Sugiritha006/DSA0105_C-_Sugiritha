
#include <iostream>
using namespace std;

class GameObject {
public:
    virtual void update(double time) = 0;
    virtual void render() = 0;

    virtual ~GameObject() {
        cout << "GameObject destroyed." << endl;
    }
};

class ParticleSystem : public GameObject {
private:
    int *particles;
    int count;

public:
    ParticleSystem(int n) {
        count = n;
        particles = new int[count];

        for (int i = 0; i < count; i++) {
            particles[i] = i + 1;
        }

        cout << "Particle System Created." << endl;
    }

    void update(double time) override {
        cout << "Updating particles for "
             << time << " seconds." << endl;
    }

    void render() override {
        cout << "Rendering "
             << count << " particles." << endl;
    }

    ~ParticleSystem() {
        delete[] particles;
        cout << "Particle System Destroyed." << endl;
    }
};

int main() {
    GameObject *objects[2];

    objects[0] = new ParticleSystem(100);
    objects[1] = new ParticleSystem(200);

    for (int i = 0; i < 2; i++) {
        objects[i]->update(0.5);
        objects[i]->render();
    }

    for (int i = 0; i < 2; i++) {
        delete objects[i];
    }

    return 0;
}
