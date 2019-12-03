#include <bits/stdc++.h>
using namespace std;

class GameofLife
{
	private:
		
		int row,col;
		vector<vector<int> > tempGrid,grid;		
		
	public:
		
	    GameofLife(int ,int,vector<vector<int> > &,vector<vector<int> > &);
	    int getNeighbours(int ,int ,vector<vector<int> > &,int ,int );
	    void copyGrid(int ,int ,vector<vector<int> > &,vector<vector<int> > &);
	    void nextGeneration(int ,int ,vector<vector<int> > &);
	    bool comp(int ,int ,vector<vector<int> > &,vector<vector<int> > &);
	    void displayGrid(int ,int ,vector<vector<int> > &);
	    bool notEmpty(int ,int ,vector<vector<int> > &);
};

