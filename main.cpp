#include "Mtmchkin.h"

int main() {
    const int maxNumberOfRounds = 500;
    try {
        Mtmchkin game("deck.txt");
        while(!game.isGameOver() && game.getNumberOfRounds() < maxNumberOfRounds){
            game.playRound();
        }
        game.printLeaderBoard();
        return 0;   
    } catch(const DeckFileInvalidSize& e){
            std::cerr << e.what() << std::endl;
    } catch(const DeckFileNotFound& e){
            std::cerr << e.what() << std::endl;
    } catch(const DeckFileFormatError& e){
        std::cerr << e.what() << std::endl;
    }
}
