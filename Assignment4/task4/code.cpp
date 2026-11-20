#include <iostream>
#include <memory>
#include <vector>

class Account
{
public:
    virtual double rate() const
    {
        return 3.5;
    }

    virtual ~Account()
    {
        std::cout
            << "Account destructor\n";
    }
};

class SeniorAccount : public Account
{
private:
    double* history;

public:
    SeniorAccount()
        : history(new double[100])
    {
        std::cout
            << "SeniorAccount constructed\n";
    }

    double rate() const override
    {
        return 4.0;
    }

    ~SeniorAccount() override
    {
        delete[] history;

        std::cout
            << "SeniorAccount destructor\n";
    }
};

int main()
{
    std::vector<std::unique_ptr<Account>> accounts;

    accounts.push_back(
        std::make_unique<Account>()
    );

    accounts.push_back(
        std::make_unique<SeniorAccount>()
    );

    std::cout
        << "Interest rates:\n";

    for (const auto& account : accounts)
    {
        std::cout
            << account->rate()
            << '\n';
    }

    return 0;
}
