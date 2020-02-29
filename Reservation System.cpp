#include<iostream>
#include<conio.h>
using namespace std ;
class Bus
{
    int number; //train number
    int seats_1;//total seats in first class
    int seats_2;// total seats in second class

public:
    Bus(int i,int j, int k)
    {
        number = i;
        seats_1 = j;
        seats_2 =k ;
    }

    int getnum(void)
    { return number;}
    int getseats_1(void)
    { return seats_1;}
    int getseats_2(void)
    { return seats_2;}
    };

class Reservation :public Bus
    { int bkd_1;// seats reserved in 1st class
    int bkd_2;//seats reserved in 2nd class
// seats reserved in 3rd class

public:
    int i,j,k;
    Reservation (int i,int j,int k):Bus(i,j,k)
    { bkd_1=bkd_2=0;}
    void book(char type,int num);
    void cancel(char type,int num);
    void disp_status(void);
};

void Reservation::book(char type,int num)
    { switch(type)
    { case'1': bkd_1+=num; //add num to bkd_1
    break;

    case'2': bkd_2+=num;//add num to bkd_2
    break;
    default: cout<<"wrong class\n";
}
}


void Reservation :: cancel(char type, int num)
    { switch(type)
    { case'1':bkd_1-=num;
    break;

    case'2':bkd_2-=num;
    break;
    default:cout<<"wrong class\n";
}
}

void Reservation::disp_status(void)
    { cout<<"\t\t Bus number:"<<getnum()<<"\n";
    cout<<" Class\tSeats\tReserved   Un Reserved\n";
    int val;
    val=getseats_1();
    cout<<"  1\t  "<<val<<"\t   "<<  bkd_1<<"\t     "<<val-bkd_1<<"\n";
    val=getseats_2();
    cout<<"  2\t  "<<val<<"\t   "<<  bkd_2<<"\t     "<<val-bkd_2<<"\n";

}

int  main()
{ //clrscr();
    int num;
    cout<<"\n For Admin's Input\n";
    cout<<"--------------------------------------------------\n";
    cout<<" Enter Bus Number : ";
    cin>>num;
    cout<<"\n Enter total Number Of seats in 1st class : ";
    int s1;
    cin>>s1;
    cout<<"\n Enter total number of seats in 2nd class : ";
    int s2;
    cin>>s2;
    cout<<"--------------------------------------------------\n\n";

    Reservation Bs(num,s1,s2);
    char cl_type;
    int choice,seats;
    do
    {
    cout<<"___________________________________________________\n";
    cout<<"|                                                  |";
    cout<<"\n|   Main Menu of BAIUST Bus Management System      |\n|\t\t\t\t\t\t   |\n";
    cout<<"|\t1.Reservation\t\t\t\t   |\n";
    cout<<"|\t2.Cancellation\t\t\t\t   |\n";
    cout<<"|\t3.Display Status\t\t\t   |\n";
    cout<<"|\t4.Exit\t\t\t\t\t   |\n";
    cout<<"|__________________________________________________|";
    cout<<"\n\n Enter your choice : ";
    cin>>choice;
    cout<<"\n";

    switch(choice)
    { case 1: cout<<" which class?(1/2):";
    cin>>cl_type;
    cout<<"\n How many seats : ";
    cin>>seats;
    cout<<"\n";

Bs.book(cl_type,seats);
    break;

    case 2:cout<<"Which class?(1/2):";
    cin>>cl_type;
    cout<<"\n How many seats?";
    cin>>seats;
    cout<<"\n";
Bs.cancel(cl_type,seats);
    break;

    case 3:Bs.disp_status();
    break;

    case 4:break;
    default : cout<<"Wrong choice!!\n";
}; //end of switch
}
    while(choice>=1&&choice<=3);
    getch();
    return 0;
}
