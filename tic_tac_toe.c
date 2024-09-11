// Tic Tac Toe game in C
// Author: sonali parmar
// Date: 07-09-2024
#include<stdio.h>
#include<stdlib.h>
// Display the current state of the game gameBoard
void showgameBoard(int boardState[][3],char gameBoard[][3]) 
{
for(int i=0;i<3;i++)
{
    for(int j=0;j<3;j++)
    {
        if(boardState[i][j]==0)
        printf("   ");
        else
        printf(" %c ",gameBoard[i][j]);
        if(j<2)
        printf(" | ");
    }
    if(i<2)
    printf("\n----------------");
    printf("\n");
}
}
// Check if a currentPlayer's move is valid
int isValidMove(int i,int j,int boardState[][3])
{
    if(boardState[i][j]==0)
    {
       boardState[i][j]=1;
        return 1;
    }
    else 
    return 0;
}
// Handle currentPlayer input and update the game state
void makeMove(int currentPlayer,int boardState[][3],char gameBoard[][3])
{
    int rowIndex,columnIndex;
    printf("\n enter row=");
    scanf("%d",&rowIndex);
    printf("\n enter column=");
    scanf("%d",&columnIndex);    
    while(1)
    {
       rowIndex=rowIndex-1;
    columnIndex=columnIndex-1;
        if(isValidMove(rowIndex,columnIndex,boardState)&&rowIndex<=3&&columnIndex<=3&&rowIndex>=0&&columnIndex>=0)
          {
             if(currentPlayer%2==0)
               gameBoard[rowIndex][columnIndex]='O';
             else
               gameBoard[rowIndex][columnIndex]='X';
               break;
          }
          else
          {
            printf("\n please enter correct row=");
            scanf("%d",&rowIndex);
            printf("\n please enter correct column=");
            scanf("%d",&columnIndex);
          }
    }
}
// Check if the game is a draw
int checkDraw(int boardState[][3])
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(boardState[i][j]==0)
            return 0;
        }
    }
    return 1;
}
// Check if a currentPlayer has won
int checkWinner(int currentPlayer,char gameBoard[][3])
{
    int r,c,i,j;
    char check;
    if(currentPlayer%2==0)
    check='O';
    else
    check='X';
    if(gameBoard[0][0]==check&&gameBoard[2][2]==check&&gameBoard[1][1]==check)
    return 1;
    if(gameBoard[2][0]==check&&gameBoard[1][1]==check&&gameBoard[0][2]==check)
    return 1;
    for(int i=0;i<3;i++)
    {
        r=0;c=0;
        for(int j=0;j<3;j++)
        {
            if(gameBoard[i][j]==check)
            r++;
            if(gameBoard[j][i]==check)
            c++;
        }
        if(r==3||c==3)
        return 1;
    }
    return 0;
}
// Main game loop: handle user input, update game state, and display results
void playTicTacToe()
{
    //Initialize game variables
    int currentPlayer;// Current currentPlayer (0 or 1)
    int menuOption;
    // Loop until the game is won or drawn
    while(1)
    {
        currentPlayer=0;
         int boardState[3][3]={0};//Array to track occupied spaces on the gameBoard
         char gameBoard[3][3]={'S'};// Game gameBoard representation (3x3 array)
         //Game menu
         printf("\n 1. Two Player game\n 2. Exit");
         printf("\n Enter your Option=");
         scanf("%d",&menuOption);
         //Handle your menuOption
        switch(menuOption)
        {
            case 1://Start two currentPlayer game
                     while(1)
                    {
                        currentPlayer++;
                        //Display current game
                        showgameBoard(boardState,gameBoard);
                        //Handle currentPlayer move
                        printf(currentPlayer%2==0?"\n second Player chance\n":"\nfirst Player chance\n");
                        makeMove(currentPlayer,boardState,gameBoard);
                        system("cls");//for mac system(clear);
                        //Check for draw
                        if(checkDraw(boardState))
                        {
                           printf("\nGAME is DRAW\n");
                           break;
                        }
                        //Check for win
                        if(checkWinner(currentPlayer,gameBoard))
                        {
                            if(currentPlayer%2==0)
                                printf("\n SECOND Player IS WINNER\n");
                            else  
                                printf("\nFIRST Player IS WINNER\n");
                                break;
                        }
                    }
                    break;
            case 2://Exit game
                   exit(0);
            default://Invalid menuOption
                    printf("\nWrong Option");
                    break;
            }
        }
}
int main()
{
    printf("\nGame Start\n");
   playTicTacToe();
    return 0;
}