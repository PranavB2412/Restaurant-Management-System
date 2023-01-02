#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

// Declaring functions that will be used through the flow of execution
void customer();
void pick_cuisine();
void display_indian_menu();
void display_french_menu();
void display_italian_menu();
void display_chinese_menu();
void add_indian_order();
void add_french_order();
void add_italian_order();
void add_chinese_order();
void calculate_bill();

// Structure to store the name and price of every food item from the menu of each cuisine. 
struct Food_item
{
    char name[50];
    float price;
};

typedef struct Food_item food;

food indian_dishes[50]={{"Aam Panna",90},{"Jal Jeera",75},{"Badam Milk",105},{"Buttermilk",95},{"Indian filter coffee",80}, {"Paneer tikka",150},{"Baked Samosa",120},{"Tandoori Aloo Tikka",125},{"Veg Kebab",135},{"Hara Bhara Kebab",150},{"Corn Pakoda",135},{"Tandoori Roti",120},{"Butter Naan",120},{"Dal Fry",215},{"Dal Makhani",225},{"Paneer Butter Masala",230},{"Mix Veg Curry",220},{"Masala Dose",170},{"Idly Vada",120},{"Peas Pulao",210},{"Gulab Jamoon",150},{"Gajar Halwa",160},{"Rasgulla",150},{"Jalebi Baby", 135}};
food french_dishes[50]={{"Champagne",450},{"Pineau",250},{"Monaco",350},{"French Cider",400},{"Orangina",350},{"Lyonnaise Salad",225},{"Onion Galette",200},{"French Cheese Puffs",200},{"Cheese Souffle",200},{"French Potato Salad",225},{"Fondue",225},{"Bouillabaisse",330},{"Steak frites",300},{"Chicken confit",300},{"French onion soup",200},{"Salmon en papillote",350},{"Quiche Lorraine",330},{"Croque monsieur",340},{"Boeuf bourguignon",310},{"Cassoulet",315},{"Creme au Caramel",220},{"Lemon Tart",250},{"Breton Butter Cake",250},{"Croissants",215}};
food italian_dishes[50]={{"Aperitivo",200},{"Spritz",195},{"Limoncello",220},{"Bellini",235},{"Cappuccino",150},{"Classic Bruschetta",220},{"Italian meatballs",245},{"Italian starter platter",220},{"Cheese corn balls",210},{"Risotto balls with pizza sauce",250},{"Cheese poppers",220},{"Pizza margherita",250},{"Mexican green wave pizza",235},{"Macaroni and cheese",325},{"Spaghetti aglio olio",300},{"Cheese lasagne",325},{"Pancetta pizza",350},{"Pasta arabiatta",210},{"Penne pasta",},{"Cheese and corn pizza",195},{"Italian butter cookies",150},{"Panettone",180},{"Lemon ricotta cake",195},{"Tiramisu",185}};
food chinese_dishes[50]={{"Soybean Milk",95},{"Yunnan Coffee",105},{"Tsingtao Beer",170},{"Chrysanthemum Tea",135},{"Xinjiang Black Beer",225},{"Chilli potatoes",225},{"Baby corn manchurian",245},{"Veg spring rolls",215},{"Schezuan cheese balls",215},{"Chilli baby corn",180},{"Pan fried dumplings",185},{"Kung pao chicken",340},{"Burnt garlic fried rice",225},{"Veg hakka noodles",},{"Lo mein",275},{"Chinese chow mein",320},{"Chinese pepper steak",210},{"Chinese chicken fried rice",320},{"Moo shu chicken",295},{"Veg manchurian gravy",250},{"Egg tarts",220},{"Pumpkin pancakes",210},{"Soy milk pudding",175},{"Red bean cakes",155}};

food order[100];
int order_pos = 0;
float subtotal = 0;


void customer()
{   
    char are_they_ordering;
    printf("---------------------Welcome to Cheesy Peasy :)---------------------\n\n");
    printf("Would you life to place an order? (Press Y to order, any other key to exit) ------>   ");
    scanf("%c", &are_they_ordering);

    switch(are_they_ordering)
    {
        case 'Y': 
        case 'y':
            pick_cuisine(); 
            break;

        default:
            printf("Come again soon!\n");
    }

    if(order_pos!=0)
        calculate_bill();    

}

