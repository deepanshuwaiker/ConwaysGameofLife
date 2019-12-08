#include "GameOfLife.h"                                     // game of life class file
#include <windows.h>
#include <time.h>

using namespace std;


GameofLife::GameofLife(int row,int col,vector<vector<int> >&grid,vector<vector<int> >&tempGrid)
{
	this->row=row;
	this->col=col;	
	this->grid=grid;
	this->tempGrid=tempGrid;
}

int GameofLife::getNeighbours(int row,int col,vector<vector<int> >&grid,int i,int j)    // for calculating neighbours
{
			if(i==0 && j==0)
			return int(grid[0][1] + grid[1][0] +grid[1][1]);
			
			else if(i==0 && j==col-1)
			return int(grid[0][j-1] + grid[1][j-1] +grid[1][j]);
			
			else if(i==row-1 && j==0)
			return int(grid[i-1][0] + grid[i-1][1] +grid[i][1]);
			
			else if(i==row-1 && j==col-1)
			return int(grid[i][j-1] + grid[i-1][j] +grid[i-1][j-1]);
			
			else if(i==0 && j!=0 && j!=col-1)
			return int(grid[0][j-1] + grid[0][j+1] +grid[1][j] + grid[1][j-1] + grid[1][j+1]);
			
			else if(i==row-1 && j!=0 && j!=col-1)
			return int(grid[i][j+1] + grid[i][j-1] +grid[i-1][j] + grid[i-1][j-1] + grid[i-1][j+1]);
			
			else if(j==0 && i!=0 && i!=row-1)
			return int(grid[i-1][0] + grid[i+1][0] +grid[i+1][1] + grid[i-1][1] + grid[i][1]);
			
			else if(j==col-1 && i!=0 && i!=row-1)
			return int(grid[i+1][j] + grid[i-1][j] +grid[i][j-1] + grid[i-1][j-1] + grid[i+1][j-1]);
				
			else
		    return int(grid[i-1][j-1] + grid[i-1][j] + grid[i-1][j+1] + grid[i][j-1] + grid[i][j+1] + grid[i+1][j-1] + grid[i+1][j] + grid[i+1][j+1]);
		    
}

void GameofLife::copyGrid(int row,int col,vector<vector<int> > &grid1,vector<vector<int> > &grid2)  // coping the current in previous
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			grid2[i][j]=grid1[i][j];
		}
	}
}


void GameofLife::nextGeneration(int row,int col,vector<vector<int> > &grid)   // for calculating the next gen grid
{
	vector<vector<int> > tempGrid;
		
	for (int i = 0; i <= row-1; i++)
	{
		vector<int> temp;
		
		for (int j = 0; j <= col-1; j++)
		{
			int neighbours;
			neighbours = getNeighbours(row,col,grid,i,j);
			
		        if (grid[i][j] == 1)
				{
					if (neighbours < 2 || neighbours > 3)
						temp.push_back(0); 
						
					else
						temp.push_back(1); 
				}

				else
				{
					if (neighbours ==3)
						temp.push_back(1); 
					
					else if(neighbours == 2)
					    temp.push_back(grid[i][j]);
					     
					else
						temp.push_back(0); 
				}
		}
		tempGrid.push_back(temp);
	}
	
	copyGrid(row,col,tempGrid, grid);
	
	
}

bool GameofLife::comp(int row,int col,vector<vector<int> > &grid,vector<vector<int> > &temp)  // for comparing the 2 grids
{
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			if(temp[i][j]!=grid[i][j])
			return false;
		}
	}
	return true;
}

void GameofLife::displayGrid(int row,int col,vector<vector<int> > &grid)  // for displaying the grid
{
	system("cls");
	cout << "\n Simulation :\n\n";
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (grid[i][j] == 1)
			{
				cout << " x ";  //alive is represented by x
			}
			else
			{
				cout << "   ";  //dead by blank
			}
		}
		cout << "\n";
	}
	Sleep(2);                  //delay in milliseconds
}


