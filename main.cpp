#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <fstream>
using namespace std;
void addPerson();
void showPeople();
void savedatabase();
void loadpeople();
void searchdatabase();


void requireEnter();
struct Person{
    string name;
    string surname;
    short age;
    string telephone;
};
short peopleindatabase;
Person people[20];

int main() {
    char test;
    do {cout<< " Number of people in database: "<< peopleindatabase<< endl;
        cout<< "Menu: "<<endl;
        cout<< "1. add person"<<endl;
        cout<< "2. show all person" <<endl;
        cout<<"3. save the data in file"<<endl;
        cout<< "4. load people from file"<<endl;
        cout<<"5. search database"<<endl;

        test = getch();

        switch (test) {

            case '1':
                addPerson();
                break;
            case '2':
                showPeople();
                break;
            case '3':
                savedatabase();
                break;
            case '4':
                loadpeople();
                break;
            case '5':
                searchdatabase();
                break;

        }

        requireEnter();
        system("cls");
    }while (test != 27);


    return 0;
}

void requireEnter()
{
    cout<< "click Enter to continue.."<<endl;
    while (getch() != 13);

}

void addPerson()
{
    cout<<"Type name: ";
    cin>> people[peopleindatabase].name;
    cout<<"Type surname: ";
    cin>> people[peopleindatabase].surname;
    cout<<"Type age: ";
    cin>> people[peopleindatabase].age;
    cout<<"Type telephone: ";
    cin>> people[peopleindatabase].telephone;
    peopleindatabase++;

}
void showPeople(){
    if (peopleindatabase >0 ){

        for (int i = 0; i < peopleindatabase; i++) {
            cout<<"person index: "<<(i+1)<<endl;
            cout<<"Name: "<<people[i].name <<endl;
            cout<<"surName: "<<people[i].surname <<endl;
            cout<<"age: "<<people[i].age <<endl;
            cout<<"telephone: "<<people[i].telephone <<endl;
            
        }

    } else
        cout<< " there is no people in database"<<endl;
}

void savedatabase(){
    ofstream file("database.txt");
    if (file.is_open())
    {
        file<<peopleindatabase<<endl;
        for (int i = 0; i < peopleindatabase; i++) {

            file<<people[i].name <<endl;
            file<<people[i].surname <<endl;
            file<<people[i].age <<endl;
           file<<people[i].telephone <<endl;

        }


        file.close();


    } else
        cout<< "I couldn't save to database"<<endl;

}
void loadpeople(){
    ifstream file("database.txt");
    if (file.is_open()){
        file>>peopleindatabase;
        if (peopleindatabase>0){
            for (int i = 0; i < peopleindatabase; i++) {

                file>>people[i].name;
                file>>people[i].surname;
                file>>people[i].age;
                file>>people[i].telephone;

            }}else
                cout<<"people loaded fine"<<endl;


        } else
            cout<< "database is empty"<<endl;


}
void searchdatabase()
{
    if (peopleindatabase >0){
        string name;
        cout<< "Please type the name your are looking for: "<<endl;
        cin>>name;
        for (int i = 0; i < peopleindatabase ; i++) {

            if (name== people[i].name){
                cout<<"person index: "<<(i+1)<<endl;
                cout<<"Name: "<<people[i].name <<endl;
                cout<<"surName: "<<people[i].surname <<endl;
                cout<<"age: "<<people[i].age <<endl;
                cout<<"telephone: "<<people[i].telephone <<endl;


            }
            
        }



    } else
        cout<<"there is nobody in database"<<endl;
}
