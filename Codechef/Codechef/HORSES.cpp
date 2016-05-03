//https://www.codechef.com/problems/HORSES

#include<iostream>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		long *skills = new long[n];

		for (int j = 0; j < n; j++) {
			cin>>skills[j];
		}

		//We need to find two elements whose difference is minimum
		long diff = abs(skills[0] - skills[1]);

		for (int k = 0; k < n; k++) {
			for (int l = 0; l < k; l++) {
				if (k != l && diff > abs(skills[k] - skills[l])) {
					diff = abs(skills[k] - skills[l]);
				}
			}
		}
		cout << diff << endl;
	}

	return 0;
}