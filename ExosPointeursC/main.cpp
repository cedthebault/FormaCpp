#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <windows.h>

using namespace std;

void printStar(int n){
    for(int i = 0; i<n;i++){
        cout<<"*";
    }
}

void switch_char(char* t,int l){
    char tmp;
    for(int i=0; i<l/2 ; i++){
        tmp=t[l-1-i];
        t[l-1-i]=t[i];
        t[i]=tmp;
    }

}

void afficheResultat(int* t,int p){
    for(int i =0;i<26;i++){
        //cout<<(char)(i+97)<<":"<<t[i]<<endl;
        cout<<(char)(i+97)<<":";
        printStar(t[i]);
        cout<<endl;
    }
    cout<<"Ponctu:"<<p<<endl;
}

void init_tableau_occur(int* t){
    for(int i =0;i<26;i++){
        t[i]=0;
    }
}

char lettreRandom(){
    return (char)(rand()%(126-32)+32);
}

void init_txt_cool(char* t,int l,char p){

    //int r=rand()%(126-32);
    for(int i =0;i<l-1;i++){
        t[i]=lettreRandom();
    }
}

void w_clear() {
    COORD topLeft  = { 0, 0 };
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen;
    DWORD written;

    GetConsoleScreenBufferInfo(console, &screen);
    FillConsoleOutputCharacterA(
        console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    FillConsoleOutputAttribute(
        console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
        screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    SetConsoleCursorPosition(console, topLeft);
}

void trucTropCool(char *t,char *tc){
    int longeur=strlen(t);
    bool is=true;
    do{
        is=false;
        for(int i=0;i<longeur-1;i++){
            if(t[i]<tc[i]){
                t[i]=lettreRandom();
                is=true;
            }
            else if(t[i]>tc[i]){
                t[i]=lettreRandom();
                is=true;
            }
        }
        usleep(10000);
        //system("cls");
        //w_clear();
        //cout<<t;
        cout<<"\r"<<t;
    }while(is);
}

int main()
{
    char texte[]= "Soit un texte donne par une chaine de caracteres. Le but est de compter le nombre d'occurrences de chaque lettre sans.";
    //char texte[]= "Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Aenean commodo ligula eget dolor. Aenean massa. Cum sociis natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. Donec quam felis, ultricies nec, pellentesque eu, pretium quis, sem. Nulla consequat massa quis enim. Donec pede justo, fringilla vel, aliquet nec, vulputate eget, arcu. In enim justo, rhoncus ut, imperdiet a, venenatis vitae, justo. Nullam dictum felis eu pede mollis pretium. Integer tincidunt. Cras dapibus. Vivamus elementum semper nisi. Aenean vulputate eleifend tellus. Aenean leo ligula, porttitor eu, consequat vitae, eleifend ac, enim. Aliquam lorem ante, dapibus in, viverra quis, feugiat a, tellus. Phasellus viverra nulla ut metus varius laoreet. Quisque rutrum. Aenean imperdiet. Etiam ultricies nisi vel augue. Curabitur ullamcorper ultricies nisi. Nam eget dui. Etiam rhoncus. Maecenas tempus, tellus eget condimentum rhoncus, sem quam semper libero, sit amet adipiscing sem neque sed ipsum. Nam quam nunc, blandit vel, luctus pulvinar, hendrerit id, lorem. Maecenas nec odio et ante tincidunt tempus. Donec vitae sapien ut libero venenatis faucibus. Nullam quis ante. Etiam sit amet orci eget eros faucibus tincidunt. Duis leo. Sed fringilla mauris sit amet nibh. Donec sodales sagittis magna. Sed consequat, leo eget bibendum sodales, augue velit cursus nunc, quis gravida magna mi a libero. Fusce vulputate eleifend sapien. Vestibulum purus quam, scelerisque ut, mollis sed, nonummy id, metus. Nullam accumsan lorem in dui. Cras ultricies mi eu turpis hendrerit fringilla. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia Curae; In ac dui quis mi consectetuer lacinia. Nam pretium turpis et arcu. Duis arcu tortor, suscipit eget, imperdiet nec, imperdiet iaculis, ipsum. Sed aliquam ultrices mauris. Integer ante arcu, accumsan a, consectetuer eget, posuere ut, mauris. Praesent adipiscing. Phasellus ullamcorper ipsum rutrum nunc. Nunc nonummy metus. Vestibulum volutpat pretium libero. Cras id dui. Aenean ut eros et nisl sagittis vestibulum. Nullam nulla.";
    int longueur=strlen(texte);
    char texte_cool[longueur];
    int tabOccurLettre[26];
    char * p_texte;
    int ponctu=0;

    srand(time(NULL));
    init_tableau_occur(tabOccurLettre);
    init_txt_cool(texte_cool,longueur,' ');


    for(int i=0;i<longueur;i++){
        //majuscule
        if(texte[i]>=65 && texte[i]<=90){
            tabOccurLettre[texte[i]-65]++;
        }
        //minuscule
        else if(texte[i]>=97 && texte[i]<=122){
            tabOccurLettre[texte[i]-97]++;
        }
        //autre
        else{
            ponctu++;
        }
    }

    cout<<texte<<endl;
    afficheResultat(tabOccurLettre,ponctu);

//    for(int k=0;k<255;k++){
//        cout<<(char)k;
//    }

    char plop[]="abcdefghijkl";
    cout<<plop<<endl;
    switch_char(plop,strlen(plop));
    cout<<plop<<endl;

    trucTropCool(texte_cool,texte);
}
