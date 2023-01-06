#ifndef PLAY_BOARD_HPP
#define PLAY_BOARD_HPP

#include<iostream>
#include<cstdlib>
#include<vector>
#include"move_snake.hpp"

using namespace std;

struct snake_body
{
    int i_number;
    int j_number;
    char shape;
};

class play_board
{
    public:
    friend class move_snake;
    void set_play_board();
    void print_play_board();
    void set_snake_body();
    void update_play_board();
    void snake_state();

    private:
    char play_board[30][140];
    vector <snake_body> sb_arr;
};

void play_board::snake_state()
{
    for(int i = 0; i < sb_arr.size(); i++)
    {
        cout << "i = " << sb_arr[i].i_number << "j = " << sb_arr[i].j_number << "ch = " << sb_arr[i].shape << endl;
    }
}

void play_board::update_play_board()
{
    for(int i = 0; i < sb_arr.size(); i++)
    {
        if((sb_arr[i].i_number > 0) && (sb_arr[i].i_number < 29))
        {
            if((sb_arr[i].j_number > 0) && (sb_arr[i].j_number < 139))
            {
                if(i == 0)
                {
                    play_board[sb_arr[i].i_number][sb_arr[i].j_number] = sb_arr[i].shape;
                }
                else
                {
                    play_board[sb_arr[i].i_number][sb_arr[i].j_number] = sb_arr[i].shape;
                }
            }
        }
    }
}

void play_board::set_snake_body()
{
    snake_body help;
    help.i_number = 15;
    help.j_number = 40;
    help.shape = '>';
    sb_arr.push_back(help);
    help.i_number = 15;
    help.j_number = 39;
    help.shape = '+';
    sb_arr.push_back(help);
}

void play_board::set_play_board()
{
    for(int i = 0; i < 30; i++)
    {
        for(int j = 0; j < 140; j++)
        {
            if((i == 0) || (i == 29))
            {
                play_board[i][j] = '=';
            }
            else
            {
                if((j == 0) || (j == 139))
                {
                    play_board[i][j] = '|';
                }
                else
                {
                    play_board[i][j] = ' ';
                }
                
            }
        }
    }
}

void play_board::print_play_board()
{
    for(int i = 0; i < 30; i++)
    {
        for(int j = 0; j < 140; j++)
        {
            cout << play_board[i][j];
        }
        cout << "\n";
    }
}

#endif
