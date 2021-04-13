#include <iostream>
using namespace std;

class Person{
    public:
        string name,address, telp;
        Person(string name, string address, int telp){
            Person::name = name;
            Person::address = address;
            Person::telp = telp;
        }
        Person(){
            name = "Unamed";
            address = "Unknown";
            telp = "0";
        }
};
class Customer{
    public:
        Person person;
        int custNumber;
        bool mail;
        Customer(){
            custNumber = 0;
            mail = false;
        }
        Customer(string nama, string address, int telp, int custNumber, bool mail){
            person.name = nama;
            person.address = address;
            person.telp = telp;
            Customer::custNumber = custNumber;
            Customer::mail = mail;
        }
        void print(){
            string isMail = (mail)? "True" : "False";
            cout << "Name            : " << person.name << endl
                 << "Address         : " << person.address << endl
                 << "Telepon         : " << person.telp << endl
                 << "Customer Number : " << custNumber << endl
                 << "Receive Mail ?  : " << isMail << endl;
        }
        void inputData(int custNumber){
            string input, nama, alamat, num;
            cout << "Name                       : ";cin >> ws; getline(cin, nama);
            cout << "Address                    : ";cin >> ws; getline(cin, alamat);
            cout << "No telp                    : "; cin >> num;
            up:
            cout << "Receive Email (true/false) : "; cin >> input;
            if((input == "True") || (input == "true")) mail = true;
            else if((input == "False") || (input == "false")) mail = false;
            else goto up;
            person.name = nama;
            person.address = alamat;
            person.telp = num;
            Customer::custNumber = custNumber;
        }
        void reset(){
            person.name = "Unamed";
            person.address = "Unknown";
            person.telp = "0";
            Customer::custNumber = 0;
            Customer::mail = false;
        }
};
class PreferredCustomer{
    public:
        int spendDollar, spendDollarAfterDisc;
        int level;
        string message;
        Customer customer;
        PreferredCustomer(){
            spendDollar = 0;
            level = 0;
            message = "Customer get 0 percent discount";
        }
        void inputDollar(){
            cout << "enter how much money the customer spent : "; cin >> spendDollar;
        }
        void checkLevelandCount(){
            if(spendDollar >= 2000){
                level = 10;
                message = "Customer get 10 percent discount";
            }else if(spendDollar >= 1500){
                level = 7;
                message = "Customer get 7 percent discount";
            }else if(spendDollar >= 1000){
                level = 6;
                message = "Customer get 6 percent discount";
            }else if(spendDollar >= 500){ 
                level = 5;
                message = "Customer get 5 percent discount";
            }else{
                level = 0;
                message = "Customer get 0 percent discount";
            }
            spendDollarAfterDisc = spendDollar - (spendDollar*level/100);
        }
        void printPref(){
            checkLevelandCount();
            customer.print();
            cout << "Money spent     : " << spendDollar << endl;
            cout << "Money to be paid: " << spendDollarAfterDisc << " ( " << message << " )" << endl;
        }
};
int main(){
    int n, x, noDelete, noChange;
    bool isLoop = true, check = false;
    PreferredCustomer prefCustomer[100];
    cout << "-- UTS PRAKTEK --\n\n";
    cout << "Enter many customer : "; cin >> n;
    while(isLoop){
        ulang:
        system("cls");
        cout << "-- UTS PRAKTEK --\n\n";
        cout << "1. Input Data Customer\n"
             << "2. Change Data Customer\n"
             << "3. Print Data Customer\n"
             << "4. Add Customer\n"
             << "5. Delete Customer\n"
             << "6. Exit\n";
        cout << "Menu : "; cin >> x;
        switch(x){
            case 1:
                cout << endl;
                for(int i = 1; i <= n; i++){
                    cout << "Customer "<< i << endl;
                    prefCustomer[i-1].customer.inputData(i);
                    prefCustomer[i-1].inputDollar();
                    cout << endl;
                }break;
            case 2:
                cout << endl;
                for(int i = 1; i <=n; i++){
                    cout << "Customer " << i << " : " << prefCustomer[i-1].customer.person.name << endl;
                }
                 cout << "\nWhich Customer Number you to change : "; cin >> noChange;
                for(int i = 1; i <= n; i++){
                    if(i == noChange){
                        prefCustomer[noChange-1].customer.inputData(noChange);
                        prefCustomer[noChange-1].inputDollar();
                        check = true;
                    }
                }
                if(!check) {
                    cout << "No change is not found\n";
                    system("pause");
                    goto ulang;
                }break;
            case 3:
                cout << endl;
                for(int i = 1; i <= n; i++){
                    cout << "Customer " << i << endl;
                    prefCustomer[i-1].printPref();
                    cout << endl;
                }
                system("pause"); break;
            case 4:
                cout << endl;
                prefCustomer[n].customer.inputData(n+1);
                prefCustomer[n].inputDollar();
                n = n+1;
                break; 
            case 5:
                cout << endl;
                for(int i = 1; i <= n; i++){
                    cout << "Customer " << i << " : " << prefCustomer[i-1].customer.person.name << endl;
                }
                cout << "\nWhich Customer Number you to delete : "; cin >> noDelete;
                for(int i = 1; i <= n; i++){
                    if(i == noDelete){
                        prefCustomer[i-1] = prefCustomer[i];
                        prefCustomer[i].customer.reset();
                        check = true;
                    }
                }
                if(check) n = n-1;
                else {
                    cout << "No delete is not found\n";
                    system("pause");
                    goto ulang;
                }break;
            case 6:
                isLoop = false; break;
            default:
                cout << "you must to enter int in range 1-6\n"; break;
        }
    }return 0;
}
