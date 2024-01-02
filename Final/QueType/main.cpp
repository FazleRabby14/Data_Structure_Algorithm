#include <iostream>
#include "quetype.cpp"

int main() {
    int numCoins, coinValue, amount;
    cin >> numCoins;
    QueType<int> coinsQueue;

    for (int i = 0; i < numCoins; i++) {
        cin >> coinValue;
        coinsQueue.Enqueue(coinValue);
    }

    cin >> amount;

    int coinCount = 0;
    while (amount > 0) {
        int coin;
        coinsQueue.Dequeue(coin);
        if (amount >= coin) {
            int numCoinsNeeded = amount / coin;
            coinCount += numCoinsNeeded;
            amount -= numCoinsNeeded * coin;
        }
    }

    cout << "Minimum number of coins: " << coinCount <<endl;

    return 0;
}
