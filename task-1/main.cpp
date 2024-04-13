#include <iostream>
#include <string>
#include <cmath>

using namespace std;

const int VARIANT = 13;

const int DEFAULT_ARRAY_SIZE = 24;

template <typename T>
int countZeros(T *arr, int size)
{
    int zeroCount = 0;

    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] == 0)
        {
            zeroCount++;
        }
    }

    return zeroCount;
}

template <typename T>
void printarray(T *arr, int len, char sep = ' ')
{

    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << sep;
    }

    cout << endl;
}

template <typename T>
void fillarray(T *&arr, int length, int min, int max)
{
    if (length < 1)
    {
        throw out_of_range("array size can't be < 1!");
    }

    max = max >= min ? max : min;

    for (size_t i = 0; i < length; i++)
    {
        arr[i] = rand() % (max - min) + min;
    }
}

template <typename T>
T sumAfterMinEl(T *arr, int length)
{
    T min = arr[0];
    T sum = 0;

    for (size_t i = 1; i < length; i++)
    {
        if (arr[i] <= min)
        {
            min = arr[i];
            sum = 0;
        }
        else
        {
            sum += arr[i];
        }
    }

    return sum;
}

template <typename T>
int zeroCount(T *arr, int length)
{
    int zeroCounter = 0;
    for (size_t i = 0; i < length; i++)
    {
        if (arr[i] == 0)
        {
            zeroCounter++;
        }
    }
    return zeroCounter;
}

inline bool validateChoice(int choice)
{
    return choice > 0 && choice < 7;
}

void print(bool isPregenArrChosen, bool willGenerateString)
{
    cout << "1 - find number of zeros\n"
         << "2 - sum after min el\n"
         << "3 - swap array choice ";

    if (isPregenArrChosen)
    {
        cout << "(now chosen pregen. arr)" << endl;
    }
    else
    {
        cout << "(now user arr chosen)" << endl;
    }

    cout << "4 - delete words with digit\n"
         << "5 - swap string choice ";

    if (willGenerateString)
    {
        cout << "(will gener. str)" << endl;
    }
    else
    {
        cout << "(now user string chosen)" << endl;
    }

    cout << "6 - exit" << endl;
}

inline int getUserChoice()
{
    int choice = 0;

    cout << "choice: ";

    cin >> choice;

    return choice;
}

bool hasDigits(string str)
{
    bool hasDigs = false;

    for (size_t i = 0; i < str.length(); i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            return true;
            break;
        }
    }

    return false;
}

char randDigOrLetter()
{
    char c = 0;

    while ((c >= 0 && c <= 47) || (c >= 58 && c <= 64) || (c >= 91 && c <= 96) || (c >= 123))
    {
        c = rand() % 123;
    }

    cout << "ch: '" << (int)c << "'" << endl;

    return c;
}

int deleteWordsWithDigits(char *&str, int length)
{

    string strWithoutDigs = "";

    string temp = "";

    for (size_t i = 0; i < length; i++)
    {
        temp += str[i];
        if (str[i] == 32 || i == length - 1)
        {

            if (!hasDigits(temp))
            {
                strWithoutDigs += temp;
            }
            temp = "";
        }
    }

    delete[] str;

    str = new char[strWithoutDigs.length()];

    for (size_t i = 0; i < strWithoutDigs.length(); i++)
    {
        str[i] = strWithoutDigs[i];
    }

    return strWithoutDigs.length();
}

void fillString(char *str, int len)
{

    for (size_t i = 0; i < len; i++)
    {
        str[i] = randDigOrLetter();
    }

    for (size_t i = 0; i < (int)sqrt(len); i++)
    {
        str[rand() % (len - 1) + 1] = 32;
    }
}

void userString(char *&str, int &updatedSize)
{

    string input = "   ";
    while (input[0] == ' ' || input[input.length() - 1] == ' ')
    {
        cout << "input string (spaces are not allowed!): \n";
        cin.ignore();
        getline(cin, input);
    }

    str = new char[input.length()];

    for (size_t i = 0; i < input.length(); i++)
    {
        str[i] = input[i];
    }

    updatedSize = input.length();
}

void updateArrayChoice(double *&arr, int &length, bool &isPregenArrChosen)
{
    delete[] arr;
    arr = nullptr;
    if (isPregenArrChosen)
    {
        arr = new double[length];
        fillarray(arr, length, -length, length);
    }
    else
    {
        cout << "choose length: " << endl;
        cin >> length;

        if (length < 1)
        {
            cout << "wrong length! choosing 10..." << endl;
            length = 10;
        }

        arr = new double[length];

        cout << "enter arr els:" << endl;

        for (size_t i = 0; i < length; i++)
        {
            cin >> arr[i];
        }
    }
}

int main()
{
    srand(time(NULL));
    int length = DEFAULT_ARRAY_SIZE;
    int strLength = DEFAULT_ARRAY_SIZE;

    double *arr = new double[length];
    fillarray(arr, length, -length * 2, length);

    char *str = new char[strLength];

    cout << endl;

    bool isPregenArrChosen = true;
    bool willGenerateString = false;

    while (true)
    {
        print(isPregenArrChosen, willGenerateString);

        int choice = 0;
        while (!validateChoice(choice))
        {
            choice = getUserChoice();
        }

        switch (choice)
        {
        case 1:

            updateArrayChoice(arr, length, isPregenArrChosen);

            cout << "arr:" << endl;
            printarray(arr, length);
            cout << "number of zeros: " << zeroCount(arr, length) << endl;
            ;
            break;

        case 2:
            updateArrayChoice(arr, length, isPregenArrChosen);

            cout << "arr:" << endl;
            printarray(arr, length);

            cout << "sum after min el: " << sumAfterMinEl(arr, length) << endl;
            break;

        case 3:
            if (isPregenArrChosen)
            {
                isPregenArrChosen = !isPregenArrChosen;
                break;
            }

        case 4:
            if (willGenerateString)
            {
                strLength = DEFAULT_ARRAY_SIZE;

                fillString(str, strLength);
            }
            else
            {
                userString(str, strLength);
            }

            cout << "chosen string: " << endl;
            printarray(str, strLength, '\0');

            strLength = deleteWordsWithDigits(str, strLength);

            cout << "str without words with digits:" << endl;

            printarray(str, strLength, '\0');
            cout << endl;

            break;

        case 5:
            willGenerateString = !willGenerateString;
            break;

        case 6:
            exit(0);
            break;

        default:
            cout << "invalid input" << endl;
            break;
        }
    }
}