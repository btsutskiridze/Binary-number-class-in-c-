#include "BinaryNumber.h"

using namespace std;

int main(){

  char* choice = new char;

  do
  {
    cout<<"\n------------------------------------------\n";
    BinaryNumber *binaryNum = new BinaryNumber;  
    binaryNum->display();
    cout<<"------------------------------------------\n";

    cout << "\nDo you want to continue?(Y/n)\n";
    cin >> *choice;

  } while (*choice == 'y' || *choice == 'Y');

  cout<<"\n**** GoodBye ****\n";

  return 0;
}