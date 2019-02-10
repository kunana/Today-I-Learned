### 이진탐색 알고리즘
#### 2019-02-10

1. 데이터가 정렬되어있어야 함
2. 시간 복잡도 O(log2(n)) , 최악의 경우일때 탐색횟수는 log2(n) + 1
3. 평균적으로 선형탐색법 보다 탐색속도가 빠르나, 원하는 데이터가 앞쪽, 혹은 뒷쪽일때는 선형탐색이 더 빠르다.
4. 그러므로 데이터의 양, 저장 상황, 정렬 상황에 따라 적절한 알고리즘을 사용하자.
 
```cpp
#include <iostream>
using namespace std;

//바이너리 서치
int main()
{
	int datas[] = { 1,2,4,8,15,21,32,56,58,60 };
	int head = 0, input = 0, center = 0, count = 1;
	int tail = sizeof(datas) / sizeof(int) - 1;	//배열의 갯수 구함
	cin >> input;								//찾을 데이터 입력

	while (datas[center] != input)				//센터가 인풋과 같은지
	{
		if (head >= tail)						// 헤드가 테일보다 작거나 같은가?
		{
			cout << "찾는 데이터가 없습니다";
			return -1;
		}
		center = (head + tail) / 2;

		if (datas[center] > input)				//센터의 데이터가 인풋보다 큰가?
			tail = center - 1; 					//크다면 테일은 센터 - 1
		else
			head = center + 1;					//작다면 헤드는 센터 + 1
		count++;
	}
	//같다면 리턴;
	cout << "원하는 데이터의 요소 번호는 : " << datas[center] << '/n';
	cout << "시도 횟수 : " << count;
	return 0;
}
```

> 재귀 탐색

```cpp
//이진 탐색 재귀
int BinarySearch(int data[], int head, int tail, int target)
{
	int center = head + tail / 2;
	if (head >= tail)
		return -1;
	if (data[center] == target)
		return data[center];
	else if (data[center] > target)
		BinarySearch(data, head, tail - 1, target);
	else
		BinarySearch(data, head, tail - 1, target);
	return 0;
}
```