#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::string;

unsigned int ComputeEditingDistance(string str1, string str2)
{
    unsigned int i, j, m, n;
    i=j=n=m=0;
    unsigned int ins, del, match, mis_match;
    n = (unsigned int)str1.size();
    m = (unsigned int)str2.size();
    unsigned int D_matrix[n+1][m+1];
    
    //Initialize Editing distance of 1st symbols
    for (i=0; i <= n; i++) {
        D_matrix[i][0] = i;
    }
    
    for (j=0; j <= m; j++) {
        D_matrix[0][j] = j;
    }
    
    for (j=1; j<=m; j++)
    {
        for (i=1; i<=n; i++)
        {
            ins = D_matrix[i][j-1] + 1;
            del = D_matrix[i-1][j] + 1;
            match = D_matrix[i-1][j-1];
            mis_match = D_matrix[i-1][j-1] + 1;
            
            if (str1[i-1] == str2[j-1])
                D_matrix[i][j] = std::min({ins, del, match});
            else
                D_matrix[i][j] = std::min({ins, del, mis_match});
            
            //cout << D_matrix[i][j] << endl;
        }
    }
    
    return D_matrix[n][m];
}

int main_editDist()
{
    string str1, str2;
    unsigned int editingDistance=0;
    cin >> str1;
    cin >> str2;
    //cout << str1 << " " << str2;
    editingDistance = ComputeEditingDistance(str1, str2);
    cout << editingDistance << endl;
    return 1;
}
