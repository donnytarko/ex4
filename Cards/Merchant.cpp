#include "Merchant.h"

void Merchant::applyEncounter (Player& player) {
    printMerchantInitialMessageForInteractiveEncounter(std::cout, player.getName(), player.getCoins());
    int response;
    int amountPayed = 0;
    std::cin >> response;
    while (response != 2 && response != 1 && response != 0 ) {
        printInvalidInput();
        printMerchantInitialMessageForInteractiveEncounter(std::cout, player.getName(), player.getCoins());
        std::cin >> response;
    }
    if (response == 1) {
        if (player.pay(5)) {
            player.heal(1);
            amountPayed = 5;
        }
        else {
            printMerchantInsufficientCoins(std::cout);
        }
    }
    if (response == 2) {
        if (player.pay(10)) {
            player.buff(1);
            amountPayed = 10;
        }
        else {
            printMerchantInsufficientCoins(std::cout);
        }
    }
    printMerchantSummary(std::cout, player.getName(), response, amountPayed);
}