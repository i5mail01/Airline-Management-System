#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<string.h>
#include<stdio.h>
#include<iomanip.h>
#include<process.h>
#include<fstream.h>
void menu();
void aaa();
void prevbankbalance();
void displaypass();
void displaysrpsngr();
void displaypassenger();
void addflight();
void addpass();
void bookflight();
void cancelbooking();
void loginfunction();
void login();
void registr();
void deluser();
void delpass();
void delflight();
void displayflights();
void disavflights();
void dismaxpass();
void dispricefl();
void xxx();
class passenger
{private:
  char passport[10];
  char name[20];
  char pava;
  char bankact[10];
  float bankbal;
  int noflightbk;
 public:
  char* getpassport()
  {return(passport);
  }
  char* getname()
  {return(name);
  }
  char pav(int i=10 , char z='a')
  {if(i==10 && z=='a')
     return(pava);
   if(i==0 && z=='a')
     pava='n';
   if(i==1 && z=='a')
     pava='y';
  }
  char* getbank()
  {return(bankact);
  }
  float bankbalance(float amt=0, char z='a')
  {if(z=='d')
     bankbal+=amt;
   if(z=='w')
     bankbal-=amt;
   if(z=='a' && amt==0)
     return(bankbal);
  }
  int noflightsbooked(int i=0 , char z='a')
  {if(i==0 && z=='b')
     noflightbk--;
   if(i==1 && z=='b')
     noflightbk++;
   if(i==0 && z=='a')
     return(noflightbk);
  }
  passenger()
  {noflightbk=0;
   pava='n';
  }
  void getdata()
  {textcolor(YELLOW);
   cprintf("Enter the name of the passenger :");
   gets(name);
   cout<<endl;
   textcolor(BLUE);
   cprintf("Enter the passport number :");
   gets(passport);
   cout<<endl;
   textcolor(GREEN);
   cprintf("Enter the bank account no :");
   gets(bankact);
   cout<<endl;
   textcolor(RED);
   cprintf("Enter the opening balance of not less than 5000 :");
   cin>>bankbal;
  }
}pa[10];
class flight
{private:
  char flno[10];
  char airline[25];
  char from[15];
  char to[15];
  float price;
  int nopass;
 public:
  char* getflight()
  {return(flno);
  }
  char* getairline()
  {return(airline);
  }
  char* getfrom()
  {return(from);
  }
  char* getto()
  {return(to);
  }
  float getprice()
  {return(price);
  }
  int getpass(int i=0 , char z='a')
  {if(i==0 && z=='a')
     return(nopass);
   if(i==1 && z=='b')
     nopass++;
   if(i==0 && z=='b')
     nopass--;
  }
  void getdata()
  {textcolor(YELLOW);
   cprintf("Enter the name of the airline :");
   gets(airline);
   cout<<endl;
   textcolor(BLUE);
   cprintf("Enter the flight number :");
   gets(flno);
   cout<<endl;
   textcolor(GREEN);
   cprintf("Enter the departing location :");
   gets(from);
   cout<<endl;
   cprintf("Enter the arriving location :");
   gets(to);
   cout<<endl;
   textcolor(RED);
   cprintf("Enter the ticket fare :");
   cin>>price;
  }
}fl[10];
class transaction
{private:
  char flightno[10];
  char airlinename[20];
  char tfrom[20];
  char tto[20];
  char tpassename[20];
  float tprice;
 public:
  char* flightget()
  {return(flightno);
  }
  char* airlineget()
  {return(airlinename);
  }
  char* fromget()
  {return(tfrom);
  }
  char* toget()
  {return(tto);
  }
  char* nameget()
  {return(tpassename);
  }
  float priceget(float amt=0 , char z='a')
  {if(z=='a'&& amt==0)
    return(tprice);
   else if(z=='b')
    tprice=amt;
  }
}tt[10];
int x=0,flightsize=0,pasize=0,users=0;
char passwords[10][10];
char usernames[10][10];
void design()
{clrscr();
 int gdriver=DETECT,gmode;
 initgraph(&gdriver,&gmode,"c:/turboc3/bgi");
 for(int i=-81 ; i<620 ; i++)
    {setcolor(i+51);
     line(51+i,200,299+i,200);
     line(51+i,250,299+i,250);
     arc(299+i,225,270,90,25);
     line(51+i,200,51+i,250);
     line(51+i,200,1+i,225);
     line(51+i,250,1+i,225);
     //left wing//
     line(201+i,200,181+i,30);
     line(196+i,40,241+i,200);
     line(196+i,40,181+i,30);
     //right wing//
     line(201+i,250,181+i,420);
     line(241+i,250,201+i,410);
     line(201+i,410,181+i,420);
     //back right wing//
     line(56+i,200,51+i,150);
     line(66+i,200,51+i,150);
     //back left wing//
     line(56+i,250,51+i,300);
     line(66+i,250,51+i,300);
     line(1+i,450,600+i,450);
     delay(20);
     cleardevice();
    }
 closegraph();
}
void ackn()
{int repeat;
 do
 {clrscr();
  cout<<endl;
  cout<<setw(50)<<"ACKNOWLEDGEMENT"<<endl;
  cout<<"--------------------------------------------------------------------------------"<<endl;
  textcolor(RED);
  cprintf(" Working on this project during my holidays , has given me a deeper insight of  the fundamentals of computer science and ways of coding");
  cout<<endl;
  textcolor(GREEN);
  cprintf(" I would also like to thank the coordinated efforts and endless support offered by friends.");
  cout<<endl;
  textcolor(BLUE);
  cprintf(" Last but not the least, I would also like to express my sincere gratitude to   the Almight ALLAH for making me accomplish this project with minimal difficultie-s to overcome apart from the support of my teacher");
  cout<<endl;
  cout<<"To proceed hit 0 :";
  cin>>repeat;
 }while(repeat!=0);
}
void intro()
{clrscr();
 int repeat;
 do
 {cout<<setw(57)<<"Welcome to Etihad Airways portal";
  cout<<endl;
  cout<<"------------------------------------------------------------------------------"<<endl;
  textcolor(3);
  cprintf("Etihad Airways,the national carrier of United Arab Emirates was inaugrated in the year 2003 with a flight to Al Ain");
  cout<<endl;
  textcolor(4);
  cprintf("In less than a decade the airline and its board witnessed impressive turnover,catering daily services to customers to over 120 countries");
  cout<<endl;
  textcolor(5);
  cprintf("Flying with Etihad Airways is truly an exhilarating and with a wide plethora of on board services exclusively available for Bussiness and First class pasenenger will make the trip memorable");
  cout<<endl;
  textcolor(6);
  cprintf("This portal is restricted to the use of only  Etihad Airways employees and all its content is the property of the government of Abu Dhabi");
  cout<<endl;
  textcolor(7);
  cprintf("Any report of misuse of the portal and manipulation of its contents without prior permission shall be dealt in accordance with UAE penal code");
  cout<<endl;
  textcolor(8);
  cprintf("Disclaimer:Please note that this protal has nothing to do with the real Etihad Airways as this is a project cr8ted by Ismail of 11A :):);)");
  cout<<endl;
  cout<<"To proceed enter 0 :";
  cin>>repeat;
 }while(repeat!=0);
}
void head()
{cout<<"-------------------------------------------------------------------------------"<<endl;
 cout<<setw(45)<<"ETIHAD AIRWAYS"<<endl;
 cout<<"-------------------------------------------------------------------------------"<<endl;
 cout<<setw(60)<<"NATIONAL CARRIER OF UNITED ARAB EMIRATES"<<endl;
 cout<<"-------------------------------------------------------------------------------"<<endl;
}
void main()
{clrscr();
 int op,ab,pin;
 design();
 ackn();
 intro();
 cout<<endl;
 cout<<"To proceed to the access point hit 0\t:";
 cin>>ab;
 if(ab==0)
   {do
    {clrscr();
     head();
     loginfunction();
     cout<<"\n Do u wish to retry logging in, if yes hit 1 else 0\t:";
     cin>>op;
    }while(op==1);
    exit(0);
   }
 getch();
}
void menu()
{int ch;
 do
 {clrscr();
  head();
  textcolor(YELLOW);
  cprintf("Choose any of the action that is listed below :");
  cout<<endl;
  cout<<"*-----------------------------------------------------------------------------*"<<endl;
  cout<<setw(46)<<"* MAIN MENU *"<<endl;
  cout<<"*-----------------------------------------------------------------------------*"<<endl;
  cout<<setw(20)<<"ADMIN"<<setw(20)<<"|"<<setw(25)<<"TRANSACTION"<<endl;
  cout<<"*--------------------------------------*--------------------------------------*"<<endl;
  cout<<setw(10)<<"* 1.Add Flight"<<setw(26)<<"|"<<setw(19)<<"5.Book A Flight"<<endl;
  cout<<setw(10)<<"* 2.Add Passenger"<<setw(23)<<"|"<<setw(29)<<"6.Cancel A Flight Booking"<<endl;
  cout<<setw(10)<<"* 3.Delete A Flight"<<setw(21)<<"|"<<setw(26)<<"7.Preview Bank Balance"<<endl;
  cout<<setw(10)<<"* 4.Delete A Passenger"<<setw(18)<<"|"<<endl;
  cout<<"*-----------------------------------------------------------------------------*"<<endl;
  cout<<setw(10)<<"* 8.Issues Related To Logging In"<<endl;
  cout<<setw(10)<<"* 9.Services Related To Passenger"<<endl;
  cout<<setw(10)<<"* 10.Serices Related To Flight"<<endl;
  cout<<setw(10)<<"* 11.Log Out"<<endl;
  cout<<setw(5)<<"* 12.Exit"<<endl;
  cout<<"*-----------------------------------------------------------------------------*"<<endl;
  cout<<" Enter any of the above mentioned options\t:";
  cin>>ch;
  switch(ch)
  {case 1 :addflight();
	   break;
   case 2 :addpass();
	   break;
   case 3 :delflight();
	   break;
   case 4 :delpass();
	   break;
   case 5 :bookflight();
	   break;
   case 6 :cancelbooking();
	   break;
   case 7 :prevbankbalance();
	   break;
   case 8 :loginfunction();
	   break;
   case 9 :displaypass();
	   break;
   case 10:displayflights();
	   break;
   case 11:main();
	   break;
   case 12:exit(0);
	   break;
   default :cout<<"\n Kindly enter valid options";
  }
 }while(ch<=12);
}
void loginfunction()
{int f;
 do
 {clrscr();
  head();
  f=0;
  cout<<"\n To proceed to user signin interface hit-0";
  cout<<"\n Dont have an acct dont worry signup for a new one, hit-1";
  cout<<"\n Want to delete a user hit-2";
  cout<<"\n To make your exit hit-3";
  cout<<"\n Pls select any of the above option\t:";
  cin>>f;
  if(f==0)
    login();
  else if(f==1)
    registr();
  else if(f==2)
    deluser();
  else if(f==3)
    exit(0);
 }while(f<=3);
}
void login()
{int confirm=0;
 char password[10],username[10],c;
 for(int i=0 ; i<3 ; i++)
    {clrscr();
     head();
     c='a';
     cout<<"Your number of chances before u r thrown out is "<<3-i;
     cout<<"\n Enter the username\t:";
     gets(username);
     for(int j=0 ; j<users ; j++)
	{if(strcmpi(usernames[j],username)==0)
	   {cout<<"\n Enter your password\t:";
	    for(int k=0 ; c!=13 ; k++)
	       {c=getch();
		if(c!=13)
		  {password[k]=c;
		   textcolor(i+1);
		   cprintf("*");
		  }
		else if(c==13)
		  {password[k]=NULL;
		   break;
		  }
	       }
	    for(int l=0 ; l<users ; l++)
	       if((strcmpi(passwords[l],password)==0) && (l==j))
		 {menu();
		  confirm=1;
		  break;
		 }
	   }
	}
     if(confirm==0)
       cout<<"\n Sorry login failed";
    }
 if(confirm==0)
   {cout<<"\n Unsuccesful attempt";
    getch();
   }
 exit(0);
}
void registr()
{int repeat=0;
 char username[10],password[10],ch,passw[20];
 do
 {clrscr();
  head();
  int confirm=1;
  ch='a';
  cout<<"\n Enter the desired username\t:";
  gets(username);
  cout<<"\n Enter the desired password\t:";
  for(int i=0 ; ch!=13 ; i++)
     {ch=getch();
      if(ch!=13)
	{password[i]=ch;
	 textcolor(i+1);
	 cprintf("*");
	}
      else if(ch==13)
	{password[i]=NULL;
	 break;
	}
     }
  cout<<endl;
  for(int l=0 ;    ; l++)
     {ch='a';
      cout<<"\n Pls reenter ur password to confirm\t:";
      for(int j=0 ; ch!=13 ; j++)
	 {ch=getch();
	  if(ch!=13)
	    {passw[j]=ch;
	     textcolor(j+1);
	     cprintf("*");
	    }
	  else if(ch==13)
	    {passw[j]=NULL;
	     break;
	    }
	 }
      if(strcmpi(passw,password)==0)
	{confirm=1;
	 break;
	}
     }
  if(confirm==1)
    {if(users<5)
       {strcpy(usernames[users],username);
	strcpy(passwords[users],password);
	users+=1;
	cout<<"\n Username and pasword successfully cr8ted";
	cout<<"\n"<<users;
       }
     else if(users>=5)
       {cout<<"\n Registration full";
	cout<<"\n No more users possible";
       }
    }
  else if(confirm==0)
    cout<<"\n Unsuccessful in cr8tion of user";
  cout<<"\n Would u like to register one more, if yes hit 1 else 0\t:";
  cin>>repeat;
 }while(repeat==1);
}
void deluser()
{int repeat=0,found;
 char us[20],pss[20],c;
 do
 {clrscr();
  head();
  c='a';
  found=0;
  cout<<"\n Enter the username of the user to be deleted\t:";
  gets(us);
  cout<<"\n Enter the password of the user to be deleted\t:";
  for(int i=0 ; c!=13 ; i++)
     {c=getch();
      if(c!=13)
	{pss[i]=c;
	 textcolor(i+1);
	 cprintf("*");
	}
      else if(c==13)
	{pss[i]=NULL;
	 break;
	}
     }
  for(int j=0 ; j<users ; j++)
     {if((strcmpi(usernames[j],us)==0)&&(strcmpi(passwords[j],pss)==0))
	{for(int k=j ; k<users ; k++)
	    {strcpy(usernames[k],usernames[k+1]);
	     strcpy(passwords[k],passwords[k+1]);
	     found=1;
	    }
	 users--;
	 break;
	}
     }
  if(found==1)
    cout<<"\n Deleted successfully";
  else if(found==0)
    {cout<<"\n Deletion unsuxccessful";
     cout<<"\n PERHAPS NO SUCH USER";
    }
  cout<<"\nTo delete some more users hit 1\t:";
  cin>>repeat;
 }while(repeat==1);
}
void addflight()
{int z,repeat=0;
 flight ff;
 do
 {clrscr();
  head();
  textcolor(8);
  cprintf("Enter the no of flights you would like to add :");
  cin>>z;
  cout<<endl;
  if(flightsize==0)
    {fstream fin("FLIGHTDETAILS.dat", ios::out);
     for(int i=0 ; i<z ; i++)
	{ff.getdata();
	 fin.write((char*)&ff , sizeof(ff));
	}
     flightsize=z;
     cout<<"\n ADDED SUCCESSFULLY";
     fin.close();
    }
  else if(flightsize>0)
    {fstream fin("FLIGHTDETAILS.dat" , ios::app);
     for(int j=flightsize ; j<(flightsize+z) ; j++)
	{ff.getdata();
	 fin.write((char*)&ff , sizeof(ff));
	}
     flightsize+=z;
     cout<<"\n Added successfully";
     fin.close();
    }
  cout<<"\n To add more flights hit 1 else 0\t:";
  cin>>repeat;
 }while(repeat==1);
}
void addpass()
{int repeat=0,z;
 passenger pp;
 do
 {clrscr();
  head();
  textcolor(8);
  cprintf("Enter the number of passenger youn would like to add :");
  cin>>z;
  if(pasize==0)
    {fstream fin("PASSENGERDETAILS.dat", ios::out);
     for(int i=0 ; i<z ; i++)
	{pp.getdata();
	 fin.write((char*)&pp, sizeof(pp));
	}
     pasize=z;
     fin.close();
     cout<<"\n Successfully added";
    }
  else if(pasize>0)
    {fstream fin("PASSENGERDETAILS.dat", ios::app);
     for(int i=pasize ; i<(pasize+z) ; i++)
	{pp.getdata();
	 fin.write((char*)&pp, sizeof(pp));
	}
     pasize+=z;
     fin.close();
     cout<<"\n Successfully added";
    }
  cout<<"\n To add more passengers hit 1 else 0\t:";
  cin>>repeat;
 }while(repeat==1);
}
void bookflight()
{int found,repeat=0,i;
 char nm[20],zn[20];
 do
 {clrscr();
  head();
  found=0;
  if((flightsize>0)&&(pasize>0)&&(x==0))
    {fstream tb("TRAN.dat" , ios::out);
     fstream fb("FLIGHTDETAILS.dat" , ios::in);
     fstream pb("PASSENGERDETAILS.dat" , ios::in);
     for(i=0 ; i<flightsize ; i++)
	fb.read((char*)&fl[i] , sizeof(fl[i]));
     for(i=0 ; i<pasize ; i++)
	pb.read((char*)&pa[i] , sizeof(pa[i]));
     pb.close();
     fb.close();
     cout<<"\n The list of available flights :"<<endl;
     cout<<"------------------------------------------------------------------------------"<<endl;
     cout<<"FLIGHT NO"<<setw(20)<<"AIRLINE"<<setw(18)<<"FROM"<<setw(16)<<"To"<<setw(16)<<"PRICE"<<endl;
     cout<<"------------------------------------------------------------------------------"<<endl;
     for(i=0 ; i<flightsize ; i++)
	 cout<<fl[i].getflight()<<setw(25)<<fl[i].getairline()<<setw(20)<<fl[i].getfrom()<<setw(15)<<fl[i].getto()<<setw(13)<<fl[i].getprice()<<endl;
     cout<<"\n Enter the flight number you would like to travel in\t:";
     gets(zn);
     cout<<"\n Enter the name of the passenger\t:";
     gets(nm);
     for(i=0 ; i<flightsize ; i++)
	{if(strcmpi(fl[i].getflight(),zn)==0)
	   {for(int j=0 ; j<pasize ; j++)
	       {if(strcmpi(pa[j].getname(),nm)==0)
		  {if(pa[j].bankbalance()-fl[i].getprice()<0)
		     {cout<<"\n Booking impossible due to insufficient bank balance";
		      found=0;
		      break;
		     }
		   found=1;
		   strcpy(tt[x].nameget(),pa[j].getname());
		   strcpy(tt[x].flightget(),fl[i].getflight());
		   strcpy(tt[x].airlineget(),fl[i].getairline());
		   strcpy(tt[x].fromget(),fl[i].getfrom());
		   strcpy(tt[x].toget(),fl[i].getto());
		   fl[i].getpass(1,'b');
		   int amt=fl[i].getprice();
		   pa[j].bankbalance(amt,'w');
		   pa[j].pav(1,'a');
		   pa[j].noflightsbooked(1,'b');
		   float f=fl[i].getprice();
		   tt[x].priceget(f,'b');
		   tb.write((char*)&tt[x] , sizeof(tt[x]));
		   tb.close();
		   x++;
		   cout<<"\n The prevailing balance of the customer "<<nm<<" is "<<pa[j].bankbalance()<<endl;
		   break;
		  }
	       }
	   }
	}
     if(found==1)
     {cout<<"\n Succesfully Booked";
      fstream fm("FLIGHTDETAILS.dat" , ios::out);
      fstream pm("PASSENGERDETAILS.dat" , ios::out);
      for(i=0 ; i<flightsize ; i++)
	 fm.write((char*)&fl[i] , sizeof(fl[i]));
      for(i=0 ; i<pasize ; i++)
	 pm.write((char*)&pa[i] , sizeof(pa[i]));
      fm.close();
      pm.close();
     }
     else if(found==0)
     {cout<<"\n UNSUCCESSFUL IN BOOKING";
      tb.close();
     }
    }
  else if((flightsize>0)&&(pasize>0)&&(x>0))
    {fstream tg("TRAN.dat" , ios::in);
     fstream fg("FLIGHTDETAILS.dat" , ios::in);
     fstream pg("PASSENGERDETAILS.dat" , ios::in);
     for(i=0 ; i<x ; i++)
	tg.read((char*)&tt[i] , sizeof(tt[i]));
     for(i=0 ; i<flightsize ; i++)
	fg.read((char*)&fl[i] , sizeof(fl[i]));
     for(i=0 ; i<pasize ; i++)
	pg.read((char*)&pa[i] , sizeof(pa[i]));
     pg.close();
     fg.close();
     tg.close();
     cout<<"\n The list of available flights :"<<endl;
     cout<<"------------------------------------------------------------------------------"<<endl;
     cout<<"FLIGHT NO"<<setw(20)<<"AIRLINE"<<setw(18)<<"FROM"<<setw(16)<<"To"<<setw(16)<<"PRICE"<<endl;
     cout<<"------------------------------------------------------------------------------"<<endl;
     for(i=0 ; i<flightsize ; i++)
	 cout<<fl[i].getflight()<<setw(25)<<fl[i].getairline()<<setw(20)<<fl[i].getfrom()<<setw(15)<<fl[i].getto()<<setw(13)<<fl[i].getprice()<<endl;
     cout<<"\n Enter the flight number you would like to travel in\t:";
     gets(zn);
     cout<<"\n Enter the name of the passenger\t:";
     gets(nm);
     for(i=0 ; i<flightsize ; i++)
	{if(strcmpi(fl[i].getflight(),zn)==0)
	   {for(int j=0 ; j<pasize ; j++)
	       {if(strcmpi(pa[j].getname(),nm)==0)
		  {if(pa[j].bankbalance()-fl[i].getprice()<0)
		     {cout<<"\n Booking impossible due to insufficient bank balance";
		      found=0;
		      break;
		     }
		   found=1;
		   strcpy(tt[x].nameget(),pa[j].getname());
		   strcpy(tt[x].flightget(),fl[i].getflight());
		   strcpy(tt[x].airlineget(),fl[i].getairline());
		   strcpy(tt[x].fromget(),fl[i].getfrom());
		   strcpy(tt[x].toget(),fl[i].getto());
		   fl[i].getpass(1,'b');
		   int amt=fl[i].getprice();
		   pa[j].bankbalance(amt,'w');
		   pa[j].pav(1,'a');
		   pa[j].noflightsbooked(1,'b');
		   float f=fl[i].getprice();
		   tt[x].priceget(f,'b');
		   x++;
		   fstream tm("TRAN.dat" , ios::out);
		   for(int b=0 ; b<x ; b++)
		      tm.write((char*)&tt[b] , sizeof(tt[b]));
		   tm.close();
		   cout<<"\n The prevailing balance of the customer "<<nm<<" is "<<pa[j].bankbalance()<<endl;
		   break;
		  }
	       }
	   }
	}
     if(found==1)
      {fstream fm("FLIGHTDETAILS.dat" , ios::out);
       fstream pm("PASSENGERDETAILS.dat" , ios::out);
       for(i=0 ; i<flightsize ; i++)
	  fm.write((char*)&fl[i] , sizeof(fl[i]));
       for(i=0 ; i<pasize ; i++)
	  pm.write((char*)&pa[i] , sizeof(pa[i]));
       fm.close();
       pm.close();
       cout<<"\n Succesfully Booked";
      }
     else if(found==0)
      cout<<"\n UNSUCCESSFUL IN BOOKING";
    }
  else
    cout<<"\n Not possible due to unavailability of passengers and flights in the records";
  cout<<"\n To book more flights hit 1 else hit 0\t:";
  cin>>repeat;
 }while(repeat==1);
}
void cancelbooking()
{int repeat=0,i,found,temp,maa;
 char nm[20],zn[20];
 do
 {clrscr();
  head();
  found=0;
  maa=0;
  if(flightsize>0 && pasize>0 && x>0)
    {fstream tg("TRAN.dat" , ios::in);
     fstream fg("FLIGHTDETAILS.dat" , ios::in);
     fstream pg("PASSENGERDETAILS.dat" , ios::in);
     for(i=0 ; i<flightsize ; i++)
	fg.read((char*)&fl[i] , sizeof(fl[i]));
     for(i=0 ; i<pasize ; i++)
	pg.read((char*)&pa[i] , sizeof(pa[i]));
     for(i=0 ; i<x ; i++)
	tg.read((char*)&tt[i] , sizeof(tt[i]));
     tg.close();
     pg.close();
     fg.close();
     cout<<"\n Enter the name of the passenger\t:";
     gets(nm);
     for(i=0 ; i<pasize ; i++)
	{if((strcmpi(nm,pa[i].getname())==0)&&(pa[i].noflightsbooked()>0))
	   {cout<<"\n The passenger "<<pa[i].getname()<<" has booked on the following flights"<<endl;
	    cout<<"-------------------------------------------------------------------------------";
	    cout<<endl;
	    cout<<setw(5)<<"FLIGHT NO"<<setw(17)<<"AIRLINE"<<setw(15)<<"FROM"<<setw(15)<<"TO"<<setw(17)<<"PRICE"<<endl;
	    cout<<"-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
	    for(int j=0 ; j<x ; j++)
	       {if(strcmpi(tt[j].nameget(),nm)==0)
		 {cout<<setw(5)<<tt[j].flightget()<<setw(25)<<tt[j].airlineget()<<setw(17)<<tt[j].fromget()<<setw(14)<<tt[j].toget()<<setw(12)<<tt[j].priceget()<<endl;
		 }
	       }
	    maa=1;
	    temp=i;
	    break;
	   }
	 else if((strcmpi(nm,pa[i].getname())==0)&&(pa[i].noflightsbooked()==0))
	   {maa=2;
	    break;
	   }
	}
     if(maa==2)
       cout<<"\n The passenger hasnt booked any flights";
     else if(maa==1)
       {cout<<"\n Enter the flight u wish to cancel \t:";
	gets(zn);
	for(int i=0 ; i<x ; i++)
	   {if((strcmpi(tt[i].flightget(),zn)==0)&&(strcmpi(tt[i].nameget(),nm)==0))
	      {for(int l=0 ; l<flightsize ; l++)
		  {if(strcmpi(fl[l].getflight(),zn)==0)
		     {found=1;
		      pa[temp].noflightsbooked(0,'b');
		      float amt=(0.50*fl[l].getprice());
		      pa[temp].bankbalance(amt,'d');
		      cout<<"\n Half the amount has been reimbursed";
		      cout<<"\n The prevailing balance of the customer "<<nm<<" is "<<pa[temp].bankbalance()<<endl;
		      fl[l].getpass(0,'b');
		      for(int b=i ; b<x ; b++)
			 tt[b]=tt[b+1];
		      x--;
		      if(pa[temp].noflightsbooked()==0)
			pa[temp].pav(0,'a');
		      break;
		     }
		  }
	      }
	   }
	if(found==0)
	   cout<<"\n UnSUCCESSFUL in cancelling the booking";
	else if(found==1)
	  {cout<<"\n Successfully cancelled";
	   fstream tm("TRAN.dat" , ios::out);
	   fstream fm("FLIGHTDETAILS.dat" , ios::out);
	   fstream pm("PASSENGERDETAILS.dat" , ios::out);
	   for(i=0 ; i<flightsize ; i++)
	      fm.write((char*)&fl[i] , sizeof(fl[i]));
	   for(i=0 ; i<pasize ; i++)
	      pm.write((char*)&pa[i] , sizeof(pa[i]));
	   for(i=0 ; i<x ; i++)
	      tm.write((char*)&tt[i] , sizeof(tt[i]));
	   tm.close();
	   pm.close();
	   fm.close();
	  }
       }
     else if(maa==0)
       cout<<"\n No such passenger";
    }
  else
    cout<<"\n There are no passenger or flight or bookings";
  cout<<"\n To cancel another booking pls hit 1 else 0\t:";
  cin>>repeat;
 }while(repeat==1);
}
void delpass()
{int repeat=0,found,i,confirm,temp;
 char nm[20];
 do
 {clrscr();
  head();
  found=0;
  confirm=0;
  if(pasize>0)
    {fstream pg("PASSENGERDETAILS.dat" , ios::in);
     for(i=0 ; i<pasize ; i++)
	pg.read((char*)&pa[i], sizeof(pa[i]));
     pg.close();
     cout<<"\n Enter the name of the passenger\t:";
     gets(nm);
     for(i=0 ; i<pasize ; i++)
	{if((strcmpi(pa[i].getname(),nm)==0)&&(pa[i].noflightsbooked()>0))
	    {found=1;
	     temp=i;
	     break;
	    }
	 else if((strcmpi(pa[i].getname(),nm)==0)&&(pa[i].noflightsbooked()==0))
	    {for(int k=i ; k<pasize ; k++)
		 pa[k]=pa[k+1];
	     pasize--;
	     fstream pm("PASSENGERDETAILS.dat" , ios::out);
	     for(i=0 ; i<pasize ;i++)
		pm.write((char*)&pa[i] , sizeof(pa[i]));
	     pm.close();
	     confirm=1;
	     break;
	    }
	}
     if((found==0)&&(confirm==0))
	cout<<"\n Sorry no such passenger by that name "<<nm<<endl;
     if((found==1)&&(confirm==0))
       {fstream tg("TRAN.dat" , ios::in);
	fstream fg("FLIGHTDETAILS.dat" , ios::in);
	for(i=0 ; i<flightsize ; i++)
	   fg.read((char*)&fl[i] , sizeof(fl[i]));
	for(i=0 ; i<x ; i++)
	   tg.read((char*)&tt[i] , sizeof(tt[i]));
	tg.close();
	fg.close();
	for(i=0 ; i<x ; i++)
	   {if(strcmpi(tt[i].nameget(),pa[temp].getname())==0)
	      {for(int j=0 ; j<flightsize ; j++)
		  {if(strcmpi(fl[j].getflight(),tt[i].flightget())==0)
		     {fl[j].getpass(0,'b');
		      confirm=1;
		      for(int m=i ; m<x ; m++)
			 tt[m]=tt[m+1];
		      x--;
		      break;
		     }
		  }
	      }
	   }
	if(confirm==1)
	  {fstream tm("TRAN.dat" , ios::out);
	   fstream fm("FLIGHTDETAILS.dat" , ios::out);
	   fstream pm("PASSENGERDETAILS.dat" , ios::out);
	   for(i=0 ; i<flightsize ; i++)
	      fm.write((char*)&fl[i] , sizeof(fl[i]));
	   for(i=temp ; i<pasize ; i++)
	      pa[i]=pa[i+1];
	   pasize--;
	   for(i=0 ; i<pasize ; i++)
	      pm.write((char*)&pa[i] , sizeof(pa[i]));
	   for(i=0 ; i<x ; i++)
	      tm.write((char*)&tt[i] , sizeof(tt[i]));
	   tm.close();
	   pm.close();
	   fm.close();
	   cout<<"\n Successfully deleted the passenger";
	  }
	else if(confirm==0)
	  cout<<"\n Failed to delete the passenger";
       }
     if(found==0 && confirm==1)
       cout<<"\n The passenger "<<nm<<" hasnt booked any flight and deletion was successful";
    }
  else
    cout<<"\n No passenger available in the records";
  cout<<"\n To delete another passenger hit 1 else 0\t:";
  cin>>repeat;
 }while(repeat==1);
}
void delflight()
{int repeat=0 ,confirm,found,i,temp,maa;
 char zn[20];
 do
 {clrscr();
  head();
  maa=0;
  found=0;
  confirm=0;
  if(flightsize>0)
    {fstream fg("FLIGHTDETAILS.dat" , ios::in);
     for(i=0 ; i<flightsize ; i++)
	 fg.read((char*)&fl[i] , sizeof(fl[i]));
     fg.close();
     cout<<"-------------------------------------------------------------------------------"<<endl;
     cout<<setw(2)<<"FLIGHT NO"<<setw(16)<<"AIRLINE"<<setw(15)<<"FROM"<<setw(15)<<"TO"<<setw(14)<<"PRICE"<<setw(11)<<"PASS NO"<<endl;
     cout<<"-------------------------------------------------------------------------------"<<endl;
     for(int i=0 ; i<flightsize ; i++)
	 cout<<setw(2)<<fl[i].getflight()<<setw(20)<<fl[i].getairline()<<setw(15)<<fl[i].getfrom()<<setw(17)<<fl[i].getto()<<setw(10)<<fl[i].getprice()<<setw(8)<<fl[i].getpass()<<endl;
     cout<<"\n Enter the flight no you would like to delete\t:";
     gets(zn);
     for(i=0 ; i<flightsize ; i++)
	{if((strcmpi(fl[i].getflight(),zn)==0)&&(fl[i].getpass()>0))
	    {temp=i;
	     found=1;
	     break;
	    }
	 else if((strcmpi(fl[i].getflight(),zn)==0)&&(fl[i].getpass()==0))
	    {maa=1;
	     temp=i;
	     break;
	    }
	}
     if(found==1 && maa==0)
       {fstream tg("TRAN.dat" , ios::in);
	fstream pg("PASSENGERDETAILS.dat" , ios::in);
	for(i=0 ; i<pasize ; i++)
	   pg.read((char*)&pa[i] , sizeof(pa[i]));
	for(i=0 ; i<x ; i++)
	   tg.read((char*)&tt[i] , sizeof(tt[i]));
	tg.close();
	pg.close();
	for(i=0 ; i<x ; i++)
	   {if(strcmpi(tt[i].flightget(),fl[temp].getflight())==0)
	      {for(int j=0 ; j<pasize ; j++)
		  {if(strcmpi(tt[i].nameget(),pa[j].getname())==0)
		     {pa[j].noflightsbooked(0,'b');
		      pa[j].bankbalance((fl[temp].getprice()+1000),'d');
		      if(pa[j].noflightsbooked()==0)
			pa[j].pav(0,'a');
		      cout<<"\n Flight ticket fare has been refunded to the passenger "<<pa[j].getname()<<" with an additional thousand as compensation and the prevailing balance is\t:"<<pa[j].bankbalance()<<endl;
		      cout<<"The no of flights the passenger has booked is\t:"<<pa[j].noflightsbooked();
		      for(int k=i ; k<x ; k++)
			 tt[k]=tt[k+1];
		      x--;
		      confirm=1;
		     }
		  }
	      }
	   }
	if(confirm==1)
	  {fstream tm("TRAN.dat" , ios::out);
	   fstream fm("FLIGHTDETAILS.dat" , ios::out);
	   fstream pm("PASSENGERDETAILS.dat" , ios::out);
	   for(i=temp ; i<flightsize ; i++)
	      fl[i]=fl[i+1];
	   flightsize--;
	   for(i=0 ; i<flightsize ; i++)
	      fm.write((char*)&fl[i] , sizeof(fl[i]));
	   for(i=0 ; i<pasize ; i++)
	      pm.write((char*)&pa[i] , sizeof(pa[i]));
	   for(i=0 ; i<x ; i++)
	      tm.write((char*)&tt[i] , sizeof(tt[i]));
	   tm.close();
	   pm.close();
	   fm.close();
	   cout<<"\n Successfully cancelled after refunding all the passenger";
	  }
	else if(confirm==0)
	  cout<<"\n Unsuccessful in deleting the flight";
       }
     else if((maa==1)&&(found==0))
       {cout<<"\n No passengers have booked the entered flight";
	for(i=temp ; i<flightsize ; i++)
	   fl[i]=fl[i+1];
	flightsize--;
	fstream fm("FLIGHTDETAILS.dat" , ios::out);
	for(i=0 ; i<flightsize ; i++)
	   fm.write((char*)&fl[i],sizeof(fl[i]));
	fm.close();
	cout<<"\n Successfully deleted the flight";
       }
     else if((found==0)&&(maa==0))
       cout<<"\n No such flight present in the records";
    }
  else
    cout<<"\n No flights available in the records";
  cout<<"\n To delete or remove another flight hit 1 else 0\t:";
  cin>>repeat;
 }while(repeat==1);
}
void displaypass()
{int ch,repeat;
 do
 {clrscr();
  head();
  cout<<"\n Choose the options listed below\t:";
  cout<<"\n------------------------------------------------------------------------------"<<endl;
  cout<<"1.Display All Passenger Or Passenger By Flight"<<endl;
  cout<<"2.Search For A Passenger In A Flight"<<endl;
  cout<<"3.Search For A Passenger"<<endl;
  cout<<"4.Return To The Main Menu"<<endl;
  cout<<"------------------------------------------------------------------------------"<<endl;
  cout<<"Please enter your choice\t:";
  cin>>ch;
  switch(ch)
  {case 1 :displaypassenger();
	   break;
   case 2 :displaysrpsngr();
	   break;
   case 3 :aaa();
	   break;
   case 4 :menu();
	   break;
   default:cout<<"\n Please dont choose invalid options";
  }
  cout<<"\n Do you want to proceed wuith another search if yes hit 1 else 0\t:";
  cin>>repeat;
 }while(repeat==1);
}
void displaypassenger()
{clrscr();
 head();
 int kb=0,z,i;
 char zn[20];
 if(pasize>0)
   {fstream pg("PASSENGERDETAILS.dat", ios::in);
    for(i=0 ; i<pasize ; i++)
       pg.read((char*)&pa[i], sizeof(pa[i]));
    pg.close();
    textcolor(BLUE);
    cout<<endl;
    cprintf("Do you want to display all passengers(1) or passengers by flight(0) :");
    cin>>z;
    if(z==1)
      {cout<<endl;
       cout<<"--------------------------------------------------------------------------------";
       cout<<"PASSPORT"<<setw(10)<<"NAME"<<setw(22)<<"BANK ACCT"<<setw(15)<<"BANK BALANCE"<<setw(24)<<"NO OF FLIGHT BOOKED"<<endl;
       cout<<"-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
       for(i=0 ; i<pasize ; i++)
	  cout<<pa[i].getpassport()<<setw(17)<<pa[i].getname()<<setw(15)<<pa[i].getbank()<<setw(14)<<pa[i].bankbalance()<<setw(18)<<pa[i].noflightsbooked()<<endl;
      }
    if((z==0)&&(x>0))
      {int m=1;
       cout<<endl;
       fstream tg("TRAN.dat" , ios::in);
       for(i=0 ; i<x ; i++)
	  tg.read((char*)&tt[i] , sizeof(tt[i]));
       tg.close();
       cout<<"Enter the flight number\t:";
       gets(zn);
       cout<<"\n The list of passengers on the flight "<<zn<<endl;
       for(i=0 ; i<x ; i++)
	  {if(strcmpi(tt[i].flightget(),zn)==0)
	     {cout<<m++<<" "<<tt[i].nameget()<<endl;
	      kb=1;
	     }
	  }
       if(kb==0)
	 cout<<"\n No passenger on the flight or perhaps invalid flight number";
      }
    else if(z==0 && x==0)
      cout<<"\n No search can be made as there are no bookings made";
   }
 else
  cout<<"\n There are no passengers to be displayed";
}
void displaysrpsngr()
{char zn[20];
 int lb,i;
 clrscr();
 head();
 if(x>0)
   {lb=0;
    fstream tg("TRAN.dat" , ios::in);
    for(i=0 ; i<x ; i++)
       tg.read((char*)&tt[i],sizeof(tt[i]));
    tg.close();
    cout<<"\n Enter the name of the passenger to find his bookings\t:";
    gets(zn);
    cout<<"\n The list of flights he has booked in :"<<endl;
    for(i=0 ; i<x ; i++)
       if(strcmpi(tt[i].nameget(),zn)==0)
	 {if(i%2==0)
	    textcolor(YELLOW);
	  else if(i%2!=0)
	    textcolor(BLUE);
	  lb=1;
	  cout<<"\n The passenger "<<tt[i].nameget()<<" has been booked on the plane on "<<tt[i].airlineget()<<" departing from "<<tt[i].fromget()<<" to "<<tt[i].toget();
	 }
    if(lb==0)
      cout<<"\n Passenger "<<zn<<" has not booked any flights";
   }
 else if(x==0)
   cout<<"\n No flight has been booked";
}
void aaa()
{int repeat,i,m;
 char zn[20];
 do
 {clrscr();
  m=0;
  head();
  if(pasize>0)
    {fstream pg("PASSENGERDETAILS.dat" , ios::in);
     for(i=0 ; i<pasize ; i++)
	pg.read((char*)&pa[i] , sizeof(pa[i]));
     pg.close();
     cout<<"\n Enter the name of the passenger you want to search it\t:";
     gets(zn);
     cout<<"\n------------------------------------------------------------------------------";
     cout<<"PASSPORT"<<setw(10)<<"NAME"<<setw(22)<<"BANK ACCT"<<setw(15)<<"BANK BALANCE"<<setw(24)<<"NO OF FLIGHT BOOKED"<<endl;
     cout<<"-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-"<<endl;
     for(i=0 ; i<pasize ; i++)
	if(strcmpi(pa[i].getname(),zn)==0)
	  {cout<<pa[i].getpassport()<<setw(17)<<pa[i].getname()<<setw(15)<<pa[i].getbank()<<setw(14)<<pa[i].bankbalance()<<pa[i].noflightsbooked()<<endl;
	   m=1;
	  }
     if(m==0)
	cout<<"\n No such passenger";
    }
  else if(pasize==0)
    cout<<"\n No passengers are there";
  cout<<"\n Do you want to seearch for another passenger if yes hit 1 else 0\t:";
  cin>>repeat;
 }while(repeat==1);
}
void displayflights()
{int ch,repeat,z=1;
 do
 {clrscr();
  head();
  textcolor(z);
  cprintf("Choose any of the option below :");
  cout<<endl;
  cout<<"------------------------------------------------------------------------------"<<endl;
  cprintf("1.Display All Available Flights ");
  cout<<endl;
  cprintf("2.Search For A Flight Having Maximum Number Of Passengers");
  cout<<endl;
  cprintf("3.Sort All Flight In Increasing Price");
  cout<<endl;
  cprintf("4.Search For A Flight");
  cout<<endl;
  cprintf("5.Return To The Main Menu");
  cout<<endl;
  cprintf("Enter your option :");
  cin>>ch;
  switch(ch)
  {case 1 :disavflights();
	   break;
   case 2 :dismaxpass();
	   break;
   case 3 :dispricefl();
	   break;
   case 4 :xxx();
	   break;
   case 5 :menu();
	   break;
   default:cout<<"\n Please do not opt for invalid options";
  }
  z++;
  cout<<"\n To make your exit pls enter 0\t:";
  cin>>repeat;
  if(repeat==0)
    exit(0);
 }while(ch<=5);
}
void disavflights()
{clrscr();
 head();
 int i;
 if(flightsize>0)
   {fstream fg("FLIGHTDETAILS.dat" , ios::in);
    for(i=0 ; i<flightsize ; i++)
       fg.read((char*)&fl[i] , sizeof(fl[i]));
    fg.close();
    cout<<"\n-------------------------------------------------------------------------------"<<endl;
    cout<<setw(2)<<"FLIGHT NO"<<setw(16)<<"AIRLINE"<<setw(15)<<"FROM"<<setw(15)<<"TO"<<setw(14)<<"PRICE"<<setw(11)<<"PASS NO"<<endl;
    cout<<"-------------------------------------------------------------------------------"<<endl;
    for(int i=0 ; i<flightsize ; i++)
	cout<<setw(2)<<fl[i].getflight()<<setw(20)<<fl[i].getairline()<<setw(15)<<fl[i].getfrom()<<setw(17)<<fl[i].getto()<<setw(10)<<fl[i].getprice()<<setw(8)<<fl[i].getpass()<<endl;
   }
 else
   cout<<"\n There are no flights available for display";
}
void dispricefl()
{clrscr();
 head();
 int i;
 if(flightsize>0)
   {flight temp;
    fstream fg("FLIGHTDETAILS.dat" , ios::in);
    for(i=0 ; i<flightsize ; i++)
       fg.read((char*)&fl[i] , sizeof(fl[i]));
    fg.close();
    for(i=0 ; i<flightsize ; i++)
       for(int j=i+1 ; j<flightsize ; j++)
	  if(fl[i].getprice()<fl[j].getprice())
	    {temp=fl[j];
	     fl[j]=fl[i];
	     fl[i]=temp;
	    }
    fstream fm("FLIGHTDETAILS.dat" , ios::out);
    for(i=0 ; i<flightsize ; i++)
       fm.write((char*)&fl[i] , sizeof(fl[i]));
    fm.close();
    cout<<"\n The sorted flights according to their price\t:";
    cout<<"\n-------------------------------------------------------------------------------"<<endl;
    cout<<setw(2)<<"FLIGHT NO"<<setw(16)<<"AIRLINE"<<setw(15)<<"FROM"<<setw(15)<<"TO"<<setw(14)<<"PRICE"<<setw(11)<<"PASS NO"<<endl;
    cout<<"-------------------------------------------------------------------------------"<<endl;
    for(int i=0 ; i<flightsize ; i++)
	cout<<setw(2)<<fl[i].getflight()<<setw(20)<<fl[i].getairline()<<setw(15)<<fl[i].getfrom()<<setw(17)<<fl[i].getto()<<setw(10)<<fl[i].getprice()<<setw(8)<<fl[i].getpass()<<endl;
   }
 else
   cout<<"\n There are no flights available to sort";
}
void xxx()
{int i,repeat=0;
 char zn[10];
 do
 {clrscr();
  head();
  int found=0;
  if(flightsize>0)
    {fstream fg("FLIGHTDETAILS.dat", ios::in);
     for(i=0 ; i<flightsize ; i++)
	fg.read((char*)&fl[i] , sizeof(fl[i]));
     fg.close();
     cout<<"\n Enter the flight number\t:";
     gets(zn);
     cout<<"\n-------------------------------------------------------------------------------"<<endl;
     cout<<setw(2)<<"FLIGHT NO"<<setw(16)<<"AIRLINE"<<setw(15)<<"FROM"<<setw(15)<<"TO"<<setw(14)<<"PRICE"<<setw(11)<<"PASS NO"<<endl;
     cout<<"-------------------------------------------------------------------------------"<<endl;
     for(i=0 ; i<flightsize ; i++)
	if(strcmpi(fl[i].getflight(),zn)==0)
	  {cout<<setw(2)<<fl[i].getflight()<<setw(20)<<fl[i].getairline()<<setw(15)<<fl[i].getfrom()<<setw(17)<<fl[i].getto()<<setw(10)<<fl[i].getprice()<<setw(8)<<fl[i].getpass()<<endl;
	   found=1;
	   break;
	  }
     if(found==0)
       cout<<"\n PERHAPS ENTERED THE WRONG FLIGHT NUNBER";
    }
  else
    cout<<"\n There are no flight available in the record";
  cout<<"\n To search for another flight hit 1 else 0\t:";
  cin>>repeat;
 }while(repeat==1);
}
void dismaxpass()
{clrscr();
 head();
 int i;
 if(flightsize>0)
   {int max=0;
    flight temp;
    fstream fg("FLIGHTDETAILS.dat" , ios::in);
    for(i=0 ; i<flightsize ; i++)
       fg.read((char*)&fl[i] , sizeof(fl[i]));
    fg.close();
    for(i=0 ; i<flightsize ; i++)
       if(fl[i].getpass()>max)
	 {max=fl[i].getpass();
	  temp=fl[i];
	 }
    cout<<"\n-------------------------------------------------------------------------------"<<endl;
    cout<<setw(2)<<"FLIGHT NO"<<setw(16)<<"AIRLINE"<<setw(15)<<"FROM"<<setw(15)<<"TO"<<setw(14)<<"PRICE"<<setw(11)<<"PASS NO"<<endl;
    cout<<"-------------------------------------------------------------------------------"<<endl;
    cout<<setw(2)<<temp.getflight()<<setw(20)<<temp.getairline()<<setw(15)<<temp.getfrom()<<setw(17)<<temp.getto()<<setw(10)<<temp.getprice()<<setw(8)<<temp.getpass()<<endl;
   }
 else
   cout<<"\n There are no flights available in the records";
}
void prevbankbalance()
{int repeat,found,i;
 char nm[20];
 do
 {clrscr();
  head();
  found=0;
  if(pasize>0)
    {fstream pg("PASSENGERDETAILS.dat" , ios::in);
     for(i=0 ; i<pasize ; i++)
	pg.read((char*)&pa[i] , sizeof(pa[i]));
     pg.close();
     cout<<"\n Enter the name of the passenger whose bank balance you want to view\t:";\
     gets(nm);
     for(i=0 ; i<pasize ; i++)
	if(strcmpi(nm,pa[i].getname())==0)
	  {found=1;
	   cout<<"\n The current balance of the passenger "<<pa[i].bankbalance()<<endl;
	   break;
	  }
     if(found==0)
       cout<<"\n PERHAPS ENTERED AN INVALID PASSENGER";
    }
  else
    cout<<"\n There are no passengers available in the records";
  cout<<"\n To make another search hit 1 else 0\t:";
  cin>>repeat;
 }while(repeat==1);
}









