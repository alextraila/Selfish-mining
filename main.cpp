#include<iostream>
#include<string>
#include<stdlib.h>
#include<stdio.h>
#include<fstream>
using namespace std;

long long seconds_beetween(int hours, int minutes, int seconds) {
    string token;
    int token_m;
    int ok = 0;
    int l=0;
    int pos=1;
    int interval = 2;
    int a, start_h = 0, start_m = 0, start_s = 0;
    long long seconds_total = 0;
     hours = 3600*hours;
     minutes = 60*minutes;
    seconds_total = hours+ minutes + seconds;
    return seconds_total;
}
int main()
{
   int hours;
   int minutes;
   int seconds;
   int hoursx;
   int minutesx;
   int secondsx;
   int precedent;
   int pos_selfish_mining = 0;
   int x;
   int y;
   ifstream f("date.in");
    f>>hours>>minutes>>seconds;
    x=seconds_beetween(hours,minutes,seconds);
    hoursx = hours;
    minutesx = minutes;
    secondsx = seconds;
    for(int i=1 ; i < 78; i++){
        f>>hours>>minutes>>seconds;
        y=seconds_beetween(hours,minutes,seconds);
        if(x-y <= 60) {
            pos_selfish_mining++;
            cout<<"ora:"<<hoursx<<" "<<"minutul:"<<" "<<minutesx<<" "<<"secunda:"<<secondsx<<" ";
            cout<<"ora:"<<hours<<" "<<"minutul:"<<" "<<minutes<<" "<<"secunda:"<<seconds;
            cout<<endl;
            cout<<endl;
        }
        x=y;
        hoursx = hours;
        minutesx = minutes;
        secondsx = seconds;
    }
  cout<<"Nr. de blocuri succ. p.: "<<pos_selfish_mining;
    return 0;

}
