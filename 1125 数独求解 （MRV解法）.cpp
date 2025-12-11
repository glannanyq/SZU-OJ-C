#include<bits/stdc++.h>

using namespace std;

int board[9][9] ;

bool isValid(int row , int col , int num)
{
	for(int i = 0 ; i < 9 ; ++i)
		if(board[row][i] == num)
			return false;
	for(int i = 0 ; i < 9 ; ++i)
		if(board[i][col] == num)
			return false;
	int strrow = row / 3 * 3 ;
	int strcol = col / 3 * 3 ;
	for(int i = 0 ; i < 3 ; ++i)
	{
		for(int j = 0 ; j < 3 ; ++j)
		{
			if(board[strrow + i][strcol + j] == num)
				return false;
		}
	}
	return true;
}

int countpossible(int row , int col)
{
	int count = 0 ;
	for(int num = 1 ; num <= 9 ; ++num)
	{
		if(isValid(row , col , num))
			count++ ;
	}
	return count ;
}

bool solve()
{
	int bestrow = -1 ;
	int bestcol = -1 ;
	int minpossible = 10 ;
	bool found0 = false ;
	for(int i = 0 ; i < 9 ; ++i)
	{
		for(int j = 0 ; j < 9 ; ++j)
		{
			if(board[i][j] == 0)
			{
				found0 = true ;
				int p = countpossible(i , j) ;
				if(p == 0)
					return false;
				if(p < minpossible)
				{
					minpossible = p;
					bestrow = i ;
					bestcol = j ;
				}
			}	
		}
	}
	if(!found0)
		return true ;
	for(int num = 1 ; num <= 9 ; ++num)
	{
		if(isValid(bestrow , bestcol , num))
		{
			board[bestrow][bestcol] = num ;
			if(solve())
				return true ;
			board[bestrow][bestcol] = 0 ;
		}
	}
	return false ;
}

int main()
{
	int i , j ;
	for(i = 0 ; i < 9 ; ++i)
		for(j = 0 ; j < 9 ; ++j)
			cin >> board[i][j];
	if(solve())
	{
		for(i = 0 ; i < 9 ; ++i)
			for(j = 0 ; j < 9 ; ++j)
				cout << board[i][j] << (j < 8 ? ' ' : '\n') ;
	}
}


