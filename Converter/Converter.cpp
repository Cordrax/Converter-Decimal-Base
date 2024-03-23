#include <iostream>
#include <string>
#include <ctype.h>
#include <cmath>
#include <cctype>

using std::string;
using std::to_string;
using std::cout;
using std::cin;
using std::toupper;

int base_to_decimal(string num, int base)
{
    int converted = 0;
    string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int unit = 0;
    int num_size = num.size();
    for (int i = 0; i != num_size; i++)
    {
        if (isdigit(num[i]))
        {
            unit = int(num[i] - '0');
        }
        else
        {
            for (int j = 0; j != chars.size(); j++)
            {
                if (chars[j] == toupper(num[i]))
                {
                    unit = j + 10;
                }
            }
        }
        converted += unit * int(pow(base, num_size - i - 1));
    }
    return converted;
}


string decimal_to_base(int num, int base)
{
    string converted = "";
    int power = 0;
    string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    while (pow(base, power) <= num)
    {
        power++;
    }
    int const powa = power;
    for (int i = 0; i < powa; i++)
    {
        string quotient = "";
        power--;
        int n = pow(base, power);
        if (num / n >= 1)
        {
            quotient = to_string(num / n);
            if (stoi(quotient) >= 10)
            {
                for (int j = 0; j != chars.size(); j++)
                {
                    if (stoi(quotient) - 10 == j)
                    {
                        quotient = chars[j];
                        break;
                    }
                }
            }
            num %= n;
        }
        else
        {
            quotient = "0";
        }
        converted += quotient;
    }

    return converted;
}



int main()
{
    int choice;
    string num;
    int base;
    cout << "Convert from a chosen base to decimal (1) or from decimal to a chosen base (2) :\n";
    cin >> choice;
    cout << "Enter the number :\n";
    cin >> num;
    cout << "Enter the base :\n";
    cin >> base;
    if (choice == 1)
    {
        cout << num << " in base " << base << " is equal to " << base_to_decimal(num, base) << " in decimal";
    }
    else
    {
        cout << num << " is equal to " << decimal_to_base(stoi(num), base) << " in base " << base;
    }
    return 0;
}


