#include <iomanip>
#include <iostream>
#include <string>

class Cart
{
private:
    std::string items[10];
    double prices[10];
    int n;
    double discount;

public:
    Cart()
        : n(0),
          discount(0)
    {
    }

    // Add item and return *this
    Cart& add(const std::string& item,
              double price)
    {
        if (n < 10)
        {
            items[n] = item;
            prices[n] = price;

            ++n;
        }

        return *this;
    }

    // this-> distinguishes member
    // from parameter
    Cart& setDiscount(double discount)
    {
        this->discount = discount;

        return *this;
    }

    double total() const
    {
        double t = 0;

        for (int i = 0; i < n; ++i)
        {
            t += prices[i];
        }

        return t *
               (100 - discount) /
               100;
    }

    void print() const
    {
        std::cout
            << "Cart total: "
            << std::fixed
            << std::setprecision(2)
            << total()
            << '\n';
    }
};

int main()
{
    // 1. Directly by name
    Cart c;

    c.add("Rice", 60)
     .add("Dal", 120)
     .setDiscount(10);

    // 2. Through pointer
    Cart* p = &c;

    p->add("Oil", 180);

    std::cout
        << "Direct/object pointer:\n";

    p->print();

    // 3. Through reference
    Cart& ref = c;

    ref.add("Sugar", 80);

    std::cout
        << "Through reference:\n";

    ref.print();

    // 4. Dynamically allocated object
    Cart* dynamicCart =
        new Cart();

    dynamicCart
        ->add("Milk", 50)
        .add("Bread", 40)
        .setDiscount(5);

    std::cout
        << "Dynamic cart:\n";

    dynamicCart->print();

    delete dynamicCart;

    // Array of pointers
    Cart cart1;
    Cart cart2;
    Cart cart3;

    cart1.add("Item A", 100);

    cart2.add("Item B", 200)
         .add("Item C", 100);

    cart3.add("Item D", 500)
         .setDiscount(10);

    Cart* carts[] =
    {
        &cart1,
        &cart2,
        &cart3
    };

    int count =
        sizeof(carts) /
        sizeof(carts[0]);

    int best = 0;

    for (int i = 1; i < count; ++i)
    {
        if (carts[i]->total() >
            carts[best]->total())
        {
            best = i;
        }
    }

    std::cout
        << "\nHighest cart total: "
        << std::fixed
        << std::setprecision(2)
        << carts[best]->total()
        << '\n';

    return 0;
}
