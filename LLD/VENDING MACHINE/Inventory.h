#ifndef INVENTORY_H
#define INVENTORY_H

#include <map>
#include <mutex>
#include "Product.h"

class Inventory{
    private:
        std::map<int, Product> product;
        mutable std::mutex mtx;

    public:
        void addProduct(const Product& product) {
            std::lock_guard<std::mutex> lock(mtx);
            proudct[product.getID()] = product;
        }

        Product* getProduct(int productID){
            std::lock_guard<std::mutex> lock(mtx);
            auto it = products.find(productID);
            if(it != products.end()){
                return &it->second;
            }
            return nullptr;
        }

        void updateQuantity(int productID, int quantity){
            std::lock_guard<std::mutex> lock(mtx);
            Product* product = getProduct(productID);
            if(product){
                product->restock(quantity);
            }
        }
};

#endif