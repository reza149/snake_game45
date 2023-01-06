#include<iostream>
#include<cstdlib>
#include<vector>

using namespace std;

struct snake_body
{
    int i_number;
    int j_number;
};

char play_board[30][140];

void set_play_board(char play_board[30][140], vector <snake_body> sb_arr)
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
    for(int i = 0; i < sb_arr.size(); i++)
    {
        if((sb_arr[i].i_number > 0) && (sb_arr[i].i_number < 29))
        {
            if((sb_arr[i].j_number > 0) && (sb_arr[i].j_number < 139))
            {
                if(i == 0)
                {
                    play_board[sb_arr[i].i_number][sb_arr[i].j_number] = '>';
                }
                else
                {
                    play_board[sb_arr[i].i_number][sb_arr[i].j_number] = '+';
                }
            }
        }
    }
}

void print_play_board(char play_board[30][140])
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

int main()
{
    vector <snake_body> sb_arr;
    snake_body help;
    int len;
    cin >> len;
    for(int i = 0; i < len; i++)
    {
        help.i_number = 15;
        help.j_number = 42 - i;
        sb_arr.push_back(help);
    }
    set_play_board(play_board, sb_arr);
    print_play_board(play_board);

    return 0;
}
//g++ -o apl lab.cpp