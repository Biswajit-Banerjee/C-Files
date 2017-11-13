#include"LL.h"
 void main()
 {
     nptr h;
     int c;
     printf("\t\t\tWELCOME\n");
     h=create();
     while(42)
     {
         printf("\n0.Exit\n1.View Linked List\n2.Add Value\n3.Clear Screen\nEnter your choice::");
         scanf("%d",&c);
         switch(c)
         {
         case 0:
            exit(0);
         case 1:
            show(h);
            break;
         case 2:
            h=addnode(h);
            break;
         case 3:
            system("cls");
            printf("\t\t\tWELCOME\n");
            break;
         default :
            printf("\n\t\t!Please give a valid input!");
         }
     }
 }




