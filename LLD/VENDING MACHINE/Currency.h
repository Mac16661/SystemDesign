#ifndef CURRENCY_H
#define CURRENCY_H

enum class CurrencyType {
    FIVE_HUNDRED,
    THOUSHAND,
    TWO_THOUSHAND
};

class Currency {
    private:
        CurrencyType type;
        float value;

    public:
        Currency(CurrencyType t) : type(t) {
            switch(t) {
                case CurrencyType::FIVE_HUNDRED: value = 500.0f; break;
                case CurrencyType::THOUSHAND: value = 1000.0f; break;
                case CurrencyType::TWO_THOUSHAND: value = 2000.0f; break;
            }
        }

        float getValue() const{
            return value;
        }
};

#endif