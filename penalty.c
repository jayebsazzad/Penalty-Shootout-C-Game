#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
void coinToss(); // Function to simulate a coin toss
void teamSelection(); // Function to allow the user to select their team
void shotMechanism();  // Function to handle the shooting mechanism for the user's team before sudden death
void saveMechanism(); // Function to handle the saving mechanism for the user's team before sudden death
void shotMechanism2(); // Function to handle the shooting mechanism for the user's team during sudden death
void saveMechanism2(); // Function to handle the saving mechanism for the user's team during sudden death
void match1(); // Function to handle the match flow when the user shoots first
void match2(); // Function to handle the match flow when opponent shoots first
int scoreboard1=0; // global variable to track PSG's score
int scoreboard2=0; // global variable to track Arsenal's score
int remainingShots1= 5; // global variable to track remaining shots for PSG
int remainingShots2= 5; // global variable to track remaining shots for Arsenal
void determineWinner(); // Function to determine and announce the winner of the shootout
void suddenDeath(); // Function to handle sudden death rounds if the match is tied after 5 shots each
void scoreReset(); // Function to reset scores and remaining shots for a new game

int main(){
    printf("===============================\n");
    printf("PSG VS ARSENAL PENALTY SHOOTOUT\n");
    printf("===============================\n");
    printf("Choose your team: Type and press Enter --> 1 for PSG, 2 for Arsenal\n");
    teamSelection();
    Sleep(2000);
    printf("COIN TOSS .....\n");
    Sleep(2000);
    coinToss();
    determineWinner();
    printf("===================================================================================================\n");
    printf("Sorry Arsenal fans, just some friendly banter :) || Anyways,congrats on winning the Premier League!\n");
    printf("===================================================================================================\n");
    printf("Wanna play again? Enter 1 for Yes, 2 for No: ");
    int num=0;
    scanf("%d",&num);
    
    while(num==1){  // Loop for replaying the game
    scoreReset();
    printf("===============================\n");
    printf("PSG VS ARSENAL PENALTY SHOOTOUT\n");
    printf("===============================\n");
    printf("Choose your team: Type and press Enter --> 1 for PSG, 2 for Arsenal\n");
    teamSelection();
    Sleep(2000);
    printf("COIN TOSS .....\n");
    Sleep(2000);
    coinToss();
    determineWinner();
    printf("===================================================================================================\n");
    printf("Sorry Arsenal fans, just some friendly banter :) || Anyways,congrats on winning the Premier League!\n");
    printf("===================================================================================================\n");
    printf("Wanna play again? Enter 1 for Yes, 2 for No: ");
    scanf("%d",&num);
        
    }
    if(num==2){
        printf("Thank you for playing! Hope you enjoyed the game :)\n");
    }
    else{
        printf("Invalid input. Exiting the game.\n");
    }
    return 0;
}
void coinToss(){
    srand(time(NULL));
    int toss=rand()%2;
    if(toss==0){
        printf("You won the coin toss! You will shoot first.\n");
        Sleep(2000);
        match1();
    }
    else{
        printf("You lost the coin toss. Arsenal will shoot first.\n");
        Sleep(2000);
        match2();
    }
}
void teamSelection(){
    int teamChoice=0;
    
    do{
        scanf("%d",&teamChoice);
    if(teamChoice==1){
        printf("You chose PSG\n");

    }
    else if(teamChoice==2){
        printf("Bruh, who chooses Arsenal? Just play as PSG.\n");

    }
    else{
        printf("Invalid input. Please enter 1 for PSG or 2 for Arsenal: ");
        
        
    }
} while(teamChoice!=1 && teamChoice!=2);
}
void match1(){
printf("=========================================\n");
printf("             HOW TO PLAY                 \n");
printf("=========================================\n");
printf("THE RULES:\n");
printf("* You and the Computer will take turns shooting and saving.\n");
printf("* Each team gets up to 5 penalty kicks + sudden death if the match is tied.\n");
printf("* The match ends early if a team mathematically wins!\n");
printf("THE CONTROLS:\n");
printf("On every turn, pick a direction by typing its number and hitting Enter:\n");
printf("\t[1] LEFT  |  [2] CENTER  |  [3] RIGHT\n\n");
printf("=========================================\n\n");
Sleep(4000);
printf("PLAY !!\n");
while((scoreboard1<=scoreboard2+remainingShots2 && scoreboard2<=scoreboard1+remainingShots1) && (remainingShots1>0 || remainingShots2>0)) {
    shotMechanism();
    if((scoreboard1<=scoreboard2+remainingShots2 && scoreboard2<=scoreboard1+remainingShots1) && (remainingShots1>0 || remainingShots2>0)){
    saveMechanism();   
    }
    if((scoreboard1== scoreboard2) && (remainingShots1==0 && remainingShots2==0)){
        while(scoreboard1==scoreboard2){
        suddenDeath();
    }
}
}
}
void match2(){
printf("=========================================\n");
printf("             HOW TO PLAY                 \n");
printf("=========================================\n");
printf("THE RULES:\n");
printf("* You and the Computer will take turns shooting and saving.\n");
printf("* Each team gets up to 5 penalty kicks + sudden death if the match is tied.\n");
printf("* The match ends early if a team mathematically wins!\n");
printf("THE CONTROLS:\n");
printf("On every turn, pick a direction by typing its number and hitting Enter:\n");
printf("\t[1] LEFT  |  [2] CENTER  |  [3] RIGHT\n\n");
printf("=========================================\n\n");
Sleep(4000);
printf("PLAY !!\n");

  
while((scoreboard1<=scoreboard2+remainingShots2 && scoreboard2<=scoreboard1+remainingShots1) && (remainingShots1>0 || remainingShots2>0)) {
    saveMechanism();
    if((scoreboard1<=scoreboard2+remainingShots2 && scoreboard2<=scoreboard1+remainingShots1) && (remainingShots1>0 || remainingShots2>0)){
    shotMechanism();
    }
    if((scoreboard1== scoreboard2) && (remainingShots1==0 && remainingShots2==0)){
        while(scoreboard1==scoreboard2){
        suddenDeath();
    }
}
}
}


