/*
=======================================================================
=  Project Name: ICC WC-2015 Ticketing & General Information System
=  File Name   : CricketWC2015.cpp
=  Time        : 13:10:31
=  Created on  : 17th December 2014
=  Author      : S. M. RUHUL KABIR HOWLADER
=  Instructor  : Dr. Mohammad Rezwanul Huq
=                Assistant Professor
=                Department of Computer Science & Engineering
=  Institution : East West University, Dhaka
=======================================================================
=  This project included the following features in C++:
=       #Arrays of objects
=       #Pointers
=       #Constructors
=       #Overloaded Constructors
=       #Destructor
=       #Static Class data
=       #Inheritance
=       #Virtual Function
=       #Linked List
=       #ETC
=======================================================================
*/

#include<bits/stdc++.h>
#include<string>
#include<cstdlib>
#include<iomanip>
#include<stdio.h>

int Match_NUM=0;
int Player_NUM=0;
int Coach_NUM=0;

using namespace std;

class Match
{
private:
    static int Count_MATCH;
    int Match_Id;
    int Sold_TIC_VIP;
    int Total_TIC_VIP;
    int Avl_TIC_VIP;
    int Sold_TIC_GS;
    int Total_TIC_GS;
    int Avl_TIC_GS;
    int Sold_TIC_IS;
    int Total_TIC_IS;
    int Avl_TIC_IS;
    string Team_1;
    string Team_2;
    string Stadium;
    string status;
    string time;
    string date;

public:
    Match()
    {
        Match_Id=0;
        Sold_TIC_VIP=0;
        Total_TIC_VIP=0;
        Avl_TIC_VIP=0;
        Sold_TIC_GS=0;
        Total_TIC_GS=0;
        Avl_TIC_GS=0;
        Sold_TIC_IS=0;
        Total_TIC_IS=0;
        Avl_TIC_IS=0;
        Team_1="Empty";
        Team_2="Empty";
        Stadium="Empty";
        status="Empty";
        time="Empty";
        date="Empty";
    }

    Match(string d,string t,string st,string s,string t1,string t2,int mi,int stv,int ttv,int atv,int stg,int ttg,int atg,int sti,int tti,int ati)
    {
        Match_Id=mi;
        Sold_TIC_VIP=stv;
        Total_TIC_VIP=ttv;
        Avl_TIC_VIP=atv;
        Sold_TIC_GS=stg;
        Total_TIC_GS=ttg;
        Avl_TIC_GS=atg;
        Sold_TIC_IS=sti;
        Total_TIC_IS=tti;
        Avl_TIC_IS=ati;
        Team_1=t1;
        Team_2=t2;
        Stadium=s;
        status=st;
        time=t;
        date=d;
    }

    ~Match() {}

    string getDate()
    {
        return date;
    }

    string getTeam_1name()
    {
        return Team_1;
    }

    string getTeam_2name()
    {
        return Team_2;
    }

    string getStadiumname()
    {
        return Stadium;
    }

    string getstat()
    {
        return status;
    }

    string gettime()
    {
        return time;
    }

    static int countmn()
    {
        return ++Count_MATCH;
    }

    void addmatch()
    {
        fflush(stdin);
        cout
                <<endl    <<"-------------------------------------------"
                <<endl    <<"////////   Add Match Information   ////////"
                <<endl    <<"-------------------------------------------";
        cout<<endl<<"Enter Team One                          : ";
        getline(cin,Team_1);
        cout<<endl<<"Enter Opposite Team                     : ";
        getline(cin,Team_2);
        cout<<endl<<"Enter Match Date                        : ";
        getline(cin,date);
        cout<<endl<<"Enter Match Time(GMT)                   : ";
        getline(cin,time);
        cout<<endl<<"Enter Stadium                           : ";
        getline(cin,Stadium);
        cout<<endl<<"Match Type                              : ";
        getline(cin,status);
        cout<<endl<<"Enter VIP Gallery Total Tickets         : ";
        cin>>Total_TIC_VIP;
        cout<<endl<<"Enter General Stand Total Tickets       : ";
        cin>>Total_TIC_GS;
        cout<<endl<<"Enter International Stand Total Tickets : ";
        cin>>Total_TIC_IS;

        Match_Id=Match::countmn();
        Avl_TIC_VIP=Total_TIC_VIP;
        Avl_TIC_GS=Total_TIC_GS;
        Avl_TIC_IS=Total_TIC_IS;
    }

