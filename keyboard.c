#include <lcd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

sbit r3 = P0^0;
sbit r2 = P0^1;
sbit r1 = P0^2;
sbit r0 = P0^3;
sbit c3 = P0^4;
sbit c2 = P0^5;
sbit c1 = P0^6;
sbit c0 = P0^7;

char operation = '\0';
int result_call_flag = 0;
char operand_buffer[8] = "";
int operand1;
int operand2;
long int result;
char result_string[16];

void check(void);
void calculate(void);
void lcd_init(unsigned char str[]);

void main()
{
	lcd_init("Type below:- ");
    while (1)
    {
        while (operation == '\0')
        {
            check();
        }
        operand1 = atoi(operand_buffer);
        strcpy(operand_buffer,"");
				while (strlen(operand_buffer < 8) && result_call_flag == 0)
        {
            check();
        }
        operand2 = atoi(operand_buffer);
        calculate();
				sprintf(result_string, "%ld", result);
				lcd_init("Result:- ");
				lcdstring(result_string);
				operation = '\0';
				result_call_flag = 0;
    }
}

void lcd_init(unsigned char str[])
{
		lcdinit();
    lcdstring(str);
    lcdcmd(0xC0);
}

void calculate()
{
    if (operation == '+')
    {
        result = operand1 + operand2;
    }
    else if (operation == '-')
    {
        result = operand1 - operand2;
    }
    else if (operation == 'X')
    {
        result = operand1 * operand2;
    }
    else if (operation == '/')
    {
        result = operand1 / operand2;
    }
}

void check()
{
    r0 = 0; r1 = r2 = r3 = 1;
    if (c0 == 0)
    {
        while (c0 == 0);
        if (strlen(operand_buffer) < 8)
        {
            strcat(operand_buffer, "7");
						lcddata('7');
        }
    }
    else if (c1 == 0)
    {
        while (c1 == 0);
        if (strlen(operand_buffer) < 8)
        {
            strcat(operand_buffer, "8");
            lcddata('8');
        }
    }
    else if (c2 == 0)
    {
        while (c2 == 0);
        if (strlen(operand_buffer) < 8)
        {
            strcat(operand_buffer, "9");
            lcddata('9');
        }
    }
    else if (c3 == 0)
    {
        while (c3 == 0);
        lcddata('/');
        operation = '/';
    }

    r1 = 0; r0 = r2 = r3 = 1;
    if (c0 == 0)
    {
        while (c0 == 0);
        if (strlen(operand_buffer) < 8)
        {
            strcat(operand_buffer, "4");
            lcddata('4');
        }
    }
    else if (c1 == 0)
    {
        while (c1 == 0);
        if (strlen(operand_buffer) < 8)
        {
            strcat(operand_buffer, "5");
            lcddata('5');
        }
    }
    else if (c2 == 0)
    {
        while (c2 == 0);
        if (strlen(operand_buffer) < 8)
        {
            strcat(operand_buffer, "6");
            lcddata('6');
        }
    }
    else if (c3 == 0)
    {
        while (c3 == 0);
        lcddata('X');
        operation = 'X';
    }

    r2 = 0; r1 = r0 = r3 = 1;
    if (c0 == 0)
    {
        while (c0 == 0);
        if (strlen(operand_buffer) < 8)
        {
            strcat(operand_buffer, "1");
            lcddata('1');
        }
    }
    else if (c1 == 0)
    {
        while (c1 == 0);
        if (strlen(operand_buffer) < 8)
        {
            strcat(operand_buffer, "2");
            lcddata('2');
        }
    }
    else if (c2 == 0)
    {
        while (c2 == 0);
        if (strlen(operand_buffer) < 8)
        {
            strcat(operand_buffer, "3");
            lcddata('3');
        }
    }
    else if (c3 == 0)
    {
        while (c3 == 0);
        lcddata('-');
        operation = '-';
    }

    r3 = 0; r1 = r2 = r0 = 1;
    if (c0 == 0)
    {
        while (c0 == 0);
        operation = '\0';
        strcpy(operand_buffer, "");
        operand1 = 0;
        operand2 = 0;
        result = 0;
        result_call_flag = 0;
        strcpy(result_string, "");
        lcd_init("Type below:-");
    }
    else if (c1 == 0)
    {
        while (c1 == 0);
        if (strlen(operand_buffer) < 8)
        {
            strcat(operand_buffer, "0");
            lcddata('0');
        }
    }
    else if (c2 == 0)
    {
        while (c2 == 0);
        lcddata('=');
        result_call_flag = 1;
    }
    else if (c3 == 0)
    {
        while (c3 == 0);
        lcddata('+');
        operation = '+';
    }
}
