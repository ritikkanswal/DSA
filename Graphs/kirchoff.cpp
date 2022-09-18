#include <bits/stdc++.h>
using namespace std;

class Graph {
  public:
  vector<vector<int>>adjMatrix;
  int n;
  Graph(int n) {
    this->n = n;
    vector<vector<int>>v(n,vector<int>(n,0));
    adjMatrix=v;
  }

  
  void addEdge(int i, int j) {
    adjMatrix[i][j] = true;
    adjMatrix[j][i] = true;
  }

  
  void removeEdge(int i, int j) {
    adjMatrix[i][j] = false;
    adjMatrix[j][i] = false;
  }

  
  void printAdjMatrix() {
    for (int i = 0; i < n; i++) {
      cout << i << " : ";
      for (int j = 0; j < n; j++)
        cout << adjMatrix[i][j] << " ";
      cout << "\n";
    }
  }
    int d=0;
    int det(vector<vector<int>> &mat, int n)
{
    vector<vector<int>> submat(n, vector<int>(n));
    if (n == 2)
        return ((mat[0][0] * mat[1][1]) - (mat[1][0] * mat[0][1]));
    else
    {
        for (int c = 0; c < n; c++)
        {
            int subi = 0;
            for (int i = 1; i < n; i++)
            {
                int subj = 0;
                for (int j = 0; j < n; j++)
                {
                    if (j == c)
                        continue;
                    submat[subi][subj] = mat[i][j];
                    subj++;
                }
                subi++;
            }
            d = d + (pow(-1, c) * mat[0][c] * det(submat, n - 1));
        }
    }
    return d;
}
  int kirchoff(){

    vector<vector<int>> mat(n - 1, vector<int>(n - 1, 0));
    vector<vector<int>> final(n, vector<int>(n, -1));
    for (int i = 0; i < n; i++)
    {
        final[i][i] += 1;
        for (int j = 0; j < n; j++)
        {
            final[i][i] += adjMatrix[i][j];
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            mat[i - 1][j - 1] = final[i][j];
        }
    }
    int d =det(mat, n - 1);
    return d;
  }
};

int main() {
  Graph g(4);

  g.addEdge(0,2);
  g.addEdge(0,3);
  g.addEdge(2,1);
  g.addEdge(2,3);
  g.addEdge(1,3);
  g.printAdjMatrix();
  cout<<g.kirchoff();
}