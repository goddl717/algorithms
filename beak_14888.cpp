#include<iostream>
using namespace std;
//
int n; 
int arr[101];
int max1 = -999999999;
int min1 = 999999999;


void all_cal(int sum, int mode[4],int cnt)
{
	//Ż�� ����.
	if (cnt == n)
	{
		if (sum > max1)
		{
			max1 = sum;
		}
		if (sum < min1)
		{
			min1 = sum;
		}
		return;

	}
	// �ϳ��� ���鼭 ��� ��츦 Ž��.
	for (int i = 0; i < 4; i++)
	{
		if (mode[i] > 0)
		{
			int temp = sum;

			if (i == 0) {
				sum = sum + arr[cnt];
				mode[i]--;
				all_cal(sum, mode, cnt + 1);
				sum = temp;
				mode[i]++;
				
			}
			else if (i == 1) {
				sum = sum - arr[cnt];
				mode[i]--;
				all_cal(sum, mode, cnt + 1);
				sum = temp;
				mode[i]++;
			}
			else if (i == 2) {
				sum = sum * arr[cnt];
				mode[i]--;
				all_cal(sum, mode, cnt + 1);
				sum = temp;
				mode[i]++;
			}
			else if (i == 3) {
				sum = sum / arr[cnt];
				mode[i]--;
				all_cal(sum, mode, cnt + 1);
				sum = temp;
				mode[i]++;
			}
		}
	}
}
int main() {
	int mode[4];
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < 4; i++)
		cin >> mode[i];

	//��ü�� ����غ���. 
	int temp = 0;
	all_cal(arr[0], mode, 1);
	printf("%d ", max1);
	printf("%d ", min1);

	


}