#ifndef VENDINGMACHINE_H
#define VENDINGMACHINE_H

#include <mutex>
#include "Inventory.h"
#include "PaymentProcessor.h"
#include "Display.h"

class vendingMachine {
    private:
        Inventory inventory;
        PaymentProcessor paymentProcessor;
        Display Display
        int selectProductID;

        static vendingMachine* instance;
        static std::mutex instanceMutex;
        std::mutex mtx;

        vendingMachine(): selectProductID(-1){}

    public:

        //Delete copy constructor and assignment operator to prevent copying
        vendingMachine(const vendingMachine) = delete;
        vendingMachine& operator=(const vendingMachine&) = delete;

        static VendingMachine* getInstace(){
            std::lock_guard<std::mutex> lock(instanceMutex);
            if(instance == nullptr) {
                instance = new VendingMachine();
            }
            return instance;
        }

        void selectProduct(int productID) {
            std::lock_guard<std::mutex> lock(mtx);
            selectProductID = productID;
        }

        void insertCoin(const Coin& coin) {
            paymentProcessor.acceptCoin(coin);
        }

        void insertCurrency(const Currency& currency){
            paymentProcessor.acceptCurrency(currency);
        }

        void dispenseProduct() {
            std::lock_guard<std::mutex> lock(mtx);
            Product* product = inventory.getProduct(selectProductID)
            if (product && product->getQuantity() > 0) {
            float totalCost = product->getPrice();
            float currentAmount = paymentProcessor.getCurrentAmount();
            if (currentAmount >= totalCost) {
                product->decrementQuantity();
                float change = paymentProcessor.calculateChange(totalCost);
                display.showMessage("Product dispensed: " + product->getName());
                if (change > 0) {
                    display.showMessage("Change returned: " + std::to_string(change));
                }
            } else {
                display.showMessage("Insufficient funds.");
            }
        } else {
            display.showMessage("Product out of stock.");
        }
    }

    void restockProduct(int productID, int quantity) {
        inventory.updateQuantity(productID, quantity);
        display.showMessage("Product restocked");
    }

    void collectMoney() {
        std::lock_guard<std::mutex> lock(mtx);
        display.showMessage("Money collected.");
    }

    void cancelTransaction() {
        std::lock_guard<std::mutex> lock(mtx);
        paymentProcessor.calculateChange(0); // Refund the amount
        display.showMessage("Transaction cancelled.");
    }

};

// Initialize the static members
VendingMachine* VendingMachine::instance = nullptr;
std::mutex VendingMachine::instanceMutex;

#endif