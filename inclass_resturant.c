/*Resturant Bill Outline
   1) accept the tax and tip both as percentages from command line
      -use printf and scanf to get tax/tip percents, then convert them to decimals
   2) randomly choose b/w salad, soup, sandwich, or pizza
      -pseudo randomly generate a number b/w 0-3 using rand() and time_t, and each number corresponds to a food item
   3) display total meal cost, tax amount, tip amount, and total bill on screen
      -multiply cost of the 1 food item by tax rate, and then do the same with tip rate 
      -total the food cost, tax, and tip, to get total bill.
      -display using printf
*/

//TIP AFTER TAX

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {
   time_t t;
   
   double salad_price = 9.95;
   double soup_price = 4.55;
   double sandwich_price = 13.25;
   double pizza_price = 22.35; 
   double tip_rate;
   double tax_rate;
   double tax;
   double tip;
   double totalBill;
   printf("Enter tax rate as percentage: ");
   scanf("%lf", &tax_rate);
   printf("Enter tip rate as percentage: ");
   scanf("%lf", &tip_rate);
   tax_rate = tax_rate / 100;  //convert percentage to decimal
   tip_rate = tip_rate / 100;
   srand((unsigned) time(&t));  // Intializes random number generator 
   int randomOrder= rand() % 4;
   if (randomOrder == 0) { //random order is salad
      tax = salad_price*tax_rate;
      totalBill = salad_price + tax;
      totalBill = (totalBill*tip_rate) + totalBill;
      printf("\nTotal bill of ordering salad: $%.2f", totalBill);
   }
   else if (randomOrder == 1) { //random order is soup
      tax = soup_price*tax_rate;
      totalBill = soup_price + tax;
      totalBill = (totalBill*tip_rate) + totalBill;
      printf("\nTotal bill of ordering soup: $%.2f", totalBill);
   }
   else if (randomOrder == 2) { //random order is sandwich
      tax = sandwich_price*tax_rate;
      totalBill = sandwich_price + tax;
      totalBill = (totalBill*tip_rate) + totalBill;
      printf("\nTotal bill of ordering sandwich: $%.2f", totalBill);
   }
   else if (randomOrder == 3) { //random order is pizza
      tax = pizza_price*tax_rate;
      totalBill = pizza_price + tax;
      totalBill = (totalBill*tip_rate) + totalBill;
      printf("\nTotal bill of ordering pizza: %.2f", totalBill);
   }
   
   
   return(0);
}

