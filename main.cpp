#include <iostream>
#include <ncurses.h>
#include <stdio.h>

using namespace std;

int main(void)
{
    initscr();              // Initialise la structure WINDOW et autres param
    cbreak();
    noecho();

    int ch;
    signed int down = 0;
    signed int right = 0;

    for(int i=0; i<60;i++)
        for(int j=0; j<60; j++)
            {
                move(i,j);
                if ((i==0)||(i==59)||(j==0)||(j==59))
                printw("X");
                else printw(" ");
            }

    move(30,30);
    printw("J");
    move(30,30);

    while ((down > -30)&(right > -30))
    {

        ch = getch();

        move(30+down,30+right);
        printw(" ");

        switch(ch)
        {
            case 'z':
                down--;
                move(30+down,30+right);
                printw("J");
                move(30+down,30+right);
                break;
            case 'd':
                right++;
                move(30+down,30+right);
                printw("J");
                move(30+down,30+right);
                break;
            case 'q':
                right--;
                move(30+down,30+right);
                printw("J");
                move(30+down,30+right);
                break;
            case 's':
                down++;
                move(30+down,30+right);
                printw("J");
                move(30+down,30+right);
                break;
        }
    }
    getch();                // Attend que l'utilisateur appuie sur touche
    endwin();               // Restaure les paramètres par défaut du terminal

    return 0;
}
