#include <stdio.h>
int main()
{
    int pr_code, qty= 0;
    int r1 = 500;
    int r2 = 800;
    int r3 = 600;
    int r4 = 1000;
    int r5 = 700;
    float total, dis, payable;

    printf("5431	Fries	500\n");
    printf("2331	Rice	800\n");
    printf("7856 	Bread	600\n");
    printf("9987	Beef	1000\n");
    printf("8865	Milk	700\n");

    printf("Enter Product Code: ");
    scanf("%d", &pr_code);

    printf("Enter Quantity: ");
    scanf("%d", &qty);

    if(pr_code==5431)
    {
        printf("Product Code	Product Name	Rate	Quantity ");
        printf("5431		Fries		500	%d", qty);
        printf("\nTotal Price : %f\n",total = r1 * qty);
    }

    else if(pr_code==2331)
    {
        printf("\nProduct Code	Product Name	Rate	Quantity \n");
        printf("2331		Rice		800	%d", qty);
        printf("\nTotal Price : %f\n",total = r2 * qty);
    }

    else if(pr_code==7856)
    {
        printf("\nProduct Code	Product Name	Rate	Quantity \n");
        printf("7856		Bread		600	%d", qty);
        printf("\nTotal Price : %f\n",total = r3 * qty);
    }

    else if(pr_code==9987)
    {
        printf("\nProduct Code	Product Name	Rate	Quantity \n");
        printf("9987		Beef		1000	%d", qty);
        printf("\nTotal Price : %f\n",total = r4 * qty);
    }

    else if(pr_code==8865)
    {
        printf("\nProduct Code	Product Name	Rate	Quantity \n");
        printf("8865		Milk		700	%d", qty);
        printf("\nTotal Price : %f\n",total = r5 * qty);
    }

    else
        printf("\nEnter Correct Code");

    if (total > 10000)
    {
        dis = (total * 0.1);
        payable = (float)total - dis;

        printf("Discounted Price = Rs %f\n", dis);
        printf("Total expenses = Rs %f\n", payable);
    }

    else
        printf("\nTotal Amount = Rs %f", total);

    return 0;
}
