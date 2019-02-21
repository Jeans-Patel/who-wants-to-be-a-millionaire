/************************patelJeansA2.c **************
Student Name: Jeans Patel Email Id: jeans@uoguelph.ca
Date: November 9th, 2018 Course Name: CIS 1500
I have exclusive control over this submission via my password.
By including this statement in this header comment, I certify that:
1) I have read and understood the University policy on academic
integrity;
2) I have completed the Computing with Integrity Tutorial on Moodle;
and
3) I have achieved at least 80% in the Computing with Integrity Self
Test.
I assert that this work is my own. I have appropriately acknowledged
any and all material (data, images, ideas or words) that I have used,
whether directly quoted or paraphrased. Furthermore, I certify that
this assignment was prepared by me specifically for this course.
**********************************************************/

/*********************************************************
Compiling the program
*********************************************************
The program should be compiled using the following flags:
-std=c99
-Wall
compiling: gcc patelJeansA2.c -std=c99 -Wall -o patelJeansA2
*********************************************************
Running the Program
*********************************************************
running: ./patelJeansA2
The user is prompted for 8 - 14 different inputs before the output is
generated.
*********************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_QUESTIONS 7

//function prototypes

void promptPlayerForName (char [50]);
void printWelcomeMessage (char  [50]);
int  calculateCurrentAward (int ,int);
void popUpCurrentQuestion4choices (int);
char askPlayerForLifeLine (void);
void popUpCurrentQuestion2choices (int);
char acceptPlayersFinalAnswer (void);
bool isCorrectFinalAnswer (char, int, char [MAX_QUESTIONS]);
void generateRandomGreeting (char [20]);
int calculateReducedAward (int, int);

int main(){

    char allCorrectAnswers [MAX_QUESTIONS + 1] = "CBCBACA";   // for my set of questions
    char greet [20];
    char nameForGame[50];
    int lifeLineUsed = 0;
    int questionNumber = 1;
    char playersResponseLifeLine;
    char finalAnswer;
    int currentAwardAmount ;
    int reducedAmount;
    
	promptPlayerForName(nameForGame);
	
	printWelcomeMessage(nameForGame);
	
	while (questionNumber <= MAX_QUESTIONS)
    {
	
		currentAwardAmount = calculateCurrentAward(questionNumber, currentAwardAmount);
		
		popUpCurrentQuestion4choices(currentAwardAmount);
	
		if (lifeLineUsed == 0)
        {
			playersResponseLifeLine = askPlayerForLifeLine();
		
			if (playersResponseLifeLine == 'Y' || playersResponseLifeLine == 'y')
            {
		
				popUpCurrentQuestion2choices(currentAwardAmount);
				lifeLineUsed ++; 
				printf("\nReminder - You get only 1 50-50 lifeline - and you are using it now \n\n");
			}
		}
		
		finalAnswer = acceptPlayersFinalAnswer ();
		
		if (isCorrectFinalAnswer (finalAnswer, questionNumber, allCorrectAnswers) )
        {
		
		 	generateRandomGreeting(greet);
			printf("%s - You just won $ %d\n", greet, currentAwardAmount);
			
			if (questionNumber < MAX_QUESTIONS)
            {
				printf("Let us play the next question now\n\n"); 
			}
		}
		
		else {
			printf  ("Oops - that was incorrect.");
            
            reducedAmount = calculateReducedAward (questionNumber, currentAwardAmount);

			printf("You still won $%d. Well done.\n\n", reducedAmount);
			
            questionNumber = MAX_QUESTIONS;
		}
		questionNumber ++;
	}
	
	printf("It was fun playing with you \n\n");
	
	return 0;

}	

void promptPlayerForName (char fullName[50])
{
    //Declaring char arrays to hold first and last name
    char firstName[50] = {' '};
    char lastName[50] = {' '};

    //Getting the user to input their first and last name
    printf("Enter your first name: ");
    scanf("%s", firstName);
    printf("Enter your last name: ");
    scanf("%s", lastName);

    //Combining the first and last name into one string
    strcpy(fullName, firstName);
    strcat(fullName, " ");
    strcat(fullName, lastName);
}

void printWelcomeMessage (char fullName[50])
{
    //Declaring integers for loops
    int i;
    int j;

    //The following loops display the players name and display the stars
    for (i = 1; i <= 4; i++)
    {
       if (i == 4)
       {
           for (j = 0; j < strlen(fullName); j++)
           {
               printf("*");
           }
           printf("\n");
       }
       else
       {
           for (j = 1; j <= i; j++)
           {
               printf("*");
           }
           printf("\n");
       }
    }
    printf("%s\n", fullName);

    for (i = 4; i >= 1; i--)
    {
       if (i == 4)
       {
           for (j = 0; j < strlen(fullName); j++)
           {
               printf("*");
           }
           printf("\n");
       }
       else
       {
           for (j = 1; j <= i; j++)
           {
               printf("*");
           }
           printf("\n");
       }
    }
}

int  calculateCurrentAward (int questionNumber, int awardPreviousQuestion)
{
    //Declaring variable to return the calculated award
    int calculated;

    if (questionNumber == 1) // If its the first question the reward will be $100
    {
        calculated = 100;
    }
    else if (questionNumber % 2 == 1) // If its an odd question the reward will be 2 * the award of the previos question
    {
        calculated = 2 * awardPreviousQuestion;
    }
    else  // If its and even question the reward will be 5 * the award of the previos question
    {
        calculated = 5 * awardPreviousQuestion;
    }

    //Returns the calculated award for the current question
    return calculated;
}

void popUpCurrentQuestion4choices (int currentAwardAmount)
{
    //Displays the questions and choices depending on their current award ammount
    if (currentAwardAmount == 100)
    {
        printf("1. Which of the following programming language is taught in CIS1500 at the University of Guelph?\n\nA. Python\t\t\tB. Cobra\nC. C\t\t\t\tD. Java\n\n");
    }
    else if (currentAwardAmount == 500)
    {
        printf("2. Which Canadian chain first opened in Hamilton in 1964?\n\nA. McDonalds\t\t\tB. Tim Horton\nC. Wendys\t\t\tD. Mr. Sub\n\n");
    }
    else if (currentAwardAmount == 1000)
    {
        printf("3. What is Canada's national sport?\n\nA. Hockey\t\t\tB. Lacrosse\nC. Hockey and Lacrosse\t\tD. Baseball\n\n");
    }
    else if (currentAwardAmount == 5000)
    {
        printf("4. Which Canadian city ranks as the most educated in the country?\n\nA. Montreal\t\t\tB. Ottawas\nC. Vancouver\t\t\tD. Toronto\n\n");
    }
    else if (currentAwardAmount == 10000)
    {
        printf("5. What is Canada's highest mountain?\n\nA. Mount Logan, Yukon\t\tB. Whistler Mountain, BC\nC. Mont Tremblant, Quebec\tD. Tip Top Mountain, Ontario\n\n");
    }
    else if (currentAwardAmount == 50000)
    {
        printf("6. What is the easternmost province of Canada?\n\nA. Ontario\t\t\tB. Prince Edward Island\nC. Newfoundland\t\t\tD. Nova Scotia\n\n");
    }
    else if (currentAwardAmount == 100000)
    {
        printf("7. The southernmost point of mainland Canada is called Point Pelee. What province is it in?\n\nA. Ontario\t\t\tB. Quebec\nC. Newfoundland\t\t\tD. Nova Scotia\n\n");
    }

}
char askPlayerForLifeLine (void)
{
    //Declaring variables for loops and return
    int i = 0;
    char answer = ' ';

    //Asks the user if they would like to use a lifeline
    printf("Would you like to use a lifeline (50-50)?\n");

    while (i == 0)  // Loop set in place to prompt the user to input values untill a valid input is entered
    {
        //Lets the user input an answer
        printf("Enter Y or y, N or n: ");
        scanf(" %c", &answer);
        //The if/else statements make sure the input is valid and the loop ends if it is or else it will repeat till a valid input is entered
        if ((answer == 'Y') || (answer == 'y') || (answer == 'N') || (answer == 'n'))
        {
            i = 1;
            printf("\n");
        }
        else
        {
            printf("Invalid input.\n");
        }
    }
    //Returns the users answer
    return answer;
}
void popUpCurrentQuestion2choices (int currentAwardAmount)
{
    //Displays only 2 choices if they choose to use the lifeline depending on what question they are on
    if (currentAwardAmount == 100)
    {
        printf("C. C\t\t\t\tD. Java\n");
    }
    else if (currentAwardAmount == 500)
    {
        printf("A. McDonalds\t\t\tB. Tim Horton\n");
    }
    else if (currentAwardAmount == 1000)
    {
        printf("A. Hockey\t\t\tB. Lacrosse\n");
    }
    else if (currentAwardAmount == 5000)
    {
        printf("A. Montreal\t\t\tB. Ottawas\n");
    }
    else if (currentAwardAmount == 10000)
    {
        printf("A. Mount Logan, Yukon\t\tB. Whistler Mountain, BC\n");
    }
    else if (currentAwardAmount == 50000)
    {
        printf("C. Newfoundland\t\t\tD. Nova Scotia\n");
    }
    else if (currentAwardAmount == 100000)
    {
        printf("A. Ontario\t\t\tB. Quebec\n");
    }
}
char acceptPlayersFinalAnswer (void)
{
    //Declaring variables for loops and return
    char answer;
    int check = 0;

    while (check == 0) // Loop set in place to prompt the user to input values untill a valid input is entered
    {
        //Lets the user input their answer
        printf("Enter you final answer ('A', 'B', 'C', or 'D'): ");
        scanf(" %c", &answer);

        //The if/else statements make sure the input is valid and the loop ends if it is or else it will repeat till a valid input is entered
        if ((answer == 'A') || (answer == 'B') || (answer == 'C') || (answer == 'D'))
        {
            check = 1;
        }
        else
        {
            printf("Please choose a valid answer.\n");
        }
    }
    //Returns the answer to main
    return answer;
}
bool isCorrectFinalAnswer (char finalAnswer, int questionNumber, char allCorrectAnswers[MAX_QUESTIONS])
{
    //Declaring variable for return
    bool correct;

    //The following if/else statements check if the answer the inputed was correct
    if ((questionNumber == 1) || (questionNumber == 6))
    {
        if (finalAnswer == 'C')
        {
            correct = true;
        }
        else
        {
            correct = false;
        }
    }
    else if ((questionNumber == 2) || (questionNumber == 3) || (questionNumber == 4))
    {
        if (finalAnswer == 'B')
        {
            correct = true;
        }
        else
        {
            correct = false;
        }
    }
    else if ((questionNumber == 5) || (questionNumber == 7))
    {
        if (finalAnswer == 'A')
        {
            correct = true;
        }
        else
        {
            correct = false;
        }
    }

    //Returns a true/false depending on if the user was correct or not
    return correct;
}
void generateRandomGreeting (char greet[20])
{
    //Declaring variable for the switch
    int randomNumber;

    //Getting a random number between 1 and 5
    randomNumber = rand() % 5 + 1;

    //The switch assigns greet with a greeting based on the random number
    switch (randomNumber)
    {
        case 1:
            strcpy(greet, "Bravo");
            break;

        case 2:
            strcpy(greet, "Congrats");
            break;

        case 3:
            strcpy(greet, "Well done");
            break;

        case 4:
            strcpy(greet, "Very nice");
            break;

        default:
            strcpy(greet, "Proud of you");
    }
}
int calculateReducedAward (int questionNumber, int currentAwardAmount)
{
    //Declare a variable for return
    int award = 0;

    //The following if/else statement calculates the amount of money the player gets based on the question they are on
    if (questionNumber == 1)
    {
        award = 0;
    }
    else if (questionNumber % 2 == 0)
    {
        award = currentAwardAmount / 5;
    }
    else
    {
        award = currentAwardAmount / 2;
    }

   //Returns the amount of money the earned to main
    return award;
}
