#include <iostream>
#include <string>

class Account {
protected:
    std::string accountNumber;
    double balance;

public:
    Account(const std::string& accNum, double initialBalance)
        : accountNumber(accNum), balance(initialBalance) {}

    virtual void deposit(double amount) {
        balance += amount;
        std::cout << "Deposited $" << amount << " into account " << accountNumber << std::endl;
    }

    virtual void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            std::cout << "Withdrawn $" << amount << " from account " << accountNumber << std::endl;
        } else {
            std::cout << "Insufficient funds in account " << accountNumber << std::endl;
        }
    }

    virtual void display() const {
        std::cout << "Account Number: " << accountNumber << ", Balance: $" << balance << std::endl;
    }
};

class SavingsAccount : public Account {
private:
    double interestRate;

public:
    SavingsAccount(const std::string& accNum, double initialBalance, double rate)
        : Account(accNum, initialBalance), interestRate(rate) {}

    void deposit(double amount) override {
    
        Account::deposit(amount);
        balance += amount * interestRate;
    }

    void display() const override {
        std::cout << "Savings Account Details: ";
        Account::display();
    }
};

class CheckingAccount : public Account {
private:
    double overdraftLimit;

public:
    CheckingAccount(const std::string& accNum, double initialBalance, double limit)
        : Account(accNum, initialBalance), overdraftLimit(limit) {}

    void withdraw(double amount) override {
      
        if (amount <= balance + overdraftLimit) {
            balance -= amount;
            std::cout << "Withdrawn $" << amount << " from checking account " << accountNumber << std::endl;
        } else {
            std::cout << "Exceeded overdraft limit in account " << accountNumber << std::endl;
        }
    }

    void display() const override {
        std::cout << "Checking Account Details: ";
        Account::display();
    }
};

int main() {
  
    SavingsAccount savings("SA001", 1000, 0.05);
    CheckingAccount checking("CA001", 500, 200);

   
    savings.deposit(500);
    savings.withdraw(200);
    savings.display();

    checking.withdraw(800);
    checking.deposit(200);
    checking.display();

    return 0;
}

