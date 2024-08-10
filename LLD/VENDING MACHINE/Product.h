#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product {
    private:
        int productID;
        std::string name;
        float price;
        int quantity;

    public:
        Product(int id, std::string n, float p, int q) : productID(id), name(n), price(p), quantity(q) {}

        int getID() const {
            return productID;
        }

        std::string getName() const {
            return name;
        }

        float getPrice() const {
            return price;
        }

        int getQuantity() const {
            return quantity;
        }

        void decrementQuantity() {
            if(quantity > 0) --quantity;
        }

        void restock(int q) {
            quantity += q;
        }
};

#endif