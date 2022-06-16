#include <stdio.h>
#include <string.h> //strlen()
#include <stdlib.h> //rand(), srand()
#include <time.h>  //time()

int calculate_amount(int*, int*, int*); //Function Prototyping

int total_amount; //Global Declaration 


int main() {
        
    //Variable Declaration 
    char item_names[10][15] = { 
                            "Vada Pav",
                            "Pav Bhaji",
                            "Samosa",
                            "Chicken Puff",
                            "Veg Puff",
                            "Egg Puff",
                            "Coffee",
                            "Tea",
                            "Chips",
                            "Biscuits"

        };
    int prices[10] = {25,40,15,25,15,20,10,10,20,10};


    //Printing The Menu
    printf("\nItem Number\tItem Name\t\tPrices\n");
    printf("------------------------------------------------\n");
    int i;
    for(i=0;i<10;i++) {
        printf("%d\t\t",i+1);
        printf("%s",item_names[i]);
        if(strlen(item_names[i])>6)
            printf("\t\t%d\n",prices[i]);
        else 
            printf("\t\t\t%d\n",prices[i]);
    }
    printf("------------------------------------------------\n");

    
    //User Input
    char check;
    int bill_item_numbers[25],bill_item_quantity[25],index=0; 
    int input, quantity;
    do {
        printf("\nEnter the required item number : ");
        scanf("%d",&input);
        printf("Enter how many of the item you would like : ");
        scanf("%d",&quantity);

        //Storing inputted item name, item number and calculating bill amount
        if (input>=1 && input<=10) {
                bill_item_numbers[index] = input-1;
                bill_item_quantity[index] = quantity;
                index++;
        }
        calculate_amount(&input,&total_amount,&quantity);
        printf("Would you like to add more items (y/n) : ");
        scanf(" %c",&check);
    }
    while(check=='y');


    //Printing Token
    int ind;
    time_t t;
    srand((unsigned) time(&t)); //Token number randomiser 
    printf("\n\t\tTOKEN %d\n",rand() % 100);  
    printf("Item Name\tQuantity\tPrice\n");
    printf("----------------------------------------\n");
    for(i=0;i<index;i++) {
        ind = bill_item_numbers[i];
        printf("%s\t",item_names[ind]);
        if(strlen(item_names[ind])>6) {
            printf("%d\t\t",bill_item_quantity[i]);
            printf("%d\n",bill_item_quantity[i]*prices[ind]);
        }
        else { 
            printf("\t%d\t\t",bill_item_quantity[i]);   
            printf("%d\n",bill_item_quantity[i]*prices[ind]);
        }
    }
    printf("----------------------------------------");
    printf("\nTotal Bill Amount: %d\n", total_amount);

    return 0;
}


// Function to calculate the bill amount
int calculate_amount(int* input, int* total_amount, int*quantity) {
        switch(*input) {        
            case 1: *total_amount += 25*(*quantity);
                    break;
            case 2: *total_amount += 40*(*quantity);
                    break;
            case 3: *total_amount += 15*(*quantity);
                    break;
            case 4: *total_amount += 25*(*quantity);
                    break;
            case 5: *total_amount += 15*(*quantity);
                    break;
            case 6: *total_amount += 20*(*quantity);
                    break;
            case 7: *total_amount += 10*(*quantity);
                    break;
            case 8: *total_amount += 10*(*quantity);
                    break;
            case 9: *total_amount += 20*(*quantity);
                    break;
            case 10: *total_amount += 10*(*quantity);
                    break;
            default:printf("Enter an item number between 1-10\n");
        }
        return 0;
}