#include <iostream>
#include "clui.h"
#include <cstring>
#include <time.h>
#include <math.h>
#include <limits>
/*
Developed by @rouzbeh_sti
402243072
Dr. Aliakbary
Shahid Beheshti University
*/
int p1, p2, gspeed, fruit1_count=0,fruit2_count=0,bomb_count=0,bomb_count2=0,del_user,del_value=0;
int fruitx1,fruity1,fruitx2,fruity2,bombx,bomby,bombx2,bomby2, start_value=0;
using namespace std;
enum direction{STOP=0,UP,DOWN,RIGHT,LEFT};
struct Snakes
{
    int score;
    int headx;
    int heady;
    int len=3;
    int tailx[100];
    int taily[100];
    direction dir;
};
Snakes a,b;

struct Players
{
    char name[100];
    int score;
}; 
Players users[50];
const int width =60, height=25;
int user_counts=0;
void main_menu();
void swap(Players& a, Players& b){
    Players temp=a;
    a=b;
    b=temp;
}
void line(){
    int temp=get_window_cols();
    for (int i = 0; i < temp; i++)
    {
        cout<<'-';
    }
    cout<<endl;
}
void welcome(){
    clear_screen();
    change_color_rgb(62, 201, 65);
    cout<<"Welcome To The Snake Game :)\n";
    change_color_rgb(62, 67, 201);
    cout<<"Good Luck, Have Fun\n";
    reset_color();
}
void goodbye(){
    clear_screen();
    change_color_rgb(61, 37, 168);
    cout<<"See you soon :)";
    delay(2000);
    quit();
}
void print_leaderboard(){
    clear_screen();
    if (user_counts==0)
    {
        change_color_rgb(49, 148, 214);
        cout<<"You have no Users\n\n";
        reset_color();
    }
    else{
    Players temp[50];
    for (int i = 0; i < user_counts; i++){
        strcpy(temp[i].name,users[i].name);
    }
    for (int i = 0; i < user_counts; i++){
        temp[i].score=users[i].score;
    }
    for (int i = 0; i < user_counts-1; i++)
    {
        for (int j = 0; j < user_counts-1-i; j++)
        {
            if (temp[j].score<temp[j+1].score)
            {
                swap(temp[j],temp[j+1]);
            }
        }
    }
    for (int i = 0; i < user_counts; i++)
    {
        change_color_rgb(129, 240, 208);
        cout<<i+1<<" - ";
        change_color_rgb(36, 65, 212);
        cout<<temp[i].name;
        change_color_rgb(230, 14, 161);
        cout<<" ---> ";
        change_color_rgb(36, 65, 212);
        cout<< temp[i].score <<endl;
        reset_color();
    }
  }
    line();
    cout<<endl;
    change_color_rgb(209, 6, 37);
    cout<<"B - ";
    change_color_rgb(194, 171, 45);
    cout<<"Back\n";
    reset_color();
}
void leaderboard(){
    clear_screen();
    if (user_counts==0)
    {
        change_color_rgb(49, 148, 214);
        cout<<"You have no Users\n\n";
        reset_color();
    }
    else{
    Players temp[50];
    for (int i = 0; i < user_counts; i++){
        strcpy(temp[i].name,users[i].name);
    }
    for (int i = 0; i < user_counts; i++){
        temp[i].score=users[i].score;
    }
    for (int i = 0; i < user_counts-1; i++)
    {
        for (int j = 0; j < user_counts-1-i; j++)
        {
            if (temp[j].score<temp[j+1].score)
            {
                swap(temp[j],temp[j+1]);
            }
        }
    }
    for (int i = 0; i < user_counts; i++)
    {
        change_color_rgb(129, 240, 208);
        cout<<i+1<<" - ";
        change_color_rgb(36, 65, 212);
        cout<<temp[i].name;
        change_color_rgb(230, 14, 161);
        cout<<" ---> ";
        change_color_rgb(36, 65, 212);
        cout<< temp[i].score <<endl;
        reset_color();
    }
  }
  line();
  cout<<endl;
    change_color_rgb(209, 6, 37);
    cout<<"B - ";
    change_color_rgb(194, 171, 45);
    cout<<"Back\n";
    reset_color();

  char enter1;
    do
    {
     enter1 = getch();
    if (    (enter1=='b' || enter1=='B')  )
    {
        break;
    }
    else {
        change_color_rgb(250, 0, 33);
        cout<<"ERROR : Please choose 'B' to get Back\n";
        delay(700);
        clear_screen();
        print_leaderboard();
    }
    } while (!( enter1=='B'  || enter1=='b'));
    switch (enter1)
    {
    case 'b':
    case 'B': main_menu(); break;
    }
}
void change_players(Players []);
void start_game();
void print_menu(){
    clear_screen();
    change_color_rgb(30, 227, 39);
    cout<< "Main Menu : \n";
    change_color_rgb(209, 6, 37);
    cout<<"1 - ";
    change_color_rgb(194, 171, 45);
    cout<<"Start Game\n";
    change_color_rgb(209, 6, 37);
    cout<<"2 - ";
    change_color_rgb(194, 171, 45);
    cout<<"Leaderboard\n";
    change_color_rgb(209, 6, 37);
    cout<<"3 - ";
    change_color_rgb(194, 171, 45);
    cout<<"Change Players\n";
    change_color_rgb(209, 6, 37);
    cout<<"4 - ";
    change_color_rgb(194, 171, 45);
    cout<<"Exit\n";
    reset_color();
    cursor_down(10);
    change_color_rgb(170, 12, 232);
    cout<<"Developed By";
    change_color_rgb(9, 218, 222);
    cout<<" Rouzbeh Soltani\n";
    cursor_up(6);

}
void main_menu(){
    clear_screen();
    char enter1;
    change_color_rgb(30, 227, 39);
    cout<< "Main Menu : \n";
    change_color_rgb(209, 6, 37);
    cout<<"1 - ";
    change_color_rgb(194, 171, 45);
    cout<<"Start Game\n";
    change_color_rgb(209, 6, 37);
    cout<<"2 - ";
    change_color_rgb(194, 171, 45);
    cout<<"Leaderboard\n";
    change_color_rgb(209, 6, 37);
    cout<<"3 - ";
    change_color_rgb(194, 171, 45);
    cout<<"Change Players\n";
    change_color_rgb(209, 6, 37);
    cout<<"4 - ";
    change_color_rgb(194, 171, 45);
    cout<<"Exit\n";
    reset_color();
    cursor_down(10);
    change_color_rgb(170, 12, 232);
    cout<<"Developed By";
    change_color_rgb(9, 218, 222);
    cout<<" Rouzbeh Soltani\n";
    cursor_up(6);
    do
    {
    enter1 = getch();
    if ((enter1=='1' || enter1=='2' || enter1=='3' || enter1=='4'))
    {
        break;
    }
    if ( !(enter1=='1' || enter1=='2' || enter1=='3' || enter1=='4') )
    {
        change_color_rgb(250, 0, 33);
        cout<<"ERROR : Please choose one of 1-4\n";
        delay(700);
        clear_screen();
        print_menu();
    }
    } while (!(enter1=='1' || enter1=='2' || enter1=='3' || enter1=='4'));
    switch (enter1)
    {
    case '1': start_game();   break;
    case '2': leaderboard(); break;
    case '3': change_players(users); break;
    case '4': goodbye();  break;
    }

}
void print_another_name(){
    clear_screen();
    change_color_rgb(119, 0, 230);
    cout<<"Press 'N' to enter another name.\n";
    cout<<"Press 'B' to go back.\n";
    reset_color();
}
void enter_name(){
    clear_screen();
    change_color_rgb(35, 168, 8);
    cout<<"Enter user's name : ";
    change_color_rgb(52, 74, 237);
    if(del_value==1){
 cin.ignore(numeric_limits<streamsize>::max(), '\n');
 del_value--;
    }
    cin.getline(users[user_counts].name,100);
    change_color_rgb(232, 157, 16);
    cout<<"User ";
    change_color_rgb(52, 74, 237);
    cout<<users[user_counts].name;
    change_color_rgb(232, 157, 16);
    cout<<" Added."<<endl;
    user_counts++;
    delay(1000);
    clear_screen();
    change_color_rgb(35, 168, 8);
    cout<<"Want to add another?"<<endl;
    char enter1;
    change_color_rgb(119, 0, 230);
    cout<<"Press 'N' to enter another name.\n";
    cout<<"Press 'B' to go back.\n";
    reset_color();
    do
    {
    enter1 = getch();
    if ((enter1=='B' || enter1=='b' || enter1=='N' || enter1=='n'))
    {
        break;
    }
    if ( !(enter1=='B' || enter1=='b' || enter1=='N' || enter1=='n') )
    {
        change_color_rgb(250, 0, 33);
        cout<<"ERROR : Please choose one of 'N' or 'B' \n";
        delay(700);
        clear_screen();
        print_another_name();
    }
    } while (!(enter1=='1' || enter1=='2' || enter1=='3' || enter1=='4'));
    switch (enter1)
    {
    case 'b':
    case 'B': main_menu();break;
    case 'n':
    case 'N': enter_name();break;
    }

}
void print_speed(){
    clear_screen();
    change_color_rgb(24, 3, 255);
    cout<<"Choose your game speed : \n\n";
    change_color_rgb(252, 18, 139);
    cout<<"1- ";
    change_color_rgb(0, 255, 0);
    cout<<"Slow\n";
    change_color_rgb(252, 18, 139);
    cout<<"2- ";
    change_color_rgb(255, 208, 0);
    cout<<"Medium\n";
    change_color_rgb(252, 18, 139);
    cout<<"3- ";
    change_color_rgb(255, 0, 0);
    cout<<"Fast\n";
    reset_color();
}
void speed(){
    clear_screen();
    char enter1;
    change_color_rgb(24, 3, 255);
    cout<<"Choose your game speed : \n\n";
    change_color_rgb(252, 18, 139);
    cout<<"1- ";
    change_color_rgb(0, 255, 0);
    cout<<"Slow\n";
    change_color_rgb(252, 18, 139);
    cout<<"2- ";
    change_color_rgb(255, 208, 0);
    cout<<"Medium\n";
    change_color_rgb(252, 18, 139);
    cout<<"3- ";
    change_color_rgb(255, 0, 0);
    cout<<"Fast\n";
    reset_color();
    do
    {
    enter1 = getch();
    if ((enter1=='1' || enter1=='2' || enter1=='3'))
    {
        break;
    }
    if ( !(enter1=='1' || enter1=='2' || enter1=='3') )
    {
        change_color_rgb(250, 0, 33);
        cout<<"ERROR : Please choose one of '1' or '2' or '3' \n";
        delay(700);
        clear_screen();
        print_speed();
    }
    } while (!(enter1=='1' || enter1=='2' || enter1=='3'));
    switch (enter1)
    {
    case '1':
    start_value=1;
    gspeed=3;
    start_game();
    ;break;
    case '2':
    start_value=1;
    gspeed=2;
    start_game();
break;
    case '3':
    start_value=1;
     start_game();
gspeed=1;break;
    }

}
void final_delete(int num){
    clear_screen();
    change_color_rgb(171, 86, 2);
    cout<<"User ";
    change_color_rgb(14, 201, 167);
    cout<<users[num].name;
    change_color_rgb(171, 86, 2);
    cout<<" Deleted.";
    for (int i = num; i < user_counts-1; i++)
    {
        users[i]=users[i+1];
    }
    user_counts--;
    del_value=1;
    delay(1200);
    change_players(users);
}
void print_rusure(int num){
    clear_screen();
    change_color_rgb(199, 158, 62);
    cout<<"Are you sure you want to delete user ";
    change_color_rgb(39, 214, 85);
    cout<<users[num].name;
    change_color_rgb(199, 158, 62);
    cout<<" ?\n\n";
    reset_color();
    line();
    cursor_down(1);
    change_color_rgb(209, 6, 37);
    cout<<"Y - ";
    change_color_rgb(194, 171, 45);
    cout<<"Yes\n";
    change_color_rgb(209, 6, 37);
    cout<<"N - ";
    change_color_rgb(194, 171, 45);
    cout<<"No\n";
    reset_color();

}
void rusure(int num){
    clear_screen();
    change_color_rgb(199, 158, 62);
    cout<<"Are you sure you want to delete user ";
    change_color_rgb(39, 214, 85);
    cout<<users[num-1].name;
    change_color_rgb(199, 158, 62);
    cout<<" ?\n\n";
    reset_color();
    line();
    cursor_down(1);
    change_color_rgb(209, 6, 37);
    cout<<"Y - ";
    change_color_rgb(194, 171, 45);
    cout<<"Yes\n";
    change_color_rgb(209, 6, 37);
    cout<<"N - ";
    change_color_rgb(194, 171, 45);
    cout<<"No\n";
    reset_color();
    char enter1;
    do
    {
     enter1 = getch();
    if (    (enter1=='y' || enter1=='Y' || enter1=='n' || enter1=='N')  )
    {
        break;
    }
    else {
        change_color_rgb(250, 0, 33);
        cout<<"ERROR : Please choose one of 'Y' or 'N'\n";
        delay(700);
        clear_screen();
        print_rusure(num);
    }
    } while (!(enter1=='N' || enter1=='n' || enter1=='y' || enter1=='Y'));
    num--;
    switch (enter1)
    {
    case 'Y':
    case 'y': final_delete(num); break;
    case 'n':
    case 'N': change_players(users); break;
    }

}
void continue_delete(){
        clear_screen();
        change_color_rgb(240, 146, 139);
        cout<<"You have ";
        change_color_rgb(20, 156, 110);
        cout<<user_counts;
        change_color_rgb(240, 146, 139);
        cout<<" Users : "<<endl;
        cursor_down(1);
        for (int i = 1; i <= user_counts; i++)
        {
            change_color_rgb(14, 232, 61);
            cout<<i<<". "<<users[i-1].name<<endl;
            reset_color();
        }
        cursor_down(1);
    
    line();
    cursor_down(1);
    change_color_rgb(181, 209, 0);
    cout<<"Select the user you want to delete : ";
    change_color_rgb(209, 146, 0);
    cin>>del_user;
     if (del_user>user_counts || del_user==0)
        {
        change_color_rgb(255, 0, 21);
        cout<<"Invalid selection, select another one.\n";
        delay(2000);
        continue_delete();
        }
        else{
            rusure(del_user);
        }
}
void print_delete_user(){
    clear_screen();
    char enter1;
    change_color_rgb(119, 0, 230);
    cout<<"Press 'D' to delete a user.\n";
    cout<<"Press 'B' to go back.\n";
    reset_color();
}
void delete_user(){
    clear_screen();
    char enter1;
    change_color_rgb(119, 0, 230);
    cout<<"Press 'D' to delete a user.\n";
    cout<<"Press 'B' to go back.\n";
    reset_color();
    do
    {
    enter1 = getch();
    if ((enter1=='B' || enter1=='b' || enter1=='d' || enter1=='D'))
    {
        break;
    }
    if ( !(enter1=='B' || enter1=='b' || enter1=='D' || enter1=='d') )
    {
        change_color_rgb(250, 0, 33);
        cout<<"ERROR : Please choose one of 'D' or 'B' \n";
        delay(700);
        clear_screen();
        print_delete_user();
    }
    } while (!(enter1=='B' || enter1=='b' || enter1=='D' || enter1=='d'));
    switch (enter1)
    {
    case 'b':
    case 'B': change_players(users);break;
    case 'd':
    case 'D': continue_delete();break;
    }
}

