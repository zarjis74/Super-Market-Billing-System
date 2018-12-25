/*
Project: Super Market Billing System
By
Zarjis Bin Zakir
Id:1411377042
Course: CSE 115
Date: 11/7/2014
*/

#include <stdio.h>
#include <string.h>
struct shop
{
    char product_name[30];
    int product_quantity;
    float per_product_price;
    float discount;
};

void new1 (struct shop data[1000], int a);
void calc (struct shop data[1000],int a,float sub_total[1000]);

int main()
{
    struct shop rct[10];
    int i,o,x=0,response,count=0;
    float s_t[20],discount,vat,total=0,net_amount=0.0,vat_tk,v;
    for(i=0; ;i++)
    {
        //printf("Easy Mart Super Shop");
        printf("\n\n\n");
        printf("\t\t Easy Mart Super Shop!\n\n");
        printf("             *****************************|\n");
        printf("             |    Billing System Menu     |\n");
        printf("             |*****************************\n\n");
        printf("1. Creat a New List to add Product\n2. EXIT\n\n");
        printf("Enter Your Option: ");
        scanf("%d",&o);
        if(o==1)
        {
            do
            {
                new1(rct,x);
                x++;
                printf("\nDo u want to add product? 1 for yes/0 for no: ");
                scanf("%d",&response);
                count++;
            }
            while(response==1);
            for(i=0;i<count;i++)
            {
                 calc(rct,i,s_t);
                 net_amount=net_amount+s_t[i];

            }

            printf("Enter vat: %%");
            scanf("%f",&vat);

            i=0;
            while(i<count)
            {
                total=total+s_t[i];
                i++;
            }

            vat_tk=(total*vat)/100;
            total=total+vat_tk;
            if(total>1000)
            {
                discount=150;
            }
            else
            {
                discount=0;
            }
            total=total-discount;


            printf("\n\nList of Customers Buying Product :\n");
            printf("---------------------------------");
            printf("\n\nBuying product\tUnit price\tQuantity\tTotal\n");
            for(i=0;i<count;i++)
            {
                printf("\n%s\t\t%0.2f\t\t%d\t\t%0.2f\n",rct[i].product_name,rct[i].per_product_price,rct[i].product_quantity,s_t[i]);
            }
            printf("------------------------------------------------------\n");
            printf("All Products Total Price\t\t\t%0.2f\n",net_amount);
            printf("\nAdditional Charges");
            printf("\n------------------");
            printf("\n\nDiscount\t\%0.2f\n",discount);

            printf("Vat %0.2f%%\t%0.2f\n",vat,vat_tk);
            printf("--------------------\n");
            printf("Total Bill\t%0.2f\n\n\n",total);


        }
        else if(o==2)
        {
            printf("\n\nThanks for Shopping with us!\n\n");

            break;
        }
    }
}
void new1(struct shop data[20], int a)
{
    getchar();
    printf("Enter your product name: ");
    gets(data[a].product_name);
    printf("Enter your product quantity: ");
    scanf("%d",&data[a].product_quantity);
    printf("Enter per product price: ");
    scanf("%f",&data[a].per_product_price);
}

void calc (struct shop data[10], int a, float sub_total[20])
{

    sub_total[a]=data[a].per_product_price * data[a].product_quantity;
}




