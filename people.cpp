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
void Display(PERSON a[], int size);
void FindRichest(PERSON a[], int size);
void Deposit(string customer,PERSON a[],int size);
void NewCopy(string file,PERSON a[], int size);

int main(){
 int  N = lines();
 PERSON people[N];

 string str1;
 string str2;
 string garabadge;
 float pay;

 ifstream Data;
 Data.open("data.txt");
 for(int i = 0; i < N; ++i){
   Data >> str1 >> str2 >> pay;
   getline(Data,garabadge);
   string name = str1 + " " + str2;
   strcpy(people[i].cName,name.c_str());
   people[i].Balance = pay;
 }

 Data.close();

 Display(people,N);
 FindRichest(people,N);

 string CustName;
 cout << "Enter your full name to deposit: ";
 getline(cin,CustName);
 
 Deposit(CustName,people,N);
 NewCopy("data.txt",people,N);

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

void Display(PERSON a[], int size){
	cout << "Name" << setw(20) << "Balance" << endl;
	cout << "------------------------------" << endl;
	for(int i = 0; i < size; ++i){
	  cout << a[i].cName << setw(10) << a[i].Balance  << endl;
	}
}

void FindRichest(PERSON a[], int size){
  int max = a[0].Balance;
  int rich = 0;
  for(int j = 1; j < size; j++){
    if(a[j].Balance > max){
      max = a[j].Balance;
      rich = j;
    }
  }

  cout << "The customer maximum balance is " << a[rich].cName << endl;
}

void Deposit(string customer,PERSON a[],int size){
  PERSON person[1];
  float deposit;
  int k = 0;
  
  strcpy(person[0].cName,customer.c_str());
  
  cout << person[0].cName << ", how much would you like to deposit? ";
  cin >> deposit;
  person[0].Balance =  deposit;
  
  for(; k < size; ++k){
    if(person[0].cName == a[k].cName){
      break;
    }
  }

  a[k].Balance +=  person[0].Balance;
  cout << "Now your new balance is " << a[k].Balance <<  endl;
}

void NewCopy(string file, PERSON a[], int size){
  fstream myfile{file,myfile.out|myfile.app};
  for(int i = 0; i < size; i++){
	myfile << a[i].cName << " " << a[i].Balance << "\n";
  }
   
  myfile.close();
}

