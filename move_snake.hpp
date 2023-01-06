#ifndef MOVE_SNAKE_HPP
#define MOVE_SNAKE_HPP

#include<iostream>
#include<cstdlib>
#include<vector>
#include"play_board.hpp"

class move_snake
{
    public:
    friend class play_board;
    void set_move(char move_char, play_board* game);
    void a_move(play_board * game);
    void w_move(play_board * game);
    void d_move(play_board * game);


    private:

};

void move_snake::d_move(play_board * game)
{
    snake_body help;
    snake_body help2;
    int column = (*game).sb_arr[0].i_number - (*game).sb_arr[1].i_number;
    int row = (*game).sb_arr[0].j_number - (*game).sb_arr[1].j_number;
    switch(column)
    {
        case -1:
        help.i_number = (*game).sb_arr[0].i_number;
        help.j_number = (*game).sb_arr[0].j_number;
        (*game).sb_arr[0].i_number = (*game).sb_arr[0].i_number;
        (*game).sb_arr[0].j_number = (*game).sb_arr[0].j_number + 1;
        for(int i = 1; i < (*game).sb_arr.size(); i++)
        {
            help2.i_number = (*game).sb_arr[i].i_number;
            help2.j_number = (*game).sb_arr[i].j_number;
            (*game).sb_arr[i].i_number = help.i_number;
            (*game).sb_arr[i].j_number = help.j_number;
            help.i_number = help2.i_number;
            help.j_number = help2.j_number;
        }

        break;
        ///////
        case 1:
        help.i_number = (*game).sb_arr[0].i_number;
        help.j_number = (*game).sb_arr[0].j_number;
        (*game).sb_arr[0].i_number = (*game).sb_arr[0].i_number;
        (*game).sb_arr[0].j_number = (*game).sb_arr[0].j_number - 1;
        for(int i = 1; i < (*game).sb_arr.size(); i++)
        {
            help2.i_number = (*game).sb_arr[i].i_number;
            help2.j_number = (*game).sb_arr[i].j_number;
            (*game).sb_arr[i].i_number = help.i_number;
            (*game).sb_arr[i].j_number = help.j_number;
            help.i_number = help2.i_number;
            help.j_number = help2.j_number;
        }

        break;
        ///////
        case 0:
        if(row == 1)
        {
            help.i_number = (*game).sb_arr[0].i_number;
            help.j_number = (*game).sb_arr[0].j_number;
            (*game).sb_arr[0].i_number = (*game).sb_arr[0].i_number + 1;
            (*game).sb_arr[0].j_number = (*game).sb_arr[0].j_number;
            for(int i = 1; i < (*game).sb_arr.size(); i++)
            {
                help2.i_number = (*game).sb_arr[i].i_number;
                help2.j_number = (*game).sb_arr[i].j_number;
                (*game).sb_arr[i].i_number = help.i_number;
                (*game).sb_arr[i].j_number = help.j_number;
                help.i_number = help2.i_number;
                help.j_number = help2.j_number;
            }
        }
        if(row == -1)
        {
            help.i_number = (*game).sb_arr[0].i_number;
            help.j_number = (*game).sb_arr[0].j_number;
            (*game).sb_arr[0].i_number = (*game).sb_arr[0].i_number - 1;
            (*game).sb_arr[0].j_number = (*game).sb_arr[0].j_number;
            for(int i = 1; i < (*game).sb_arr.size(); i++)
            {
                help2.i_number = (*game).sb_arr[i].i_number;
                help2.j_number = (*game).sb_arr[i].j_number;
                (*game).sb_arr[i].i_number = help.i_number;
                (*game).sb_arr[i].j_number = help.j_number;
                help.i_number = help2.i_number;
                help.j_number = help2.j_number;
            }
        }
        break;
    }
}