void pick_cuisine()
{   
    char blank;
    scanf("%c",&blank);
    char cuisine_number;
    printf("\n\nWhich cuisine would you like to order from?\n\n");
    printf(" 1. Indian\n\n 2. French\n\n 3. Italian\n\n 4. Chinese\n\n Make your choice:  (1/2/3/4) ----->  ");
    scanf("%c", &cuisine_number);
    switch(cuisine_number)
    {
        case '1': 
            display_indian_menu(); 
            break;
        case '2': 
            display_french_menu(); 
            break;
        case '3': 
            display_italian_menu(); 
            break;
        case '4': 
            display_chinese_menu(); 
            break;

        default:
            printf("Invalid choice. Please choose again - \n"); 
            pick_cuisine(); 
            break;
    }
    
}

/* This function displays the food items in the Indian menu.
*/
void display_indian_menu()
{   
    
    printf("--------------------------------------------------------------\n");
    printf("\n----------------------Indian menu----------------------\n\n");

    // Printing beverages.
    printf("\n\t\tBeverages\n\n");
    for(int i = 0; i<5; i++)
       { printf("[%d] %s  --------- Rs.%0.2f\n", (i+1), indian_dishes[i].name, indian_dishes[i].price);
       }
    
    // Printing starters
    printf("\n\t\tStarters\n\n");
    for(int i = 5; i<11; i++)
        { printf("[%d] %s  --------- Rs.%0.2f\n", (i+1), indian_dishes[i].name, indian_dishes[i].price);
        }

    // Printing Mains
    printf("\n\t\tMains\n\n");
    for(int i = 11; i<20; i++)
        { printf("[%d] %s  --------- Rs.%0.2f\n", (i+1), indian_dishes[i].name, indian_dishes[i].price);
        }
    
    // Printing Desserts
    printf("\n\t\tDesserts\n\n");
    for(int i = 20; i<24; i++)
        { printf("[%d] %s  --------- Rs.%0.2f\n", (i+1), indian_dishes[i].name, indian_dishes[i].price);
        }

    printf("\n---------------------------------------\n\n");    
    add_indian_order();
}

void display_french_menu()
{
    printf("--------------------------------------------------------------\n");
    printf("\n----------------------French menu----------------------\n\n"); 
    printf("\n\t\tBeverages\n\n");
    for(int i = 0; i<5; i++)
        printf("[%d] %s  --------- Rs.%0.2f\n", (i+1), french_dishes[i].name, french_dishes[i].price);
    
    printf("\n\t\tStarters\n\n");
    for(int i = 5; i<11; i++)
        printf("[%d] %s  --------- Rs.%0.2f\n", (i+1), french_dishes[i].name, french_dishes[i].price);

    printf("\n\t\tMains\n\n");
    for(int i = 11; i<20; i++)
        printf("[%d] %s  --------- Rs.%0.2f\n", (i+1), french_dishes[i].name, french_dishes[i].price);
    
    printf("\n\t\tDesserts\n\n");
    for(int i = 20; i<24; i++)
        printf("[%d] %s  --------- Rs.%0.2f\n", (i+1), french_dishes[i].name, french_dishes[i].price);

    printf("\n---------------------------------------\n\n");
    add_french_order();
}

void display_italian_menu()
{
    printf("--------------------------------------------------------------\n");
    printf("\n----------------------Italian menu----------------------\n\n");
    printf("\n\t\tBeverages\n\n");
    for(int i = 0; i<5; i++)
        printf("[%d] %s  --------- Rs.%0.2f\n", (i+1), italian_dishes[i].name, italian_dishes[i].price);
    
    printf("\n\t\tStarters\n\n");
    for(int i = 5; i<11; i++)
        printf("[%d] %s  --------- Rs.%0.2f\n", (i+1), italian_dishes[i].name, italian_dishes[i].price);

    printf("\n\t\tMains\n\n");
    for(int i = 11; i<20; i++)
        printf("[%d] %s  --------- Rs.%0.2f\n", (i+1), italian_dishes[i].name, italian_dishes[i].price);
    
    printf("\n\t\tDesserts\n\n");
    for(int i = 20; i<24; i++)
        printf("[%d] %s  --------- Rs.%0.2f\n", (i+1), italian_dishes[i].name, italian_dishes[i].price);

    printf("\n---------------------------------------\n\n");
    add_italian_order();
}
void display_chinese_menu()
{   
    printf("--------------------------------------------------------------\n");
    printf("\n----------------------Chinese menu----------------------\n\n");
    printf("\n\t\tBeverages\n\n");
    for(int i = 0; i<5; i++)
        printf("[%d] %s  --------- Rs.%0.2f\n", (i+1), chinese_dishes[i].name, chinese_dishes[i].price);
    
    printf("\n\t\tStarters\n\n");
    for(int i = 5; i<11; i++)
        printf("[%d] %s  --------- Rs.%0.2f\n", (i+1), chinese_dishes[i].name, chinese_dishes[i].price);

    printf("\n\t\tMains\n\n");
    for(int i = 11; i<20; i++)
        printf("[%d] %s  --------- Rs.%0.2f\n", (i+1), chinese_dishes[i].name, chinese_dishes[i].price);
    
    printf("\n\t\tDesserts\n\n");
    for(int i = 20; i<24; i++)
        printf("[%d] %s  --------- Rs.%0.2f\n", (i+1), chinese_dishes[i].name, chinese_dishes[i].price);

    printf("\n---------------------------------------\n\n");
    add_chinese_order();
}

