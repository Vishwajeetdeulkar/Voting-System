#include<iostream>
#include<fstream>
#include<process.h>
#include<string.h>
#include<stdlib.h>
//#include<stdio.h>
#include<ctype.h>
#include<conio.h>
#include<dos.h>

using namespace std;

static int lastcode=0;
static int start,ent,diff,data[100][2],vote_stat=0;
static int u1,w1;

class candidate_record
{
protected:
int candidate_namecode ;
char candidate_name[50] ;
char partyname[50];

public:
    int votes;
    candidate_record()//constructor for candidate record
    {
        candidate_namecode=0;
        votes=0;
    }
    void getdata(int tcode)
    {
        candidate_namecode=tcode;
        cout<<"\ncandidate namecode: "<<candidate_namecode;
        cout<<"\nEnter name: ";cin>>candidate_name;
        cout<<"\nEnter party name: ";cin>>partyname;
    }

    void showdata()
    {
        cout<<"\ncandidate namecode: "<<candidate_namecode;
        cout<<"\n name: "<<candidate_name;
        cout<<"\n party name: "<<partyname;
    }
    void diskIn(int);
    void diskOut();
    static int diskCount();
    void showdata1()
    {
        cout<<"\ncandidate namecode: "<<candidate_namecode;
        cout<<"\nEnter name: "<<candidate_name;
        cout<<"\nEnter party name: "<<partyname;
        cout<<"\nGOT VOTES: "<<votes;
    }
   int getcode()
   {
       return candidate_namecode;
   }
   void got_vote()
   {
    votes=votes+1;
    }
   int ret_votes()
   {
       //int y;
       return votes;
   }

};


void candidate_record::diskIn(int pn)
{
    ifstream infile;
    infile.open("GROUP.DAT",ios::binary);
    infile.seekg(pn*sizeof(candidate_record));
    infile.read((char*)this,sizeof(*this));
}

void candidate_record::diskOut()
{
    ofstream outfile;
    outfile.open("GROUP.DAT",ios::app|ios::binary);
    outfile.write((char*)this,sizeof(*this));
}

int candidate_record::diskCount()
{
    ifstream infile;
    infile.open("GROUP.DAT",ios::binary);
    infile.seekg(0,ios::end);
    return (int)infile.tellg()/sizeof(candidate_record);
}

class vote:protected candidate_record  //inherited class from class candidate_record
{
private:
    int vote_status;
public:
    static void start_voting();
    static void display_results();
   // ~vote();
};

void vote ::start_voting()
{
    int id_no;int fg2=0,fg3=0;
    cout<<"\nENTER YOUR USER ID:  ";cin>>id_no;

    //fg2 flag for voting code is right or wrong

    //fg3 flag for voting to do or not

    for(int k=0;k<diff;k++)
    for(int i=0;i<2;i++)
{
    if(i==0)
    if(data[k][i]==id_no)
    fg2=1;
    if(i==1)
    {
    if(data[k][i]==0)
    {
    fg3=1;u1=k;w1=i;
    //data[k][i]=1;
    break;
    }
    }
}


if((fg2==1)&&(fg3==1))
{
    data[u1][w1]=1;
    int z;
    candidate_record cand;
            cout<<"\nCANDIDATES ARE RESPECTIVELY:\n";
            int num;
        candidate_record cr;
        num=candidate_record::diskCount();
    for(int l=0;l<num;l++)
    {
       // cout<<"\nPerson: "<<l;
        cr.diskIn(l);
        cr.showdata();
         cout<<"\n\n";
        }
        cout<<"\n\n";


    cout<<"\n\n\nCAST A VOTE\n\n\nENTER CANDIDATE CODE PLEASE:  ";cin>>z;
    int flg=0;
   int tcode=candidate_record::diskCount();
   for(int i=1;i<=tcode;i++)
    {
     if(z==i)
     {
         flg=1;
     }
    }
    if(flg==1)
    {
  cout<<"\n\nYOUR VOTE IS CASTED TO ";

   int num;
        candidate_record cr;
        num=candidate_record::diskCount();
    for(int l=0;l<num;l++)
    {
        cr.diskIn(l);
        if(cr.getcode()==z)
        {
        cr.votes++;
        cr.showdata1();
        //to save  data of votes in file
       // cr.diskOut();

        }
        }
        cout<<"\n===========\n";
    }


}

else
{
    cout<<"INVALID NUMBER OR YOU ALREADY VOTE FOR SOMEONE!!!!!!!!!";
    return;
}
}

void vote::display_results()
{
  int save_winner[100];int max1=0;


 cout<<"\n\nRESULTS ARE AS FOLLOWS: ";



// fstream file;
            cout<<"WINNER IS:\n";
        int num;
        candidate_record cr;
        num=candidate_record::diskCount();
    for(int l=0;l<num;l++)
    {
        cr.diskIn(l);
       if(cr.ret_votes()>max1)
       {
           max1=cr.ret_votes();
       }
        }
        //sorting winner

 for(int l1=0;l1<num;l1++)
    {
       // cout<<"\nPerson: "<<l;
        cr.diskIn(l1);
        if(cr.ret_votes()==max1)
        {
        cr.showdata1();
        exit(0);
        }

        }
 cout<<"\n";

}

