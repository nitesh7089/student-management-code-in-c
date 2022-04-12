#include<stdio.h>
#include<conio.h>
#include<windows.h>
void gotoxy(int x,int y)
{
        COORD c;
        c.X=x;
        c.Y=y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

// color printing in console screen..

void black()
{
    printf("\033[1;30m"); // here [1;30] means 1 means bold letter and you put 0 for normal.
}
void red()
{
    printf("\033[1;31m");
}
void green()
{
    printf("\033[1;32m");
}
void yellow()
{
    printf("\033[1;33m");
}
void blue()
{
    printf("\033[1;34m");
}
void purple()
{
    printf("\033[1;35m");
}
void cyan()
{
    printf("\033[1;36m");
}
void white()
{
    printf("\033[1;37m");
}
void reset()
{
    printf("\033[0m");
}


//// -----------------------------designs for text ..............................................


char designf( char* x, char* y)
{
    // flashing text

    // char *s = "welcome";
    for (int i = 0; i < 2; i++)
    {
        system("cls");
        if (i == 0)
        {
            yellow();
            printf("%s", x);
            Sleep(2000);
            system("cls");
        }
        else
        {    yellow();
           printf("%s", y);
            Sleep(2000);
        system("cls");
        }   
    }
     reset();
}
// -------------------- END -------------------

char designrl(char* x)
{
    // right to left remove text.

    // char s[] = "Student Management system";
    int count = strlen(x);
    system("cls");
    for (int i = 0; i <= strlen(x); i++)
    {
        yellow();
        printf("%c", x[i]);
        Sleep(150);
    }
    system("cls");

    for (int i = 0; i < strlen(x) + 2; i++)
    {
        for (int j = 0; j <= count; j++)
        {
            yellow();
            printf("%c", x[j]);
        }
        count--;
        printf("\n");
        Sleep(50);
        system("cls");
    }
   reset();
    // ------------- END-----------------
}

char designlr(char* x)
{
    // left to right remove text.

    // char s[] = "Student Management system";
    int count = strlen(x);
    system("cls");
    for (int i = 0; i <= strlen(x); i++)
    {
        yellow();
        printf("%c", x[i]);
        Sleep(200);
    }
    system("cls");

    for (int i = 0; i < strlen(x) + 2; i++)
    {
        for (int j = i; j <= strlen(x); j++)
        {
            yellow();
            printf("%c", x[j]);
        }
        printf("\n");
        Sleep(50);
        system("cls");
    }
     reset();
    // --------------- END --------------
}

char design4(char* x,char* y,char* z)
{
    // char s1[] = "Please";
    // char s2[] = "Subscribe My";
    // char s3[] = "Youtube Channel";
    system("cls");
    gotoxy(10, 3);
    for (int i = 0; i <= strlen(x); i++)
    {
        red();
        printf("%c", x[i]);
        Sleep(200);
        
    }
    system("cls");
    gotoxy(10, 3);
    for (int i = 0; i <= strlen(y); i++)
    {

        printf("%c", y[i]);
        Sleep(200);
    }
    system("cls");
    gotoxy(10, 3);
    for (int i = 0; i <= strlen(z); i++)
    {
        green();
        printf("%c", z[i]);
        Sleep(200);
         
    }
    reset();
}
