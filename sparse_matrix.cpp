#include<iostream>
#define srow 50
#define mrow 20
#define mcolumn 20

using namespace std;

int main()
{
	int matrix[mrow][mcolumn];
	int matrixSparse[srow][3];
	int count=0,row,column;
	int index = 0;

	cin >> row;
	cin >> column;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			cin >> matrix[i][j];
		}
	}

	for(int i=0;i< row;i++){
		for(int j=0;j< column;j++){
			if(matrix[i][j]!=0)
				count++;
		}
	}

	cout << row << " " << column << endl;
	cout << count << endl;

	for(int i=0;i< row;i++){
		for (int j = 0; j < column; j++) {
			if (matrix[i][j] != 0) {
				matrixSparse[index][0] = i;
				matrixSparse[index][1] = j;
				matrixSparse[index][2] = matrix[i][j];
				index++;
			}
		}
	}

	for(int i=0;i<count;i++){
		for (int j = 0; j < 3; j++) {
			cout << matrixSparse[i][j] << " ";
		}
		cout << endl;
	}
}