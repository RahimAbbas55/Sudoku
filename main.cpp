#include <iostream>
#include<cstdlib>
#include<ctime>
#include<curses.h>

using namespace std;
void sudokuboard(int a[][9]);
bool searchcol(int col,int ans);
bool searchrow(int row,int ans);
void check(int ans);
bool search_box(int ans);
void rules();
bool end_game();


int a[9][9]={{8,0,1,0,9,0,3,0,2},{3,5,0,0,6,8,0,4,9},{4,9,7,0,0,0,1,0,6},
            {2,1,0,9,0,5,0,3,4},{6,7,5,0,4,0,9,2,0},{9,0,0,6,8,0,5,0,0},
            {5,2,0,8,0,0,4,7,3},{7,4,3,0,2,6,8,0,0},{1,8,0,4,3,0,2,0,5}};


int en_row,en_col;
int col,row;

int main()//MAIN FUNCTION
{
    int col = 0,row=0,ans = 0,choice;
    cout<<"\t\t\t\t\tWELCOME TO SUDOKU!!!!!\n\n";
    cout<<"\t\t\t\t\tTO PLAY,PRESS (1). TO EXIT,PRESS(0).\n\n";
    cout<<"\t\t\t\t\tENTER YOUR CHOICE: ";cin>>choice;
    while(choice==1)
    {
        rules();
        if(end_game())
        {
            cout<<"\t\t\t\t\tGAME ENDED. THANKS FOR PLAYING\n\n";
            break;
        }
        sudokuboard(a);
        check(ans);
    
        cout<<"\t\t\t\t\tPRESS(1) TO PLAY AGAIN. PRESS(0) TO QUIT:\n\n";
        cin>>choice;
    }
    
    system("pause");
    return 0;
}

void sudokuboard(int a[][9])//TO PRINT THE GAME BOARD
{
   
    cout<<"\t\t\t\t\tThe Sudoku Board is: "<<"\n";
    cout<<" ______________________"<<"\n";
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(j==0 || j==3 || j==6 || j==9)
            {
                cout<<"||";
            }
            cout<<a[i][j];
            if(j<9)
            {
                cout<<" ";
            }
        }
        cout<<"||";
        if(i==2 || i==5 || i==8)
        {
            cout<<"\n";
            cout<<"  ______________________";
        }
        cout<<"\n";
    }
}

bool searchcol(int col,int ans)//TO CHECK IF THE ELEMENT IS PRESENT IN ITS COLUMN OR NOT
{
    for(int i=0;i<9;i++)
    {
        if(a[i][col]==ans)
            return false;
    }
    return true;
}

bool searchrow(int row,int ans)//FUNCTION TO CHECK IF THE ELEMENT IS PRESENT IN ITS ROW OR NOT
{
    for(int i=0;i<9;i++)
    {
        if(a[row][i]==ans)
            return false;
    }
    return true;
}


void check(int ans)//TO CHECK THE ENTERED ELEMENT THROUGHOUT
{
    bool flag1=0,flag2=0,flag3=0;

    cout<<"Enter Starting Row Number: ";
    cin>>row;
    cout<<"\n";
    cout<<"Enter Starting Column Number: ";
    cin>>col;
    cout<<"\n";
    cout<<"Enter Ending Row Number: ";
    cin>>en_row;
    cout<<"\n";
    cout<<"Enter Ending Column Number: ";
    cin>>en_col;
    cout<<"\n";

    for(int i=row;i<en_row;i++)
    {
        for(int j=col;j<en_col;j++)
        {
            flag1=0;
            flag2=0;
            flag3=0;
            if(a[i][j]==0)
            {
                cout<<"Enter Number: "<<"\n";
                cin>>ans;
              
                flag1=searchrow(row,ans);
                flag2=searchcol(col,ans);
                flag3=search_box(ans);
                if(!flag1 && !flag2 && flag3)
                {
                    a[i][j]=ans;
                    cout<<"Element Placed."<<"\n";
                }
                else
                {
                    cout<<"Element is already present."<<"\n";
                }
                cout<<"\nGRID IS:"<<"\n";
                cout<<"  ______________________"<<"\n";
                for(int i=0;i<9;i++)
                {
                    
                    for(int j=0;j<9;j++)
                    {
                        if(j==0 || j==3 || j==6 || j==9)
                        {
                            cout<<"||";
                        }
                        cout<<a[i][j];
                        if(j<9)
                        {
                            cout<<" ";
                        }
                    }
                    cout<<"||";
                    if(i==2 || i==5 || i==8)
                    {
                        cout<<"\n";
                        cout<<"  ______________________";
                    }
                    cout<<"\n";
                }
            }
        }
    }
}

bool search_box(int ans) //tO CHECK IF THE ELEMENT IS NOT PRESENT IN ITS BOX
{
    for(int i=row;i<en_row;i++)
    {
        for(int j=col;j<en_col;j++)
        {
            if(a[i][j]==ans)
            return false;
        }
    }
    return true;
}

void rules()//RULES OF THE GAME
{
    cout<<"\t\t\t\t\tYOU HAVE TO ENTER THE STARTING AND ENDING COLUMN NUMBER TO SPECIFY A BOX IN THE GRID.\n\n";
    cout<<"\t\t\t\t\tTHEN,YOU WILL HAVE TO ENTER THE NUMBER.\n\n";
    cout<<"\t\t\t\t\tIF THE ELEMENT IS PRESENT IN THE ROW OR COLUMN OR IN THE BOX,THE MESSAGE 'ELEMENT ALREADY PRESENT' WILL BE DISPLAYED.\n\n";
    cout<<"\t\t\t\t\tIF THE ELEMENT IS NOT PRESENT IN ANY OF THE GIVEN, IT WILL BE PLACED IN THAT SPECIFIC CELL.\n\n";
    cout<<"\t\t\t\t\tTHE GAME WILL END WHEN ALL OF THE BOXES ARE FILLED.\n\n";
}

bool end_game()//TO CHECK IF THE GAME HAS ENDED OR NOT
{
    bool flag=0;
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(a[i][j]!=0)
            return true;
        }
    }
    return false;
}