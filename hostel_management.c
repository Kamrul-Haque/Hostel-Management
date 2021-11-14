// header files
#include <stdio.h>
#include <string.h>
#include <conio.h>

// global variables
int i, j, main_exit;

// functions
void menu();
void create();
void update();
void index();
void delete ();
void view();
void account();
void deposit();
void withdraw();
void balance();
void close();

// for storing date
struct date
{
    int day, month, year;
};

// anonymous structure
// for storing student records
struct
{
    char name[60];
    int age;
    char city[60];
    char mail_id[30];
    char room_no[8];
    char father_name[60];
    int father_phone;
    int phone;
    char roll_no[10];
    float balance;
    struct date dob;
} add, upd, check, rem;

// delay function
void delay(int j)
{
    int i, k;
    for (i = 0; i < j; i++)
        k = i;
}

//main function
int main()
{
    SetConsoleOutputCP(1252);
    menu();
    return 0;
    getche();
}

// menu function
void menu()
{
    // clear screen
    system("CLS");
    // console output color
    system("color 3");

    int choice;

    printf("\n\n\t\t\tHOSTEL MANAGEMENT SYSTEM");
    printf("\n\n\n\t\t------- Main Menu -------");
    printf("\n\n\t\t1> Enter new Student's data\n\t\t2> Update information of existing Student\n\t\t3> Check the details of existing Student\n\t\t4> Remove existing Student's Data\n\t\t5> View all Student's Data\n\t\t6> View Account Information\n\t\t7> Deposit to Account\n\t\t8> Withdraw from Account\n\t\t0> Exit the System\n\n\n");

    printf("\t\tEnter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        create();
        break;
    case 2:
        update();
        break;
    case 3:
        view();
        break;
    case 4:
        delete ();
        break;
    case 5:
        index();
        break;
    case 6:
        account();
        break;
    case 7:
        deposit();
        break;
    case 8:
        withdraw();
        break;
    case 0:
        close();
        break;
    default:
        menu();
    }
}

// create new student record
void create()
{
    system("CLS");
    int choice;
    FILE *ptr;

    ptr = fopen("record.dat", "a+");

// label
roll_no:

    printf("\t\t\t------ ADD STUDENT'S DATA --------");
    printf("\nEnter roll number: ");
    scanf("%s", check.roll_no);
    while (fscanf(ptr, "%s %s %d/%d/%d %d %s %d %s %s %d %s\n", add.roll_no, add.name, &add.dob.day, &add.dob.month, &add.dob.year, &add.age, add.city, &add.phone, add.mail_id, add.father_name, &add.father_phone, add.room_no) != EOF)
    {
        if (strcmp(check.roll_no, add.roll_no) == 0)
        {
            printf("Students roll no. already in use!");
            goto roll_no;
        }
    }

    strcpy(add.roll_no, check.roll_no);
    printf("\nEnter the name: ");
    scanf("%s", add.name);
    printf("\nEnter the date of birth(dd/mm/yyyy): ");
    scanf("%d/%d/%d", &add.dob.day, &add.dob.month, &add.dob.year);
    printf("\nEnter the age: ");
    scanf("%d", &add.age);
    printf("\nEnter the city: ");
    scanf("%s", add.city);
    printf("\nEnter the phone number: ");
    scanf("%d", &add.phone);
    printf("\nEnter your email id: ");
    scanf("%s", add.mail_id);
    printf("\nEnter your Father's name: ");
    scanf("%s", add.father_name);
    printf("\nEnter your Father's phone no.: ");
    scanf("%d", &add.father_phone);
    printf("\nEnter your room no.: ");
    scanf("%s", add.room_no);

    fprintf(ptr, "%s %s %d/%d/%d %d %s %d %s %s %d %s\n", add.roll_no, add.name, add.dob.day, add.dob.month, add.dob.year, add.age, add.city, add.phone, add.mail_id, add.father_name, add.father_phone, add.room_no);

    fclose(ptr);

    printf("\nStudent added successfully!");

add_invalid:
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit: ");
    scanf("%d", &main_exit);

    if (main_exit == 1)
        menu();
    else if (main_exit == 0)
        close();
    else
    {
        printf("\nInvalid!\a");
        goto add_invalid;
    }
}

