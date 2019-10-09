#include<iostream>
using namespace std;
int dir[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };
int n; char mat[101][101];
int ly, lx;
int visited[101][101];
int key[26];
int cnt = 0;

void bfs(int y, int x)
{
	for (int i = 0; i < 4; i++)
	{
		int nx, ny;
		nx = x + dir[i][0];
		ny = y + dir[i][1];

		if (nx >= 0 && nx < lx && ny >= 0 && ny < ly && visited[ny][nx] == 0)
		{
			//ã�� ���
			if (mat[ny][nx] == '$')
			{
				cnt++;
				visited[ny][nx] = 1;
				bfs(ny, nx);
				
			}
			//�׳� .���ִ� ���
			if (mat[ny][nx] == '.')
			{
				visited[ny][nx] = 1;
				bfs(ny, nx);
				visited[ny][nx] = 0;
			}
			//�ҹ��ڸ� 
			//Ű�� �ݴ� ���.
 			else if (mat[ny][nx] - 'a' >= 0 && mat[ny][nx] - 'a' < 26)
			{
				key[mat[ny][nx] - 'a'] = 1;
				visited[ny][nx] = 1;
				bfs(ny, nx);
				visited[ny][nx] = 0;
			}
			//���� ������ ��� 
			else if (mat[ny][nx] - 'A' >= 0 && mat[ny][nx] - 'A' < 26)
			{
				//Ű�� ������ 
				if (key[mat[ny][nx] - 'A'] == 1)
				{
					visited[ny][nx] = 1;
					bfs(ny, nx);
					visited[ny][nx] = 0;
				}
			}
			//�׳� ���� ���.
		}
	}
}
int main() {


	cin >> n;
	string temp;

	for (int elisu = 0; elisu < n; elisu++) {
		cin >> ly >> lx;

		for (int i = 0; i < ly; i++)
			cin >> mat[i];

		cin >> temp;

		//0�̸� �׳� bfs
		//0�� �ƴϸ� key �� ����.
		if (temp[0] - '0' != 0)
		{
			for (int i = 0; i < temp.size(); i++)
				key[temp[i] - 'a'] = 1;

		}


		//�ι� ������ �ǰŵ� .
		int k = 0;
		while (k < 2) {
			for (int i = 0; i < ly; i++)
				for (int j = 0; j < lx; j++)
					if (mat[i][j] == '.' && (i == 0 || i == ly - 1 || j == 0 || j == lx - 1))
						bfs(i, j);
			k++;
		}
		//key �� ����.
		for (int i = 0; i < 26; i++)
			key[i] = 0;

		for (int i = 0; i < 101; i++)
			for (int j = 0; j < 101; j++)
			{
				visited[i][j] = 0;
				mat[i][j] = '0';
			}


		printf("%d\n", cnt);
		cnt = 0;
	}
	return 0;
}