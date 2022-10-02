#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
using namespace std;

class BinaryNumber
{
private:
  int *bit;
  int *number;
  string *binaryNumber;
  void convertToBinary();
  void inputValues();

  string* getOnescomplement();
  string* getTwoscomplement();

  void displayBinaryNumber();
  void displayOnesComplement();
  void displayTwosComplement();

public:
  BinaryNumber();
  ~BinaryNumber();
  void display();
};

BinaryNumber::BinaryNumber()
{
  //take inputs
  this->inputValues();

  //now convert number to binary
  this->convertToBinary();
}

void BinaryNumber::display(){
  cout<<'\n';
  this->displayBinaryNumber();
  this->displayOnesComplement();
  this->displayTwosComplement();
}

void BinaryNumber::inputValues(){

  this->number = new int;
  this->bit = new int;

//input number
  cout << "Please enter the number: ";
  cin >> *number;
  while (1)
  {
    if(!cin.fail()){
      break;
    }
    else{
      cout<< "please enter positive integer!\n";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(),'\n');
      cin >> *number;
    }
  }
  
  //input bit system
  cout << "Please enter the bit stytem, you want the number to be outputed in: ";
  cin >> *bit;
  while (1)
  {
    if(!cin.fail() && *bit > 0 )
      break;
    else{
      cout<< "please enter positive integer!\n";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(),'\n');
      cin >> *bit; 
    }
  }

}

void BinaryNumber::convertToBinary(){
      //for converting integer into binary number
  int *numberInBinary = new int(0), *remainder = new int, *product = new int(1), *num = new int(*number);

  while(*num!= 0){
    *remainder = *num % 2;
    *numberInBinary = *numberInBinary + ((*remainder) * (*product));
    *num = *num / 2;
    *product *= 10;
  }

  this->binaryNumber = new string(to_string(*numberInBinary));
}

string *BinaryNumber::getOnescomplement(){
  string *ones = new string;
  ones->resize(binaryNumber->length());

  for (int i = 0;i < binaryNumber->length(); i++) {
    if((*binaryNumber)[i]=='0')
    {
      (*ones)[i]='1';
    }
    else
    {
      (*ones)[i]='0';
    }
  }

  return ones;
}

string *BinaryNumber::getTwoscomplement(){
  string *ones = this->getOnescomplement();
  string *twos = new string;
  twos->resize(binaryNumber->length());

  int *carr = new int(1);

  for (int i = binaryNumber->length()  - 1; i >= 0; i--) 
  {
    if ((*ones)[i] == '1' && *carr == 1) 
    {
      (*twos)[i] = '0';
    }
    else if ((*ones)[i] == '0' && *carr == 1) 
    {
      (*twos)[i] = '1';
      *carr = 0;
    }
    else 
    {
      (*twos)[i] = (*ones)[i];
    }
  }

  return twos;
}

void BinaryNumber::displayBinaryNumber(){
      cout << *number << " in "<< *bit << " bit system: "
    << setfill('0') << setw(*bit) << *binaryNumber << endl;
}

void BinaryNumber::displayOnesComplement(){
  string *ones = this->getOnescomplement();
  cout << "One's complement of " << *(this->number) << " => " << setfill('1') << setw(*bit) << *ones<<endl; 
}

void BinaryNumber::displayTwosComplement(){
  string *twos = this->getTwoscomplement();
  cout << "Twos's complement of " << *(this->number) << " => " << setfill('1') << setw(*bit) << *twos<<endl; 
}

