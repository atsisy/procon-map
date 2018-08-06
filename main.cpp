#include <iostream>
#include <stdio.h>
#include <time.h>
using namespace std;

inline void InitRand()
{
	srand((int)time(NULL));
}

inline int random()
{
	return rand() % 3 + 1;
}

int sign(int n)
{
	return (rand() % 5 < 1) ? n *= -1 : n;
}

int main()
{
	int date[12][12] = {};
	int x, y, half_X = 0, half_Y = 0;
	int h, i, j;
	int rem_x, rem_y;

	InitRand();

	cin >> x >> y;

	(x % 2) ? rem_x = 1 : rem_x = 0;
	(y % 2) ? rem_y = 1 : rem_y = 0;

	half_X = x / 2;
	half_Y = y / 2;

	for (i = 0; i < half_Y; i++) {
		for (j = 0; j < half_X; j++) {
			date[i][j] = sign(random());
			//cout << date[i][j] << ' ';
		}
		cout << endl;
	}

	cout << endl;

	if (rem_x) {
		for (i = 0; i < y; i++) {
			date[i][half_X] = sign(random());
		}
	}

	if (rem_y) {
		for (i = 0; i < x; i++) {
			date[half_Y][i] = sign(random());
		}
	}

	for (h = 0; h <= half_Y; h++) {
		for (i = 0; i <= half_X; i++) {
			for (j = x; j >= half_X - 1; j--) {
				if (x - i - j == 1) {
					date[h][j] = date[h][i];
				}
			}
		}
	}

	for (h = 0; h <= half_Y; h++) {
		for (i = 0; i <= half_X; i++) {
			for (j = y; j >= half_Y - 1; j--) {
				if (y - h - j == 1) {
					date[j][i] = date[h][i];
				}
			}
		}
	}

	for (h = half_Y; h <= y; h++) {
		for (i = 0; i <= half_X; i++) {
			for (j = x; j >= half_X - 1; j--) {
				if (x - i - j == 1) {
					date[h][j] = date[h][i];
				}
			}
		}
	}

	for (i = 0; i < y; i++) {
		for (j = 0; j < x; j++) {
			printf("%3d", date[i][j]);
		}
		cout << endl;
	}

	return 0;
}
