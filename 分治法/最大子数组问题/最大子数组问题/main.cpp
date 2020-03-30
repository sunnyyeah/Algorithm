#include<iostream>
#include<vector>
using namespace std;

// 求解跨越中心的最大子数组
int cross_max_subarray(vector<int> & a, int & low, int mid, int & high) {
	int sum_L = 0, sum_R = 0;		// 左右两边的累加和
	int max_L = INT_MIN;		// 左边的最大值
	int max_R = INT_MIN;		// 右边的最大值
	int min_i;					// 左边最大值的脚标
	int max_j;					// 右边最大值的脚标

	// 从mid往low计算子数组的最大和
	for (int i = mid; i >= low; i--) {
		sum_L += a[i];
		if (sum_L > max_L) {
			max_L = sum_L;
			min_i = i;
		}
	}

	// 从mid+1往high计算子数组最大和
	for (int j = mid + 1; j <= high; j++) {
		sum_R += a[j];
		if (sum_R > max_R) {
			max_R = sum_R;
			max_j = j;
		}
	}

	low = min_i;		// 返回左边脚标
	high = max_j;		// 返回右边角标

	return max_L + max_R;
}

// 递归求解原问题
int max_subarray(vector<int> &a, int low, int high) {
	if (low == high)
		return a[low];
	else{
		int mid = (low + high) / 2;
		int L, R, M;
		L = max_subarray(a, low, mid);				// 求解左边的子问题
		R = max_subarray(a, mid + 1, high);			// 求解右边的子问题
		M = cross_max_subarray(a, low, mid, high);	// 求解跨中心的子问题

		//cout << low << "," << high << endl;		// 输出每次最大子数组的区间，最后一个为最大的数组区间

		// 判断三个子问题中哪个返回的值最大
		if (L >= R && L >= M)
			return L;
		else
			if (R >= L && R >= M)
				return R;
			else
				return M;
		
	}
}

int main() {
	int n[] = { 13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7 };
	vector<int> a(n, n+16);

	// 输出
	for (int i = 0; i < a.size(); i++)
		cout << a[i] << " ";

	cout << endl;

	int result;
	result = max_subarray(a, 0, a.size()-1);
	cout << result << endl;
	
	return 0;
}