    void Show_Match()
    {
        cout<<"_______________________________________________________________________________"<<endl
            <<setw(3)<<"Id"<<setw(10)<<"Team 1"<<setw(10)<<"Team 2"<<setw(11)<<"D or D/N"
            <<setw(13)<<"Date"<<setw(15)<<"Start Time"<<setw(15)<<"Stadium"<<endl;
        cout<<"_______________________________________________________________________________"<<endl;
        cout<<endl<<setw(3)<<Match_Id<<setw(10)<<Team_1<<setw(10)<<Team_2<<setw(11)<<status
            <<setw(13)<<date<<setw(15)<<time<<setw(15)<<Stadium<<endl<<endl;
        cout<<"_______________________________________________________________________________"<<endl;
        cout<<setw(8)<<"Vip Avl"<<setw(10)<<"Vip Sold"<<setw(10)<<"Vip Tot"
            <<setw(8)<<"GS Avl"<<setw(8)<<"GS Sold"<<setw(8)<<"GS Tot"
            <<setw(8)<<"IS Avl"<<setw(8)<<"IS Sold"<<setw(8)<<"IS Tot"
            <<endl;
        cout<<"_______________________________________________________________________________"<<endl;
        cout<<endl<<setw(8)<<Avl_TIC_VIP<<setw(10)<<Sold_TIC_VIP<<setw(10)<<Total_TIC_VIP
            <<setw(8)<<Avl_TIC_GS<<setw(8)<<Sold_TIC_GS<<setw(8)<<Total_TIC_GS
            <<setw(8)<<Avl_TIC_IS<<setw(8)<<Sold_TIC_IS<<setw(8)<<Total_TIC_IS<<endl<<endl<<endl;
    }

    void Sell_Ticket()
    {
        int sold,k,mon;
        float vt=100;
        float it=70;
        float gt=30;
        cout<<endl<<"         ----------------------------"
            <<endl<<"         Match Number: "<<Match_Id
            <<endl<<"         Date        : "<<date
            <<endl<<"         Time        : "<<time
            <<endl<<"         Day Light   : "<<status
            <<endl<<"         Team 1      : "<<Team_1
            <<endl<<"         Team 2      : "<<Team_2
            <<endl<<"         Stadium     : "<<Stadium
            <<endl<<"         ----------------------------"<<endl;
        cout
                <<endl<<"         Enter Gallery Type "
                <<endl<<"         -----------------------------------"
                <<endl<<"         :    1 for VIP                    :"
                <<endl<<"         :    2 for General                :"
                <<endl<<"         :    3 for International Stand    :"
                <<endl<<"         -----------------------------------"
                <<endl<<"              Enter Choice:";
        cin>>k;
        if(k==1)
        {
            cout<<"         How Many Tickets Do You Want: ";
            cin>>sold;
            if(sold>4)
            {
                cout<<"Sorry! You Can Only Buy 4 Tickets"<<endl;
            }
            else if(sold<=Avl_TIC_VIP)
            {
                Avl_TIC_VIP-=sold;
                Sold_TIC_VIP+=sold;
                mon=vt*sold;
                cout
                        <<endl<<"         ============================"
                        <<endl<<"           Transection Succesfully"
                        <<endl<<"           Total price is: "<<mon
                        <<endl<<"         ============================";
                cout<<endl<<endl;
            }
            else if(Avl_TIC_VIP==0)
            {
                cout<<"         All Ticket are sold out"<<endl;
            }
            else if(sold>Avl_TIC_VIP)
            {
                cout<<"         Sorry not enough tickets"<<endl;
            }
        }
        if(k==2)
        {
            cout<<"         How Many Tickets Do You Want: ";
            cin>>sold;
            if(sold>4)
            {
                cout<<endl<<"         Sorry! You Can Only Buy 4 Tickets"<<endl;
            }
            else if(sold<=Avl_TIC_GS)
            {
                Avl_TIC_GS-=sold;
                Sold_TIC_GS+=sold;
                mon=vt*sold;
                cout
                        <<endl<<"         ============================"
                        <<endl<<"           Transaction Successfully"
                        <<endl<<"           Total price is: "<<mon
                        <<endl<<"         ============================";
                cout<<endl<<endl;
            }
            else if(Avl_TIC_GS==0)
            {
                cout<<endl<<"         All Ticket are sold out"<<endl;
            }
            else if(sold>Avl_TIC_GS)
            {
                cout<<endl<<"         Sorry not enough tickets"<<endl;
            }
        }
        if(k==3)
        {
            cout<<endl<<"         How Many Tickets Do You Want: ";
            cin>>sold;
            if(sold>4)
            {
                cout<<endl<<"         Sorry! You Can Only Buy 4 Tickets"<<endl;
            }
            else if(sold<Avl_TIC_IS)
            {
                Avl_TIC_IS-=sold;
                Sold_TIC_IS+=sold;
                mon=vt*sold;
                cout
                        <<endl<<"         ============================"
                        <<endl<<"           Transection Succesfully"
                        <<endl<<"           Total price is: "<<mon
                        <<endl<<"         ============================";
                cout<<endl<<endl;
            }
            else if(Avl_TIC_IS==0)
            {
                cout<<"All Ticket are sold out"<<endl;
            }
            else if(sold>Avl_TIC_IS)
            {
                cout<<"Sorry not enough tickets"<<endl;
            }
        }
    }
};

