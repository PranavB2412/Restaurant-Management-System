#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include "admin.h"
#include "customer.h"

void main()
{
    char admin_or_customer;
    char blank;
    printf("\n\n --- Utility ---   \n\n Press 1 for Customer. \n Press 2 for Admin. \n Press 3 to exit. \n\n - - - -  ");
    scanf("%c", &admin_or_customer);
    scanf("%c", &blank);

    switch (admin_or_customer)
    {
        case '1':
            customer();
            break;
        
        case '2':
            admin();
            break;

        case '3':
            printf("Thank you for visiting! Have a nice day :) \n");
            break;

        default:
            printf("Invalid entry. Please choose again - - - > \n");
            main();

    }    
    
}