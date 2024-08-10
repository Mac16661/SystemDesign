#ifndef COIN_H
#define COIN_H

enum class CoinType {
    TEN,
    TWENTY,
    FIFTY,
    HUNDRED,
    TWO_HUNDRED
};

class Coin{
    private:
        CoinType type;
        float value;

    public:
        Coin(CoinType t) : type(t) {
            switch(t) {
                case CoinType::TEN: value = 10.0f; break;
                case CoinType::TWENTY: value = 20.0f; break;
                case CoinType::FIFTY: value = 50.0f; break;
                case CoinType::HUNDRED: value = 100.0f; break;
                case CoinType::TWO_HUNDRED: value = 200.0f; break;
            }
        }

        float getValue() const {
            return value;
        }
}

#endif