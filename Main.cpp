#include<bits/stdc++.h>
#include "GameOflife.cpp"                                  // game of life cpp file where all functions are declared


int main()
{

	char enter,a;
	int choice;
	int row,col;
	
	cout<<"\t\t\t\t\t\t"<<" Welcome to the Game of Life"<<"\t"<<endl;
	cout<<"\t\t\t\t\t\t"<<"----------------------------"<<"\t"<<endl<<endl;
	
	options:
			
	cout<<"Choose from the below options to continue "<<endl<<endl;
	cout<<"1. Enter custom matrix"<<endl;
	cout<<"2. Generate random matrix"<<endl<<endl;
	
	cout<<"Your Choice :";
	cin>>choice;
	
	cout<<endl;
	
	cout<<"Enter rows & columns :";
	cin>>row>>col;
	cout<<endl;
	
	vector<vector<int> > grid,original;
	vector<vector<int> > tempGrid(row,vector<int> (col,0));   //intializing all cells with 0 value
	
	GameofLife gol=GameofLife(row,col,grid,tempGrid);
		
	switch (choice)
	{
		
		case 1: 
			
	     	cout<<"Enter the matrix :"<<endl;
			for(int i=0;i<row;i++)                           // for contructing custom matrix
			{
			    vector<int> vec;
			    
			    for(int j=0;j<col;j++)
			    {
			        int val;
			        cin>>val;
			        vec.push_back(val);
			    }
			    grid.push_back(vec);
			    original.push_back(vec);
			}
			
		break;
		
		case 2:
			
		    srand(time(0));
		
			for (int p = 0; p < row; p++)                  // for constructing random matrix
		    {
		    	 vector<int> vec;
		    	
		         for (int  q= 0; q < col; q++)
		         {
		              int random;	  
	                  random = rand() % 2;
	                  vec.push_back(random);
		         }
		         
		         grid.push_back(vec);
		         original.push_back(vec);
		    }
	    
		break;
		
		default:
			
			cout<<"INVALID CHOICE\n"<<endl;
			goto options;
			
		break;
	}

    int flag=0;
    
    while(1)                                              // infinite loop
	{
		if(gol.comp(row,col,grid,tempGrid))              // loop breaks when previous and current grids are same
		{
			flag=1;
			break;
		}
		
		gol.displayGrid(row,col,grid);
		gol.copyGrid(row,col,grid,tempGrid);
		gol.nextGeneration(row,col,grid);	
		
		if(gol.comp(row,col,grid,original))             // loop breaks when original and current grids are same
		{
			flag=1;
			break;
		}
	}
	
	if(flag==1)
	gol.displayGrid(row,col,grid);	                   // for displayng final generation
	
	cout<<"\nperform another operaton(y/n) :";	
	cin>>enter;
	cout<<endl;
	
	if(enter=='y')
	goto options;
	
	else
	exit(0);
		 
	return 0;
}


