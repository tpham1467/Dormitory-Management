#pragma once
#include <iostream>
#include <Windows.h>
#include <Shlwapi.h>
#include <conio.h>
#include<string>
using namespace std;
void SetWindowSize(SHORT width, SHORT height);
void SetScreenBufferSize(SHORT width, SHORT height);
void DisableResizeWindow();
void clrscr(void);
void gotoXY(SHORT x, SHORT y);
SHORT wherex();
SHORT wherey();
void setColor(WORD color);
void setBackgroundColor(WORD color);
void Outstring(SHORT x, SHORT y, WORD color, WORD background, string s );
void Outchar(SHORT x, SHORT y, WORD color, WORD background, char s);
void Outfloat(SHORT x, SHORT y, WORD color, WORD background,  float s);
void Outint(SHORT x, SHORT y, WORD color, WORD background, int s);
void Cursor(BOOL bVisible = TRUE, DWORD dwSize = 25);
void deleteRow(SHORT SStartPos, SHORT SNumberRow);
