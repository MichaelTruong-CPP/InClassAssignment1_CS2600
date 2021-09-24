/* Number guessing game Ouline
    1) create a menu with options that is displayed on screen
        -create a label menu above printf statements
        -use fprint to display menu
        -use fscan to get user input as a char[]
        -create a while loop so that the program does not terminate until user presses "3"
        -use strcmp(x,y) to compare char[]'s
    2) if option 1 is selected
        -pseudo randomly generate an integer between 1 and default max num (or user selected max num) with rand() 
            and time_t into variable randomNumber
        -use sprintf to store the random # as a char[] in a new variable random
        -prompt user to enter number using fprint and fscan, getting user input as char[]
        -the user is prompted until he char[] userGuess is equal to char[] random
        -use goto menu if user presses q or correctly guesses number
        a. if user does not press q and guesses a number instead
            -store the userGuess into variable guess, as an integer by using atoi(x)
            -let user know if guess too high or low by comparing variable guess and variable randomNumber
        The main reason why we convert data types is because the user input must be able to take in a char[] and int in one scanf statement
    3) if option 2 is selected
        a. temporary save max number
            -prompt user using printf and scanf until they input a number less than the default max number (10), 
                and greater than the lowest number possible (1), by using while loop; 1 <= num <= 10
        b. permantly save max number
            -read and write to .txt file (saved_user_max_number.txt)
            -then simply combine with part a
        goto menu when done
    4) if option 3 is selected
        -thank user for playing by using printf      
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//SOME CODE IS COMMENTED OUT BECAUSE IT IS FOR THE SAVED USER MAX NUMBER IMPLEMENTATION

//int get_saved_user_max_number();
//void edit_saved_user_max_number(int max_number);

int main() {
    time_t t;
    char keyPress[] = "4";
    char userGuess[] = "";
    int default_max_number = 10;  
    menu:
    printf("\nPress 1 to play a game\n");
    printf("Press 2 to change max number\n");
    printf("Press 3 to quit\n");
    scanf("%s", &keyPress);
    while (strcmp(keyPress, "3") != 0) {
        srand((unsigned) time(&t));
        int randomNumber= rand() % default_max_number;
        //int randomNumber= rand() % get_saved_user_max_number();
        randomNumber++;
        char random[100];
        sprintf(random, "%d", randomNumber);  //convert from int to char[]
        if (strcmp(keyPress, "1") == 0) {
                while (strcmp(userGuess, random) != 0) {
                    printf("Guess the number: ");
                    scanf("%s", &userGuess);
                    if (strcmp(userGuess, "q") == 0) {
                        goto menu;
                    }
                    int guess = atoi(userGuess);  //convert from char[] to int
                    if (guess > randomNumber) {
                        printf("You are too high\n");
                    } 
                    if (guess < randomNumber) {
                        printf("You are too low\n");
                    } 
                
                } 
                printf("You win!");
                goto menu;
        }
        if (strcmp(keyPress, "2") == 0) {
            printf("Enter new max number no greater than 10 and no less than 1: ");
            scanf("%d", &default_max_number);
            while (default_max_number > 10 || default_max_number < 1) {
                printf("Enter new max number no greater than 10 and no less than 1: ");
                scanf("%d", &default_max_number);
            }
            //edit_saved_user_max_number(default_max_number);
            goto menu;
        }
        else {
            goto menu;
        }

    }
    printf("\nThank you for playing!");

}

/*
int get_saved_user_max_number() {
    FILE *fp;
    char buff[255];
    int num;

    
    fp = fopen("saved_user_max_number.txt", "r");
    fgets(buff, 255, (FILE*)fp);
    fgets(buff, 255, (FILE*)fp);
    //printf("%s\n", buff );
    int max_num = atoi(buff);
    
    fclose(fp);
    return max_num;
}

void edit_saved_user_max_number(int max_number) {
    FILE *fp;
    char buff[255];
    sprintf(buff, "%d", max_number);

    fp = fopen("saved_user_max_number.txt", "w");
    fprintf(fp, "The saved max number is located under this line:\n");
    fprintf(fp, "%s\n", buff);
     
    fclose(fp);
}
*/
