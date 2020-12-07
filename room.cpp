# include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <conio.h> 
#include "readingFile.h"


char mapa[10][18] =
{
    "11111111111111111",
    "10000000110000001",
    "10000000110000001",
    "10000000110000001",
    "10000000110000001",
    "11111000000000001",
    "11111000000000001",
    "10000000110000001",
    "10000000110000001",
    "11111111111111111",
};

int pohyb_p;
int xp_pozicia = 1;
int yp_pozicia = 1;
int i, a, b;

/*farby*/
void red() {
    printf("\033[1;31m");
}
void green() {
    printf("\033[0;32m");
}
void yellow() {
    printf("\033[0;33m");
}
void blue() {
    printf("\033[0;34m");
}
void magenta() {
    printf("\033[0;35m");
}
void white() {
    printf("\033[0m");
}



int room(char z_postavy, int c_player)
{
    int* x_ptr = &xp_pozicia;
    int* y_ptr = &yp_pozicia;
    

    srand(time(0));
     int x_Random = rand() % 15, y_Random = rand() % 8;

     
    /*Vytvorenie prekážok*/
    for (b = 1; b < 12; b++)
    {
        
       
            mapa[y_Random][x_Random] = { '#' };
            x_Random = rand() % 15, y_Random = rand() % 8;

        
    }
    /*umiestnenie otázky a generovani nahodne otazky*/
    srand(time(0));
    int n = rand()%3;


    char question = mapa[n+6][n+4] = { '?' };
    int rngQuestion = rand() % (15 + 1 - 0) + 0;
    const char* answear = "Ne";

    /*Vyplnenie mapy*/
    for (i = 0; i < 10; i++)
    {
        for (a = 0; a < 18; a++)
        {
            if (mapa[i][a] == '0')
                mapa[i][a] = '.';

            else if (mapa[i][a] == '1')
            {
                mapa[i][a] = '#';
            }

        }
        
    }

    void (*farby[7])() = { red,green,yellow,blue,magenta,white };

    /*Vytvorenie mapy*/
    do
    {
        farby[c_player]();
        char player = mapa[yp_pozicia][xp_pozicia] = z_postavy;
        
        for (i = 0; i < 10; i++)
        {
            printf("\n \t");
            for (a = 0; a < 18; a++)
            {
                printf("%c", mapa[i][a]);
            }
        }

     int pohyb_p = _getch( );
     switch (pohyb_p)
     {
     case 56:
         if (mapa[yp_pozicia - 1][xp_pozicia] == '#')
         {
             player = mapa[yp_pozicia][xp_pozicia] = z_postavy;
             mapa[yp_pozicia - 1][xp_pozicia] = { '#' };
         }
         else
         {
             mapa[yp_pozicia][xp_pozicia] = '.';
             player = mapa[yp_pozicia - 1][xp_pozicia] = z_postavy;
             //findQuestion(rngQuestion, answear);
             (*y_ptr)--;
         }
         break;

     case 50:
         if (mapa[yp_pozicia + 1][xp_pozicia] == '#')
         {
             player = mapa[yp_pozicia][xp_pozicia] = z_postavy;
             mapa[yp_pozicia + 1][xp_pozicia] = '#';
         }
         else
         {
             mapa[yp_pozicia][xp_pozicia] = '.';
             player = mapa[yp_pozicia + 1][xp_pozicia] = z_postavy;
             (*y_ptr)++;
         }
         break;
     case 54:
         if (player = mapa[yp_pozicia][xp_pozicia + 1] == '#')
         {
             player = mapa[yp_pozicia][xp_pozicia] = z_postavy;
             mapa[yp_pozicia][xp_pozicia + 1] = '#';
         }
         else
         {
             mapa[yp_pozicia][xp_pozicia] = '.';
             player = mapa[yp_pozicia][xp_pozicia + 1] = z_postavy;
             (*x_ptr)++;
         }
         break;
     case 52:
         if (mapa[yp_pozicia][xp_pozicia - 1] == '#')
         {
             player = mapa[yp_pozicia][xp_pozicia] = z_postavy;
             mapa[yp_pozicia][xp_pozicia - 1] = '#';
         }
         else
         {
             mapa[yp_pozicia][xp_pozicia] = '.';
             player = mapa[yp_pozicia][xp_pozicia - 1] = z_postavy;
             (*x_ptr)--;
         }
         break;
     }


     
      system("cls");
     
     
     
    } while (mapa[yp_pozicia][xp_pozicia] != mapa[n + 6][n + 4]);

    
    return 1;
}
