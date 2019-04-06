//---------------------------------------------------------------------------
//                               RAILWAY RESERVATION
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
//    HEADER FILES
//---------------------------------------------------------------------------
#include<fstream.h>
#include<string.h>
#include<iostream.h>
#include<stdio.h>
#include<dos.h>
#include<conio.h>
#include<stdlib.h>
#include<iomanip.h>
#include<process.h>

//using namespace std;
// if shows error for the above use:
 #define std::cout cout
 #define std::cin cin
//---------------------------------------------------------------------------
//FUNCTION PROTOTYPES
//---------------------------------------------------------------------------
void book1();
void modify();
void resdetail();
void add_train();
void search();
void ticket();
void box();
void railres();
void settings();
void train_sch();
void pnr_sta();
void avail();
void booking();
void cancel();
void deletee();
void trainlist();
void pnrlist();
//---------------------------------------------------------------------------
//  GLOBAL VARIBLES
//---------------------------------------------------------------------------
char trname[30];
int trno,vaca,abc=0;
int pnrr;
int seatt;
char coachh[4];
//---------------------------------------------------------------------------
//                      THIS CLASS DEALS WITH TRAIN SCHEDULE DETAILS
//---------------------------------------------------------------------------
class train
{
 char tname[20];
 int tno,day[10];
 char arr[10][10];
 char dept[10][10];
 char sched[10][20];
 int dist[10];
 public:
 void display();
 int Tno()
 {
  return tno;
 }
 char *gettname()
 {
  return tname;
 }
 void getfrom()
 {
  cout<<sched[0];
 }
 void input();
 int modify1();
 void getto()
 {
  cout<<sched[9];
 }
 int tkt(char x[20],char y[20]);
}s,g;
//---------------------------------------------------------------------------
//        THIS FUNCTION IS USED TO CREATE A NEW TRAIN AND ITS SCHEDULE
//---------------------------------------------------------------------------
void train::input()
{
 cout<<"ENTER TRAIN NAME :";
 gets(tname);
 cout<<"ENTER TRAIN NUMBER :";
 cin>>tno;
 cout<<"ARRIVAL =>\n";
 for(int i=0;i<10;i++)
 {
  cout<<i+1<<")";
  gets(arr[i]);
 }
 cout<<"DEPARTURE =>\n";
 for(int j=0;j<10;j++)
 {
  cout<<j+1<<")";
  gets(dept[j]);
 }
 cout<<"ENTER THE DAYS TAKEN =>\n";
 for(int b=0;b<10;b++)
 {
  cout<<b+1<<")";
  cin>>day[b];
 }
 cout<<"STATIONS =>\n";
 for(int k=0;k<10;k++)
 {
  cout<<k+1<<")";
  gets(sched[k]);
 }
 cout<<"DISTANCE =>\n";
 for(int p=0;p<10;p++)
 {
  cout<<p+1<<")";
  cin>>dist[p];
 }
}
//---------------------------------------------------------------------------
//       THIS FUNCTION DISPLAYS TRAIN SCHEDULE OF THE REQUIRED TRAIN
//---------------------------------------------------------------------------
void train::display()
{
 clrscr();
 box();
 int k=11;
 gotoxy(10,6);
 cout<<"TRAIN NAME:"<<tname;
 gotoxy(10,7);
 cout<<"TRAIN NUMBER:"<<tno<<endl;
 gotoxy(10,9);
 cout<<"ROUTE"<<setw(18)<<"ARRIVAL"<<setw(14)<<"DEPARTURE"<<setw(8)<<"DAY"<<setw(10)<<"DISTANCE";
 gotoxy(8,10);
 cout<<"*********************************************************";
 for(int i=0;i<10;i++)
 {
  gotoxy(10,k);
  cout<<sched[i];
  gotoxy(27,k);
  cout<<arr[i];
  gotoxy(40,k);
  cout<<dept[i];
  gotoxy(54,k);
  cout<<day[i];
  gotoxy(62,k);
  cout<<dist[i]<<endl;
  k++;
 }
}
//---------------------------------------------------------------------------
//        THIS FUNCTION MODIFIES THE DETAILS OF THE SPECIFIED TRAIN
//---------------------------------------------------------------------------
int train::modify1()
{
 clrscr();
 int i;
 cout<<"\n1.Train Number\n2.Train Name\n3.Stations\n4.Arrival Time\n";
 cout<<"5.Departure Time\n6.Days\n7.Distance\n8.Total seats \n";
 int a;
 cout<<"Enter your choice: ";
 cin>>a;
 switch(a)
 {
  case 1:
  {
   clrscr();
   cout<<"Enter train no: ";
   cin>>tno;
   return 1;

  }
  case 2:
  {
   clrscr();
   cout<<"Enter the train name: ";
   gets(tname);
   return 2;

   }
  case 3:
  {
   clrscr();
   cout<<"Enter the stations =>\n";
   for(i=0;i<10;i++)
   {
    cout<<i+1<<")";
    gets(sched[i]);
   }
   break;
   }

  case 4:
  {
   clrscr();
   cout<<"ENTER THE ARRIVAL TIME =>\n";
   for(i=0;i<10;i++)
   {
    cout<<i+1<<")";
    gets(arr[i]);
   }
   break;
   }

  case 5:
  {
   clrscr();
   cout<<"ENTER THE DEPARTURE TIME =>\n";
   for(i=0;i<10;i++)
   {
    cout<<i+1<<")";
    gets(dept[i]);
   }
   break;
   }

  case 6:

   clrscr();
   cout<<"Enter the day =>\n";
   for(i=0;i<10;i++)
   {
    cout<<i+1<<")";
    cin>>day[i];
   }
   break;


  case 7:

   clrscr();
   cout<<"Enter the distance =>\n";
   for(i=0;i<10;i++)
   {
    cout<<i+1<<")";
    cin>>dist[i];
   }
   break;


  case 8:

   clrscr();
   return 8;


  default:
  cout<<"Invalid choice: ";
  return 9;
 }
 return 0;
}
//---------------------------------------------------------------------------
// THIS FUNCTION RETURNS THE DISTANCE BETWEEN THE SOURCE AND THE DESTINATION
//---------------------------------------------------------------------------
int train::tkt(char x[20],char y[20])
{
 int a,n;
 for(int i=0;i<10;i++)
 {
  if(strcmpi(x,sched[i])==0)
  a=dist[i];
  if(strcmpi(y,sched[i])==0)
  n=dist[i];
 }
 int d=abs(a-n);
 return d;
}
//---------------------------------------------------------------------------
//       THIS CLASS DEALS WITH TRAIN SEATS DETAILS AND RESERVATION
//---------------------------------------------------------------------------
class train2
{
 int tno,total,vacant,reserved;
 char name[30];
 public:
 void input();
 void vacancy()
 {
  vacant=total-reserved;
 }
 int getres()
 {
  return reserved;
 }
 int getvac()
 {
  return vacant;
 }
 int gettno()
 {
  return tno;
 }
 void t(int tn)
 {
  tno=tn;
 }
 void tname(char n[30])
 {
  strcpy(name,n);
 }
 void modify2();
 void modify(int st);
}r,o;
//---------------------------------------------------------------------------
//          THIS FUNCTION IS TO CHANGE THE NUMBER OF SEATS AVAILABLE
//---------------------------------------------------------------------------
void train2::modify2()
{
 cout<<"TOTAL SEATS";
 cin>>total;
 vacancy();
}
//---------------------------------------------------------------------------
//           THIS FUNCTION IS USED TO STORE THE TRAIN SEATS DETAILS
//---------------------------------------------------------------------------
void train2::input()
{
 cout<<"Enter train no: ";
 cin>>tno;
 cout<<"Enter train name: ";
 gets(name);
 cout<<"Enter total number of seats: ";
 cin>>total;
 cout<<"Enter number of reserved seats: ";
 cin>>reserved;
 vacant=total-reserved;
 cout<< endl;
}
//---------------------------------------------------------------------------
//    THIS FUNCTION MODIFIES THE TRAIN SEATS DETAILS DURING NEW BOOKING
//---------------------------------------------------------------------------
void train2::modify(int st)
{
 reserved+=st;
 vacancy();
}
//---------------------------------------------------------------------------
//                THIS CLASS DEALS WITH PASSENGER DETAILS
//---------------------------------------------------------------------------
class book
{
 int pnr_no;
 long int train_no;
 char train_name[30];
 int seat_no;
 char name[40];
 int age;
 char gender;
 char coach[10];
 char from[20];
 char to[20];
 public:
 void input();
 void output();
 int gettno()
 {
  return train_no;
 }
 int getpnrno()
 {
  return pnr_no;
 }
 int getseat()
 {
  return seat_no;
 }
 char *getcoach()
 {
  return coach;
 }
 char *gettname()
 {
  return train_name;
 }
 void t(int tn)
 {
  train_no=tn;
 }
 void n(char nm[30])
 {
  strcpy(train_name,nm);
 }
 void s(int st)
 {
  seat_no=st;
 }
 void c(char co[4])
 {
  char ch[4];
  if(strcmpi(co,"B1")==0)
  strcpy(ch,"B1");
  else if(strcmpi(co,"S1")==0)
  strcpy(ch,"S1");
  else
  strcpy(ch,"S1");
  strcpy(coach,ch);
 }
 void p(int pn)
 {
  pnr_no=pn;
 }
 char *fm()
 {
  return from;
 }
 char *t()
 {
  return to;
 }
}b,m;
//---------------------------------------------------------------------------
//                 THIS FUNCTION IS USED TO BOOK A TICKET
//---------------------------------------------------------------------------
void book::input()
{
 cout<<"FROM :";
 gets(from);
 cout<<"\nTO :";
 gets(to);
 cout<<"\nNAME OF THE PASSENGER :";
 gets(name);
 cout<<"\nAGE :";
 cin>>age;
 cout<<"\nGENDER (M/F) :";
 cin>>gender;
}
//---------------------------------------------------------------------------
//          THIS CLASS DEALS WITH THE PNR STATUS OF PASSENGERS
//---------------------------------------------------------------------------
class pnr
{
 int pnr_no;
 long int train_no;
 char train_name[30];
 int seat_no;
 char name[40];
 int age;
 char gender;
 char coach[10];
 char from[20];
 char to[20];
 public:
 void pinput();
 void poutput();
 int getpnr()
 {
  return pnr_no;
 }
 int gettno()
 {
  return train_no;
 }
 char *gettname()
 {
  return train_name;
 }
 char *getname()
 {
  return name;
 }
}p;
//---------------------------------------------------------------------------
//         THIS FUNCTION DISPLAYS THE PNR STATUS ON ENQUIRY
//---------------------------------------------------------------------------
void pnr::poutput()
{
 int i;
 char ch=257;
 for(i=4;i<60;i++)
 {
  gotoxy(i,4);
  cout<<ch;
 }
 for(i=4;i<30;i++)
 {
  gotoxy(4,i);
  cout<<ch;
 }
 for(i=4;i<61;i++)
 {
  gotoxy(i,30);
  cout<<ch;
 }
 for(i=4;i<30;i++)
 {
  gotoxy(60,i);
  cout<<ch;
 }
 gotoxy(7,11);
 cout<<"PNR NO.:"<<pnr_no;
 gotoxy(30,11);
 cout<<"TRAIN NO.:"<<train_no;
 gotoxy(7,13);
 cout<<"TRAIN NAME :"<<train_name;
 gotoxy(7,15);
 cout<<"NAME :"<<name;
 gotoxy(7,17);
 cout<<"AGE :"<<age;
 gotoxy(30,17);
 cout<<"GENDER :"<<gender;
 gotoxy(7,19);
 cout<<"FROM :"<<from;
 gotoxy(30,19);
 cout<<"TO :"<<to;
 gotoxy(7,21);
 cout<<"SEAT NO :"<<seat_no;
 gotoxy(30,21);
 cout<<"COACH NO. :"<<coach<<endl;
}
//---------------------------------------------------------------------------
//               THIS FUNCTION CREATES A BOX FOR DISPLAY
//---------------------------------------------------------------------------
void box()
{
 clrscr();
 int i;
 for(i=4;i<70;i++)
 {
  gotoxy(i,4);
  cout<<"*";
 }
 for(i=4;i<25 ;i++)
 {
  gotoxy(4,i);
  cout<<"*";
 }
 for(i=4;i<70;i++)
 {
  gotoxy(i,65);
  cout<<"*";
 }
 for(i=4;i<25;i++)
 {
  gotoxy(70,i);
  cout<<"*";
 }
}
//---------------------------------------------------------------------------
//           THIS FUNCTION DISPLAYS THE MAIN MENU  OF THE PROGRAM
//---------------------------------------------------------------------------
void mainmenu()
{
 int ch;
 do
 {
  clrscr();
  box();
  gotoxy(28,8);
  cout<<"INDIAN RAILWAYS\n";
  gotoxy(4,12);
  cout<<"******************************************************************";
  gotoxy(16,15);
  cout<<"1.RAILWAY RESERVATION";
  gotoxy(16,17);
  cout<<"2.SETTINGS";
  gotoxy(54,6);
  cout<<"<0>-EXIT";
  gotoxy(14,19);
  cout<<"Enter your choice => ";
  cin>>ch;
  switch(ch)
  {
   case 1:
   railres();
   break;

   case 2:
   settings();
   break;

   case 0:
   exit(1);

   default:
   gotoxy(16,23);
   cout<<"#Invalid choice#";
   getch();
  }
 }while(ch!=0);
}
//---------------------------------------------------------------------------
//                  VOID MAIN CALLS THE MAINMENU FUNCTION
//---------------------------------------------------------------------------
void main()
{
 clrscr();
 mainmenu();
}
//---------------------------------------------------------------------------
//          THIS FUNCTION DISPLAYS THE RAILWAY RESERVATION MENU
//---------------------------------------------------------------------------
void railres()
{
 int ch;
 while(ch!=7)
 {
  clrscr();
  box();
  gotoxy(54,9);
  cout<<"<0>-EXIT";
  gotoxy(25,6);
  cout<<"RAILWAY RESERVATION";
  gotoxy(4,8);
  cout<<"****************************************************************";
  gotoxy(16,10);
  cout<<"1.TRAIN SCHEDULE";
  gotoxy(16,12);
  cout<<"2.AVAILABILITY";
  gotoxy(16,14);
  cout<<"3.BOOKING";
  gotoxy(16,16);
  cout<<"4.CANCELLATION";
  gotoxy(16,18);
  cout<<"5.PNR STATUS";
  gotoxy(16,20);
  cout<<"6.PREVIOUS MENU\n";
  gotoxy(16,22);
  cout<<"Enter your choice => ";
  cin>>ch;
  switch(ch)
  {
   case 0:
   box();
   gotoxy(15,15);
   cout<<"!!*THANK YOU FOR VISITING INDIAN RAILWAYS*!!";
   getch();
   exit(1);

   case 1:
   train_sch();
   getch();
   break;

   case 2:
   avail();
   getch();
   break;

   case 3:
   booking();
   getch();
   break;

   case 4:
   cancel();
   break;

   case 5:
   pnr_sta();
   break;

   case 6:
   mainmenu();
   break;

   default:
   cout<<"#Invalid Entry#";
  }
 }
}
//---------------------------------------------------------------------------
//  THIS FUNCTION IS USED TO ACCESS THE SETTINGS MENU (FOR PROGRAMMER ONLY)
//---------------------------------------------------------------------------
void settings()
{
 clrscr();
 char pass[20];
 box();
 char password[]={"passtrength"};
 gotoxy(15,10);
 cout<<"Enter the password :";
 gets(pass);
 if(strcmp(pass,password)==0)
 {
  char ans='y';
  int op;
  do
  {
   clrscr();
   box();
   gotoxy(25,6);
   cout<<"TRAIN SETTINGS MENU\n";
   gotoxy(16,7);
   cout<<"--------------------------------------\n";
   gotoxy(25,10);
   cout<<"1.MODIFY DETAILS\n";
   gotoxy(25,12);
   cout<<"2.ADD NEW TRAIN\n";
   gotoxy(25,14);
   cout<<"3.SEARCH FOR A TRAIN\n";
   gotoxy(25,16);
   cout<<"4.PREVIOUS MENU\n";
   gotoxy(60,6);
   cout<<"<0>EXIT";
   gotoxy(18,20);
   cout<<"ENTER YOUR CHOICE :";
   cin>>op;
   switch(op)
   {
    case 1:
    modify();
    break;

    case 2:
    add_train();
    resdetail();
    break;

    case 3:
    search();
    break;

    case 4:
    mainmenu();
    break;

    case 0:
    exit(1);
   }
  }while(ans=='y'||ans=='Y');
 }
 else
 {
  gotoxy(15,15);
  cout<<"###WRONG PASSWORD###";
  getch();
 }
}
//---------------------------------------------------------------------------
//      THIS FUNCTION IS USED TO CHANGE THE DETAILS OF THE TRAIN SPECIFIED
//---------------------------------------------------------------------------
void modify()
{
 int pos1,pos2,tn,c=1,p;
 fstream f1,f2;
 trainlist();
 gotoxy(10,23);
 cout<<"ENTER THE TRAIN NUMBER :";
 cin>>tn;
 f1.open("train2.dat",ios::in|ios::out|ios::binary);
 f2.open("train.dat",ios::in|ios::out|ios::binary);
 f2.read((char*)&s,sizeof(s));
 while(!f2.eof())
 {
  if(tn==s.Tno())
  {
   c=0;
   pos2=f2.tellg();
   break;
  }
  f2.read((char*)&s,sizeof(s));
 }
 f1.read((char*)&r,sizeof(r));
 while(!f1.eof())
 {
  if(tn==r.gettno())
  {
   pos1=f1.tellg();
   break;
  }
  f1.read((char*)&r,sizeof(r));
 }
 if(c==0)
 {
  p=s.modify1();
 }
 else if(c==1)
 {
  clrscr();
  gotoxy(15,15);
  cout<<"TRAIN NUMBER NOT RECOGNISED";
  getch();
 }
 if(p==1)
 {
  r.t(s.Tno());
 }
 else if(p==2)
 {
  r.tname(s.gettname());
 }
 else if(p==8)
 {
  r.modify2();
 }
 if(p==8)
 {
  f1.seekp(pos1-sizeof(r),ios::beg);
  f1.write((char*)&r,sizeof(r));
 }
 else if(p==1||p==2)
 {
  f2.seekp(pos2-sizeof(s),ios::beg);
  f2.write((char*)&s,sizeof(s));
  f1.seekp(pos1-sizeof(r),ios::beg);
  f1.write((char*)&r,sizeof(r));
 }
 else if(p==0)
 {
  f2.seekp(pos2-sizeof(s),ios::beg);
  f2.write((char*)&s,sizeof(s));
 }
 f1.close();
 f2.close();
}
//---------------------------------------------------------------------------
//                     THIS FUNCTION ADDS A NEW TRAIN
//---------------------------------------------------------------------------
void add_train()
{
 clrscr();
 fstream f1;
 cout<<"    TRAIN SCHEDULE DETAILS\n";
 cout<<"------------------------------------\n";
 f1.open("TRAIN.dat",ios::out|ios::binary|ios::app);
 g.input();
 f1.write((char*)&g,sizeof(g));
 f1.close();
}
//---------------------------------------------------------------------------
//         THIS FUNCION CALLS THE INPUT FUCNTION OF CLASS TRAIN2
//---------------------------------------------------------------------------
void resdetail()
{
 clrscr();
 fstream f4;
 cout<<"     TRAIN SEAT DETAILS\n";
 cout<<"------------------------------------\n";
 f4.open("train2.dat",ios::app|ios::out);
 o.input();
 f4.write((char*)&o,sizeof(o));
 f4.close();
}
//---------------------------------------------------------------------------
//      THIS FUNCTION DISPLAYS THE SCHEDULE OF THE ENQUIRED TRAIN
//---------------------------------------------------------------------------
void search()
{
 clrscr();
 fstream f2;
 int t,k=0;
 f2.open("TRAIN.dat",ios::in|ios::binary);
 trainlist();
 gotoxy(7,23);
 cout<<"Enter the train number you wish to see the details of: ";
 cin>>t;
 f2.read((char*)&s,sizeof(s));
 while(!f2.eof())
 {
  if(s.Tno()==t)
  {
   k=1;
   s.display();
   getch();
  }
  f2.read((char*)&s,sizeof(s));
 }
 if(k==0)
 {
  clrscr();
  gotoxy(15,15);
  cout<<"TRAIN NOT AVAILABLE";
  getch();
 }
 f2.close();
}
//---------------------------------------------------------------------------
//           THIS FUNCTION SHOWS THE LIST OF AVAILABLE TRAINS
//---------------------------------------------------------------------------
void trainlist()
{
 fstream g;
 char name[40];
 int n,i=11;
 box();
 gotoxy(6,7);
 cout<<"TRAIN NO"<<setw(15)<<"TRAIN NAME"<<setw(15)<<"FROM"<<setw(15)<<"TO";
 gotoxy(8,9);
 cout<<"**********************************************************";
 g.open("TRAIN.dat",ios::in|ios::binary);
 g.read((char*)&s,sizeof(s));
 while(!g.eof())
 {
  strcpy(name,s.gettname());
  n=s.Tno();
  gotoxy(6,i);
  cout<<n;
  gotoxy(17,i);
  cout<<name;
  gotoxy(36,i);
  s.getfrom();
  gotoxy(53,i);
  s.getto();
  i++;
  g.read((char*)&s,sizeof(s));
 }
 g.close();
}
//---------------------------------------------------------------------------
//       THIS FUNCTION SHOWS THE SCHEDULE DETAILS OF THE ENQUIRED TRAIN
//---------------------------------------------------------------------------
void train_sch()
{
 clrscr();
 int tn,flag=0;
 fstream g;
 trainlist();
 gotoxy(10,23);
 cout<<"ENTER THE TRAIN NUMBER TO SEE THE SCHEDULE =>";
 cin>>tn;
 trno=tn;
 g.open("TRAIN.dat",ios::in|ios::binary);
 g.read((char*)&s,sizeof(s));
 while(!g.eof())
 {
  if(tn==s.Tno())
  {
   flag=1;
   s.display();
  }
  g.read((char*)&s,sizeof(s));
 }
 if(flag==0)
 {
  clrscr();
  gotoxy(8,8);
  cout<<"###INVALID TRAIN NUMBER###";
  getch();
  train_sch();
 }
}
//---------------------------------------------------------------------------
//          THIS FUNCTION SHOWS THE AVAILABLITY OF DIFFERENT TRAINS
//---------------------------------------------------------------------------
void avail()
{
 fstream g;
 int tn;
 trainlist();
 gotoxy(10,23);
 cout<<"ENTER THE TRAIN NUMBER ";
 cin>>tn;
 trno=tn;
 g.open("train2.dat",ios::in|ios::binary);
 g.read((char*)&r,sizeof(r));
 while(!g.eof())
 {
  if(tn==r.gettno())
  {
   clrscr();
   box();
   abc=1;
   if(r.getvac()>0)
   {
    vaca=0;
    gotoxy(15,10);
    cout<<"SEATS ARE AVAILABLE";
    gotoxy(15,12);
    cout<<"SEATS VACANT ="<<r.getvac();
   }
   else
   {
    gotoxy(15,10);
    cout<<"SEATS NOT AVAILABLE";
    vaca=1;
   }
   break;
  }
  g.read((char*)&r,sizeof(r));
 }
 if(abc==0)
 {
  clrscr();
  gotoxy(15,15);
  cout<<"TRAIN NOT AVAILABLE";
 }
g.close();
}
//---------------------------------------------------------------------------
//                    THIS FUNCTION HELPS TO BOOK A TICKET
//---------------------------------------------------------------------------
void booking()
{
 fstream z,g;
 avail();
 char ch;
 gotoxy(15,15);
 if(vaca==1)
 {
  cout<<"BOOKING NOT POSSIBLE";
  getch();
 }
 else if(vaca==0&&abc==1)
 {
  cout<<"DO YOU WANT TO CONTINUE YOUR BOOKING ?";
  cin>>ch;
  if(ch=='y'||ch=='Y')
  {
   g.open("TRAIN.dat",ios::in|ios::binary);
   g.read((char*)&s,sizeof(s));
   while(!g.eof())
   {
    if(trno==s.Tno())
     s.display();
     g.read((char*)&s,sizeof(s));
   }
   g.close();
   z.open("train3.dat",ios::out|ios::app|ios::binary);
   if(ch=='y'||ch=='Y')
   {
    book1();
    cout<<"\n\n\n\n";
    m.input();
    z.write((char*)&m,sizeof(m));
    z.close();
    ticket();
   }
  }
  else
  {
   railres();
  }
 }
}
//---------------------------------------------------------------------------
//               THIS FUNCTION SHOWS THE TICKET AFTER BOOKING
//---------------------------------------------------------------------------
void ticket()
{
 fstream f1;
 int dist=s.tkt(m.fm(),m.t());
 int price=dist*1.4;
 f1.open("train3.dat",ios::in|ios::binary|ios::beg);
 f1.read((char*)&p,sizeof(p));
 while(!f1.eof())
 {
  if(p.getpnr()==pnrr)
  {
   clrscr();
   p.poutput();
   break;
  }
  f1.read((char*)&p,sizeof(p));
 }
 f1.close();
 gotoxy(27,6);
 cout<<"TICKET"<<endl;
 gotoxy(4,8);
 cout<<"--------------------------------------------------------";
 gotoxy(7,23);
 cout<<"DISTANCE :"<<dist;
 gotoxy(30,23);
 cout<<"PRICE : Rs."<<price;
}
//---------------------------------------------------------------------------
// THIS FUNCTION ASSIGNS VALUES TO TRAINNAME,PNR_NO,SEATNO,COACH,TRAINNO
//---------------------------------------------------------------------------
void book1()
{
 fstream x,q,u,w,z;
 int max1=0;
 int max2=0;
 char ch[4];
 q.open("train3.dat",ios::in|ios::binary);
 q.read((char*)&b,sizeof(b));
 while(!q.eof())
 {
  if(max1<b.getpnrno())
  {
   max1=b.getpnrno();
  }
  q.read((char*)&b,sizeof(b));
 }
 q.close();
 u.open("train3.dat",ios::in|ios::binary);
 u.read((char*)&b,sizeof(b));
 while(!u.eof())
 {
  if(trno==b.gettno())
  {
   max2++;
   strcpy(coachh,b.getcoach());
  }
  u.read((char*)&b,sizeof(b));
 }
 u.close();
 seatt=max2+1;
 int pos;
 pnrr=max1+1;
 m.t(trno);
 m.s(seatt);
 m.p(pnrr);
 m.c(coachh);
 x.open("train2.dat",ios::out|ios::in|ios::binary);
 x.read((char*)&r,sizeof(r));
 while(!x.eof())
 {
  pos=x.tellg();
  if(trno==r.gettno())
  {
   r.modify(1);
   break;
  }
  x.read((char*)&r,sizeof(r));
 }
 x.seekg(pos-sizeof(r));
 x.write((char*)&r,sizeof(r));
 x.close();
 z.open("train.dat",ios::in|ios::binary);
 z.read((char*)&s,sizeof(s));
 while(!z.eof())
 {
  if(trno==s.Tno())
  {
   strcpy(trname,s.gettname());
   break;
  }
  z.read((char*)&s,sizeof(s));
 }
 m.n(trname);
 z.close();
}
//---------------------------------------------------------------------------
//             THIS FUNCTION IS USED TO CANCEL A TICKET
//---------------------------------------------------------------------------
void cancel()
{
 fstream f1,f2,x;
 pnrlist();
 int pnrr1,flag=0,pos;
 long int tn;
 cout<<"\nENTER THE PNR NUMBER TO CANCEL :";
 cin>>pnrr1;
 clrscr();
 f1.open("train3.dat",ios::in|ios::binary);
 f2.open("temp.dat",ios::out|ios::binary);
 f1.read((char*)&p,sizeof(p));
 while(!f1.eof())
 {
  if(pnrr1!=p.getpnr())
  f2.write((char*)&p,sizeof(p));
  else if(pnrr1==p.getpnr())
  {
   flag=1;
   tn=p.gettno();
  }
  f1.read((char*)&p,sizeof(p));
 }
 f1.close();
 f2.close();
 remove("train3.dat");
 rename("temp.dat","train3.dat");
 gotoxy(15,15);
 if(flag==1)
 {
  cout<<"YOUR TICKET HAS BEEN CANCELLED SUCCESSFULLY";
  x.open("train2.dat",ios::out|ios::in|ios::binary);
  x.read((char*)&r,sizeof(r));
  while(!x.eof())
  {
   pos=x.tellg();
   if(tn==r.gettno())
   {
    r.modify(-1);
    break;
   }
   x.read((char*)&r,sizeof(r));
  }
 }
 else
 {
  cout<<"##TICKET CANCELLATION FAILED##";
 }
 x.seekg(pos-sizeof(r));
 x.write((char*)&r,sizeof(r));
 x.close();
 getch();
}
//---------------------------------------------------------------------------
//           THIS FUNCTION DISPLAYS THE PNR LIST OF THE ENQUIRED TRAIN
//---------------------------------------------------------------------------
void pnrlist()
{
 fstream g;
 int pn,k=7,tn,flag=0;
 char name[40];
 trainlist();
 gotoxy(7,23);
 cout<<"ENTER THE TRAIN NUMBER :";
 cin>>tn;
 clrscr();
 g.open("train3.dat",ios::in|ios::binary);
 g.read((char*)&p,sizeof(p));
 while(!g.eof())
 {
  if(tn==p.gettno())
  {
   flag=1;
   gotoxy(5,5);
   cout<<"PNR NO"<<setw(40)<<"NAME";
   gotoxy(4,6);
   cout<<"*********************************************************";
   pn=p.getpnr();
   strcpy(name,p.getname());
   gotoxy(5,k);
   cout<<pn;
   gotoxy(43,k);
   cout<<name;
   k++;
  }
  g.read((char*)&p,sizeof(p));
 }
 if(flag==0)
 {
  gotoxy(8,8);
  cout<<"###PNR LIST NOT AVAILABLE###";
  getch();
  pnrlist();
 }
 g.close();
}
//---------------------------------------------------------------------------
//      THIS FUNCTION DISPLAYS THE PNR STATUS OF THE ENTERED PNR NUMBER
//---------------------------------------------------------------------------
void pnr_sta()
{
 clrscr();
 fstream f1;
 int pn,flag=0;
 pnrlist();
 cout<<"\nEnter the pnr no. to search for";
 cin>>pn;
 clrscr();
 f1.open("train3.dat",ios::in|ios::binary);
 f1.read((char*)&p,sizeof(p));
 while(!f1.eof())
 {
  if(p.getpnr()==pn)
  {
   gotoxy(27,6);
   cout<<"PNR STATUS"<<endl;
   gotoxy(4,8);
   cout<<"--------------------------------------------------------";
   flag=1;
   p.poutput();
   getch();
   break;
  }
  f1.read((char*)&p,sizeof(p));
 }
 f1.close();
 if(flag==0)
 {
  gotoxy(15,15);
  cout<<"##INFO NOT AVAILABLE##";
  getch();
 }
 f1.close();
}
