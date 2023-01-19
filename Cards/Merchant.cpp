#include "Merchant.h"
#include <string>

void Merchant::applyEncounter (Player& player) {
    printMerchantInitialMessageForInteractiveEncounter(std::cout, player.getName(), player.getCoins());
    std::string response_string;
    int amountPayed = 0;
    std::cin >> response_string;
    int response = std::stoi(response_string);
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