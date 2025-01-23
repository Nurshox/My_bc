#include "../include/string_func.h"

int _strlen(char*s)
{
    int i;
    for(i = 0; s[i]; i++);
    return i;
}

void _strcpy(char*s1, char*s2)
{
    for(int i = 0; s2[i]; i++)
        s1[i] = s2[i];
}

int check_oper(char c)
{
    if(c == '+' || c == '-' || c == '*' || c == '/' || c == '%')
        return 1;
    return 0;
}

int parnt_check(char*str, int len)
{
    int count=0;
    for(int i=0; i<len; i++)
    {
        if(str[i] =='(')
            count++;
        else if(str[i] == ')')
            count--; 
    }
    if(count < 0 || count > 0) 
        return 1;
    return 0;
}

int handling_errors(char*str)
{
    int len = _strlen(str);
    if(len==1)
    {
        printf("%c\n", str[0]);
        return 1;
    }
    for(int i=0; i<len; i++)
    {
        if(str[i] == '/' && str[i+1] == '0'  )
        {
            write(2, "divide by zero\n", 15);
            return 1;
        }
        if(str[i] == '(' && str[i+1] == ')')
        {
            write(2, "parse error\n", 12);
            return 1;
        }
        if(str[i] >= 'a' && str[i+1] <= 'z')
        {
            write(2, "parse error\n", 12);
            return 1;
        }
        if(check_oper(str[i]) && check_oper(str[i+1]) && (str[i]!='+' || str[i]!='-'))  
        {
            write(2, "parse error\n", 12);
            return 1;
        }
    }   
    if(parnt_check(str, len)==1) 
    {
        write(2, "parse error\n", 12);
        return 1;
    }
    return 0;
}


int is_digit(char c)
{
    if(c>='0'&&c<='9')
        return 1;
    return 0;
}

int oper_prec(char c)
{
    if( c=='(' || c==')')
        return 0;
    if(c =='+' || c == '-')
        return 1;
    if(c =='*' || c == '/' || c == '%')
        return 2;
    return -1;
}

int my_atoi(char* param_1)
{
  int m, value=0;
  
  for(int i=0; i < param_1[i]; i++){
    if(param_1[i] != '-'){
      m = param_1[i]-'0';
      value = 10*value+m;
    }
  }
    if(param_1[0] == '-')
      value*=-1;
    
    return value;
}


int calculus_func(int num1, int num2, char oper)
{
    if(oper == '+')
        return (num1 + num2);
    else if(oper == '-')
        return (num1 - num2);
    else if(oper == '*')
        return (num1 * num2);
    else if(oper == '/')
        return (num1 / num2);
    else if(oper == '%')
        return (num1 % num2);
    return 0;
}