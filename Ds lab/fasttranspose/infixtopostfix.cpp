#include <iostream>
#include <"stack1.cpp">
using namespace std;
int icp[] = {20, 19, 12, 12, 13, 13, 13, 0};
int isp[] = {0, 19 ,12 , 12, 13, 13 ,13, 0};
enum precedence{lparen, rparen, plus, minus, times, divide, mod, eos, operand};
char stack::topele()
{
    return s[top];
}


int main()
{

}
