//......... PF Assignment 3.........//
/* Code written By Kunwar Ahmad
   FA-20-BSE-064 G1(Section B)*/

#include<stdio.h>
#include<string.h>

struct book
{
    int bookid;
    int bookcode;
    char name[20];
    char Aname[20];
    int d, m, y;
    float price;
    int copy_in_hand;
    int copy_sold;
};

// Display Books in Tabular Form
void display(struct book books[])
{
    int i;
    printf("\n BOOKS ENTERED : \n\n");    //displaying the books with
    printf("|------------------------------------------------------------------------------------------------------------|\n");
    printf("|------------------------------------------------------------------------------------------------------------|\n");
    printf("|   ID     CODE           NAME               AUTHOR           DATE         PRICE         STOCK        SOLD   |\n");
    printf("|------------------------------------------------------------------------------------------------------------|\n");
    printf("|------------------------------------------------------------------------------------------------------------|");
    for (int i = 0; i < 100; i++)
    {
        if (books[i].bookcode != 0)     //deleted book will not be visible
            printf("\n| %3d   | %5d  |  %12s     | %12s     | (%d/%d/%d) | %9.2f    | %5d     | %5d     |", books[i].bookid,
                   books[i].bookcode,
                   books[i].name,
                   books[i].Aname,
                   books[i].d,
                   books[i].m,
                   books[i].y,
                   books[i].price,
                   books[i].copy_in_hand,
                   books[i].copy_sold);
    }
    printf("\n--------------------------------------------------------------------------------------------------------------");
}

//Deleting Book
void del(struct book books[])
{
    int i;
    printf("\n Enter Book Code you want to delete: ");
    scanf("%d", &i);
    books[i - 1].bookcode = 0;
    printf(" Book Deleted\n");
}

//Searching Book
void search(struct book books[])
{
    int i, k, flag;
    printf("\nEnter Book Code to search : ");
    scanf("%d", &i);

    for (k = 0; k < 100; k++)
    {
        if (books[k].bookcode == i)
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
}

//Selling Book
void sale(struct book books[])
{
    int i, k, flag = 0, sale;
    printf("\nEnter Book Code to Sale : ");
    scanf("%d", &i);
    printf("\nEnter no of books you want to sale : ");
    scanf("%d", &sale);

    for (k = 0; k < 100; k++)
    {
        if (i == books[k].bookcode)
        {
            if (sale <= books[k].copy_in_hand)
            {
                books[k].copy_in_hand -= sale;
                books[k].copy_sold += sale;
                printf("%d Books at ID %d is Sold", sale, k + 1);
            }
            else
            {
                printf("Out of stock or enter less quantity\n ");
            }
        }
    }
}


void main()
{
    int i, no;
    struct book books[100] = { {1,1011,"Calculus","Ahmad",10,02,2005,2000.25,45,5},
        {2,1012,"Geometry","Kunwar",10,02,2005,2200,37,13},
        {3,1013,"Calculus II","Fahad",10,02,2005,2300,35,15},
        {4,1014,"Islamiyat","Rohan",10,02,2005,2350,34,16},
        {5,1015,"English","Ali",10,02,2005,1000,37,13},
        {6,1016,"Chemistry","Saim",10,02,2005,150,25,25},
        {7,1017,"Physics","Arsalan",10,02,2005,1700,47,3},
        {8,1018,"Urdu","Faizan",10,02,2005,950,40,10},
        {9,1019,"Maths","Humayun",10,02,2005,2350,15,35},
        {10,1020,"Pak Studies","Shahzad",10,02,2005,1200,35,15},
        {0,0," "," ",0,0,0,0.0,0,0}
    };
    char option;


    int menu = 0;
    while (menu != 6)    //for repetition of Menu
    {
        //Displaying Menu
        printf("\n\n\n");
        printf("                                    ____*********____\n\n");
        printf("                                    1 - Add book\n\n");
        printf("                                    2 - Display books\n\n");
        printf("                                    3 - Delete book\n\n");
        printf("                                    4 - Search book\n\n");
        printf("                                    5 - Sale book\n\n");
        printf("                                    6 - Exit\n\n");
        printf("                                    ____*********____\n\n\n");



        printf("\nEnter following option to perform function (1 to 6) = ");
        scanf("%d", &menu);

        if (menu == 1)          //OPTION 1 To Add Book Record
        {
            printf("Enter Book Id: ");
            scanf("%d", &no);
            for (i = no - 1; i < 100; i++)
            {
                //User will enter No of Book
                books[i].bookid = no;

                printf("Book Code: ");
                scanf("%d", &books[i].bookcode);
                fflush(stdin);

                printf("Book Name: ");
                gets(books[i].name);
                fflush(stdin);

                printf("Author Name: ");
                gets(books[i].Aname);
                fflush(stdin);

                printf("Publish Date (dd/mm/yyyy) : ");
                scanf("%d/%d/%d", &books[i].d, &books[i].m, &books[i].y);
                fflush(stdin);

                printf("Book Price: ");
                scanf("%f", &books[i].price);
                fflush(stdin);

                printf("Books in hand: ");
                scanf("%d", &books[i].copy_in_hand);
                fflush(stdin);

                printf("Books Sold: ");
                scanf("%d", &books[i].copy_sold);
                fflush(stdin);

                printf("\nYou want to enter more(Y/N) :");
                scanf("%c", &option);

                if (option == 'y' || option == 'Y')
                {
                    printf("Enter Book ID =");
                    scanf("%d", &no);
                }
                else
                {
                    break;
                }
            }
        }

        else if (menu == 2)     //OPTION 2 To Display Book Record
        {
            printf("\n2-Display book \n");
            display(books);
        }

        else if (menu == 3)
        {
            del(books);
        }

        else if (menu == 4)
        {
            printf("\n4-Search book codes : \n");
            search(books);
        }

        else if (menu == 5)
        {
            sale(books);
        }

        if (menu > 6)   //if user entered invalid option
        {
            printf("\n    Enter a valid option.");
        }

    }
    printf("\nExited Successfully\n");
}