int Match::Count_MATCH=0;

class team
{
protected:
    string name;
    string born;
    string age;
    string country;

public:
    team()
    {
        name="Empty";
        born="Empty";
        age="Empty";
        country="Empty";
    }

    team(string n,string b,string a,string c)
    {
        name=n;
        born=b;
        age=a;
        country=c;
    }

    virtual bool Is_Great()=0;

    string get_Name()
    {
        return name;
    }

    ~team() {}

    void setinfo()
    {
        fflush(stdin);
        cout<<endl<<"         Enter Name                : ";
        getline(cin,name);
        cout<<endl<<"         Enter Birth Place         : ";
        getline(cin,born);
        cout<<endl<<"         Enter Age                 : ";
        getline(cin,age);
        cout<<endl<<"         Enter Country             : ";
        getline(cin,country);
    }

    void showinfo()
    {
        cout
                <<endl<<"            Name                           : "<<name
                <<endl<<"            Born                           : "<<born
                <<endl<<"            Age                            : "<<age
                <<endl<<"            Country                        : "<<country;
    }
};

class Player:public team
{
private:
    string type;
    int matchplayed;
    int runs;
    int ballsplayed;
    float batavg;
    float batsr;
    int wicket;
    int ballsbowled;
    int runsgiven;
    float econ;
    float bowlsr;

public:
    Player():team(),
        type(" "),
        matchplayed(0),
        runs(0),
        ballsplayed(0),
        batavg(0.0),
        batsr(0.0),
        wicket(0),
        ballsbowled(0),
        runsgiven(0),
        econ(0.0),
        bowlsr(0.0) {}

    Player(string n,string b,string a,string c,
           string t,int mp,int r,int bb,int bp,float ba,
           float bs,int w,float bwa,float bws,int rg):
        team(n,b,a,c),
        type(t),
        matchplayed(mp),
        runs(r),
        ballsplayed(bp),
        batavg(ba),
        batsr(bs),
        wicket(w),
        ballsbowled(bb),
        runsgiven(rg),
        econ(bwa),
        bowlsr(bws) {}

    void Setinfo_Player()
    {
        cout<<endl;
        team::setinfo();
        fflush(stdin);
        cout<<endl<<"         Enter Type                : ";
        getline(cin,type);
        cout<<endl<<"         Enter Match Played        : ";
        cin>>matchplayed;
        cout<<endl<<"         Enter Total Runs Scored   : ";
        cin>>runs;
        cout<<endl<<"         Enter Balls Played        : ";
        cin>>ballsplayed;
        cout<<endl<<"         Enter Total Wikets:       : ";
        cin>>wicket;
        cout<<endl<<"         Enter Balls Boweled       : ";
        cin>>ballsbowled;
        cout<<endl<<"         Enter Runs Given          : ";
        cin>>runsgiven;
        batavg=runs/matchplayed;
        batsr=runs/ballsplayed*100;
        econ=(runsgiven/ballsbowled)*6;
        bowlsr=ballsbowled/wicket;
    }