// view all students records
void index()
{
    system("CLS");
    FILE *view;
    view = fopen("record.dat", "r");
    int match = 0;

    printf("\t\t\t------ VIEW ALL STUDENTS DATA --------\n");
    printf("\nROLL NO.\tNAME\t\tCITY\t PHONE\t\t AGE\t ROOM NO.\n");

    while (fscanf(view, "%s %s %d/%d/%d %d %s %d %s %s %d %s\n", add.roll_no, add.name, &add.dob.day, &add.dob.month, &add.dob.year, &add.age, add.city, &add.phone, add.mail_id, add.father_name, &add.father_phone, add.room_no) != EOF)
    {
        printf("\n%8s %11s\t %11s\t %d\t %d\t %s", add.roll_no, add.name, add.city, add.phone, add.age, add.room_no);
        match++;
    }

    fclose(view);

    if (match == 0)
    {
        printf("\nNO RECORDS!!\n");
    }

index_invalid:
    printf("\n\nEnter 1 to go to the main menu and 0 to exit: ");
    scanf("%d", &main_exit);

    if (main_exit == 1)
        menu();
    else if (main_exit == 0)
        close();
    else
    {
        printf("\nInvalid!\a");
        goto index_invalid;
    }
}

// view data of a particular student
void view()
{
    system("CLS");
    FILE *ptr;
    int match = 0;
    int choice;

    ptr = fopen("record.dat", "r");

    printf("\t\t\t------ VIEW ALL STUDENTS DATA --------\n");
    printf("\n\t\t\tDo you want to check by\n1.Roll no\n2.Name\nEnter your choice: ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        printf("\n\nEnter the roll number: ");
        scanf("%s", check.roll_no);

        while (fscanf(ptr, "%s %s %d/%d/%d %d %s %d %s %s %d %s\n", add.roll_no, add.name, &add.dob.day, &add.dob.month, &add.dob.year, &add.age, add.city, &add.phone, add.mail_id, add.father_name, &add.father_phone, add.room_no) != EOF)
        {
            if (strcmp(add.roll_no, check.roll_no) == 0)
            {
                match = 1;

                printf("\nROLL NO.: %s\nName: %s\nDOB: %d/%d/%d\nAge: %d\nCity: %s\nPhone number: %d\nE-Mail id: %s\nFather's name: %s\nFather's Phone No.: %d\nRoom No: %s\n", add.roll_no, add.name, add.dob.day, add.dob.month, add.dob.year, add.age, add.city, add.phone, add.mail_id, add.father_name, add.father_phone, add.room_no);
            }
        }
    }
    else if (choice == 2)
    {
        printf("\n\nEnter the name: ");
        scanf("%s", check.name);
        while (fscanf(ptr, "%s %s %d/%d/%d %d %s %d %s %s %d %s\n", add.roll_no, add.name, &add.dob.day, &add.dob.month, &add.dob.year, &add.age, add.city, &add.phone, add.mail_id, add.father_name, &add.father_phone, add.room_no) != EOF)
        {
            if (strcmp(add.name, check.name) == 0)
            {
                match = 1;
                printf("\nROLL NO.: %s\nName: %s\nDOB: %d/%d/%d\nAge: %d\nCity: %s\nPhone number: %d\nE-Mail id: %s\nFather's name: %s\nFather's Phone No.: %d\nRoom No: %s\n", add.roll_no, add.name, add.dob.day, add.dob.month, add.dob.year, add.age, add.city, add.phone, add.mail_id, add.father_name, add.father_phone, add.room_no);
            }
        }
    }

    fclose(ptr);

    if (match != 1)
        printf("\nRecord not found!!\a\a\a");

view_invalid:
    printf("\nEnter 0 to try again, 1 to return to main menu and 2 to exit: ");
    scanf("%d", &main_exit);
    if (main_exit == 1)
        menu();
    else if (main_exit == 2)
        close();
    else if (main_exit == 0)
        view();
    else
    {
        printf("\nInvalid!\a");
        goto view_invalid;
    }
}

