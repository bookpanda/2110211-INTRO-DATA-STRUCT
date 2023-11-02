#include<bits/stdc++.h>
using namespace std;

//init
int CoffeeOut = 0;
int TeaOut = 0;
int Change5 = 0;
int Change10 = 0;
int Change20 = 0;
int Balance = 0;
int main() {
    while(1) {
        string btn;
        cin >> btn;

        
        //multiplexer or lookup table
        //in diagram, load every possible inputs every clock?
        if((btn == "P5" || btn == "P10" || btn == "P20") && CoffeeOut==0 && TeaOut==0) {
            if(btn == "P5") addMoney(5);
            else if(btn == "P10") addMoney(10);
            else if(btn == "P20") addMoney(20);
        } else if(btn == "Pcoffee" && Balance >= 25 && CoffeeOut==0 && TeaOut==0) {
            buy(25);
            CoffeeOut = 1;
        } else if(btn == "Ptea" && Balance >= 25 && CoffeeOut==0 && TeaOut==0) {
            buy(20);
            TeaOut = 1;
        } else if(btn == "Pchange") {
            Change5 = 0;
            Change10 = 0;
            Change20 = 0;
            getChanges(); //this updates Balance to 0
            CoffeeOut = 0;
            TeaOut = 0;
        } else if(btn == "Pnext") {
            CoffeeOut = 0;
            TeaOut = 0;
        } else if(btn == "reset") {
            CoffeeOut = 0;
            TeaOut = 0;
            Balance = 0;
            Change5 = 0;
            Change10 = 0;
            Change20 = 0;
        }
    }
}

int addMoney(int amount) {
    if(!(Balance + amount > 50))
        Balance += amount;
}

int buy(int amount) {
    Balance -= amount;
}

int getChanges() {
    while(1) {
        if(Balance >= 20) {
            Change20+=1;
            Balance -= 20;
        }
    }
    while(1) {
        if(Balance >= 10) {
            Change10+=1;
            Balance -= 10;
        }
    }
    while(1) {
        if(Balance >= 5) {
            Change5+=1;
            Balance -= 5;
        }
    }
}