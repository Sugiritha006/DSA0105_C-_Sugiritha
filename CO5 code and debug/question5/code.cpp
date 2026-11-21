
#include <iostream>
using namespace std;

class Entity {
public:
    virtual ~Entity() {}

    virtual void attack() {
        cout << "Entity performs generic attack."
             << endl;
    }

    virtual void display() const {
        cout << "Generic Entity." << endl;
    }
};

class Dragon : public Entity {
public:
    void attack() override {
        cout << "Dragon breathes scorching fire!"
             << endl;
    }

    void display() const override {
        cout << "Dragon Entity." << endl;
    }
};

// Pass by reference prevents object slicing
void triggerEncounter(const Entity &e) {
    e.attack();
}

int main() {
    Dragon boss;

    cout << "Entity Information: ";
    boss.display();

    triggerEncounter(boss);

    return 0;
}
