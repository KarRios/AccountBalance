// Karina Rios
// 301-3
#include<iostream>
#include<string>
#include<cstring>
#include<fstream>
#include<iomanip>
using namespace std;

struct PERSON{
  char cName[20];
  float Balance;
};
  
int lines();
PERSON* readData(int N);
void Display(PERSON a[], int N);
void FindRichest(PERSON a[], int N);
void Deposit(PERSON arr[],int N,string custName,float amount);
void NewCopy(string file,PERSON a[], int N);
string userName();
float Amount(PERSON a[],int N,string name);

void printmenu() {
    cout << "Please enter a choice:" << endl;
    cout << "1. Display records"<< endl;
    cout << "2. Deposit funds"<< endl;
    cout << "3. Find Highest Balance" << endl;
    cout << "4. Update records" << endl;
    cout << "5. Exit the program" << endl;
}

int main()
{
    int size = lines();
    PERSON* people;
    people = readData(size);
    string cust;
    float amount;
    
    int choice;
    do
    {
        printmenu();
        cin >> choice;
        switch(choice)
        {
            case 1:
                Display(people,size);
                break;

            case 2:
                cust = userName();
		amount = Amount(people,size,cust);
		Deposit(people,size,cust,amount);
                break;

            case 3:
                FindRichest(people,size);
                break;

            case 4:
                NewCopy("data.txt",people,size);
                break;

            case 5:
                Display(people,size);
                break;

            default:
                cout << "Invalid entry" << endl;
                break;
        }
        cout << endl;
   } while(choice != 5);
      return 0;
}


string userName(){
  string name;
  cout << "Enter name: ";
  cin.get();
  getline(cin,name);
  cout << endl;
  return name;
}

float Amount(PERSON a[],int N,string name){
  float amount;
  char charName[20];
  memcpy(charName,name.c_str(),name.size());
  for(int i = 0; i < N; i++){
    if(a[i].cName == charName){
      cout << "Amount: ";
      cin >> amount;
      return amount;
    }
  }

  cout << "Record not found" << endl;
  return 0;
}
  

int lines(){
  int num = 0;
  string line;
  ifstream myFile;
  myFile.open("data.txt");
  while(getline(myFile, line)){
      ++num;
  }
  myFile.close();
  return num;
}

PERSON* readData(int N){
  PERSON* p;
  p = new PERSON[N];
  
  string str1, str2,trash;
  ifstream Data;
  Data.open("data.txt");
  for(int i = 0; i < N;i++){
    Data >> str1 >> str2 >> p[i].Balance;
    getline(Data,trash);
    string name = str1 + " " + str2;
    strcpy(p[i].cName,name.c_str());
  }
  Data.close();

  return p;

  delete p;
  p = NULL;
}


void Display(PERSON a[], int N){
  cout << "Name" << setw(20) << "Balance" << endl;
  cout << "------------------------------" << endl;
  for(int i = 0; i < N; ++i){
    cout << a[i].cName << setw(10) << a[i].Balance  << endl;
  }
}

void FindRichest(PERSON a[], int N){
  int max = a[0].Balance;
  int rich = 0;
  for(int j = 1; j < N; j++){
    if(a[j].Balance > max){
      max = a[j].Balance;
      rich = j;
    }
  }

  cout << "Highest balance: " << a[rich].cName << endl;
}

void Deposit(PERSON arr[],int N,string custName,float amount){
  for(int i = 0; i < N; i++){
    if(arr[i].cName == custName.c_str()){
      arr[i].Balance += amount;
      cout << "New Balance: " << arr[i].Balance << endl;
    }
  }
}

void NewCopy(string file, PERSON a[], int N){
  ofstream myfile;
  myfile.open(file);
  for(int i = 0; i < N; i++){
	myfile << a[i].cName << " " << a[i].Balance << "\n";
  }
   
  myfile.close();

  cout << "File Updated..." << endl;
}



