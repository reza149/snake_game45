#include <iostream>
#include <cstdlib>
#include <vector>
#include "move_snake.hpp"
#include "play_board.hpp"

using namespace std;

void start_game()
{
    int score_limit;
    cout << "please enter your maximum winning score: ";
    cin >> score_limit;
    cout << "\n";
    char choose_char;
    cout << "\n\n";
    play_board game;
    move_snake do_move;
    game.set_snake_body();
    game.set_play_board();
    game.apple_maker();
    game.score = 0;
    game.update_play_board();
    game.hit_apple = false;
    do
    {
        game.set_play_board();
        if(game.eat_apple_test())
        {
            game.apple_maker();
            game.grow_snake();
            game.score = game.score + 1;
            game.hit_apple = false;
        }
        if(game.score == score_limit)
        {
            cout << "\n\n";
            cout << "********\n";
            cout << "\n\n";
            cout << "you win\n";
            break;
        }
        game.update_play_board();
        game.print_play_board();
        if(game.test_head_snake())
        {
            cout << "\n\n";
            cout << "********\n";
            cout << "\n\n";
            cout << "game over\n";
            break;
        }
        cout << "w: move up"<< "\t"<< "a: move left" << endl;
        cout << "d: move right" << endl;
        cout << "your score: " << game.score << endl;
        cout << "e: exit\n";
        cout << "enter char -> ";
        cin >> choose_char;
        do_move.set_move(choose_char, &game);
        cout << "\n\n\n";
        system("clear");
    } while (choose_char != 'e');
}

void menu()
{
    int choose;
    cout << "welcome to the apple snake game\n";
    do
    {
        cout << "1: start game\t"
             << "2: EXIT\n";
        cout << "Enter number -> ";
        cin >> choose;
        if (choose == 1)
        {
            start_game();
        }
        cout << "\n";
    } while (choose != 2);
    cout << "goodbye\n";
}

int main()
{
    menu();
}
// g++ -o game main.cpp