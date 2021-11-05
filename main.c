#include <stdio.h>
#include <stdlib.h>
#include "rlyres.h"
#include"conio2.h"

int main()
{
    int choice, ticket_no, check,result;
    char* pmob_no, *train_no,*ptrain_no;
    int* pticket_no;
    Passenger* ptr;
    add_trains();
    while(1)
    {
        choice=enterchoice();
        if(choice==9)
        exit(0);
        switch(choice)
        {
        case 1:
            view_trains();
            getch();
            clrscr();
            break;
        case 2:
            ptr=get_passenger_details();
            clrscr();
            if(ptr!=NULL)
            {
            ticket_no=book_ticket(*ptr);
            if(ticket_no==-1)
            {
            textcolor(LIGHTRED);
            printf("Booking Failed!");
            }
            else
            {
            textcolor(LIGHTGREEN);
            printf("Ticket Successfully Booked\nYour ticket no is %d",ticket_no);
            }
            textcolor(WHITE);
            printf("\nPress any key to go back to the main screen");
            getch();
            clrscr();
            }
            break;
        case 3:
            clrscr();
            ticket_no=accept_ticket_no();
            if(ticket_no!=0)
            view_ticket(ticket_no);
            textcolor(WHITE);
            printf("\nPress any key to go back to the main screen");
            getch();
            clrscr();
            break;
       case 4:
            clrscr();
            pmob_no=accept_mob_no();
            if(pmob_no!=NULL)
            {
            pticket_no=get_ticket_no(pmob_no);
            view_all_tickets(pmob_no,pticket_no);
            }
            clrscr();
            break;

         case 5:
            view_all_bookings();
            textcolor(WHITE);
            printf("\n\nPress any key to go back to main screen!");
            getch();
            clrscr();
            break;
        case 6:
            clrscr();
            ptrain_no=accept_train_no();
            if(ptrain_no!=NULL)
            view_booking(ptrain_no);
            clrscr();
            break;
        case 7:
            clrscr();
            ticket_no=accept_ticket_no();
            if(ticket_no!=0)
            {
            check=cancel_ticket(ticket_no);
            if(check==1)
            {
            textcolor(LIGHTGREEN);
            printf("Ticket no %d successfully cancelled",ticket_no);
            }
            else if(check==0)
            {
            textcolor(RED);
            printf("Sorry! No tickets booked against the ticket number %d",ticket_no);
            }
            else if(check == 2)
            {
            textcolor(RED);
            printf("Sorry! Error in cancellation. Try again!");
            }
            textcolor(WHITE);
            printf("\n\nPress any key to go back to main screen!");
            }
            getch();
            clrscr();
            break;
        case 8:
            clrscr();
            train_no=accept_train_no();
            if(train_no!=NULL)
            {
            check=cancel_train(train_no);
            if(check==1)
            {
            textcolor(LIGHTGREEN);
            printf("Train no %s successfully cancelled",train_no);
            }
            else if(check==0)
            {
            textcolor(RED);
            printf("Sorry! No train number %s in our system",train_no);
            }
            else if(check == 2)
            {
            textcolor(RED);
            printf("Sorry! Error in cancellation. Try again!");
            }
            textcolor(WHITE);
            printf("\n\nPress any key to go back to main screen!");
            }
            getch();
            clrscr();
            break;

        default:
            textcolor(LIGHTRED);
            printf("Wrong Choice! Try Again\n");
            getch();
            clrscr();
        }
    }
    return 0;
}