void add_indian_order()
{
    printf("What would you like to order? \n"); 
    int selected_item; 
    scanf("%d", &selected_item); 
    order[order_pos]=indian_dishes[selected_item-1];

    char want_to_order;
    char blank;
    scanf("%c", &blank);

    int quantity;
    printf("Enter quantity : ");
    scanf("%d", &quantity);
    scanf("%c", &blank);

    subtotal+= ((order[order_pos].price)*quantity);    
    order_pos+=1;

    printf("Would you like to order more? (Y to order more, any other key to exit) --->  ");
    scanf("%c", &want_to_order);

    if(want_to_order=='y' || want_to_order=='Y')
        pick_cuisine();
}

void add_french_order()
{
    printf("What would you like to order? \n"); 
    int selected_item; 
    scanf("%d", &selected_item); 
    order[order_pos]=french_dishes[selected_item-1];

    char want_to_order;
    char blank;
    scanf("%c", &blank);

    int quantity;
    printf("Enter quantity : ");
    scanf("%d", &quantity);
    scanf("%c", &blank);

    subtotal+= ((order[order_pos].price)*quantity);    
    order_pos+=1;

    printf("Would you like to order more? (Y to order more, any other key to exit) --->  ");
    scanf("%c", &want_to_order);

    if(want_to_order=='y' || want_to_order=='Y')
        pick_cuisine();
}

void add_italian_order()
{
    printf("What would you like to order? \n"); 
    int selected_item; 
    scanf("%d", &selected_item); 
    order[order_pos]=italian_dishes[selected_item-1];

    char want_to_order;
    char blank;
    scanf("%c", &blank);

    int quantity;
    printf("Enter quantity : ");
    scanf("%d", &quantity);
    scanf("%c", &blank);

    subtotal+= ((order[order_pos].price)*quantity);    
    order_pos+=1;

    printf("Would you like to order more? (Y to order more, any other key to exit) --->  ");
    scanf("%c", &want_to_order);

    if(want_to_order=='y' || want_to_order=='Y')
        pick_cuisine();
}

void add_chinese_order()
{
    printf("What would you like to order? \n"); 
    int selected_item; 
    scanf("%d", &selected_item); 
    order[order_pos]=chinese_dishes[selected_item-1];

    char want_to_order;
    char blank;
    scanf("%c", &blank);

    int quantity;
    printf("Enter quantity : ");
    scanf("%d", &quantity);
    scanf("%c", &blank);

    subtotal+= ((order[order_pos].price)*quantity);    
    order_pos+=1;

    printf("Would you like to order more? (Y to order more, any other key to exit) --->  ");
    scanf("%c", &want_to_order);

    if(want_to_order=='y' || want_to_order=='Y')
        pick_cuisine();
}

void calculate_bill()
{
    float cgst = 0, sgst = 0;
    float final_bill = 0;

    printf("\n\n ------------------------------------------------ \n");
    printf("\n\t BILL:        \n");
    printf("\n ------------------------------------------------ \n\n");

    for(int i = 0; i<order_pos; i++)
    {
        printf("[%d] %s ----->   %0.2f\n", (i+1), order[i].name, order[i].price);
    }

    cgst = 0.025*subtotal;
    sgst = 0.025*subtotal;

    printf("SUBTOTAL     :\t\t\t\t %0.2f Rs.     \n", subtotal);
    printf("CGST @ 2.5%% :\t\t\t\t %0.2f Rs.     \n", cgst);
    printf("SGST @ 2.5%% :\t\t\t\t %0.2f Rs.     \n", sgst);

    printf("\nTotal GST:\t\t\t\t %0.2f Rs.      \n", cgst+sgst);
    printf("\n-------------------------------------------------\n");

    final_bill = subtotal + cgst + sgst;
    printf("Total Bill:\t\t\t\t %0.2f Rs.       \n", final_bill);
    printf("---------------------------------------------------\n");
    printf("\n\t   Thanks for coming!!!    \n");
    printf("---------------------------------------------------\n");

}