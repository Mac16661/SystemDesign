#ifndef PAYMENTPROCESSOR_H
#define PAYMENTPROCESSOR_H

#include <mutex>
#include "Coin.h"
#include "Currency.h"

class PaymentProcessor {
    private:
        float currentAmount;
        mutable std::mutex mtx;

    public:
        PaymentProcessor() : currentAmount(0.0f) {}

        void acceptCoin(const Coin& coin){
            std::lock_guard<std::mutex> lock(mtx);
            currentAmount += coin.getValue();
        }

        void acceptCurrency(const Currency& currency){
            std::lock_guard<std::mutex> lock(mtx);
            currentAmount += currency.getValue();
        }

        float getCurrentAmount() const {
            std::lock_guard<std::mutex> lock(mtx);
            return currentAmount;
        }

        float calculateChange(float totalCost){
            std::lock_guard<std::mutex> lock(mtx);
            if(currentAmount >= totalCost){
                float change = currentAmount - totalCost;
                currentAmount = 0;
                return change;
            }
            return 0;
        }
};

#endif