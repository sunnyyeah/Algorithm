/// 说明：
/// 设要移动的圆盘数位n，A B C为柱子编号
/// ①当n = 1时，直接将圆盘从A移到C ———— 可作为终止条件
/// ②当n = 2时，先将第一个圆盘移到B，再将第二个圆盘移到C，最后将第一个圆盘移到C。那么圆盘的运行轨迹为：A-B，A-C，B-C
/// ③当n > 2时，可以将1到n-1个圆盘当成一个整体，作为第一个圆盘，而第n个圆盘单独作为一个整体，作为第二个圆盘，那么它们的移动轨迹为：A-B（n-1个），A-C（第n个），B-C（n-1个）
/// 使用hanoi(n, A, B, C)对圆盘进行移动，该调用函数表示，有n个圆盘从A移到C。

#include <iostream>
using namespace std;

int k = 0;			// 总移动次数

// 递归操作
void hanoi(int n, char A, char B, char C) {
	/// 函数说明：
	/// 1. A移到C，B为辅组。
	// 终止条件：只有一个圆盘，直接A-C
	if (n == 1) {
		cout << "将1个圆盘从" << A << "移到" << C << endl;
		k += 1;
	}
		
	else {
		hanoi(n - 1, A, C, B);   // 将n-1个圆盘从A移到B
		cout << "将" << n - 1 << "个圆盘从" << A << "移到" << C << endl;// 将第n个圆盘从A移动C
		k += 1;
		hanoi(n - 1, B, A, C);	// 将n-1个圆盘从B移到C
	}
}

int main() {
	int n;
	cout << "输入圆盘个数：";
	cin >> n;
	// A B C为柱子编号
	hanoi(n, 'A', 'B', 'C');

	cout << "共移动了" << k << "次" << endl;

	cin.get();
	cin.get();
	return 0;
}