// update student info
void update()
{
    system("CLS");
    int choice, match = 0;
    FILE *old, *new;

    old = fopen("record.dat", "r");
    new = fopen("new.dat", "w");

    printf("\t\t\t------ UPDATE STUDENT'S DATA --------\n");
    printf("\nEnter the roll no. of the student: ");
    scanf("%s", upd.roll_no);

    while (fscanf(old, "%s %s %d/%d/%d %d %s %d %s %s %d %s\n", add.roll_no, add.name, &add.dob.day, &add.dob.month, &add.dob.year, &add.age, add.city, &add.phone, add.mail_id, add.father_name, &add.father_phone, add.room_no) != EOF)
    {
        if (strcmp(add.roll_no, upd.roll_no) == 0)
        {
            match = 1;
            printf("\nWhich information do you want to change?\n1. Room no.\n2. Phone\n\nEnter your choice: ");
            scanf("%d", &choice);

            if (choice == 1)
            {
                printf("Enter the new room no.: ");
                scanf("%s", upd.room_no);
                fprintf(new, "%s %s %d/%d/%d %d %s %d %s %s %d %s\n", add.roll_no, add.name, add.dob.day, add.dob.month, add.dob.year, add.age, add.city, add.phone, add.mail_id, add.father_name, add.father_phone, upd.room_no);
                printf("Changes saved!");
            }
            else if (choice == 2)
            {
                printf("Enter the new phone number: ");
                scanf("%d", &upd.phone);
                fprintf(new, "%s %s %d/%d/%d %d %s %d %s %s %d %s\n", add.roll_no, add.name, add.dob.day, add.dob.month, add.dob.year, add.age, add.city, upd.phone, add.mail_id, add.father_name, add.father_phone, add.room_no);
                printf("Changes saved!");
            }
        }
        else
            fprintf(new, "%s %s %d/%d/%d %d %s %d %s %s %d %s\n", add.roll_no, add.name, add.dob.day, add.dob.month, add.dob.year, add.age, add.city, add.phone, add.mail_id, add.father_name, add.father_phone, add.room_no);
    }

    fclose(old);
    fclose(new);
    remove("record.dat");
    rename("new.dat", "record.dat");

    if (match != 1)
        printf("\nRecord not found!!\a\a\a");

update_invalid:
    printf("\nEnter 0 to try again, 1 to return to main menu and 2 to exit: ");
    scanf("%d", &main_exit);
    if (main_exit == 1)
        menu();
    else if (main_exit == 2)
        close();
    else if (main_exit == 0)
        update();
    else
    {
        printf("\nInvalid!\a");
        goto update_invalid;
    }
}

// delete records
void delete ()
{
    system("CLS");
    FILE *old, *new;
    int match = 0;

    old = fopen("record.dat", "r");
    new = fopen("new.dat", "w");

    printf("\t\t\t------ DELETE STUDENT'S DATA --------\n");
    printf("Enter the roll no. of student: ");
    scanf("%s", rem.roll_no);
    while (fscanf(old, "%s %s %d/%d/%d %d %s %d %s %s %d %s\n", add.roll_no, add.name, &add.dob.day, &add.dob.month, &add.dob.year, &add.age, add.city, &add.phone, add.mail_id, add.father_name, &add.father_phone, add.room_no) != EOF)
    {
        if (strcmp(add.roll_no, rem.roll_no) != 0)
            fprintf(new, "%s %s %d/%d/%d %d %s %d %s %s %d %s\n", add.roll_no, add.name, add.dob.day, add.dob.month, add.dob.year, add.age, add.city, add.phone, add.mail_id, add.father_name, add.father_phone, add.room_no);

        else
        {
            match++;
            printf("\nRecord deleted successfully!\n");
        }
    }
    fclose(old);
    fclose(new);
    remove("record.dat");
    rename("new.dat", "record.dat");
    if (match == 0)
        printf("\nRecord not found!!\a\a\a");

delete_invalid:
    printf("\nEnter 0 to try again, 1 to return to main menu and 2 to exit: ");
    scanf("%d", &main_exit);
    if (main_exit == 1)
        menu();
    else if (main_exit == 2)
        close();
    else if (main_exit == 0)
        delete ();
    else
    {
        printf("\nInvalid!\a");
        goto delete_invalid;
    }
}

