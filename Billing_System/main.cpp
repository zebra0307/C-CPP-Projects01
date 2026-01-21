#include "headers/Common.h"
#include "headers/Bill.h"
#include "headers/BillingOperations.h"

int main() {
    Bill b;

    bool exit = false;
    while(!exit){
        system("cls");
        int val;

        cout<<"\tWelcome To Super Market Billing System"<<endl;
        cout<<"\t**************************************"<<endl;
        cout<<"\t\t1.Add Item."<<endl;
        cout<<"\t\t2.Print Bill."<<endl;
        cout<<"\t\t3.Exit."<<endl;
        cout<<"\t\tEnter Choice: ";
        cin>>val;

        if(val==1){
            system("cls");
            addItem(b);	
            Sleep(3000);
        }

        else if(val==2){
            printBill();
        }

        else if(val==3){
            system("cls");
            exit = true;
            cout<<"\tGood Luck!"<<endl;
            Sleep(3000);
        }	
    }

    return 0;
}