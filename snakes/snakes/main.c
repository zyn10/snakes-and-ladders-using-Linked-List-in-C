//
//  main.c
//  snakes
//
//  Created by 👻 on 06/05/2022.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


struct node {
   int data;
   int key;
   struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;
//======================================================
//=============      INSERT In LIST    =================
//======================================================
void insertFun(int key, int inputData) {

   struct node *link = (struct node*) malloc(sizeof(struct node));   //---->create a dummy link
   
   link->key = key;
   link->data = inputData;

   link->next = NULL;

    if (head==NULL) {
        head=link;
        current=link;
    }

    else {
    current->next = link;//---->passing adress of next one
    current = current->next;//moving tail itself forwrd
    }
}
//======================================================
//==========       DELETE FROM HEAD    =================
//======================================================
struct node* popHead(void) {
   struct node *tempLink = head;//----> dummy reference to first link
   head = head->next;//---------------> replacing dummy to live
   return tempLink;//-----------------> returning the head
}
//======================================================
//===========  TO CHECK EMPTY LIST  ====================
//======================================================
int emp(void ) {
    return head == NULL;
    //----->if head==Null then it will return true
}
//======================================================
//=============  TO LENGTH OF LIST  ====================
//======================================================
int checkLength(void) {
   int dummy = 0;
   struct node *current;
    
   for(current = head; current != NULL; current = current->next)
       //------> unitl end it will iterate and cal the links
   {
      dummy++;
   }
   return dummy;
}
//======================================================
//================   TO POP INDEX   ====================
//======================================================
struct node* pop(int inputKey) {

   struct node* current = head;
   struct node* previous = NULL;
    
   //---> check for empty list
   if(head == NULL) {
      return NULL;
   }

   //---------->traversal of whole list
   while(current->key != inputKey) {


      if(current->next == NULL) {
         return NULL;
      } else {
     
         previous = current;
         current = current->next;
      }
   }

   if(current == head) {
      head = head->next;
   }
   else
   {
      previous->next = current->next;
   }
    