// account information
void account()
{
    system("CLS");

    printf("\t\t\t------- ACCOUNT INFORMATION -------\n");
    printf("\n\t\t ACCOUNT NO: 00079537643-DHK-12");
    printf("\n\t\t BANK NAME: Islami Bank Ltd");
    printf("\n\t\t BRANCH NAME: Asuliya 1220");
    printf("\n\t\t");
    balance();

account_invalid:
    printf("\n\n\nEnter 0 to try again, 1 to return to main menu and 2 to exit: ");
    scanf("%d", &main_exit);
    if (main_exit == 1)
        menu();
    else if (main_exit == 2)
        close();
    else if (main_exit == 0)
        account();
    else
    {
        printf("\nInvalid!\a");
        goto account_invalid;
    }
}

// account information
void balance()
{
    FILE *view;
    view = fopen("balance.dat", "r");

    while (fscanf(view, "%f\n", &add.balance) != EOF)
    {
        printf(" BALANCE: %.2f", add.balance);
    }

    fclose(view);
}

// deposit to account
void deposit()
{
    system("CLS");
    int choice;
    FILE *old, *new;

    old = fopen("balance.dat", "r");
    new = fopen("new.dat", "w");

    printf("\t\t\t------ DEPOSIT AMOUNT --------\n");
    printf("\n\t\t CURRENT");
    balance();

    while (fscanf(old, "%f\n", &add.balance) != EOF)
    {
        printf("\n\t\t Enter amount: ");
        scanf("%f", &upd.balance);
        fprintf(new, "%f\n", add.balance + upd.balance);
    }

    fclose(old);
    fclose(new);
    remove("balance.dat");
    rename("new.dat", "balance.dat");

    printf("\n\t\t Deposited successfully!\n\n");
    printf("\n\t\t NEW");
    balance();

deposit_invalid:
    printf("\n\nEnter 0 to try again, 1 to return to main menu and 2 to exit: ");
    scanf("%d", &main_exit);
    if (main_exit == 1)
        menu();
    else if (main_exit == 2)
        close();
    else if (main_exit == 0)
        deposit();
    else
    {
        printf("\nInvalid!\a");
        goto deposit_invalid;
    }
}

// withdraw from account
void withdraw()
{
    system("CLS");
    int choice;
    FILE *old, *new;

    old = fopen("balance.dat", "r");
    new = fopen("new.dat", "w");

    printf("\t\t\t------ WITHDRAW AMOUNT --------\n");
    printf("\n\t\t CURRENT");
    balance();

    while (fscanf(old, "%f\n", &add.balance) != EOF)
    {
        printf("\n\t\t Enter amount: ");
        scanf("%f", &upd.balance);

        if (add.balance < upd.balance)
        {
            printf("\t\t Insufficient Balance!\n");
            for (i = 0; i <= 9; i++)
            {
                delay(100000000);
                printf(".");
            }
            fprintf(new, "%f\n", add.balance);
        }
        else
        {
            fprintf(new, "%f\n", add.balance - upd.balance);
            printf("\n\t\t Withdrawn successfully!\n\n");
        }
    }

    fclose(old);
    fclose(new);
    remove("balance.dat");
    rename("new.dat", "balance.dat");

    printf("\n\t\t NEW");
    balance();

withdraw_invalid:
    printf("\n\nEnter 0 to try again, 1 to return to main menu and 2 to exit: ");
    scanf("%d", &main_exit);
    if (main_exit == 1)
        menu();
    else if (main_exit == 2)
        close();
    else if (main_exit == 0)
        withdraw();
    else
    {
        printf("\nInvalid!\a");
        goto withdraw_invalid;
    }
}

// exit system
void close()
{
    system("CLS");
    wprintf(L"\n\n\n\t\t\t Copyright \u00A9 Kamrul Haque \n\n\n");
}