void shotMechanism(){
    int shot=0;
    scanf("%d",&shot);
    while(shot<1 || shot>3)
    {
        printf("Invalid input. Please enter 1 for LEFT, 2 for CENTER, or 3 for RIGHT: ");
        scanf("%d",&shot);
    }
    
    srand(time(NULL));
    int save=rand()%3+1;
        
        if(shot==save){
            printf("Oh no! The goalkeeper saved your shot!\n");
            printf("Scoreboard: PSG %d - %d Arsenal\n",scoreboard1,scoreboard2);
            remainingShots1--;
            printf("Remaining shots for PSG: %d\n",remainingShots1);
          
            }
        
        else{
            printf("Goal!!! You scored a penalty!\n");
            scoreboard1++;
        printf("Scoreboard: PSG %d - %d Arsenal\n",scoreboard1,scoreboard2); 
         remainingShots1--;
            printf("Remaining shots for PSG: %d\n",remainingShots1);
        }
}
void saveMechanism(){
    int save=0;
    scanf("%d",&save);
    while (save<1 || save>3)
    {
        printf("Invalid input. Please enter 1 for LEFT, 2 for CENTER, or 3 for RIGHT: ");
        scanf("%d",&save);
    }
    srand(time(NULL));
    int shot=rand()%3+1;
        
        if(shot==save){
            printf("Great save! You stopped the penalty!\n");
            printf("Scoreboard: PSG %d - %d Arsenal\n",scoreboard1,scoreboard2);
             remainingShots2--;
            printf("Remaining shots for Arsenal: %d\n",remainingShots2);
          
        }
        else{
            printf("Oh no! Arsenal scored their penalty!\n");
            scoreboard2++;
      printf("Scoreboard: PSG %d - %d Arsenal\n",scoreboard1,scoreboard2);    
       remainingShots2--;
      printf("Remaining shots for Arsenal: %d\n",remainingShots2);
          
        }
}
void shotMechanism2(){
    int shot=0;
    scanf("%d",&shot);
    while(shot<1 || shot>3)
    {
        printf("Invalid input. Please enter 1 for LEFT, 2 for CENTER, or 3 for RIGHT: ");
        scanf("%d",&shot);
    }
    srand(time(NULL));
    int save=rand()%3+1;
        
        if(shot==save){
            printf("Oh no! The Arsenal keeper saved your shot!\n");
            printf("Scoreboard: PSG %d - %d Arsenal\n",scoreboard1,scoreboard2);
            remainingShots1--;
        
            }
        
        else{
            printf("Goal!!! You scored your penalty!\n");
            scoreboard1++;
            Sleep(500);
        printf("Scoreboard: PSG %d - %d Arsenal\n",scoreboard1,scoreboard2); 
         remainingShots1--;
         
        }
}
void saveMechanism2(){
    int save=0;
    scanf("%d",&save);
    while (save<1 || save>3)
    {
        printf("Invalid input. Please enter 1 for LEFT, 2 for CENTER, or 3 for RIGHT: ");
        scanf("%d",&save);
    }
    srand(time(NULL));
    int shot=rand()%3+1;
        
        if(shot==save){
            printf("Great save! You stopped the penalty!\n");
            printf("Scoreboard: PSG %d - %d Arsenal\n",scoreboard1,scoreboard2);
             remainingShots2--;
           
        }
        else{
            printf("Oh no! The opponent scored a penalty!\n");
            scoreboard2++;
      printf("Scoreboard: PSG %d - %d Arsenal\n",scoreboard1,scoreboard2);    
       remainingShots2--;
            
        }
}
void determineWinner(){
    if(scoreboard1>scoreboard2){
        printf("Vamosss!! PSG wins the penalty shootout - just like in real life!\n");
    }
    else if(scoreboard2>scoreboard1){
        printf("Arsenal wins the penalty shootout  :(  || No worries,PSG won in real life  :)\n");
    }
}
void suddenDeath(){
    printf("Sudden Death! Each team gets one more shot.\n");
    shotMechanism2();
    saveMechanism2();
    
}
void scoreReset(){
    scoreboard1 = 0;
    scoreboard2 = 0;

    remainingShots1 = 5;
    remainingShots2 = 5;
    
}
