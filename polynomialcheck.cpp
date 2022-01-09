#include <iostream>
#include <vector>
#include <string>
using namespace std;

string polyChecker(string s) {
    bool isInvalid = false;

    //checking if string is empty
    if (s.empty()) {
       cout << "Enter valid string" << endl;
       isInvalid = true;
   }
     
    //checking invalid characters (,), and -
     if (s.find('(') != string::npos || s.find(')') != string::npos || s.find('-') != string::npos) {
        cout << "Parentheses or negation is not allowed" << endl;
        isInvalid = true;
    }  

    if (s.find('^') != string::npos) {
        //cout << "No exponent sign found" << endl;
        isInvalid = true;
    }  
   
    int currentExp = 1;
   for (int i = 0; i < s.length(); i++) {
       //checking for exponent
       if (s.at(i) == '^') {
           if (s.at(i+1) > currentExp) {
               currentExp = s.at(i+1); //setting entered power as exponent
           }
            if (!isdigit(s.at(i+1))) {
                    isInvalid = true;
            }
           //checking if the exponent has any decimals
           if (i+2 < s.length()) {
               if (s.at(i+2) != '.') {
                   isInvalid = false;
               }
               else {
                   cout << "Error: A decimal was found in the exponent. Invalid polynomial" << endl;
                   isInvalid = true;
               }
           }
       }
   }
   
   //Output big-O notation of the equation
   if (isInvalid == false) {
       cout << "Polynomial " << s << " is valid" << endl;
       cout << "Big-O notation for: " << s << " is O(n^" << currentExp << ")" << endl;       
   }
    if (isInvalid == true) {
        cout << "Invalid polynomial" << endl;
    }

}
   
int main(int argc, char** argv)
{
   string polynomialEq;
   cout << "Enter a valid polynomial: " << endl;
   getline(cin, polynomialEq);

   cout << polyChecker(polynomialEq) << endl;

  return 0;
}

