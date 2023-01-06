#include<iostream>
#include<vector>

using namespace std;
struct test
{
    int num;
    char ch;
};

int main()
{
    test arr[10];
    for(int i = 0; i < 10; i++)
    {
        arr[i].num = i + 5;
        arr[i].ch = 97 + i;
    }
    for(int i = 0; i < 10; i++)
    {
        cout << arr[i].num << "\t";
    }
    cout << "\n";
    for(int i = 0; i < 10; i++)
    {
        cout << arr[i].ch << "\t";
    }
    cout << "\n";
    int help;
    int help2;

    help = arr[0].num;
    arr[0].num = 15;
    for(int i = 1; i < 10; i++)
    {
        help2 = arr[i].num;
        arr[i].num = help;
        help = help2;
    }
    for(int i = 0; i < 10; i++)
    {
        cout << arr[i].num << "\t";
    }
    cout << "\n";
    for(int i = 0; i < 10; i++)
    {
        cout << arr[i].ch << "\t";
    }
    cout << "\n";




    return 0;
}
//g++ -o apl2 lab2.cpp