#include<iostream>
#include<vector>
using namespace std;

// ����Խ���ĵ����������
int cross_max_subarray(vector<int> & a, int & low, int mid, int & high) {
	int sum_L = 0, sum_R = 0;		// �������ߵ��ۼӺ�
	int max_L = INT_MIN;		// ��ߵ����ֵ
	int max_R = INT_MIN;		// �ұߵ����ֵ
	int min_i;					// ������ֵ�Ľű�
	int max_j;					// �ұ����ֵ�Ľű�

	// ��mid��low���������������
	for (int i = mid; i >= low; i--) {
		sum_L += a[i];
		if (sum_L > max_L) {
			max_L = sum_L;
			min_i = i;
		}
	}

	// ��mid+1��high��������������
	for (int j = mid + 1; j <= high; j++) {
		sum_R += a[j];
		if (sum_R > max_R) {
			max_R = sum_R;
			max_j = j;
		}
	}

	low = min_i;		// ������߽ű�
	high = max_j;		// �����ұ߽Ǳ�

	return max_L + max_R;
}

// �ݹ����ԭ����
int max_subarray(vector<int> &a, int low, int high) {
	if (low == high)
		return a[low];
	else{
		int mid = (low + high) / 2;
		int L, R, M;
		L = max_subarray(a, low, mid);				// �����ߵ�������
		R = max_subarray(a, mid + 1, high);			// ����ұߵ�������
		M = cross_max_subarray(a, low, mid, high);	// �������ĵ�������

		//cout << low << "," << high << endl;		// ���ÿ���������������䣬���һ��Ϊ������������

		// �ж��������������ĸ����ص�ֵ���
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

	// ���
	for (int i = 0; i < a.size(); i++)
		cout << a[i] << " ";

	cout << endl;

	int result;
	result = max_subarray(a, 0, a.size()-1);
	cout << result << endl;
	
	return 0;
}