#include <iostream>
using namespace std;
int time = 0;
void hanoi(int disks, char source, char temp, char target) {

	if (disks == 1) {
		cout << "move disk from " << source << " to " << target << endl;
		time++;
		cout << "move disk from " << source << " to " << target << endl;
		time++;
	}
	else {
		hanoi(disks - 1, source, target, temp);
		hanoi(1, source, temp, target);
		hanoi(disks - 1, temp, source, target);
	}

}

void hanoi2colors(int disks) {
	char source = 'A';
	char temp = 'B';
	char target = 'C';
	int i;
	for (i = disks / 2; i > 1; i--) { //a->c a->b c->a b->c
		hanoi(i - 1, source, temp, target);
		cout << "move disk from " << source << " to " << temp << endl;
		time++;
		cout << "move disk from " << source << " to " << temp << endl;
		time++;
		hanoi(i - 1, target, temp, source);
		cout << "move disk from " << source << " to " << target << endl;
		time++;
	}
	cout << "move disk from " << source << " to " << temp << endl;
	time++;
	cout << "move disk from " << source << " to " << target << endl;
	time++;
}

int main() {
	int n;
	while (true) {
		cout << "請輸入盤數：";
		cin >> n;
		hanoi2colors(n);
		cout << "次數:" << time<<endl;
		time = 0;
	}
	return 0;
}
