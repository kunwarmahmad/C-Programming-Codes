//......... PF Assignment 2.........//
/* Code written By Kunwar Ahmad
   FA-20-BSE-064  G1(Section B)*/

#include<stdio.h>
int add_book(int books[]);
int print_books(int books[]);
int del_book(int books[]);
int searchBook(int books[]);
int sortBooks(int books[]);


int main()
{
    //Displaying Menu
    printf("_______________________\n");
    printf("1 - Add book code\n");
    printf("2 - Display book codes\n");
    printf("3 - Delete book code\n");
    printf("4 - Search book Code\n");
    printf("5 - Arrange book code\n");
    printf("6 - Exit\n");
    printf("_______________________\n");

    int books[20] = {0};
    int menu = 0;
    while (menu != 6)    //for repetition of Menu
    {
        printf("\nEnter following option to perform function (1 to 6) = ");
        scanf("%d", &menu);
        if (menu == 1)      //Comparing the options
        {
            add_book(books);
        }

        else if (menu == 2)
        {
            printf("\n2-Display book codes : \n");
            print_books(books);
        }

        else if (menu == 3)
        {
            del_book(books);
        }

        else if (menu == 4)
        {
            printf("\n4-Search book codes : \n");
            searchBook(books);
        }

        else if (menu == 5)
        {
            printf("\n5 - Arranged Book Codes : \n");
            sortBooks(books);
        }

        if (menu > 6)   //if user entered invalid option
        {
            printf("Enter a valid option.");
        }
        printf("\nExited Successfully.\n\n");
    }
    return 0;
}

//Adding Books
int add_book(int books[])
{
    int i;
    printf("\nEnter 20 book codes \n\n");
    for (i = 0; i < 20; i++)
    {
        printf(" Book %d    =   ", i + 1);   //User will enter 20 book codes
        scanf("%d", &books[i]);
    }
    return books[i];
}

//Printing Entered Books
int print_books(int books[])
{
    int i;
    printf("\n BOOKS ENTERED : \n");    //displaying the books with code
    for (int i = 0; i < 20; i++)
    {
        if (books[i] != 0)  //deleted book will not be visib
            printf(" \nBook [%d]    =   %d", i + 1, books[i]);
    }

    return 0;
}

//Deleting Book
int del_book(int books[])
{
    int i;
    printf("\n Enter Book you want to delete: ");
    scanf("%d", &i);
    books[i - 1] = 0;
    printf(" Book Deleted\n");
    return 0;
}

//Searching Book
int searchBook(int books[])
{
    int i, k, flag;
    printf("\nEnter Book Code to search : ");
    scanf("%d", &i);

    for (k = 0; k < 20; k++)
    {
        if (books[k] == i)
        {
            printf("Found Book %d. \n ", k + 1);
            flag = 0;
            break;
        }
        else
        {
            flag = 1;
        }
    }
    if (flag == 1)
    {
        printf("Book not Found.\n ");
    }
    return 0;
}

//Arranging Books in ascending order
int sortBooks(int books[])
{
    int i, pass, k = 1, hold;
    for (pass = 1; pass < 20; pass++)
    {
        for (i = 0; i <= 20 - 2; i++)
        {
            if (books[i] > books[i + 1])
            {
                hold = books[i];
                books[i] = books[i + 1];
                books[i + 1] = hold;
            }
        }
    }
    for (i = 0; i < 20; i++)  // displaying Arranged books
    {
        if (books[i] != 0)
        {
            printf("book %d- %d\n", k, books[i]);
            k++;
        }
    }
    return 0;
}
