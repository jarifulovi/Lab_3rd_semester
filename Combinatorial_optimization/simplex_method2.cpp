#include<iostream>
#include<vector>
using namespace std;

class Tableau{
    public :
        vector<vector<double>> table;
        int rows,cols;
    
        // Function to print the tableau for debugging
        void printTableau() {
            cout << "Table for llp : \n";
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    cout << table[i][j] << "\t";
                }
                cout << endl;
            }
            cout << endl;
        }
};
bool simplex(Tableau& tableau) {
    while(true){
        // Find the pivot column (the most negative coefficient in the objective row)
        int pivotCol = -1;
        for (int j = 0; j < tableau.cols - 1; j++) {
            if (tableau.table[0][j] < 0) {
                if (pivotCol == -1 || tableau.table[0][j] < tableau.table[0][pivotCol]) {
                    pivotCol = j;
                }
            }
        }
        if (pivotCol == -1) {
            // If no negative coefficients in the objective row, we are done
            return true;
        }
        // Find the pivot row (the smallest ratio of right-hand side to pivot column coefficient)
        int pivotRow = -1;
        double minRatio = -1;
        for (int i = 0; i < tableau.rows; i++) {
            if (tableau.table[i][pivotCol] > 0) {
                double ratio = tableau.table[i][tableau.cols - 1] / tableau.table[i][pivotCol];
                if (pivotRow == -1 || ratio < minRatio) {
                    pivotRow = i;
                    minRatio = ratio;
                }
            }
        }
        if (pivotRow == -1) {
            // If no positive coefficients in the pivot column, the problem is unbounded
            return false;
        }
        // Perform pivot operation to make the pivot element 1 and update the tableau
        double pivotElement = tableau.table[pivotRow][pivotCol];
        for (int j = 0; j < tableau.cols; j++) {
            tableau.table[pivotRow][j] /= pivotElement;
        }
        // Make the other elements in the pivot column zero
        for (int i = 0; i < tableau.rows; i++) {
            if (i != pivotRow) {
                double factor = tableau.table[i][pivotCol];
                for (int j = 0; j < tableau.cols; j++) {
                    tableau.table[i][j] -= factor * tableau.table[pivotRow][j];
                }
            }
        }
    }
}


int main(){
    Tableau tableau;
    int con,var;
    cout << "Enter number of constrains and variables\n";
    cin >> con >> var;
    // resize table vector
    tableau.rows = con + 1;
    tableau.cols = var + con + 2;
    tableau.table.resize(tableau.rows, vector<double>(tableau.cols, 0));
    cout << "Enter objective function in standard form( c1x1 + c2x2 + ... = cnz excluding z )\n";
    for(int i=0;i<tableau.cols;i++){
        if(i<var)
        cin >> tableau.table[0][i];
        else if(i == tableau.cols-2)
        tableau.table[0][i] = 1;   // z coefficient part
        else
        tableau.table[0][i] = 0;  
    }
    cout << "Enter the coefficient of constrains(only variable's coefficient)\n";
    for(int i=1;i<tableau.rows;i++){
        cout << "Enter left-hand coefficient\n";
        for(int j=0;j<tableau.cols-1;j++){
            if(j<var)
            cin >> tableau.table[i][j];
            else if(j==var+i-1)
            tableau.table[i][j] = 1;  // slack variable coefficient
            else 
            tableau.table[i][j] = 0;  // other coefficient
        }
        cout << "Enter right-hand value\n";
        cin >> tableau.table[i][tableau.cols-1];
    }
    if(simplex(tableau)){
        tableau.printTableau();
        cout << "\nOptimal solution : " << tableau.table[0][tableau.cols-1] << "\n";
        cout << "optimal solution for variables :\n";
        // basic part
        for(int i=0;i<var;i++){    // every col except the value col
            bool isBasic = true;
            int temp = 0;                    // finding a only 1 coefficient
            int solution = -1;
            for(int j=0;j<tableau.rows;j++){   
                //if(tableau.table[j][i]==1) solution = tableau.table[j][tableau.cols-1];
                //if(tableau.table[j][i]==0||tableau.table[j][i]==1||temp<=1) isBasic = true;
                if(tableau.table[j][i]==1){
                    temp++;
                    solution = tableau.table[j][tableau.cols-1];
                }
                else if(tableau.table[j][i]!=0) isBasic = false;
            }
            if(temp!=1) isBasic = false; 
            if(isBasic)
            cout << "X " << i+1 << " : " << solution << "\n";
            else 
            cout << "X " << i+1 << " : " << solution << "\n";
        }
    }
    else {
        cout << "The problem is unbounded\n";
    }
    return 0;
}