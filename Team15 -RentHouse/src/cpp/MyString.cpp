#include "MyString.h"
#include <cstring>
#include <iostream>
#include <iomanip>
#pragma warning(disable : 4996)

void MyString::copyFrom(const MyString &other)
{
    str = new char[strlen(other.str) + 1];
    strcpy(str, other.str);
    size = other.size;
}

void MyString::free()
{
    delete[] str;
}

MyString::MyString(const char *data)
{
    if (data == nullptr)
    {
        str = new char[1];
        str[0] = '\0';
        size = 0;
    }
    else
    {
        size = strlen(data);
        str = new char[size + 1];
        strcpy(str, data);
    }
}

size_t getNumSize(size_t num)
{
    size_t res = 0;
    while (num)
    {
        res++;
        num /= 10;
    }
    return res;
}

MyString::MyString(size_t n)
{
    size_t numSize = getNumSize(n);
    str = new char[numSize + 1];

    str[numSize] = '\0';

    for (size_t i = 0; i < numSize; i++, n /= 10)
        str[numSize - 1 - i] = (n % 10) + '0';
    size = numSize;
}

MyString::MyString()
{
    str = new char[1];
    str[0] = '\0';
    size = 0;
}

MyString::MyString(const MyString &other)
{
    copyFrom(other);
}

MyString &MyString::operator=(const MyString &other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}

MyString::~MyString()
{
    free();
}

size_t MyString::getSize() const
{
    return size;
}

void MyString::concatFrom(const MyString &other)
{
    char *temp = new char[getSize() + other.getSize() + 1];
    strcpy(temp, str);
    strcat(temp, other.str);

    delete[] str;
    str = temp;
    size = size + other.getSize();
}

const char *MyString::c_str() const
{
    return str;
}

MyString *MyString::clone() const
{
    return new MyString(*this);
}

void MyString::getLine(std::istream &outFile)
{
    const size_t BUFF_SIZE = 1024;

    delete[] str;
    char buff[BUFF_SIZE];

    outFile.getline(buff, BUFF_SIZE, '\n');

    size_t len = strlen(buff);
    str = new char[len + 1];

    for (size_t i = 0; i < len; i++)
    {
        str[i] = buff[i];
    }
    str[len] = '\0';
    size = len;
}

MyString &MyString::operator+=(const MyString &other)
{
    concatFrom(other);
    return *this;
}

MyString operator+(const MyString &lhs, const MyString &rhs)
{
    MyString copyOfLeft(lhs);
    copyOfLeft += rhs;
    return copyOfLeft;
}

std::ostream &operator<<(std::ostream &stream, const MyString &str)
{
    stream << str.str << '\n';
    return stream;
}

std::istream &operator>>(std::istream &stream, MyString &str)
{
    delete[] str.str;
    char buff[1024];
    stream >> std::setw(1024) >> buff;

    str.size = strlen(buff);
    str.str = new char[str.size + 1];
    strcpy(str.str, buff);

    return stream;
}

std::ifstream &operator>>(std::ifstream &ifstr, MyString &str)
{
    delete[] str.str;

    char buff[256];
    ifstr.getline(buff, 256);

    str.size = strlen(buff);
    str.str = new char[str.size + 1];
    strcpy(str.str, buff);

    return ifstr;
}

bool operator==(const MyString &lhs, const MyString &rhs)
{
    return strcmp(lhs.c_str(), rhs.c_str()) == 0;
}

bool operator<=(const MyString &lhs, const MyString &rhs)
{
    return strcmp(lhs.c_str(), rhs.c_str()) <= 0;
}

bool operator<(const MyString &lhs, const MyString &rhs)
{
    return strcmp(lhs.c_str(), rhs.c_str()) < 0;
}

MyString::MyString(MyString &&otherString)
{
    str = otherString.str;
    size = otherString.size;
    otherString.str = nullptr;
}

MyString &MyString::operator=(MyString &&otherString)
{

    if (this != &otherString)
    {
        free();
        str = otherString.str;
        otherString.str = nullptr;
        size = otherString.size;
    }
    return *this;
}

bool MyString::isInt() const
{
    bool isNeg = (str[0] == '-');

    for (size_t i = isNeg; i < size; i++)
    {
        if (str[i] < '0' || str[i] > '9')
        {
            return false;
        }
    }

    if (size == 0 || str[0] == '\0')
    {
        return false;
    }
    return true;
}

bool MyString::isOnlyNumbers() const
{
    for (size_t i = 0; i < size; i++)
    {
        if (str[i] < '0' || str[i] > '9')
        {
            return false;
        }
    }

    if (size == 0 || str[0] == '\0')
    {
        return false;
    }
    return true;
}

int MyString::convertToInt() const
{
    bool isNeg = (str[0] == '-');
    int n = 0;
    if (!isOnlyNumbers())
    {
        return 0;
    }

    for (size_t i = isNeg; i < size; i++)
    {
        n += (str[i] - '0');
        n *= 10;
    }
    n /= 10;

    return isNeg ? -n : n;
}

bool MyString::isDouble() const
{
    if (isOnlyNumbers())
    {
        return true;
    }

    bool isNeg = (str[0] == '-');
    int dotCount = 0;

    for (size_t i = isNeg; i < size; i++)
    {
        if (str[i] < '0' || str[i] > '9')
        {
            if (str[i] == '.')
            {
                if (i != 0 && i != isNeg && i != size - 1 && dotCount == 0)
                {
                    dotCount++;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    }
    return dotCount == 1;
}

size_t MyString::findDotInDouble() const
{
    for (size_t i = 0; i < size; i++)
    {
        if (str[i] == '.')
        {
            return i;
        }
    }
    return 0;
}

double MyString::convertToDouble() const
{
    if (isOnlyNumbers())
    {
        return convertToInt();
    }

    double n = 0;
    double after = 0;

    if (!isDouble())
    {
        return 0;
    }

    size_t index = findDotInDouble();
    bool isNeg = (str[0] == '-');

    for (size_t i = isNeg; i < index; i++)
    {
        n += (str[i] - '0');
        n *= 10;
    }
    n /= 10;
    for (size_t i = index + 1; i < size; i++)
    {
        after += (str[i] - '0');
        after *= 10;
    }
    after /= 10;
    for (size_t i = 0; i < size - index - 1; i++)
    {
        after /= 10;
    }
    double output = (n + after);

    return isNeg ? -output : output;
}

bool MyString::isChar(const char symb) const
{
    return size == 1 && str[0] == symb;
}

char *MyString::getText() const
{
    return str;
}