   return current;
}
void displayPath(void){
    printf("Path followed = ");
    struct node *ptr = head;
    while(ptr != NULL)
    {
        printf("%d->",ptr->data);
        ptr = ptr->next;
    }
       
}
//======================================================
//============== DISPLAY FUNCTION   ====================
//======================================================
void display(void)
{
    struct node *ptr = head;
    int counter=0;
    int breakcounter=0;
    int onecheck=0;
    printf("\n\n\t\t==========================================   SNAKES & LADDERS   ==============================================\n\n");
   
    //---------->start from the beginning
    while(ptr != NULL)
    { onecheck++;
       if(counter<9)
       {
           if(breakcounter<9){
                    printf("\t\t %d  |",ptr->data);
                   ptr = ptr->next;
                   breakcounter++;
               
           }
           else if (breakcounter>=9){
               
               printf("\t\t%d  |",ptr->data);
               ptr = ptr->next;
           }
          counter++;
       }
        else if(counter==9)
        {
           printf("\t\t%d   \n\n",ptr->data);
           ptr = ptr->next;
           counter=0;
        
        }
        
        
        
    }
    printf("\n\n\t\t===============================================================================================================\n\n");
    printf("\n\n\n");
}
//======================================================
//============== Set Board by Random   =================
//======================================================
int setBoard(void)
{
    //64---> Maximum Value
    //32---> Minimum Value
    srand(time(0));
    int num = (rand() % (64 - 32 + 1)) + 32;
    return num;
}
//======================================================
//==============      DICE ROLL     ====================
//======================================================
int randomMove (void)
{
  int temp;
  A:temp= rand () % 7;
  if (temp== 0)
    goto A;
  else
    return temp;
}
//======================================================
//==============     Update Board      =================
//======================================================
void updatedBoard (int checkWin, char player[4],int dest)
{
  
  if (checkWin == dest)
    {
      printf ("Wohoooo....You Win \n\nPlayer %s wins\n", player);
      scanf ("%*s");
      exit (0);
    }
    int i=0,j=0;//---------> for loop
    int tempp=0,dummy=0;//---------> for Index Manipulation
    int shiftMove = 0, diceindex;
    
  for (i = 8; i > 0; i--)
    {
      tempp = i - 1;
      if ((shiftMove % 2) == 0)
      {
          dummy = 0;
          for (j = 8; j >= 1; j--)
          {
              diceindex = (i * j) + (tempp * dummy++);

          if (checkWin == diceindex)
              printf ("%s\t", player);
          else
              printf ("%d\t", diceindex);
        }
      shiftMove++;
    }
      else
    {
      dummy = 7;
      for (j = 1; j <= 8; j++)
        {
          diceindex = (i * j) + (tempp * dummy--);

          if (checkWin == diceindex)
        printf ("%s\t", player);
          else
        printf ("%d\t", diceindex);
        }


      shiftMove++;
    }
      printf ("\n\n");
    }

    printf("\n===============================================================================================================\n");

  
}
//printf("Snakes: | 25 to 9  | 65 to 40 | 99 to 1  |\nLadder: | 13 to 42 | 60 to 83 | 70 to 93 |\n\n");

int main(int argc, const char * argv[])
{
    int dest=setBoard();//-----> Return Destination
    printf("\n\n\t\t===============================================================================================================");
    printf("\n\t\t==========================================   SNAKES & LADDERS   ===============================================");
    printf("\n\t\t===============================================================================================================\n\n");
    printf("\nYour Destination on 8x8 Board will be  %d boxes ",dest+1);
    //--------------------------------------------------------//
    //------------------- ladders Postions ------------------//
    //------------------------------------------------------//
    int ladder1_S,ladder2_S,ladder3_S;//---> Source
    int ladder1_D,ladder2_D,ladder3_D;//---> Destination
    //--------------------------------------------------------//
    //------------------- Snake Postion   -------------------//
    //------------------------------------------------------//
    int snake1_S,snake2_S,snake3_S;//------> Source
    int snake1_D,snake2_D,snake3_D;//-----> Destination
    //--------------------------------------------------------//
    //------------------- Setting Postions ------------------//
    //------------------------------------------------------//
//for unit testing
    //    ladder1_S=3 , ladder2_S=13 ,ladder3_S=23;//---> Source
//    ladder1_D=10 , ladder2_D=20 ,ladder3_D=30;//---> Destination
//    snake1_S=13 , snake2_S=23 , snake3_S=32;//------> Source
    snake1_D=3 , snake2_D=15 , snake3_D=10;//-----> Destination
    printf("\nYou Are only allowed to place 3 ladders and 3 snakes\n");
    printf("\nEnter Source of Ladder 1");
    scanf("%d",&ladder1_S);
    printf("\nEnter Destination of Ladder 1");
    scanf("%d",&ladder1_D);
    printf("\nEnter Source of Ladder 2 ");
    scanf("%d",&ladder2_S);
    printf("\nEnter Destination of Ladder 2 ");
    scanf("%d",&ladder2_D);
    printf("\nEnter Source of Ladder 3 ");
    scanf("%d",&ladder3_S);
    printf("\nEnter Destination of Ladder 3");
    scanf("%d",&ladder3_D);
    printf("\nEnter Source of Snake 1");
    scanf("%d",&snake1_S);
    printf("\nEnter Destination of Snake 1");
    scanf("%d",&snake1_D);
    printf("\nEnter Source of Snake 2 ");
    scanf("%d",&snake2_S);
    printf("\nEnter Destination of Snake 2");
    scanf("%d",&snake2_D);
    printf("\nEnter Source of Snake 3");
    scanf("%d",&snake3_S);
    printf("Enter Destination of Snake 3");
    scanf("%d",&snake3_D);
    
    
    
    

    int i=0,dice, currentPosition = 0, cur_pos2 = 0;
    char choice;
    while (1)
      {
        printf("\n\nLadder: | %d to %d | %d to %d | %d to %d |\n",ladder1_S,ladder1_D,ladder2_S,ladder2_D,ladder3_D,ladder3_S);
        printf("Snakes: | %d to %d | %d to %d | %d to %d |\n\n",snake1_S,snake1_D,snake2_S,snake2_D,snake3_S,snake3_D);
        
        printf ("Choose your option\n");
        printf ("Press 1 to Roll the dice \n");
        printf ("Press 2 for Exit\n");
        scanf ("%s", &choice);

        switch (choice)
      {

      case '1':
        dice = randomMove ();
        system ("cls");
              
        printf("\n\n\t\t===============================================================================================================");
        printf("\n\t\t==========================================   SNAKES & LADDERS   ===============================================");
        printf("\n\t\t===============================================================================================================\n\n");
              
        currentPosition = dice + currentPosition;
        insertFun(i, currentPosition);
        if (currentPosition < dest)
          {
            if (currentPosition == snake3_S)
          {
            updatedBoard (snake3_D, "|^^|",dest);    //-------->Check Snake
          }
            if (currentPosition == snake2_S)
          {
            updatedBoard (snake2_D, "|^^|",dest);    //-------->Check Snake
          }
            if (currentPosition == snake1_S)
          {
            updatedBoard (snake1_D, "|^^|",dest);    //-------->Check Snake
          }
            if (currentPosition == ladder3_S)
          {
            updatedBoard (ladder3_D, "|^^|",dest);    //-------->Check ladder
          }
            if (currentPosition == ladder2_S)
          {
            updatedBoard (ladder2_D, "|^^|",dest);    //-------->Check ladder
          }
            if (currentPosition == ladder1_S)
          {
            updatedBoard (ladder1_D, "|^^|",dest);    //-------->Check ladder
          }
            else
          {
            updatedBoard (currentPosition, "|^^|",dest);
          }
            printf ("Dice = %d\n", dice);
            printf("\n\n\===============================================================================================================\n\n");

          }
        else
          {
            currentPosition = currentPosition - dice;
            printf ("wohooo You win.\n");
            displayPath();
              printf("%d\n\n",dest);
              exit(0);
          }
              i++;
        break;
      case '2':
        exit (0);
        break;

      default:
        printf ("Incorrect choice.Try Again\n");

      }
      }
    return 0;
}