    void Showinfo_Player()
    {
        team::showinfo();
        cout
                <<endl<<"            Type                           : "<<type
                <<endl<<"            Match Played                   : "<<matchplayed
                <<endl<<"            Runs Scored                    : "<<runs
                <<endl<<"            Balls Played                   : "<<ballsplayed
                <<endl<<"            Batting Average                : "<<batavg
                <<endl<<"            Batting Strike Rate            : "<<batsr
                <<endl<<"            Wickets Taken                  : "<<wicket
                <<endl<<"            Balls Bowled                   : "<<ballsbowled
                <<endl<<"            Runs Given                     : "<<runsgiven
                <<endl<<"            Economy                        : "<<econ
                <<endl<<"            Bowling Strike Rate            : "<<bowlsr
                <<endl<<"            Remark                         : ";
    }

    bool Is_Great()
    {
        if(runs>9999 || matchplayed>250 || wicket>300 || batavg>40 || batsr>110 || econ<=4.5 || bowlsr<20)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

class Coach:public team
{
private:
    string experience;
    string workteams;
    int achievements;

public:
    Coach():team(),
        experience(" "),
        workteams(" "),
        achievements(0) {}

    Coach(string n,string b,string a,string c,
          string e,string w,int ac):
        team(n,b,a,c),
        experience(e),
        workteams(w),
        achievements(ac) {}

    void Setinfo_Coach()
    {
        cout<<endl;
        team::setinfo();
        fflush(stdin);
        cout<<endl<<"         Enter Experience          : ";
        getline(cin,experience);
        cout<<endl<<"         Enter Work Team           : ";
        getline(cin,workteams);
        cout<<endl<<"         Enter Total Wining Series : ";
        cin>>achievements;
    }
    void Showinfo_Coach()
    {
        cout<<endl;
        team::showinfo();
        cout<<endl<<"            Experience                     : "<<experience
            <<endl<<"            Work Team                      : "<<workteams
            <<endl<<"            Total Wining Series            : "<<achievements
            <<endl<<"            Remark                         : ";
    }
    bool Is_Great()
    {
        if(achievements>9)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};


void Main_Menu_Function()
{
    cout
            <<endl<<"         --------------------------------------------"
            <<endl<<"         |      Welcome to ICC World Cup 2015       |"
            <<endl<<"         --------------------------------------------"
            <<endl<<"         |       1.  Match Information              |"
            <<endl<<"         |       2.  Team Information               |"
            <<endl<<"         |       3.  Stadium Information            |"
            <<endl<<"         |       4.  Search Match Schedule          |"
            <<endl<<"         |       5.  Sell Tickets                   |"
            <<endl<<"         |       6.  Exit from the System           |"
            <<endl<<"         --------------------------------------------"
            <<endl<<"         |       Only Press 1 to 6                  |"
            <<endl<<"         --------------------------------------------"
            <<endl<<"                 Enter Your Choice: ";
}

void Case1_Menu_Function()
{
    cout
            <<endl<<"         Only Press a,b,c,d"
            <<endl<<"         --------------------"
            <<endl<<"         :  a. Add Match    :"
            <<endl<<"         :  b. Show Match   :"
            <<endl<<"         :  c. Search Match :"
            <<endl<<"         :  d. Go to Home   :"
            <<endl<<"         --------------------"
            <<endl<<"            Enter Choice: ";
}

void Sell_Ticket_Function(Match objh[])
{
    int make,k;
    string tem;
    cout
            <<"         -----------------------------------"<<endl
            <<"         :   Press 1 to sell by Team 1     :"<<endl
            <<"         :   Press 2 to sell by Team 2     :"<<endl
            <<"         :   Press 3 to sell by Stadiums   :"<<endl
            <<"         :   Press 4 to sell by Date       :"<<endl
            <<"         -----------------------------------"<<endl
            <<"             Enter Your Choice: ";
    cin >> make;
    if(make == 1)
    {
        cout << "    Enter The Team 1 Name : ";
        cin >> tem;
        for(int i=0; i<Match_NUM; i++)
        {
            if(tem==objh[i].getTeam_1name())
            {
                k=i;
                break;
            }
        }
        objh[k].Sell_Ticket();
    }
    else if(make == 2)
    {
        cout << "    Enter The Team 2 Name : ";
        cin >> tem;
        for(int i=0; i<Match_NUM; i++)
        {
            if(tem==objh[i].getTeam_2name())
            {
                k=i;
                break;
            }
        }
        objh[k].Sell_Ticket();
    }
    else if(make == 3)
    {
        cout << "    Enter The Stadium Name : ";
        cin >> tem;
        for(int i=0; i<Match_NUM; i++)
        {
            if(tem==objh[i].getStadiumname())
            {
                k=i;
                break;
            }
        }
        objh[k].Sell_Ticket();
    }
    else if(make == 4)
    {
        cout << "    Enter The Date : ";
        cin >> tem;
        for(int i=0; i<Match_NUM; i++)
        {
            if(tem==objh[i].getDate())
            {
                k=i;
                break;
            }
        }
        objh[k].Sell_Ticket();
    }
}

void Search_Match_Function(Match obj[])
{
    int k,d=0,tschoice;
    string search, tem;
    string make;
    cout<<"         ---------------------"<<endl
        <<"         :  1. by Team       :"<<endl
        <<"         :  2. by Stadium    :"<<endl
        <<"         :  3. by Date       :"<<endl
        <<"         :  4. by Day Light  :"<<endl
        <<"         ---------------------"<<endl
        <<"         Enter 1 to 4 : ";
    cin>>make;
    if(make=="1")
    {
        cout<<endl<<"         Enter Team: ";
        cin>>search;
        for(int l=0; l<Match_NUM; l++)
        {
            if(search==obj[l].getTeam_1name() || search==obj[l].getTeam_2name())
            {
                obj[l].Show_Match();
                d++;
            }
        }
        if(d==0)
        {
            cout<<"         No Match Available."<<endl;
        }
    }
    else if(make=="2")
    {
        cout<<endl<<"         Enter Stadium: ";
        cin>>search;
        for(int l=0; l<Match_NUM; l++)
        {
            if(search==obj[l].getStadiumname())
            {
                obj[l].Show_Match();
                d++;
            }
        }
        if(d==0)
        {
            cout<<"         No Match Available In This Stadium."<<endl;
        }
    }
    else if(make=="3")
    {
        cout<<endl<<"         Enter Date: ";
        cin>>search;
        for(int l=0; l<Match_NUM; l++)
        {
            if(search==obj[l].getDate())
            {
                obj[l].Show_Match();
                d++;
            }
        }
        if(d==0)
        {
            cout<<"         No Match Available In This Date."<<endl;
        }
    }
    else if(make=="4")
    {
        cout<<endl<<"         Enter Daylight: ";
        cin>>search;
        for(int l=0; l<Match_NUM; l++)
        {
            if(search==obj[l].getstat())
            {
                obj[l].Show_Match();
                d++;
            }
        }
        if(d==0)
        {
            cout<<"         No Match Available In Day or D/N"<<endl;
        }
    }
    cout<<endl<<"         Do You Want To Sell Tickets?"
        <<endl<<"         1 for Yes and 2 for No"
        <<endl<<"         Enter Your Choice : ";
    cin>>tschoice;
    switch(tschoice)
    {
    case 1:
    {
        int id,tempnum;
        cout<<endl<<"         Enter Match Number : ";
        cin>>id;
        tempnum = (id - 1);
        obj[tempnum].Sell_Ticket();
        break;
    }
    case 2:
    {
        break;
    }
    }
}

void Match_Information_Function(Match obj[])
{
    for( ; ; )
    {
        string k;
        int j;
        Case1_Menu_Function();
        cin>>k;
        if(k=="a")
        {
            for( ; ; )
            {
                cout<<endl<<"Press 1 for add and 2 for end:";
                cin>>j;
                if(j==1)
                {
                    obj[Match_NUM++].addmatch();
                }
                else if(j==2)
                {
                    break;
                }
            }
        }
        else if(k=="b")
        {
            for(int i=0; i<Match_NUM; i++)
            {
                obj[i].Show_Match();
            }
        }
        else if(k=="c")
        {
            Search_Match_Function(obj);
        }
        else if(k=="d")
        {
            break;
        }
    }
}

void Player_Information_Function(Player objj[])
{
    string choice;
    int j;
    for( ; ; )
    {
        cout
                <<endl<<"         --------------------------"
                <<endl<<"         :   a. for Add Player    :"
                <<endl<<"         :   b. for Show Player   :"
                <<endl<<"         :   c. for Exit          :"
                <<endl<<"         --------------------------"
                <<endl<<"         Enter Choice : ";
        cin>>choice;
        cout<<endl<<"         -------------------------";
        if(choice=="a")
        {
            for( ; ; )
            {
                cout<<endl<<"Press 1 for add and 2 for end:";
                cin>>j;
                if(j==1)
                {
                    objj[Player_NUM++].Setinfo_Player();
                }
                else if(j==2)
                {
                    break;
                }
            }
        }
        else if(choice=="b")
        {
            for(int i=0; i<Player_NUM; i++)
            {
                objj[i].Showinfo_Player();
                if(objj[i].Is_Great()==true)
                {
                    cout<<"He shall always be remembered."<<endl;
                }
                else
                {
                    cout<<"Average."<<endl;
                }
            }
        }
        else if(choice=="c")
        {
            break;
        }
    }
}

void Coach_Information_Function(Coach objk[])
{
    string choice;
    int j;
    for( ; ; )
    {
        cout
                <<endl<<"         -------------------------"
                <<endl<<"         :   a. for Add Coach    :"
                <<endl<<"         :   b. for Show Coach   :"
                <<endl<<"         :   c. for Exit         :"
                <<endl<<"         -------------------------"
                <<endl<<"         Enter Choice : ";
        cin>>choice;
        cout<<endl<<"         -------------------------";
        if(choice=="a")
        {
            for( ; ; )
            {
                cout<<endl<<"Press 1 for add and 2 for end:";
                cin>>j;
                if(j==1)
                {
                    objk[Coach_NUM++].Setinfo_Coach();
                }
                else if(j==2)
                {
                    break;
                }
            }
        }
        else if(choice=="b")
        {
            for(int i=0; i<Coach_NUM; i++)
            {
                objk[i].Showinfo_Coach();
                if(objk[i].Is_Great()==true)
                {
                    cout<<"He shall always be remembered."<<endl;
                }
                else
                {
                    cout<<"Average."<<endl;
                }
            }
        }
        else if(choice=="c")
        {
            break;
        }
    }
}
class Stadium
{
private:
    int idcount;
    string name;
    string build;
    string capacity;
    string city;
    string surface;
    string owner;
    Stadium* Next;

public:
    Stadium()
    {
        idcount=0;
        name=" ";
        build=" ";
        capacity=" ";
        city=" ";
        surface=" ";
        owner=" ";
        Next=NULL;
    }

    void Set_Stadium(int i,string n,string b,string c,string ct,string s,string o)
    {
        idcount=i;
        name=n;
        build=b;
        capacity=c;
        city=ct;
        surface=s;
        owner=o;
    }

    void Input_Stadium()
    {
        cout<<endl<<"///////Input stadium Information////////"<<endl;
        cout<<endl<<"Enter Stadium No     : ";
        cin>>idcount;
        fflush(stdin);
        cout<<endl<<"Enter Stadium Name   : ";
        getline(cin,name);
        cout<<endl<<"Enter Build          : ";
        getline(cin,build);
        cout<<endl<<"Enter Capacity       : ";
        getline(cin,capacity);
        cout<<endl<<"Enter City           : ";
        getline(cin,city);
        cout<<endl<<"Enter Surface        : ";
        getline(cin,surface);
        cout<<endl<<"Enter Owner          : ";
        getline(cin,owner);
    }

    int countid()
    {
        return idcount;
    }
    void set_p(Stadium* pt)
    {
        Next=pt;
    }
    Stadium* GetNext()
    {
        return Next;
    }
    string get_Name()
    {
        return name;
    }
    string get_Build()
    {
        return build;
    }
    string get_Capacity()
    {
        return capacity;
    }

    string get_City()
    {
        return city;
    }

    string get_Surface()
    {
        return surface;
    }

    string get_Owner()
    {
        return owner;
    }
};

class Stadium_Linked_List
{
private:
    Stadium* first;
public:
    Stadium_Linked_List()
    {
        first=NULL;
    }

    void addStadium()
    {
        Stadium* current;
        current= new Stadium;
        current->Input_Stadium();
        current->set_p(first);
        first=current;
    }
    void showStadiums()
    {
        Stadium* temp;
        temp=first;
        while(temp!=NULL)
        {
            cout<<endl<<"----------------------------------------------------------"
                <<endl<<"////  Stadium No  "<<temp->countid()<<"  ////"<<"\t";
            cout<<endl<<"----------------------------------------------------------";
            cout<<endl<<":  "<<"Stadium Name -> "<<setw(30)<<temp->get_Name()<<"\t"<<" :";
            cout<<endl<<":  "<<"Build        -> "<<setw(30)<<temp->get_Build()<<"\t"<<" :";
            cout<<endl<<":  "<<"Capacity     -> "<<setw(30)<<temp->get_Capacity()<<"\t"<<" :";
            cout<<endl<<":  "<<"City         -> "<<setw(30)<<temp->get_City()<<"\t"<<" :";
            cout<<endl<<":  "<<"Surface      -> "<<setw(30)<<temp->get_Surface()<<"\t"<<" :";
            cout<<endl<<":  "<<"Owner        -> "<<setw(30)<<temp->get_Owner()<<"\t"<<" :"<<endl;
            temp=temp->GetNext();
        }

    }
};

int main()
{
    Match Match_Object[60];
    Stadium_Linked_List sobj;
    Player Player_Object[300];
    Coach Coach_Object[15];
    int choice;
    int r;
    for( ; ; )
    {
        Main_Menu_Function();
        cin>>choice;
        cout<<"         -----------------------------------------------"<<endl;

        switch(choice)
        {
        case 1:
        {
            Match_Information_Function(Match_Object);
            break;
        }
        case 2:
        {
            cout<<endl<<"         -------------------------------"
                <<endl<<"         :  1. for Player Information  :"
                <<endl<<"         :  2. for Coach Information   :"
                <<endl<<"         :  3. for Exit                :"
                <<endl<<"         -------------------------------"
                <<endl<<"         Enter Choice : ";
            cin>>r;
            if(r==1)
            {
                Player_Information_Function(Player_Object);
            }
            else if(r==2)
            {
                Coach_Information_Function(Coach_Object);
            }
            else if(r==3)
            {
                break;
            }

            break;
        }
        case 3:
        {
            string g;
            for( ; ; )
            {
                cout
                        <<endl<<"         ----------------------------------------------"
                        <<endl<<"         :  Enter a for Add Stadium Information.      :"
                        <<endl<<"         :  Enter b for Show Stadium Information.     :"
                        <<endl<<"         :  Enter c for Exit                          :"
                        <<endl<<"         ----------------------------------------------"
                        <<endl<<"         Enter Your Choice : ";
                cin>>g;
                if(g=="a")
                {
                    sobj.addStadium();
                }
                else if(g=="b")
                {
                    sobj.showStadiums();
                }
                else if(g=="c")
                {
                    break;
                }
            }
            break;
        }

        case 4:
        {
            Search_Match_Function(Match_Object);
            break;
        }

        case 5:
        {
            Sell_Ticket_Function(Match_Object);
            break;
        }

        case 6:
        {
            return EXIT_SUCCESS;
        }

        default:
        {
            cout
                    <<endl<<"         Please Type Correctly"
                    <<endl<<"         Enter number which is in range"
                    <<endl;
        }
        }
    }
}





