#include<bits/stdc++.h>

using namespace std;

int board[9][9] ;

int rowUsed[9];
int colUsed[9];
int boxUsed[3][3];

void flip(int row, int col, int num)
{
    int bit = 1 << (num - 1);
    rowUsed[row] ^= bit;
    colUsed[col] ^= bit;
    boxUsed[row / 3][col / 3] ^= bit;
}

int count1(int n)
{
	int count = 0 ;
	while(n > 0)
	{
		n &= (n - 1) ;
		count++;
	}
	return count;
} 

int countpossible(int row , int col)
{
	int used = rowUsed[row] | colUsed[col] | boxUsed[row / 3][col / 3];
	return count1((~used) & 0x1FF);
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
					minpossible = p ;
					bestrow = i ;
					bestcol = j ;
				}
				if(minpossible == 1) goto search_done;
			}	
		}
	}
	search_done:
	if(!found0)
		return true ;
	int used = rowUsed[bestrow] | colUsed[bestcol] | boxUsed[bestrow / 3][bestcol / 3];
	for(int num = 1; num <= 9; ++num)
    {
        if(!((used >> (num - 1)) & 1))
        {
            board[bestrow][bestcol] = num;
            flip(bestrow, bestcol, num);
            if(solve())
				return true;
            flip(bestrow, bestcol, num);
            board[bestrow][bestcol] = 0;
        }
    }
    return false;
}

int main()
{
	int i , j ;
	for(i = 0 ; i < 9 ; ++i)
		for(j = 0 ; j < 9 ; ++j)
		{
			cin >> board[i][j];
			if(board[i][j] != 0)
				flip(i , j , board[i][j]) ;
		}
			
	if(solve())
	{
		for(i = 0 ; i < 9 ; ++i)
			for(j = 0 ; j < 9 ; ++j)
				cout << board[i][j] << (j < 8 ? ' ' : '\n') ;
	}
}
