/*#include "Mtmchkin.h"
#include <string>
#include <iostream>
using std::istringstream;

void createTextFile(const string &filename, const string &input)
{
    std::ofstream file(filename);
    if(file){
        file << input;
    }
}

int main() {
    createTextFile("deck_file.txt", "Witch\nWitch\nWitch\nWitch\nWitch");
    istringstream in("2\nItay Healer\nPikachu Ninja");
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    std::cin.rdbuf(in.rdbuf());

    Mtmchkin game("deck_file.txt");
    while(!game.isGameOver() && game.getNumberOfRounds() < 100){
        game.playRound();
        game.printLeaderBoard();
    }

    std::cin.rdbuf(cinbuf);
    return 0;
}*/