char description()
{
//delay(2000);
cout<<"\t\t ELECTION VOTING SOFTWARE \n\n";
//delay(500);
cout<<"\t DESCRIPTION : IN THIS PROJECT , A  SET OF VOTERS \n\n\n";
//delay(500);
cout<<"\t VOTERS WILL BE ABLE TO CAST THE VOTE .VOTERS WILL HAVE \n\n\n";
//delay(500);
cout<<"\t TO PROVE THEIR IDENTITY BY GIVING THEIR IDENTIFICATION \n\n\n";
//delay(500);
cout<<"\t NO. A AUTHENTICATED USER WILL BE ABLE TO CAST THE VOTE.\n\n\n";
//delay(500);
cout<<"\n\n\n\t\t\tPLEASE PRESS ENTER TO CONTINUE & Esc. TO EXIT\t";
char ch;
for(;;)
{
ch=getch();
if(ch==13)
break;
else
if(ch==27)
exit(-1);
else
cout<<"\n\n\t\t\t\a ! WRONG KEY ENTERED !";
//delay(300);
cout<<"\n\n\n\n\t\t\t PRESS ENTER ";
}
return 0;
}


int main()
{
//clrscr() ;
char des;
description();
// exit();
//     clrscr();


//clrscr() ;
   char ch_menu;
while (1)
{
//clrscr();
cout<<"\n\n\n\t\t E L E C T I O N ";
cout <<" V O T I N G S O F T W A R E\n " ;
cout <<"\n******************************************************************************" ;
cout <<"\n\n1: VOTE " ;
cout <<"\n2: SEE LIST OF CANDIADATES OR VOTERS " ;
cout <<"\n3: EDIT CANDIDATE RECORDS " ;
cout <<"\n4:DISPLAY RESULTS ";
cout <<"\n0: QUIT " ;
cout <<"\nEnter Choice : " ;
ch_menu = getche() ;

candidate_record cand;

switch(ch_menu)
{
    case '0':
        {
            exit(0);break;
        }
    case '1':
        {
            vote::start_voting();
             break;
        }
    case '2':
        {
            char sub_menu2;
            cout<<"\n\n1.CANDIDATES LIST\n\n2.VOTERS LIST\n\n0.QUIT\n\nENTER YOUR CHOICE: ";
            sub_menu2=getche();
            if(sub_menu2=='1')
            {
            int num;
            candidate_record cr;
            num=candidate_record::diskCount();
            for(int l=0;l<num;l++)
             {
       // cout<<"\nPerson: "<<l;
              cr.diskIn(l);
              cr.showdata();
               cout<<"\n\n";
              }
               cout<<"\n\n";
               }
                else if(sub_menu2=='2')
               {
                for(int k=0;k<diff;k++)
                {
                 for(int i=0;i<2;i++)
                   {
                  cout<<data[k][i];
                  if(i==0)
                    cout<<" : ";
                   }
                  cout<<"\n";
                  }
                  }
                 else
                 break;
                 break;
        }
    case '3':
        {
            char sub_menu;
            cout<<"\n\n1.ADD CANDIDATE\n\n2.DELETE CANDIDATE\n\n3.ADD VOTER LIST\n\n0.EXIT\nENETR YOUR CHOICE: ";
              sub_menu=getche();
              if(sub_menu=='1')
                 {
                  candidate_record cr;
              char ch;int tcode;
             tcode=candidate_record ::diskCount();//////////////////////////// to obtain last code num
               //tcode=1;
               do
                {
              cout<<"\nEnter person's data:\n";
              cr.getdata(tcode);
              cr.diskOut();
              cout<<"\nDo you want to enter another person(y/n)  ";
              cin>>ch;
                }while(ch=='y');

               }//end of submenu if

           else if(sub_menu=='2')

             {
            int id;
             cout<<"\nENTER CODE TO DELETE RECORD: ";cin>>id;
             candidate_record cr;
             fstream file ;
            file.open("GROUP.DAT", ios::in|ios::binary) ;
            fstream temp ;
             temp.open("temp.dat", ios::out|ios::binary) ;
              file.seekg(0,ios::beg) ;
              while ( !file.eof() )
               {
              file.read(reinterpret_cast<char*>(&cr), sizeof(cr)) ;
              if ( file.eof() )
               break ;
              if ( cr.getcode() != id )
             temp.write(reinterpret_cast<char*>(&cr), sizeof(cr)) ;
             }
            file.close() ;
            temp.close() ;
            file.open("GROUP.DAT", ios::out|ios::binary) ;
            temp.open("temp.dat", ios::in|ios::binary) ;
            temp.seekg(0,ios::beg) ;
             while ( !temp.eof() )
               {
               temp.read(reinterpret_cast<char*>(&cr), sizeof(cr)) ;
               if ( temp.eof() )
                 break ;
              file.write(reinterpret_cast<char*> (&cr), sizeof(cr)) ;
                }
              file.close() ;
               temp.close() ;
             }
            else if(sub_menu=='3')
            {
            cout<<"\n\nEnter range of User IDS \n\nSTART: ";cin>>start;
             cout<<"\n\nEND: ";cin>>ent;
              diff=ent-start+1;
             int s=start;
             for(int k=0;k<diff;k++)
              for(int i=0;i<2;i++)
               {
              if(i==0)
              {
              data[k][i]=s;
               s++;
               }
                 else
               {
                data[k][i]=0;
                 }
                 }

                   }

                   break;
        }
        case '4':
            {
                vote ::display_results();
                 break;
            }
}//end of switch

}//end of menu while

getch();
  return 0;


}


