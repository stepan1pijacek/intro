#include <conio.h>
#include <stdio.h>
#include <windows.h>   
#include "room.h"

void main_menu();
void setting_player();
void setting_color();


/*zlošky slov*/
char ESCAPE[8][90] =
{
 "\n __________     __________    __________        ______         __________    _________",
 "\n|         |   |          |  |          |       /      \\      |      _   |  |         |",
 "\n|    _____|   |     _____|  |      ____|      /   /\\   \\     |     |_|  |  |    _____|",
 "\n|   |__       |     |___    |     |          /   /__\\   \\    |     _____|  |   |__    ",
 "\n|    __|      |___      |   |     |         /    ____    \\   |    |        |    __|  ",
 "\n|   |_____  ______|     |   |     |____    /    /    \\    \\  |    |        |   |_____ ",
 "\n|         ||            |   |          |  /    /      \\    \\ |    |        |         |",
 "\n|_________||____________|   |__________| /____/        \\____\\|____|        |_________|\n", };

char ROOM[8][58] =
{ "\n__________   __________   __________   ____       ____",
  "\n|     __   | |          | |          | |    \\    /    |",
  "\n|    |__|  | |    __    | |    __    | |     \\  /     |",
  "\n|      ____| |   |  |   | |   |  |   | |      \\/      |",
  "\n|      \\     |   |  |   | |   |  |   | |    \\    /    |",
  "\n|   |   \\    |   |__|   | |   |__|   | |    |\\  /|    |",
  "\n|   |\\   \\   |          | |          | |    | \\/ |    |",
  "\n|___| \\___\\  |__________| |__________| |____|    |____|",
};
char credits[2][46] = { "\n \n \t \t \t \t\tcreated by: Lukas Joch\n",
                 " \n \t \t \t \t \t\t    Jakub Jarina\n" };

/*parametre hráèa*/
char name[20];
int c_player;
char z_postavy = 'x';

/*skrytie kurzoru*/
void hidecursor()
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
}

/*tlaè*/
void intro()
{
    int i = 0;
    int y = 0;
    hidecursor();
    blue();

    /*tlaè ESCAPE*/
    for (i = 0; i <= 7; i++) {


        for (y = 0; y <= 89; y++)
        {
            printf("%c", ESCAPE[i][y]);
            fflush(stdout);
            Sleep(1);


        }
    }
    red();

    /*tlaè ROOM*/
    for (i = 0; i <= 7; i++) {


        for (y = 0; y <= 57; y++)
        {
            printf("%c", ROOM[i][y]);
            fflush(stdout);
            Sleep(1);


        }
    }
    white();


    /*tlaè credits*/
    for (i = 0; i <= 1; i++) {


        for (y = 0; y <= 33; y++)
        {
            printf("%c", credits[i][y]);
            fflush(stdout);
            Sleep(1);
        }
    }
    system("pause");
    system("cls");
}


//Hra
void Start()
{
    room(z_postavy, c_player);
    
}

//Nastavení hry
void Nastaveni()
{

    printf("1.  Zmena mena\n");
    printf("2.  Zmena farby\n");
    printf("3.  Zmena postavy\n");
    printf("4.  Main menu\n");

    int volba = _getch();

    switch (volba) {
    case 49:
        system("cls");
        printf("Nove meno:");
        fgets(name, 20, stdin);
        system("cls");
        Nastaveni();

        break;
    case 50:
        setting_color();
        Nastaveni();
        break;
    case 51:

        setting_player();
        Nastaveni();
        break;
    case 52:
        system("cls");
        main_menu();
        break;

        

    }
}
void setting_player ()
{
zaciatok:
    system("cls");
    printf("Vyberte si z postav:(x o + * $)\n");
    z_postavy = getchar();
    if ((z_postavy == 120) || (z_postavy == 111) || (z_postavy == 43) || (z_postavy == 42) || (z_postavy == 36))
    {
        system("cls");
       
    }
    else {
        printf("Chyba postavy! Zadajte jednu z moznosti.");
        Sleep(1000);
        goto zaciatok;
    }
}

void setting_color ()
{
    void (*farby[7])() = { red,green,yellow,blue,magenta,white };
    int a = 0, i = 0;

    system("cls");
    for (i = 0; i <= 5; i++)
    {
        farby[i]();
        printf("%d. farba\n", i);
    }

    a = _getch();
    switch (a) {
    case 48:
        c_player = 0;
        system("cls");
        break;
    case 49:
        c_player = 1;
        system("cls");
        break;
    case 50:
        c_player = 2;
        system("cls");
        break;
    case 51:
        c_player = 3;
        system("cls");
        break;
    case 52:
        c_player = 4;
        system("cls");
        break;
    case 53:
        c_player = 5;
        system("cls");
        break;

    }
}

/*Hlavné menu*/
void main_menu()
{
zacatek:
    printf_s("Vitaj, %s \n\n",name);
    printf_s("Vyberte jednu z moznosti: \n");
    printf_s("1. Start\n");
    printf_s("2. Nastaveni\n");
    printf_s("0. Konec\n");


    int a = _getch();
    system("cls");

    switch (a)
    {
    case 49:
        Start();
        break;
    case 50:
        Nastaveni();
        break;
    case 48:
        exit(0);
        break;
    default:
        printf_s("Spatna volba!\n");
        while (getchar() != '\n');
        getchar();
        goto zacatek;
    }
}


int main()
{
    hidecursor();
    intro();

    printf("Zadajte svoje meno:");
    fgets(name, 20, stdin);
    system("cls");
    setting_player();
    system("cls");
    setting_color();
    main_menu();
    
}