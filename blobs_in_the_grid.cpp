
#include <iostream>
using namespace std;

#define ROWC 3
#define COLUMNC 11

class Grid
{
	friend istream& operator>>(istream& in, Grid& g){
		int num1 = 0;
		int num2 = 0;
		for (int i = 0; i < g.asteriskCount; i++){
			cin >> num1 >> num2;
			g.m[num1][num2] = 1;
		} return in;
	}

	friend ostream& operator<<(ostream& out, Grid& g){
		for (int i = 0; i < ROWC; i++) {
			for (int j = 0; j < COLUMNC; j++) {
				if (g.m[i][j] != 1) {
					g.m[i][j] = 0;
				}
			} 
		}
		return out;
	}
	
public:
	Grid(){
		cin >> asteriskCount;
	}
	int isSafe(int M[][COLUMNC], int row, int col, bool visited[][COLUMNC]) {
		return (row >= 0) && (row < ROWC) && (col >= 0) && (col < COLUMNC) && (M[row][col] && !visited[row][col]);
	}

	void DFS(int M[][COLUMNC], int row, int col, bool visited[][COLUMNC]) {
		static int rowNbr[] = { -1, 0, 0, 1 };
		static int colNbr[] = { 0,-1, 1, 0 };

		visited[row][col] = true;

		for (int k = 0; k < 4; ++k) {
			if (isSafe(M, row + rowNbr[k], col + colNbr[k], visited)) {
				DFS(M, row + rowNbr[k], col + colNbr[k], visited);
			}
		}
	}
	int computeNumberOfBlobs() {
		bool visited[ROWC][COLUMNC];
		memset(visited, 0, sizeof(visited));

		int count = 0;
		for (int i = 0; i < ROWC; ++i) {
			for (int j = 0; j < COLUMNC; ++j) {
				if (m[i][j]) {
					cout << "*";
					if (!visited[i][j]) {
						DFS(m, i, j, visited);
						++count;
					}
				} else {
					cout << " ";
				}
			} cout << endl;
		} 
		return count;
	}
private:
	int asteriskCount;
	int m[ROWC][COLUMNC];
};

int main()
{
	Grid g1;

	cin >> g1;

	cout << g1;

	cout << g1.computeNumberOfBlobs() << endl;

	return 0;
}

