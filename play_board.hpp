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

struct apple_st
{
    int i_apple;
    int j_apple;
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
    void apple_maker();
    void grow_snake();
    bool test_head_snake();
    bool eat_apple_test();
    
    bool hit_apple;
    int score;

    private:
    char play_board[30][140];
    vector <snake_body> sb_arr;
    apple_st apple;
    int help_make_apple;
};

bool play_board::test_head_snake()
{
    bool help = false;
    bool test1 = false;
    bool test2 = false;
    if((sb_arr[0].i_number == 0) || (sb_arr[0].i_number == 29))
    {
        help = true;
        return help;
    }
    if((sb_arr[0].j_number == 0) || (sb_arr[0].j_number == 139))
    {
        help = true;
        return help;
    }
    for(int i = 1; i < (sb_arr.size() - 1); i++)
    {
        if(sb_arr[0].i_number == sb_arr[i].i_number)
        {
            test1 = true;
        }
        if(sb_arr[0].j_number == sb_arr[i].j_number)
        {
            test2 = true;
        }
        if((test1 == true) && (test2 == true))
        {
            help = true;
            return help;
        }
        test1 = false;
        test2 = false;
    }
    return help;
}

void play_board::grow_snake()
{
    bool help2 = false;
    int help = 0;
    snake_body extra_body;
    extra_body.shape = '+';
    do
    {
        switch(help)
        {
            case 0:
            extra_body.i_number = sb_arr[sb_arr.size() - 1].i_number - 1;
            extra_body.j_number = sb_arr[sb_arr.size() - 1].j_number;

            break;
            /////////
            case 1:
            extra_body.i_number = sb_arr[sb_arr.size() - 1].i_number;
            extra_body.j_number = sb_arr[sb_arr.size() - 1].j_number + 1;

            break;
            /////////
            case 2:
            extra_body.i_number = sb_arr[sb_arr.size() - 1].i_number + 1;
            extra_body.j_number = sb_arr[sb_arr.size() - 1].j_number;

            break;
        }

        if((extra_body.i_number > 0) && (extra_body.i_number < 29))
        {
            if((extra_body.j_number > 0) && (extra_body.j_number < 139))
            {
                if(play_board[extra_body.i_number][extra_body.j_number] != '>')
                {
                    if(play_board[extra_body.i_number][extra_body.j_number] != '+')
                    {
                        help2 = true;
                    }
                }
            }
        }
        help = help + 1;
        help = help % 3;
    } while (help2 == false);
    sb_arr.push_back(extra_body);
}

bool play_board::eat_apple_test()
{
    if(apple.i_apple == sb_arr[0].i_number)
    {
        if(apple.j_apple == sb_arr[0].j_number)
        {
            return true;
        }
    }
    return false;
}

void play_board::apple_maker()
{
    help_make_apple = help_make_apple + 1;
    bool help2 = false;
    int help = help_make_apple;
    int i_apple;
    int j_apple;
    help = help % 3;
    do
    {
        switch(help)
        {
            case 0:
            i_apple = sb_arr[0].i_number - 6;
            j_apple = sb_arr[0].j_number;

            break;
            ////////
            case 1:
            i_apple = sb_arr[0].i_number;
            j_apple = sb_arr[0].j_number + 6;

            break;
            ////////
            case 2:
            i_apple = sb_arr[0].i_number + 6;
            j_apple = sb_arr[0].j_number;

            break;
        }
        if((i_apple > 0) && (i_apple < 29))
        {
            if((j_apple > 0) && (j_apple < 139))
            {
                if(play_board[i_apple][j_apple] != '>')
                {
                    if(play_board[i_apple][j_apple] != '+')
                    {
                        help2 = true;
                    }
                }
            }
        }
        help = help + 1;
    }while(help2 == false);
    apple.i_apple = i_apple;
    apple.j_apple = j_apple;
}

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
    play_board[apple.i_apple][apple.j_apple] = '@';
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
    help_make_apple = 0;
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
