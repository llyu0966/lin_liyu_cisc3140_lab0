#include <iostream>
#include <string>
using namespace std;

// This function receives the cipeher text and shift number
// returns the encrypted text
string encrypt(string text, int s_num)
{
    string result = "";
    const string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    
    string::size_type pos;

    result.reserve(text.length());

    for(string::iterator it = text.begin(); it != text.end(); ++it)
    {
        if((pos = alphabet.find(*it)) != string::npos)
            result += alphabet[(pos+s_num) % 52];
        else
            result += *it;
    }
  
    return result;
}

// This function receives the cipeher text 
// calls the encrypt() function
// finds the encrypted text containing a particular string
// returns the shift number
int find_s(string text)
{
    string str1 = "";
    string str2 = "Yanks";
    int max = 52;

    for(int i=1; i<max; i++)
    {
        str1 = encrypt(text, i);
    
        if(str1.find(str2) != string::npos)
        {
            return i;
        }
    }
    // if not found, return 0
    return 0;
}

int main()
{
    string text1 = "uIFzBOLTbSFbMTPlOPXObTuIFcSPOYcPNCFST";
    string text2 = "dBFTBSdJQIFSfYFSDJTFxJUIdqMVTqMVT";

    int shift_number = find_s(text1);
    cout << "The first cipher text : " << text1 << endl;
    cout << "Shift Number: " << shift_number << endl;
    cout << "Plain text: " << encrypt(text1, shift_number) << endl;

    cout << "\nThe second cipher text : " << text2 << endl;
    cout << "Shift Number: " << shift_number << endl;
    cout << "Plain text: " << encrypt(text2, shift_number) << endl;
    return 0;
}