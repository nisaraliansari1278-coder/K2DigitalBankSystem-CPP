 #include <iostream>
#include <conio.h>
#include <fstream>
using namespace std;

// ----- DATA -----
string name[5] = {"Nisar Ali","Kamran Ali","Tahseenullah","Sajjad Ali","Imran Hashim"};
int pin[5] = {1234,2345,3456,4567,5678};
int account_balance[5] = {400000,210000,150000,100000,300000};

int user_index = -1;


// ====================== LOGIN FUNCTION ==================
void login() {

    while(true){  
        string names;
        cout<<"enter your name"<<endl;
        getline(cin,names);

        int pins;
        cout<<"enter your 4 digit pin\n";
        cin>>pins;

        for(int i=0;i<5;i++){
            if(names==name[i] && pins==pin[i]){
                cout<<"Login Successfully\n";
                user_index = i;
                cout<<"YOUR ACCOUNT BALANCE IS  "<<account_balance[i]<<" PKR "<<endl;
                return;
            }
        }

        cout<<"YOU ENTERED INCORRECT NAME OR PIN — TRY AGAIN!\n\n";
    }
    cout<<"------WELCOME TO THE BANK OF K2-----------\n\n\n";
}



// ====================== TRANSFER FUNCTION ======================
void transfer_money() {

    int transfer;
    cout<<"ENTER YOUR TRANSFER AMOUNT: ";
    cin>>transfer;

    if(transfer<=0){
        cout<<"INVALID AMOUNT — TRY AGAIN\n";
        return;
    }

    if(transfer > account_balance[user_index]){
        cout<<"YOU HAVE INSUFFICIENT BALANCE\n";
        return;
    }

    account_balance[user_index] -= transfer;
    cout<<"TRANSACTION SUCCESSFUL!\n";
    cout<<"REMAINING BALANCE: "<<account_balance[user_index]<<" PKR\n";
}



// ====================== DEPOSIT FUNCTION ======================
void deposit_money() {

    int deposit;
    cout<<"ENTER YOUR DEPOSIT AMOUNT: ";
    cin>>deposit;

    if(deposit < 100){
        cout<<"INVALID AMOUNT — TRY AGAIN\n";
        return;
    }

    account_balance[user_index] += deposit;
    cout<<"TRANSACTION SUCCESSFUL!\n";
    cout<<"REMAINING BALANCE: "<<account_balance[user_index]<<" PKR\n";
}



// ====================== WITHDRAW FUNCTION ======================
void withdraw_money() {

    int withdraw;
    cout<<"ENTER YOUR WITHDRAW AMOUNT: ";
    cin>>withdraw;

    if(withdraw > account_balance[user_index]){
        cout<<"INSUFFICIENT BALANCE\n";
        return;
    }

    account_balance[user_index] -= withdraw;
    cout<<"TRANSACTION SUCCESSFUL!\n";
    cout<<"REMAINING BALANCE: "<<account_balance[user_index]<<" PKR\n";
}



// ====================== CHECK BALANCE FUNCTION ======================
void check_balance() {
    cout<<"YOUR ACCOUNT BALANCE IS: "<<account_balance[user_index]<<" PKR\n";
}



// ====================== CHANGE PIN FUNCTION ======================
void change_pin() {

    int oldpin,newpin;

    cout<<"ENTER OLD PIN: ";
    cin>>oldpin;

    if(oldpin != pin[user_index]){
        cout<<"WRONG PIN — TRY AGAIN\n";
        return;
    }

    cout<<"ENTER NEW PIN: ";
    cin>>newpin;

    pin[user_index] = newpin;

    cout<<"PIN CHANGED SUCCESSFULLY!\n";
}



// ====================== MOBILE LOAD FUNCTION ======================
void mobile_load() {

    int load;
    cout<<"ENTER MOBILE LOAD AMOUNT: ";
    cin>>load;

    if(load > account_balance[user_index]){
        cout<<"INSUFFICIENT BALANCE\n";
        return;
    }

    account_balance[user_index] -= load;
    cout<<"MOBILE LOAD SUCCESSFUL!\n";
    cout<<"REMAINING BALANCE: "<<account_balance[user_index]<<" PKR\n";
}



// ====================== DONATION FUNCTION ======================
void donate_fund() {

    int fund;
    cout<<"ENTER DONATION AMOUNT: ";
    cin>>fund;

    if(fund <= 0 || fund > account_balance[user_index]){
        cout<<"INVALID AMOUNT\n";
        return;
    }

    account_balance[user_index] -= fund;

    cout<<"THANK YOU FOR DONATING!\n";
    cout<<"REMAINING BALANCE: "<<account_balance[user_index]<<" PKR\n";
}



// ====================== MENU FUNCTION ======================
int menu() {

    cout<<"\n\n========== WELCOME TO THE BANK OF K2 ==========\n";
    cout<<"1) TRANSFER MONEY\n";
    cout<<"2) DEPOSIT\n";
    cout<<"3) WITHDRAW\n";
    cout<<"4) CHECK BALANCE\n";
    cout<<"5) CHANGE PIN\n";
    cout<<"6) MOBILE LOAD\n";
    cout<<"7) DONATION\n";
    cout<<"8) EXIT\n\n";

    int select;
    cout<<"SELECT OPTION: ";
    cin>>select;
    return select;
}



// ====================== FILE SAVING FUNCTION ======================
void save_to_file(){
    ofstream file("bank_data.txt");

    if (!file) {
        cout<<"ERROR: FILE NOT CREATED\n";
        return;
    }

    for (int i = 0; i < 5; i++) {
        file << name[i] << " "
             << pin[i] << " "
             << account_balance[i] << endl;
    }

    file.close();
    cout<<"\nYOUR DATA IS SUCCESSFULLY STORED\n";
}



// ====================== MAIN PROGRAM ======================
int main() {

    login();

    while(true){

        int select = menu();

        switch(select){
            case 1: transfer_money(); break;
            case 2: deposit_money(); break;
            case 3: withdraw_money(); break;
            case 4: check_balance(); break;
            case 5: change_pin(); break;
            case 6: mobile_load(); break;
            case 7: donate_fund(); break;

            default: 
                cout<<"THANKS FOR USING THE BANK OF K2\n";
                save_to_file();
                return 0;
        }

        // -------- ASK FOR ANOTHER TRANSACTION ----------
        string again;
        cout<<"\nDo you want another transaction? (yes/no): ";
        cin>>again;

        if(again!="yes" && again!="YES"){
            cout<<"\nTHANKS FOR USING THE BANK OF K2\n";
            save_to_file();
            return 0;
        }
    }

    cout<<"THANKS FOR USING THE BANK OF K2\n";
    save_to_file();
    return 0;
}
