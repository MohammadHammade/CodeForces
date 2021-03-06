#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAX_N = 1e3 + 5, NO_OF_DIRECTIONS = 4;
char grid[MAX_N][MAX_N];
int X[MAX_N][MAX_N], Y[MAX_N][MAX_N];
char direction[NO_OF_DIRECTIONS] = {'U', 'R', 'L', 'D'};
char reverse_direction[NO_OF_DIRECTIONS] = {'D', 'L', 'R', 'U'};
int next_x[NO_OF_DIRECTIONS] = {-1, 0, 0, 1};
int next_y[NO_OF_DIRECTIONS] = {0, 1, -1, 0};

void find_looping_partner(int i, int j)
{
    for(int d = 0; d < NO_OF_DIRECTIONS; d++)
    {
        int next_i = i + next_x[d];
        int next_j = j + next_y[d];
        
        if(X[next_i][next_j] == -1 && Y[next_i][next_j] == -1)
        {
            grid[i][j] = direction[d];
            grid[next_i][next_j] = reverse_direction[d];
            
            return;
        }
    }
}

void dfs(int i, int j, int final_x, int final_y, char D)
{
    grid[i][j] = D;
    
    for(int d = 0; d < NO_OF_DIRECTIONS; d++)
    {
        int next_i = i + next_x[d];
        int next_j = j + next_y[d];
        
        if(grid[next_i][next_j] != 0)
        {
            continue;
        }
       
        if(X[next_i][next_j] == final_x && Y[next_i][next_j] == final_y)
        {
            dfs(next_i, next_j, final_x, final_y, reverse_direction[d]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> X[i][j] >> Y[i][j];
        }
    }
    
    memset(grid, 0, sizeof(grid));
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(grid[i][j] != 0)
            {
                continue;
            }
            
            if(X[i][j] == i && Y[i][j] == j)
            {
                dfs(i, j, X[i][j], Y[i][j], 'X');
            }
            
            if(X[i][j] == -1 && Y[i][j] == -1)
            {
                find_looping_partner(i, j);
            }
        }
    }
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(grid[i][j] == 0)
            {
                cout << "INVALID\n";
                
                return 0;
            }
        }
    }
    
    cout << "VALID\n";
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cout << grid[i][j];
        }
        
        cout << "\n";
    }
    
    return 0;
}
