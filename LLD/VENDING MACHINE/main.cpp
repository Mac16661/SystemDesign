#include <thread>
#include "VendingMachine.h"
#include "Coin.h"
#include "Currency.h"
#include "Product.h"

void simulateTransaction(int productID, CoinType coinType, CurrencyType currencyType) {
    VendingMachine* vm = VendingMachine::getInstance();
    vm->selectProduct(productID);
    vm->insertCoin(Coin(coinType));
    vm->insertCurrency(Currency(currencyType));
    vm->dispenseProduct();
}

int main() {
    VendingMachine* vm = VendingMachine::getInstance();

    // Add products to the inventory
    Product p1(1, "Soda", 1.50f, 10);
    Product p2(2, "Chips", 1.00f, 5);
    Product p3(3, "Candy", 0.75f, 20);

    vm->restockProduct(1, 10);
    vm->restockProduct(2, 5);
    vm->restockProduct(3, 20);

    // Create threads to simulate concurrent transactions
    std::thread t1(simulateTransaction, 1, CoinType::HUNDRED, CurrencyType::FIVE_HUNDRED);
    std::thread t2(simulateTransaction, 2, CoinType::FIFTY, CurrencyType::THOUSAND);
    std::thread t3(simulateTransaction, 3, CoinType::TWENTY, CurrencyType::TWO_THOUSAND);

    // Wait for all threads to complete
    t1.join();
    t2.join();
    t3.join();

    return 0;
}