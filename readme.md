# This is the code of student management system in c language.

Copy this below code and paste in to your code editor with any file name with extension .c . For an example we make a file and the file name is - student.c, than make another file with name myheader.c this file code is also in the below line. and compile this student.c file and enjoy.
you can use this project as your school or college mini project. 

## Prior configration
For run this code smoothly use code block or dev c++ code editor this editors are specially design for c/c++ programing it is come with mingw c/c++ compiler.
## student.c file code

```c
// code start here
#include <myheader.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
char design0();
char design();
void mainmenu();
void menu();
void choice();
void add();
void view();
void search();
void modify();
void del();
void sort();
struct student
{
    char name[30];
    int class;
    int roll;
    char mobile[12];
    char date[12];

} st;

FILE *fp;
long sz = sizeof(st);

int main()
{

    mainmenu();
    choice();
    return 0;
}

void mainmenu()
{
    char m[] = "=======================: S t u d e n t   M a n a g e m e n t   S y s t e m :=========================";
    system("cls");
    Sleep(3000);
    gotoxy(50, 2);
    yellow();
    printf("=====================================================================================================");
    yellow();
    gotoxy(50, 4);
    white();
    design0(m);
    gotoxy(50, 6);
    cyan();
    printf("                                                        - Devloped By @ Nitesh Prajapati.  ");
    gotoxy(50, 8);
    yellow();
    printf("=====================================================================================================");
    Sleep(1000);
    Beep(800, 800);
    yellow();
    gotoxy(30, 12);
    printf("1. Add Record: \n");
    gotoxy(30, 14);
    printf("2. View Record: \n");
    gotoxy(30, 16);
    printf("3. Search Record: \n");
    gotoxy(30, 18);
    printf("4. Modify Record: \n");
    gotoxy(30, 20);
    printf("5. Delete Record: \n");
    gotoxy(30, 22);
    printf("6. Sort Records: \n");
    cyan();
    gotoxy(30, 24);
    printf("0. Exit \n");
    reset();
}
void menu()
{
    char s[] = "=======================:MAIN MENU:===================";
    system("cls");
    white();
    gotoxy(50, 4);
    design0(s);
    Sleep(1000);
    Beep(800, 800);
    yellow();
    gotoxy(30, 10);
    printf("1. Add Record: \n");
    gotoxy(30, 12);
    printf("2. View Record: \n");
    gotoxy(30, 14);
    printf("3. Search Record: \n");
    gotoxy(30, 16);
    printf("4. Modify Record: \n");
    gotoxy(30, 18);
    printf("5. Delete Record: \n");
    gotoxy(30, 20);
    printf("6. Sort Records: \n");
    cyan();
    gotoxy(30, 22);
    printf("0. Exit \n");
    reset();
    choice();
}

void choice()
{
    int choice;
    gotoxy(30, 26);
    printf("Enter Your Choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        system("cls");
        add();
        getch();
        break;
    case 2:
        system("cls");
        view();
        break;
    case 3:
        search();
        break;
    case 4:
        modify();
        break;
    case 5:
        del();
        break;
    case 6:
        sort();
        break;
    case 0:
        Beep(500, 800);
        exit(0);
        break;
    default:
        printf("Invailid Input;");
        printf("Press any key to main menu:");
        getch();
        menu();

        break;
    }
}

void add()
{
    char str[] = "========================= ADD RECORD ===========================";
    char mydate[12];
    char another = 'y';
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(mydate, "%02d/%02d/%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
    strcpy(st.date, mydate);
    fp = fopen("student.txt", "ab");
    while (another == 'y' || another == 'Y')
    {
        system("cls");
        gotoxy(50, 4);
        white();
        design0(str);
        gotoxy(30, 10);
        yellow();
        printf("Enter Student Name: ");
        reset();
        fflush(stdin);
        gets(st.name);
        gotoxy(30, 12);
        yellow();
        printf("Enter Class : ");
        reset();
        scanf("%d", &st.class);
        gotoxy(30, 14);
        yellow();
        printf("Enter Roll No: ");
        reset();
        scanf("%d", &st.roll);
        gotoxy(30, 16);
        yellow();
        printf("Enter Mobile No: ");
        reset();
        fflush(stdin);
        gets(st.mobile);
        fwrite(&st, sz, 1, fp);
        gotoxy(30, 19);
        green();
        printf("Record Save Successfully->>>\n");
        Beep(750, 800);
        gotoxy(30, 21);
        yellow();
        printf("Want to add of another record? Then press 'Y' else 'N'.");
        fflush(stdin);
        another = getche();
        system("cls");
        gotoxy(30, 10);
    }
    fclose(fp);
    gotoxy(30, 16);
    purple();
    printf("Press Any Key To Back To Main Menu: ");
    getch();
    menu();
}

void view()
{
    int i = 1;
    char op;
    char str[] = "================ View Student Records ================", str1[] = "Invalid Input>> ", str2[] = "Try Again..";
    system("cls");
    gotoxy(50, 4);
    white();
    design0(str);
    gotoxy(30, 10);
    blue();
    printf("%-5s %-30s %-15s %-20s %-21s %s\n", "S.No", "Name", "Class", "Mobile", "Roll No", "Date");
    fp = fopen("student.txt", "rb");
    while (fread(&st, sz, 1, fp) == 1)
    {
        gotoxy(30, 11 + i);
        white();
        printf("%-5d %-30s %-15d %-20s %-20d  %s\n", i, st.name, st.class, st.mobile, st.roll, st.date);
        i++;
    }
    fclose(fp);
loop2:
    gotoxy(30, 12 + i);
    green();
    printf("Note:  'Press \"M\" Key To Back For Main Menu & \"Q\" For exit' ");
    fflush(stdin);
    op = getche();
    if (op == 'M' || op == 'm')
    {
        menu();
    }
    else if (op == 'Q' || op == 'q')
    {
        reset();
        Beep(750, 800);
        system("cls");
        exit(0);
    }
    else
        red();
    gotoxy(30, 14 + i);
    Beep(750, 800);
    design(str1, str2);
    system("cls");
    Sleep(500);
    reset();
    fflush(stdin);
    goto loop2;
}

void search()
{
    char str0[] = "===============Search Records ==============";
    char str1[] = "===============Search Records by Name ==============";
    char str2[] = "===============Search Records by Roll no. ==============";
    char str3[] = "===============Search Records by Class ==============";
    int ch, j = 0;
    int rl, cl, f = 0;
    char op1;

    char stname[30];
    int i = 1;
src:
    fp = fopen("student.txt", "rb");
    system("cls");
    gotoxy(50, 4);
    white();
    design0(str0);
    gotoxy(30, 10);
    yellow();
    printf("1. Search records by Name: \n");
    gotoxy(30, 12);
    yellow();
    printf("2. Search records by Roll no: \n");
    gotoxy(30, 14);
    yellow();
    printf("3. Search records by Class: \n");
    gotoxy(30, 16);
    yellow();
    printf("4. Go to main menu: \n");
    gotoxy(30, 18);
    cyan();
    printf("0. Exit \n");
    gotoxy(30, 20);
    white();
    printf("Enter  your choice: ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        system("cls");
        gotoxy(50, 4);
        white();
        design0(str1);
        gotoxy(30, 10);
        yellow();
        printf("Enter name of student : ");
        reset();
        fflush(stdin);
        gets(stname);
        gotoxy(30, 12);
        blue();
        printf("%-5s %-30s %-15s %-20s %-21s %s\n", "S.No", "Name", "Class", "Mobile", "Roll No", "Date");
        while (fread(&st, sz, 1, fp) == 1)
        {
            if (strcmpi(stname, st.name) == 0)
            {
                f = 1;
                gotoxy(30, 14 + j);
                white();
                printf("%-5d %-30s %-15d %-20s %-20d  %s\n", i, st.name, st.class, st.mobile, st.roll, st.date);
                j++;
            }
            i++;
        }
        fclose(fp);

        if (f == 0)
        {
            gotoxy(30, 16 + j);
            red();
            printf("Records Not Found...");
            Beep(750, 800);
        loop1:
            gotoxy(30, 18 + j);
            yellow();
            printf("goto menu press 'Y' \n");
            gotoxy(81, 18 + j);
            fflush(stdin);
            j = 0;
            f = 0;
            i = 1;
            op1 = getche();
            if (op1 == 'y' || op1 == 'Y')
            {
                goto src;
            }
            else
                system("cls");
            fflush(stdin);
            j = 0;
            f = 0;
            i = 1;
            gotoxy(30, 16 + j);
            red();
            printf("Invalid Input! Try Again...");
            Beep(750, 800);
            Sleep(3000);
            goto loop1;
        }
        else
            gotoxy(30, 16 + j);
        green();
        printf("%d Records found...", j);
        Beep(750, 800);
        gotoxy(30, 18 + j);
        yellow();
        printf("goto menu press 'Y'  \n");
        gotoxy(81, 18 + j);
        fflush(stdin);
        j = 0;
        f = 0;
        i = 1;
        op1 = getche();
        if (op1 == 'y' || op1 == 'Y')
        {
            goto src;
        }
        else
            system("cls");
        fflush(stdin);
        gotoxy(30, 16 + j);
        j = 0;
        f = 0;
        i = 1;
        red();
        printf("Invalid Input! Try Again...");
        Beep(750, 800);
        Sleep(3000);
        goto loop1;
        reset();
        break;

    case 2:
        system("cls");
        gotoxy(50, 4);
        white();
        design0(str2);
        gotoxy(30, 10);
        yellow();
        printf("Enter Roll no of student : ");
        reset();
        scanf("%d", &rl);
        gotoxy(30, 12);
        blue();
        printf("%-5s %-30s %-15s %-20s %-21s %s\n", "S.No", "Name", "Class", "Mobile", "Roll No", "Date");
        while (fread(&st, sz, 1, fp) == 1)
        {
            if (rl == st.roll)
            {
                f = 1;
                gotoxy(30, 14 + j);
                white();
                printf("%-5d %-30s %-15d %-20s %-20d  %s\n", i, st.name, st.class, st.mobile, st.roll, st.date);
                j++;
            }
            i++;
        }

        fclose(fp);
        if (f == 0)
        {
            gotoxy(30, 16 + j);
            red();
            printf("Records Not Found...");
            Beep(750, 800);
        loop2:
            gotoxy(30, 18 + j);
            yellow();
            printf("goto menu press 'Y' \n");
            gotoxy(81, 18 + j);
            fflush(stdin);
            j = 0;
            f = 0;
            i = 1;
            op1 = getche();
            if (op1 == 'y' || op1 == 'Y')
            {
                goto src;
            }
            else
                system("cls");
            fflush(stdin);
            j = 0;
            f = 0;
            i = 1;
            gotoxy(30, 16 + j);
            red();
            printf("Invalid Input! Try Again...");
            Beep(750, 800);
            Sleep(3000);
            goto loop2;
        }
        else
            gotoxy(30, 16 + j);
        green();
        printf("%d Records found...", j);
        Beep(750, 800);
        gotoxy(30, 18 + j);
        yellow();
        printf("goto menu press 'Y'  \n");
        gotoxy(81, 18 + j);
        fflush(stdin);
        j = 0;
        f = 0;
        i = 1;
        op1 = getche();
        if (op1 == 'y' || op1 == 'Y')
        {
            goto src;
        }
        else
            system("cls");
        fflush(stdin);
        gotoxy(30, 16 + j);
        j = 0;
        f = 0;
        i = 1;
        red();
        printf("Invalid Input! Try Again...");
        Beep(750, 800);
        Sleep(3000);
        goto loop2;
        reset();
        break;
    case 3:
        system("cls");
        gotoxy(50, 4);
        white();
        design0(str3);
        gotoxy(30, 10);
        yellow();
        printf("Enter Class of student : ");
        reset();
        scanf("%d", &cl);
        gotoxy(30, 12);
        blue();
        printf("%-5s %-30s %-15s %-20s %-21s %s\n", "S.No", "Name", "Class", "Mobile", "Roll No", "Date");
        while (fread(&st, sz, 1, fp) == 1)
        {
            if (cl == st.class)
            {
                f = 1;
                gotoxy(30, 14 + j);
                white();
                printf("%-5d %-30s %-15d %-20s %-20d  %s\n", i, st.name, st.class, st.mobile, st.roll, st.date);
                j++;
            }
            i++;
        }

        fclose(fp);
        if (f == 0)
        {
            gotoxy(30, 16 + j);
            red();
            printf("Records Not Found...");
            Beep(750, 800);
        loop3:
            gotoxy(30, 18 + j);
            yellow();
            printf("goto menu press 'Y' \n");
            gotoxy(81, 18 + j);
            fflush(stdin);
            j = 0;
            f = 0;
            i = 1;
            op1 = getche();
            if (op1 == 'y' || op1 == 'Y')
            {
                goto src;
            }
            else
                system("cls");
            fflush(stdin);
            j = 0;
            f = 0;
            i = 1;
            gotoxy(30, 16 + j);
            red();
            printf("Invalid Input! Try Again...");
            Beep(750, 800);
            Sleep(3000);
            goto loop3;
        }
        else
            gotoxy(30, 16 + j);
        green();
        printf("%d Records found...", j);
        Beep(750, 800);
        gotoxy(30, 18 + j);
        yellow();
        printf("goto menu press 'Y'  \n");
        gotoxy(81, 18 + j);
        fflush(stdin);
        j = 0;
        f = 0;
        i = 1;
        op1 = getche();
        if (op1 == 'y' || op1 == 'Y')
        {
            goto src;
        }
        else
            system("cls");
        fflush(stdin);
        gotoxy(30, 16 + j);
        j = 0;
        f = 0;
        i = 1;
        red();
        printf("Invalid Input! Try Again...");
        Beep(750, 800);
        Sleep(3000);
        goto loop3;
        reset();
        break;
    case 4:
        gotoxy(30, 20);

        menu();
        break;

    case 0:
        Beep(750, 800);
        gotoxy(30, 20);
        exit(0);
        break;

    default:
    l1:
        system("cls");
        gotoxy(30, 10);
        red();
        printf("Invalid Input....\n");
        Beep(750, 800);
        gotoxy(30, 12);
        green();
        printf("Press any Key......\n");
        getch();
        yellow();
        gotoxy(30, 14);
        printf("goto menu press 'Y' \n");
        gotoxy(30, 16);
        reset();
        fflush(stdin);
        op1 = getche();
        if (op1 == 'y' || op1 == 'Y')
        {
            search();
        }
        else
            gotoxy(30, 10);
        printf("sorry error 404 ");
        Beep(850, 800);
        goto l1;
        break;
    }
    // }
}

void modify()
{
    char str[] = "================ Modify Students Records ================";
    char op1;
    char stname[30];
    int rl, i = 0, cl, f = 0;
loop:
    fp = fopen("student.txt", "rb+");
    system("cls");
    gotoxy(50, 4);
    white();
    design0(str);
    gotoxy(30, 10);
    yellow();
    printf("Enter Class to Modify : ");
    scanf("%d", &cl);
    gotoxy(30, 12);
    printf("Enter Roll to Modify : ");
    scanf("%d", &rl);
    gotoxy(30, 14);
    blue();
    printf("%-5s %-30s %-15s %-20s %-21s %s\n", "S.No", "Name", "Class", "Mobile", "Roll No", "Date");
    while (fread(&st, sz, 1, fp) == 1)
    {
        i++;
        if (cl == st.class && rl == st.roll)
        {
            f = 1;
            gotoxy(30, 16);
            white();
            printf("%-5d %-30s %-15d %-20s %-20d  %s\n", i, st.name, st.class, st.mobile, st.roll, st.date);
            gotoxy(30, 18);
            printf("What you Want to change type here: ");
            fflush(stdin);
            gets(stname);
            if (strcmpi(stname, "Name") == 0)
            {
                gotoxy(30, 20);
                printf("Enter Student New Name: ");
                fflush(stdin);
                gets(st.name);
                green();
                gotoxy(30, 24);
                printf("Record Modified successfully...");
                Beep(750, 800);
            }
            else if (strcmpi(stname, "Class") == 0)
            {
                gotoxy(30, 20);
                printf("Enter New Class Name: ");
                scanf("%d", &st.class);
                green();
                gotoxy(30, 24);
                printf("Record Modified successfully...");
                Beep(750, 800);
            }
            else if (strcmpi(stname, "Mobile") == 0)
            {
                gotoxy(30, 20);
                printf("Enter New Mobile No: ");
                fflush(stdin);
                gets(st.mobile);
                green();
                gotoxy(30, 24);
                printf("Record Modified successfully...");
                Beep(750, 800);
            }
            else if (strcmpi(stname, "Roll No") == 0)
            {
                gotoxy(30, 20);
                printf("Enter New Roll No: ");
                scanf("%d", &st.roll);
                green();
                gotoxy(30, 24);
                printf("Record Modified successfully...");
                Beep(750, 800);
            }
            else
            {
                gotoxy(30, 24);
                red();
                printf("Record Not Modified..");
                Beep(750, 800);
            }

            fseek(fp, -sz, 1);
            fwrite(&st, sz, 1, fp);
            fclose(fp);
            break;
        }
    }
    if (f == 0)
    {
        gotoxy(30, 22);
        red();
        printf("Records Not Found...");
        Beep(750, 800);
        yellow();
        gotoxy(30, 24);
        printf("Note:  'Press \"M\" Key To Back For Main Menu & \"Q\" For exit & Press Any Key For Modify Menu' ");
        op1 = getche();
        if (op1 == 'M' || op1 == 'm')
        {
            i = 0;
            f = 0;
            menu();
        }
        else if (op1 == 'Q' || op1 == 'q')
        {
            Beep(850, 800);
            reset();
            system("cls");
            i = 0;
            f = 0;
            exit(0);
        }
        else
            system("cls");
        gotoxy(30, 20);
        printf("Back to Modify Menu <<...");
        Sleep(1000);
        reset();
        i = 0;
        f = 0;
        goto loop;
    }
    else
        yellow();
    gotoxy(30, 26);
    printf("Note:  'Press \"M\" Key To Back For Main Menu & \"Q\" For exit & Press Any Key For Modify Menu' ");
    op1 = getche();
    if (op1 == 'M' || op1 == 'm')
    {
        i = 0;
        f = 0;
        menu();
    }
    else if (op1 == 'Q' || op1 == 'q')
    {
        Beep(850, 800);
        reset();
        system("cls");
        i = 0;
        f = 0;
        exit(0);
    }
    else
        system("cls");
    red();
    gotoxy(30, 20);
    printf("Back to Modify Menu <<...");
    Sleep(2000);
    reset();
    i = 0;
    f = 0;
    goto loop;
}

void del()
{
    char str[] = "================ Delete Students Records ================";
    char op1;
    int rl, cl, f = 0, i = 0;
    FILE *tempfp;
    system("cls");
    fp = fopen("student.txt", "rb");
    tempfp = fopen("temp.txt", "ab");
    gotoxy(50, 4);
    design0(str);
    gotoxy(30, 10);
    yellow();
    printf("Enter class No: ");
    scanf("%d", &cl);
    gotoxy(30, 11);
    yellow();
    printf("Enter Roll No: ");
    scanf("%d", &rl);
    gotoxy(30, 14);
    blue();
    printf("%-5s %-30s %-15s %-20s %-21s %s\n", "S.No", "Name", "Class", "Mobile", "Roll No", "Date");
    while (fread(&st, sz, 1, fp) == 1)
    {
        i++;
        if (cl == st.class && rl == st.roll)
        {
            f = 1;
            gotoxy(30, 16);
            white();
            printf("%-5d %-30s %-15d %-20s %-20d  %s\n", i, st.name, st.class, st.mobile, st.roll, st.date);
        }
        else
        {
            fwrite(&st, sz, 1, tempfp);
        }
    }
    fclose(fp);
    fclose(tempfp);
    remove("student.txt");
    rename("temp.txt", "student.txt");

    if (f == 0)
    {
        gotoxy(30, 18);
        red();
        printf("Records Not Found...");
        Beep(750, 800);
    }
    else
    {
        green();
        gotoxy(30, 18);
        printf(" Records Delete successfully...");
        Beep(750, 800);
    }
    gotoxy(30, 20);
    yellow();
    printf("Note:  'Press \"M\" Key To Back For Main Menu & \"Q\" For exit & Press Any Key To delete Menu' ");
    op1 = getche();
    if (op1 == 'M' || op1 == 'm')
    {
        i = 0;
        f = 0;
        menu();
    }
    else if (op1 == 'Q' || op1 == 'q')
    {
        Beep(850, 800);
        reset();
        system("cls");
        i = 0;
        f = 0;
        exit(0);
    }

    else
        i = 0;
    f = 0;
    del();
}

void sort()
{
    char str[] = "================ View Sorted records  ================";
    int i, j, ch1, c = 0;
    int count = 1;
    struct student s1[1000], t;
    system("cls");
    white();
    gotoxy(50, 4);
    design0(str);
    yellow();
    gotoxy(30, 10);
    printf("1. Sort By roll: \n");
    yellow();
    gotoxy(30, 12);
    printf("2. Sort By class: \n");
    yellow();
    gotoxy(30, 14);
    printf("3. Go to Main Menu: \n");
    cyan();
    gotoxy(30, 16);
    printf("0. Exit ");
    white();
    gotoxy(30, 18);
    printf("Enter Your choice: ");
    reset();
    scanf("%d", &ch1);

    switch (ch1)
    {
    case 1:
        fp = fopen("student.txt", "rb");
        blue();
        gotoxy(30, 20);
        printf("%-5s %-30s %-15s %-20s %-21s %s\n", "S.No", "Name", "Class", "Mobile", "Roll No", "Date");
        while (fread(&st, sz, 1, fp) == 1)
        {
            s1[c++] = st;
        }
        for (i = 0; i < c - 1; i++)
        {
            for (j = i + 1; j < c; j++)
            {
                if (s1[i].roll > s1[j].roll)
                {
                    t = s1[i];
                    s1[i] = s1[j];
                    s1[j] = t;
                }
            }
        }

        for (i = 0; i < c; i++)
        {
            white();
            gotoxy(30, 22 + (count - 1));
            printf("%-5d %-30s %-15d %-20s %-20d  %s\n", count, s1[i].name, s1[i].class, s1[i].mobile, s1[i].roll, s1[i].date);
            count++;
        }
        fclose(fp);
        green();
        gotoxy(30, 24 + (count - 1));
        printf("Press Any Key To Back To Menu: ");
        getch();
        count = 0;
        i = 0;
        j = 0;
        c = 0;
        sort();
        break;
    case 2:
        fp = fopen("student.txt", "rb");
        blue();
        gotoxy(30, 20);
        printf("%-5s %-30s %-15s %-20s %-21s %s\n", "S.No", "Name", "Class", "Mobile", "Roll No", "Date");
        while (fread(&st, sz, 1, fp) == 1)
        {
            s1[c++] = st;
        }
        for (i = 0; i < c - 1; i++)
        {
            for (j = i + 1; j < c; j++)
            {
                if (s1[i].class > s1[j].class)
                {
                    t = s1[i];
                    s1[i] = s1[j];
                    s1[j] = t;
                }
            }
        }

        for (i = 0; i < c; i++)
        {
            white();
            gotoxy(30, 22 + (count - 1));
            printf("%-5d %-30s %-15d %-20s %-20d  %s\n", count, s1[i].name, s1[i].class, s1[i].mobile, s1[i].roll, s1[i].date);
            count++;
        }
        fclose(fp);
        green();
        gotoxy(30, 24 + (count - 1));
        printf("Press Any Key To Back To Menu: ");
        getch();
        count = 0;
        i = 0;
        j = 0;
        c = 0;
        sort();
        break;
    case 3:
        menu();
    case 0:
        Beep(500, 800);
        system("cls");
        exit(0);
        break;
    default:
        system("cls");
        i = 0;
        j = 0;
        c = 0;
        gotoxy(30, 10);
        red();
        printf("Invalid Choice! Please Chose Valid Option...");
        Beep(750, 800);
        reset();
        Sleep(3000);
        sort();

        break;
    }
}
char design0(char *x)
{

    // printf("HII\r "); /* It is replace the blank space with character "\r"*/
    for (int j = 0; j <= strlen(x); j++)
    {
        printf("%c", x[j]);
        Sleep(20);
    }
    reset();
}

char design(char *x, char *y)
{
    // flashing text

    // char *s = "welcome";
    for (int i = 0; i < 2; i++)
    {

        if (i == 0)
        {
            printf("%s ", x);
            Sleep(2000);
            //system("cls");
        }
        else
        {
            printf("%s", y);
            Sleep(2000);
            //system("cls");
        }
    }
    reset();
}
```
## myheader.c file code
Please Dont't change this file name this file include in program.
```c
// code start here
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

```



## Downlaod
If you want to donwload this file goto the  code button when you click the button dropdown menu will apear than you click on download zip and file is download on your local system.

