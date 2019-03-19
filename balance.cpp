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

int main(){
  int size = lines();
  PERSON* people = readData(size);

  Display(people,size);
  FindRichest(people,size);

  string cust = userName();
  float amount = Amount(cust);
  Deposit(people,size,cust,amount);
  
  string name = userName();
  float money = Amount(name);
  Deposit(people,size,name,money);
  
  FindRichest(people,size);
  NewCopy("data.txt",people,N);

 return 0;
}

string userName(){
  string name;
  cout << "Enter name: ";
  getline(cin,name);
  cout << endl;
  return name;
}

float Amount(PERSON a[],int N,string name){
  float amount;
  for(int i = 0; i < N; i++){
    if(a[i].cName == name.c_str()){
      cout << "Amount: "
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
}

PERSON* readData(int N){
  PERSON* p;
  p = new PERSON[N];

  string str1, str2,trash;
  ifstream Data;
  Data.open("data.txt");
  for(int i = 0; i < N; ++i){
    Data >> str1 >> str2 >> p[i] ;
    getline(Data,trash);
    string name = str1.substr(0,9) + " " + str2.substr(0,10);
    strcpy(p[i].cName,name.c_str());
  }
  Data.close();

  return p;
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

  cout << "Highest balance" << a[rich].cName << endl;
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