void print_create_user(){
    clear_screen();
    char enter1;
    change_color_rgb(119, 0, 230);
    cout<<"Press 'N' to enter name.\n";
    cout<<"Press 'B' to go back.\n";
}
void create_user(){
    clear_screen();
    char enter1;
    change_color_rgb(119, 0, 230);
    cout<<"Press 'N' to enter name.\n";
    cout<<"Press 'B' to go back.\n";
    reset_color();
    do
    {
    enter1 = getch();
    if ((enter1=='B' || enter1=='b' || enter1=='N' || enter1=='n'))
    {
        break;
    }
    if ( !(enter1=='B' || enter1=='b' || enter1=='N' || enter1=='n') )
    {
        change_color_rgb(250, 0, 33);
        cout<<"ERROR : Please choose one of 'N' or 'B' \n";
        delay(700);
        clear_screen();
        print_create_user();
    }
    } while (!(enter1=='1' || enter1=='2' || enter1=='3' || enter1=='4'));
    switch (enter1)
    {
    case 'b':
    case 'B': change_players(users);break;
    case 'n':
    case 'N': enter_name();break;
    }
    
}
void print_change_players(){
    clear_screen();
    if (user_counts==0)
    {
        change_color_rgb(49, 148, 214);
        cout<<"You have no users\n";
        cursor_down(1);
        reset_color();
    }
    else{
        change_color_rgb(240, 146, 139);
        cout<<"You have ";
        change_color_rgb(20, 156, 110);
        cout<<user_counts;
        change_color_rgb(240, 146, 139);
        cout<<" Users : "<<endl;
        cursor_down(1);
        for (int i = 1; i <= user_counts; i++)
        {
            change_color_rgb(14, 232, 61);
            cout<<i<<". "<<users[i-1].name<<endl;
            reset_color();
        }
        cursor_down(1);
    }
    line();
    cursor_down(1);
    change_color_rgb(209, 6, 37);
    cout<<"N - ";
    change_color_rgb(194, 171, 45);
    cout<<"Create new user\n";
    change_color_rgb(209, 6, 37);
    cout<<"B - ";
    change_color_rgb(194, 171, 45);
    cout<<"Back\n";
    reset_color();
    
}
void change_players(Players users[]){
    char enter1;
    clear_screen();
    if (user_counts==0)
    {
        change_color_rgb(49, 148, 214);
        cout<<"You have no users\n";
        cursor_down(1);
        reset_color();
    line();
    cursor_down(1);
    change_color_rgb(209, 6, 37);
    cout<<"N - ";
    change_color_rgb(194, 171, 45);
    cout<<"Create new user\n";
    change_color_rgb(209, 6, 37);
    cout<<"B - ";
    change_color_rgb(194, 171, 45);
    cout<<"Back\n";
    reset_color();
    do
    {
     enter1 = getch();
    if (    (enter1=='N' || enter1=='B' || enter1=='n' || enter1=='b')  )
    {
        break;
    }
    else {
        change_color_rgb(250, 0, 33);
        cout<<"ERROR : Please choose one of 'N' or 'B'\n";
        delay(700);
        clear_screen();
        print_change_players();
    }
    } while (!(enter1=='N' || enter1=='B' || enter1=='n' || enter1=='b'));
    switch (enter1)
    {
    case 'b':
    case 'B': main_menu(); break;
    case 'n':
    case 'N': create_user(); break;
    }

    }
    else{
        change_color_rgb(240, 146, 139);
        cout<<"You have ";
        change_color_rgb(20, 156, 110);
        cout<<user_counts;
        change_color_rgb(240, 146, 139);
        cout<<" Users : "<<endl;
        cursor_down(1);
        for (int i = 1; i <= user_counts; i++)
        {
            change_color_rgb(14, 232, 61);
            cout<<i<<". "<<users[i-1].name<<endl;
            reset_color();
        }
        cursor_down(1);
    
    line();
    cursor_down(1);
    change_color_rgb(209, 6, 37);
    cout<<"D - ";
    change_color_rgb(194, 171, 45);
    cout<<"Delete a user\n";
    change_color_rgb(209, 6, 37);
    cout<<"N - ";
    change_color_rgb(194, 171, 45);
    cout<<"Create new user\n";
    change_color_rgb(209, 6, 37);
    cout<<"B - ";
    change_color_rgb(194, 171, 45);
    cout<<"Back\n";
    reset_color();
    do
    {
     enter1 = getch();
    if (    (enter1=='N' || enter1=='B' || enter1=='n' || enter1=='b' || enter1=='d'|| enter1=='D')  )
    {
        break;
    }
    else {
        change_color_rgb(250, 0, 33);
        cout<<"ERROR : Please choose one of 'N' or 'B' or 'D'\n";
        delay(700);
        clear_screen();
        print_change_players();
    }
    } while (!(enter1=='N' || enter1=='B' || enter1=='n' || enter1=='b' || enter1=='d'|| enter1=='D'));
    switch (enter1)
    {
    case 'b':
    case 'B': main_menu(); break;
    case 'n':
    case 'N': create_user(); break;
    case 'd':
    case 'D': delete_user(); break;
    }
  }
}
void print_confirm(){
            clear_screen();
            change_color_rgb(69, 36, 255);
            cout<<"You Selected ";
            change_color_rgb(34, 45, 201);
            cout<<users[p1].name;
            change_color_rgb(69, 36, 255);
            cout<<" and ";
            change_color_rgb(189, 9, 9);
            cout<<users[p2].name<<".\n"<<endl;
            change_color_rgb(247, 141, 20);
            cout<<"Proceed?\n\n";
    line();
    cursor_down(1);
    change_color_rgb(209, 6, 37);
    cout<<"Y - ";
    change_color_rgb(194, 171, 45);
    cout<<"Yes\n";
    change_color_rgb(209, 6, 37);
    cout<<"N - ";
    change_color_rgb(194, 171, 45);
    cout<<"No\n";
    reset_color();

}
void con_choose_player(){
    clear_screen();
        change_color_rgb(0, 191, 255);
        cout<<"Your users : \n\n";
        for (int i = 1; i <= user_counts; i++)
        {
            change_color_rgb(14, 232, 61);
            cout<<i<<". "<<users[i-1].name<<endl;
            reset_color();
        }
        cursor_down(1);
        line();
        cursor_down(1);
        change_color_rgb(255, 196, 0);
        cout<<"Select player 1 : ";
        cin>>p1;
        cout<<"\nSelect player 2 : ";
        cin>>p2;
        p1--;
        p2--;
        reset_color();
        if (p1==p2)
        {
            change_color_rgb(255, 0, 21);
            cout<<"You've already selected that user, select another one.\n";
            delay(2000);
            con_choose_player();
        }
        else if (p1>=user_counts || p2>=user_counts || p1==-1 || p2==-1)
        {
        change_color_rgb(255, 0, 21);
        cout<<"Invalid selection, select another one.\n";
        delay(2000);
        con_choose_player();
        }
        else{
            char enter1;
            clear_screen();
            change_color_rgb(110, 168, 24);
            cout<<"You Selected ";
            change_color_rgb(34, 45, 201);
            cout<<users[p1].name;
            change_color_rgb(110, 168, 24);
            cout<<" and ";
            change_color_rgb(189, 9, 9);
            cout<<users[p2].name<<"\n"<<endl;
            change_color_rgb(247, 141, 20);
            cout<<"Proceed?\n\n";
            reset_color();
    line();
    cursor_down(1);
    change_color_rgb(209, 6, 37);
    cout<<"Y - ";
    change_color_rgb(194, 171, 45);
    cout<<"Yes\n";
    change_color_rgb(209, 6, 37);
    cout<<"N - ";
    change_color_rgb(194, 171, 45);
    cout<<"No\n";
    reset_color();
    do
    {
     enter1 = getch();
    if (    (enter1=='y' || enter1=='Y' || enter1=='n' || enter1=='N')  )
    {
        break;
    }
    else {
        change_color_rgb(250, 0, 33);
        cout<<"ERROR : Please choose one of 'Y' or 'N'\n";
        delay(700);
        clear_screen();
        print_confirm();
    }
    } while (!(enter1=='N' || enter1=='n' || enter1=='y' || enter1=='Y'));
    switch (enter1)
    {
    case 'Y':
    case 'y': speed(); break;
    case 'n':
    case 'N': con_choose_player(); break;
    }

  }
}
void print_choose_player(){
        clear_screen();
    if (user_counts==0)
{
        change_color_rgb(49, 148, 214);
        cout<<"You have no users\n";
        cursor_down(1);
        reset_color();
        
    line();
    cursor_down(1);
    change_color_rgb(209, 6, 37);
    cout<<"N - ";
    change_color_rgb(194, 171, 45);
    cout<<"Create new user\n";
    change_color_rgb(209, 6, 37);
    cout<<"B - ";
    change_color_rgb(194, 171, 45);
    cout<<"Back\n";
    reset_color();
}
 else{
        change_color_rgb(0, 191, 255);
        cout<<"Your users : \n\n";
        for (int i = 1; i <= user_counts; i++)
        {
            change_color_rgb(14, 232, 61);
            cout<<i<<". "<<users[i-1].name<<endl;
            reset_color();
        }
        cursor_down(1);
        line();
        cursor_down(1);
    change_color_rgb(209, 6, 37);
    cout<<"C - ";
    change_color_rgb(194, 171, 45);
    cout<<"Continue\n";
    change_color_rgb(209, 6, 37);
    cout<<"N - ";
    change_color_rgb(194, 171, 45);
    cout<<"Create new user\n";
    change_color_rgb(209, 6, 37);
    cout<<"B - ";
    change_color_rgb(194, 171, 45);
    cout<<"Back\n";
    reset_color();
}
}
void choose_player(){
    char enter1;
    clear_screen();
    if (user_counts==0 || user_counts==1)
{
        change_color_rgb(49, 148, 214);
        cout<<"You don't have enough users\n";
        cursor_down(1);
        reset_color();
    line();
    cursor_down(1);
    change_color_rgb(209, 6, 37);
    cout<<"N - ";
    change_color_rgb(194, 171, 45);
    cout<<"Create new user\n";
    change_color_rgb(209, 6, 37);
    cout<<"B - ";
    change_color_rgb(194, 171, 45);
    cout<<"Back\n";
    reset_color();
    do
    {
     enter1 = getch();
    if (    (enter1=='N' || enter1=='B' || enter1=='n' || enter1=='b')  )
    {
        break;
    }
    else {
        change_color_rgb(250, 0, 33);
        cout<<"ERROR : Please choose one of 'N' or 'B'\n";
        delay(700);
        clear_screen();
        print_choose_player();
    }
    } while (!(enter1=='N' || enter1=='B' || enter1=='n' || enter1=='b'));
    switch (enter1)
    {
    case 'b':
    case 'B': main_menu(); break;
    case 'n':
    case 'N': create_user(); break;
    }
}
   
    else{
        change_color_rgb(0, 191, 255);
        cout<<"Your users : \n\n";
        for (int i = 1; i <= user_counts; i++)
        {
            change_color_rgb(14, 232, 61);
            cout<<i<<". "<<users[i-1].name<<endl;
            reset_color();
        }
        cursor_down(1);
        line();
        cursor_down(1);
    change_color_rgb(209, 6, 37);
    cout<<"C - ";
    change_color_rgb(194, 171, 45);
    cout<<"Continue\n";
    change_color_rgb(209, 6, 37);
    cout<<"N - ";
    change_color_rgb(194, 171, 45);
    cout<<"Create new user\n";
    change_color_rgb(209, 6, 37);
    cout<<"B - ";
    change_color_rgb(194, 171, 45);
    cout<<"Back\n";
    reset_color();
    do
    {
     enter1 = getch();
    if ( (enter1=='N' || enter1=='B' || enter1=='n' || enter1=='b' || enter1=='c' || enter1=='C')  )
    {
        break;
    }
    else {
        change_color_rgb(250, 0, 33);
        cout<<"ERROR : Please choose one of 'N' or 'B' or 'C'\n";
        delay(700);
        clear_screen();
        print_choose_player();
    }
    } while (!(enter1=='N' || enter1=='B' || enter1=='n' || enter1=='b'));
    switch (enter1)
    {
    case 'b':
    case 'B': main_menu(); break;
    case 'n':
    case 'N': create_user(); break;
    case 'C':
    case 'c': con_choose_player() ;break;
    }
   }
}
void bomb (){
    if (bomb_count==0)
    {
        srand(time(NULL));
        bombx=rand()%(width-1);
        bomby=rand()%(height-1);
        bomb_count=1;
        if (bombx==0 || bomby==0)
        {
            bomb_count=0;
            bomb();
        }
        
    }
}
void bomb2() {
    if (bomb_count2 == 0) {
        bool validPosition;
        do {
            bombx2 = rand() % (width - 1);
            bomby2 = rand() % (height - 1);
            validPosition = true;

            if ((bombx2 == 0 || bomby2 == 0) || (bombx2 == bombx && bomby2 == bomby)) {
                validPosition = false;
            }
        } while (!validPosition);

        bomb_count2 = 1;
    }
}
void fruit1(){
    if (fruit1_count==0)
    {
        do{
        srand(time(NULL));
        fruitx1=rand()%(width-1);
        fruity1=rand()%(height-1);
        fruit1_count=1;
        }while( (fruitx1 == bombx && fruity1 == bomby) || (fruitx1==0 || fruity1==0));
    }
}
void fruit2(){
    if (fruit2_count==0)
    {
        do{
        srand(time(NULL));
        fruitx2=rand()%(width-1);
        fruity2=rand()%(height-1);
        fruit2_count=1;
        }while( (fruitx2 == bombx && fruity2 == bomby) || (fruitx2==0 || fruity2==0) || (fruitx2==fruitx1 && fruity2==fruity1));
    }
}
void lost(int cause){
    start_value=0;
    del_value=1;
    clear_screen();
    change_color_rgb(255, 0, 0);
    cout<<"Game Over !\n\n"<<endl;
    delay(1000);
    switch (cause)
    {
    case 1:
        change_color_rgb(34, 45, 201);
        cout<<users[p1].name;
        change_color_rgb(0, 255, 255);
        cout<<" just had an unexpected meet-and-greet with the wall. Better luck next time avoiding those wall parties!";
        reset_color();
      break;
    case 2:
        change_color_rgb(189, 9, 9);
        cout<<users[p2].name;
        change_color_rgb(0, 255, 255);
        cout<<" just had an unexpected meet-and-greet with the wall. Better luck next time avoiding those wall parties!";
        reset_color();

      break;
    case 3: 
        change_color_rgb(0, 255, 255);
        cout<<" Oh dear, ";
        change_color_rgb(34, 45, 201);
        cout<<users[p1].name;
        change_color_rgb(0, 255, 255);
        cout<<" has just made a meal out of itself. A case of mistaken identity, perhaps? Better luck next time!";
        reset_color();
    break;
    case 4: 
        change_color_rgb(0, 255, 255);
        cout<<" Oh dear, ";
        change_color_rgb(189, 9, 9);
        cout<<users[p2].name;
        change_color_rgb(0, 255, 255);
        cout<<" has just made a meal out of itself. A case of mistaken identity, perhaps? Better luck next time!";
        reset_color();
    break;
    case 5:
    change_color_rgb(0, 255, 255);
    cout<<"Whoops! Looks like ";
    change_color_rgb(34, 45, 201);
    cout<<users[p1].name;
    change_color_rgb(0, 255, 255);
    cout<<" mistook ";
    change_color_rgb(189, 9, 9);
    cout<<users[p2].name;
    change_color_rgb(0, 255, 255);
    cout<<"'s tail for the dinner bell. friendly tip: not all tails are snacks! ";
    reset_color();
     break;
    case 6: 
    change_color_rgb(0, 255, 255);
    cout<<"Whoops! Looks like ";
    change_color_rgb(189, 9, 9);
    cout<<users[p2].name;
    change_color_rgb(0, 255, 255);
    cout<<" mistook ";
    change_color_rgb(34, 45, 201);
    cout<<users[p1].name;
    change_color_rgb(0, 255, 255);
    cout<<"'s tail for the dinner bell. friendly tip: not all tails are snacks! ";
    reset_color();
    break;
    case 7: 
    change_color_rgb(0, 255, 255);
    cout<<"Looks like ";
    change_color_rgb(34, 45, 201);
    cout<<users[p1].name;
    change_color_rgb(0, 255, 255);
    cout<<" just went out with a bang, literally! Note to self: bombs are not part of a balanced diet.";
    reset_color();
    break;
    case 8:
    change_color_rgb(0, 255, 255);
    cout<<"Looks like ";
    change_color_rgb(189, 9, 9);
    cout<<users[p2].name;
    change_color_rgb(0, 255, 255);
    cout<<" just went out with a bang, literally! Note to self: bombs are not part of a balanced diet.";
    reset_color();
     break;
    case 9:
    change_color_rgb(0, 255, 255);
    cout<<"Wow! The snakes just smacked heads!";
    reset_color();
    break;
    }
    delay(2000);
    cout<<endl<<endl;
    line();
    cout<<endl<<endl;
    change_color_rgb(34, 45, 201);
    cout<<users[p1].name;
    change_color_rgb(138, 209, 139);
    cout<<" ---> ";
    change_color_rgb(0, 255, 255);
    cout<<a.score;
    cursor_forward(20);
    change_color_rgb(189, 9, 9);
    cout<<users[p2].name;
    change_color_rgb(138, 209, 139);
    cout<<" ---> ";
    change_color_rgb(0, 255, 255);
    cout<<b.score;
    reset_color();
    delay(1000);
    cout<<endl<<endl;
    if (a.score==b.score)
    {
        change_color_rgb(232, 222, 39);
        cout<<"It's a tie game! Looks like we've got a neck-and-neck race here!\n";
        reset_color();
    }
    if (a.score>b.score)
    {
        change_color_rgb(232, 222, 39);
        cout<<"The game has a hero, and it's ";
        change_color_rgb(34, 45, 201);
        cout<<users[p1].name;
        change_color_rgb(232, 222, 39);
        cout<<"! They've outsmarted ";
        change_color_rgb(189, 9, 9);
        cout<<users[p2].name;
        change_color_rgb(232, 222, 39);
        cout<<" in this epic battle of wits. Hats off to the winner!";
        reset_color();
    }
    if (a.score<b.score)
    {
        change_color_rgb(232, 222, 39);
        cout<<"The game has a hero, and it's ";
        change_color_rgb(189, 9, 9);
        cout<<users[p2].name;
        change_color_rgb(232, 222, 39);
        cout<<"! They've outsmarted ";
        change_color_rgb(34, 45, 201);
        cout<<users[p1].name;
        change_color_rgb(232, 222, 39);
        cout<<" in this epic battle of wits. Hats off to the winner!";
        reset_color();
    }
    delay(3500);
    leaderboard();
}
void input() {
    if (kbhit()) {
        int ch = getch();

        if (ch == 224 || ch == 0) {
            ch = getch();  
            switch (ch) {
                case 72: 
                if(b.dir!=DOWN)
                b.dir = UP;
                 break;  
                case 80: 
                if(b.dir!=UP)
                b.dir = DOWN;
                 break; 
                case 77:
                if(b.dir!=LEFT)
                 b.dir = RIGHT;
                  break;
                case 75: 
                if(b.dir!=RIGHT)
                b.dir = LEFT;
                 break;
            }
        } else {
            // Handle WASD for Snake A
            switch (ch) {
                case 'w':
                case 'W': 
                if(a.dir!=DOWN)
                a.dir = UP;
                 break;
                case 's':
                case 'S': 
                if(a.dir!=UP)
                a.dir = DOWN; 
                break;
                case 'd':
                case 'D':
                if(a.dir!=LEFT)
                 a.dir = RIGHT; 
                 break;
                case 'a':
                case 'A': 
                if(a.dir!=RIGHT)
                a.dir = LEFT; 
                break;
            }
        }
    }
}
void movea(){
    int alastx=a.tailx[0];
    int alasty=a.taily[0];

    a.tailx[0]=a.headx;
    a.taily[0]=a.heady;
    int alast2x,alast2y;
    for (int i = 1; i < a.len; i++)
    {
        alast2x=a.tailx[i];
        alast2y=a.taily[i];
        a.tailx[i]=alastx;
        a.taily[i]=alasty;
        alastx=alast2x;
        alasty=alast2y;
    }
    switch (a.dir){
    case UP:a.heady--;  break;
    case DOWN:a.heady++;  break;
    case RIGHT:a.headx++;  break;
    case LEFT:a.headx--;  break;
    default: break;
    }
}
void moveb(){
    int blastx=b.tailx[0];
    int blasty=b.taily[0];
    b.tailx[0]=b.headx;
    b.taily[0]=b.heady;
    int blast2x,blast2y;
    for (int i = 1; i < b.len; i++)
    {
        blast2x=b.tailx[i];
        blast2y=b.taily[i];
        b.tailx[i]=blastx;
        b.taily[i]=blasty;
        blastx=blast2x;
        blasty=blast2y;
    }
    switch (b.dir){
    case UP:b.heady--;  break;
    case DOWN:b.heady++;  break;
    case RIGHT:b.headx++;  break;
    case LEFT:b.headx--;  break;
    default: break;
    }
}
void start_game(){
    clear_screen();
    if(start_value==0)
       choose_player();
    a.headx=15;
    a.heady=10;
    b.headx=45;
    b.heady=10;
    a.score=0;
    b.score=0;
    a.len=3;
    b.len=3;
    a.tailx[0]=a.headx;
    a.taily[0]=a.heady+1;
    a.tailx[1]=a.headx;
    a.taily[1]=a.heady+2;
    a.tailx[2]=a.headx;
    a.taily[2]=a.heady+3;
    b.tailx[0]=b.headx;
    b.taily[0]=b.heady+1;
    b.tailx[1]=b.headx;
    b.taily[1]=b.heady+2;
    b.tailx[2]=b.headx;
    b.taily[2]=b.heady+3;
    bool gameOver=false;
    a.dir=RIGHT;
    b.dir=LEFT;
    while (!gameOver)
    {   //p1
    flush();
        clear_screen();
        if (a.headx<=0 || a.headx>=width || a.heady<0 || a.heady>=height)//a biroon
        {
            lost(1);
            break;
        }
        if (b.headx<=0 || b.headx>=width || b.heady<0 || b.heady>=height) // b biroon
        {
            lost(2);
            break;
        }
        for (int i = 0; i < a.len; i++) //a be khodesh
        {
            if (a.headx==a.tailx[i] && a.heady==a.taily[i])
            {
            lost(3);
            break;  
            }
        }
        for (int i = 0; i < b.len; i++) // b be khodesh
        {
            if (b.headx==b.tailx[i] && b.heady==b.taily[i])
            {
            lost(4);
            break;
            }
        }
        for (int i = 0; i < b.len; i++) // a be b
        {
            if (a.headx==b.tailx[i] && a.heady==b.taily[i])
            {
            lost(5);
            break;

            }
        }
        for (int i = 0; i < b.len; i++) // b be a
        {
            if (b.headx==a.tailx[i] && b.heady==a.taily[i])
            {
            lost(6);
            break;
            }
        }
        if (a.headx==bombx && a.heady==bomby) //a be bomb
        {
        lost(7);
        break;
        }
        if (b.headx==bombx && b.heady==bomby) //b be bomb
        {
        lost(8);
        break;
        }
        if (a.headx==bombx2 && a.heady==bomby2) //a be bomb
        {
        lost(7);
        break;
        }
        if (b.headx==bombx2 && b.heady==bomby2) //b be bomb
        {
        lost(8);
        break;
        }
        if (a.headx==b.headx && a.heady==b.heady)
        {
        lost(9);
        break;
        }
        

        bomb();
        bomb2();
        fruit1();
        fruit2();
        cursor_forward(3);
        change_color_rgb(34, 45, 201);
        cout<<users[p1].name;
        change_color_rgb(155, 242, 209);
        cout<<"  ==>  ";
        change_color_rgb(222, 80, 235);
        cout<<a.score;
        //p2
        cursor_forward(30);
        change_color_rgb(189, 9, 9);
        cout<<users[p2].name;
        change_color_rgb(155, 242, 209);
        cout<<"  ==>  ";
        change_color_rgb(222, 80, 235);
        cout<<b.score<<endl;
        reset_color();
        for (int i = 0; i < width; i++)
        {
            cout<<"-";
        }
        cout<<endl;
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                if (j==0 || j==width-1)
                    cout<<"|";
                else if (j==a.headx && i==a.heady)
                {
                    change_color_rgb(34, 45, 201);
                    cout<<"0";
                    reset_color();
                }
                else if (j==b.headx && i==b.heady)
                {
                    change_color_rgb(189, 9, 9);
                    cout<<"0";
                    reset_color();
                }
                else if(j==fruitx1&& i==fruity1)
                {
                    change_color_rgb(0, 255, 0);
                    cout<<"$";
                    reset_color();
                }
                else if(j==fruitx2&& i==fruity2)
                {
                    change_color_rgb(0, 255, 0);
                    cout<<"$";
                    reset_color();
                }
                else if(j==bombx && i==bomby)
                {
                    change_color_rgb(252, 3, 28);
                    cout<<"*";
                    reset_color();
                }
                else if(j==bombx2 && i==bomby2)
                {
                    change_color_rgb(252, 3, 28);
                    cout<<"*";
                    reset_color();
                }
                else{
                    bool space=false;
                    for (int k = 0; k < a.len; k++)
                    {
                        if (j==a.tailx[k] && i==a.taily[k])
                        {
                            change_color_rgb(34, 45, 201);
                            cout<<"o";
                            space=true;
                            reset_color();
                        }
                    }
                    for (int z = 0; z < b.len; z++)
                    {
                        if (j==b.tailx[z] && i==b.taily[z])
                        {
                            change_color_rgb(189, 9, 9);
                            space=true;
                            cout<<"o";
                            reset_color();
                        }
                    }
                    if(!space){
                    cout<<" ";
                    }
                    
                }
                
            }
            cout<<endl;
        }
        for (int i = 0; i < width; i++)
        {
            cout<<"-";
        }
        if (a.headx==fruitx1 && a.heady==fruity1)
        {
            fruit1_count--;
            a.score++;
            users[p1].score++;
            a.len++;
        }
        if (b.headx==fruitx1 && b.heady==fruity1)
        {
            fruit1_count--;
            b.score++;
            users[p2].score++;
            b.len++;
        }
        if (a.headx==fruitx2 && a.heady==fruity2)
        {
            fruit2_count--;
            a.score++;
            users[p1].score++;
            a.len++;
        }
        if (b.headx==fruitx2 && b.heady==fruity2)
        {
            fruit2_count--;
            b.score++;
            users[p2].score++;
            b.len++;
        }
        //draw ends
        cout<<endl;
        input();
        moveb();
        movea();
        cursor_to_pos(height+4,0);
        reset_color();
        change_color_rgb(9, 218, 222);
        cout<<"Guide : ";
        cursor_to_pos(height+6,0);
        change_color_rgb(34, 45, 201); 
        cout<<users[p1].name<<":   W";
        cursor_down(1);
        cursor_backward(3);
        cout<<"A S D";
        reset_color();
        cursor_up(1);
        cursor_forward(30);
        change_color_rgb(189, 9, 9); 
        cout<<users[p2].name<<":  ARROW KEYS";
        cursor_to_pos(height+7,0);

        switch (gspeed)
        {
        case 1:delay(50); break; // fast
        case 2:delay(100); break; // meduim
        case 3:delay(150); break; //slow
        }
        }
}

int main(){
    init_clui();
    welcome();
    delay(1000);
    clear_screen();
    main_menu();
}