void move_snake::a_move(play_board * game)
{
    snake_body help;
    snake_body help2;
    int column = (*game).sb_arr[0].i_number - (*game).sb_arr[1].i_number;
    int row = (*game).sb_arr[0].j_number - (*game).sb_arr[1].j_number;
    switch(column)
    {
        case -1:
        help.i_number = (*game).sb_arr[0].i_number;
        help.j_number = (*game).sb_arr[0].j_number;
        (*game).sb_arr[0].i_number = (*game).sb_arr[0].i_number;
        (*game).sb_arr[0].j_number = (*game).sb_arr[0].j_number - 1;
        for(int i = 1; i < (*game).sb_arr.size(); i++)
        {
            help2.i_number = (*game).sb_arr[i].i_number;
            help2.j_number = (*game).sb_arr[i].j_number;
            (*game).sb_arr[i].i_number = help.i_number;
            (*game).sb_arr[i].j_number = help.j_number;
            help.i_number = help2.i_number;
            help.j_number = help2.j_number;
        }
        break;

        case 1:
        help.i_number = (*game).sb_arr[0].i_number;
        help.j_number = (*game).sb_arr[0].j_number;
        (*game).sb_arr[0].i_number = (*game).sb_arr[0].i_number;
        (*game).sb_arr[0].j_number = (*game).sb_arr[0].j_number + 1;
        for(int i = 1; i < (*game).sb_arr.size(); i++)
        {
            help2.i_number = (*game).sb_arr[i].i_number;
            help2.j_number = (*game).sb_arr[i].j_number;
            (*game).sb_arr[i].i_number = help.i_number;
            (*game).sb_arr[i].j_number = help.j_number;
            help.i_number = help2.i_number;
            help.j_number = help2.j_number;
        }
        break;

        case 0:
        if(row == 1)
        {
            help.i_number = (*game).sb_arr[0].i_number;
            help.j_number = (*game).sb_arr[0].j_number;
            (*game).sb_arr[0].i_number = (*game).sb_arr[0].i_number - 1;
            (*game).sb_arr[0].j_number = (*game).sb_arr[0].j_number;
            for(int i = 1; i < (*game).sb_arr.size(); i++)
            {
                help2.i_number = (*game).sb_arr[i].i_number;
                help2.j_number = (*game).sb_arr[i].j_number;
                (*game).sb_arr[i].i_number = help.i_number;
                (*game).sb_arr[i].j_number = help.j_number;
                help.i_number = help2.i_number;
                help.j_number = help2.j_number;
            }
        }
        if(row == -1)
        {
            help.i_number = (*game).sb_arr[0].i_number;
            help.j_number = (*game).sb_arr[0].j_number;
            (*game).sb_arr[0].i_number = (*game).sb_arr[0].i_number + 1;
            (*game).sb_arr[0].j_number = (*game).sb_arr[0].j_number;
            for(int i = 1; i < (*game).sb_arr.size(); i++)
            {
                help2.i_number = (*game).sb_arr[i].i_number;
                help2.j_number = (*game).sb_arr[i].j_number;
                (*game).sb_arr[i].i_number = help.i_number;
                (*game).sb_arr[i].j_number = help.j_number;
                help.i_number = help2.i_number;
                help.j_number = help2.j_number;
            }
        }

        break;
    }
}

void move_snake::w_move(play_board * game)
{
    snake_body help;
    snake_body help2;
    int column = (*game).sb_arr[0].i_number - (*game).sb_arr[1].i_number;
    int row = (*game).sb_arr[0].j_number - (*game).sb_arr[1].j_number;
    switch(column)
    {
        case -1:
        help.i_number = (*game).sb_arr[0].i_number;
        help.j_number = (*game).sb_arr[0].j_number;
        (*game).sb_arr[0].i_number = (*game).sb_arr[0].i_number - 1;
        (*game).sb_arr[0].j_number = (*game).sb_arr[0].j_number;
        for(int i = 1; i < (*game).sb_arr.size(); i++)
        {
            help2.i_number = (*game).sb_arr[i].i_number;
            help2.j_number = (*game).sb_arr[i].j_number;
            (*game).sb_arr[i].i_number = help.i_number;
            (*game).sb_arr[i].j_number = help.j_number;
            help.i_number = help2.i_number;
            help.j_number = help2.j_number;
        }
        break;

        case 1:
        help.i_number = (*game).sb_arr[0].i_number;
        help.j_number = (*game).sb_arr[0].j_number;
        (*game).sb_arr[0].i_number = (*game).sb_arr[0].i_number + 1;
        (*game).sb_arr[0].j_number = (*game).sb_arr[0].j_number;
        for(int i = 1; i < (*game).sb_arr.size(); i++)
        {
            help2.i_number = (*game).sb_arr[i].i_number;
            help2.j_number = (*game).sb_arr[i].j_number;
            (*game).sb_arr[i].i_number = help.i_number;
            (*game).sb_arr[i].j_number = help.j_number;
            help.i_number = help2.i_number;
            help.j_number = help2.j_number;
        }
        break;

        case 0:
        if(row == 1)
        {
            help.i_number = (*game).sb_arr[0].i_number;
            help.j_number = (*game).sb_arr[0].j_number;
            (*game).sb_arr[0].i_number = (*game).sb_arr[0].i_number;
            (*game).sb_arr[0].j_number = (*game).sb_arr[0].j_number + 1;
            for(int i = 1; i < (*game).sb_arr.size(); i++)
            {
                help2.i_number = (*game).sb_arr[i].i_number;
                help2.j_number = (*game).sb_arr[i].j_number;
                (*game).sb_arr[i].i_number = help.i_number;
                (*game).sb_arr[i].j_number = help.j_number;
                help.i_number = help2.i_number;
                help.j_number = help2.j_number;
            }
        }

        if(row == -1)
        {
            help.i_number = (*game).sb_arr[0].i_number;
            help.j_number = (*game).sb_arr[0].j_number;
            (*game).sb_arr[0].i_number = (*game).sb_arr[0].i_number;
            (*game).sb_arr[0].j_number = (*game).sb_arr[0].j_number - 1;
            for(int i = 1; i < (*game).sb_arr.size(); i++)
            {
                help2.i_number = (*game).sb_arr[i].i_number;
                help2.j_number = (*game).sb_arr[i].j_number;
                (*game).sb_arr[i].i_number = help.i_number;
                (*game).sb_arr[i].j_number = help.j_number;
                help.i_number = help2.i_number;
                help.j_number = help2.j_number;
            }
        }

        break;
    }
}

void move_snake::set_move(char move_char, play_board * game)
{
    switch(move_char)
    {
        case 'a':
        a_move(game);
        break;

        case 'w':
        w_move(game);
        break;

        case 'd':
        d_move(game);
        break;
    }
}

#endif 