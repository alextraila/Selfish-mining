#include <iostream>
#include <cmath>
#include <time.h>
#include <stdlib.h>
using namespace std;
void minerieg(int &lant_privat,int &dist,int &lant_public,int &blocuri_selfish) {
    lant_privat += 1;
    if(dist == 0 && lant_privat == 2) {
        lant_privat = 0;
        lant_public = 0;
        blocuri_selfish += 2;
    }
}

void minericinst(int &lant_privat,int &dist,int &lant_public,int &blocuri_selfish,int &blocuri_cinst,double g) {
    lant_public += 1;
    float s;
    if(dist == 0) {
        blocuri_cinst += 1;
        s=rand()/(double)32767;
        if(lant_privat > 0 && s <= g) {
            blocuri_selfish += 1;

        }
        else
        if(lant_privat > 0 && s > g) {
            blocuri_cinst += 1;
        }
        lant_privat = 0;
        lant_public = 0;
    }
    else
    if(dist == 2) {
        blocuri_selfish += lant_privat;
        lant_public = 0;
        lant_privat = 0;
    }
}
double sim(double a, double g, long long n_simulare) {
    int dist = 0;
    int lant_privat = 0;
    int lant_public = 0;
    int blocuri_cinst = 0;
    int blocuri_selfish = 0;

    double revenue = 0;
    int blocuri_orfane = 0;
    int blocuri_totale = 0;

    float r;
    for(long long i = 1; i <= n_simulare; i++) {
        r=rand()/(double)32767;
        dist = lant_privat - lant_public;

        if (r <= a) {
            minerieg(lant_privat,dist,lant_public,blocuri_selfish);
        }
        else {
            minericinst(lant_privat,dist,lant_public,blocuri_selfish,blocuri_cinst,g);
        }
    }
    dist = lant_privat - lant_public;
    if(dist > 0) {
        blocuri_selfish += lant_privat;
        lant_public = 0;
        lant_privat = 0;
    }

    blocuri_totale = blocuri_cinst + blocuri_selfish;
    blocuri_orfane = n_simulare - blocuri_totale;

    if(blocuri_cinst || blocuri_selfish) {
        revenue = 100*(blocuri_selfish/(double)blocuri_totale);
    }
    cout<<"Blocurile validate de catre minerii cinstiti: "<< blocuri_cinst<<endl;
    cout<<"Blocurile validate de catre minerii egoisti: "<< blocuri_selfish<<endl;
    cout<<"Numarul total de blocuri minate: "<<blocuri_totale<<endl;
    cout<<"Numarul de blocuri orfane: "<< blocuri_orfane<<endl;
    cout<<"Castig: "<< revenue<<endl;
    return (blocuri_selfish/(double)blocuri_totale);

}

int main()
{
    double a=0.33;
     double  g=0.48;
     long long n_sim= 78;

    cout<<"Probabilitatea teoretica :"<<(a*(1-a)*(1-a)*(4*a+g*(1-2*a))-a*a*a)/(double)(1-a*(1+(2-a)*a))<<endl;
    cout<<"Probabilitatea simulata :"<<sim(a,g,n_sim);
    return 0;
}
