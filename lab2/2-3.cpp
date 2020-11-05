#include <iostream>
#include<fstream>

using namespace std;

long long int MergeSort(long long int Arr[], long long int Sub_Arr[], int left, int right);
long long int Merge(long long int Arr[], long long int Sub_Arr[], int left, int mid, int right);

long long int Merge__Sort(long long int Arr[], int array_size)
{
long long int Sub_Arr[array_size];
return MergeSort(Arr, Sub_Arr, 0, array_size - 1);
}

long long int MergeSort(long long int Arr[], long long int Sub_Arr[], int left, int right)
{
int mid;
long long int counting = 0;
if (right > left)
{

mid = (right + left) / 2;

counting = MergeSort(Arr, Sub_Arr, left, mid);
counting += MergeSort(Arr, Sub_Arr, mid + 1, right);

counting += Merge(Arr, Sub_Arr, left, mid + 1, right);
}
return counting;
}

long long int Merge(long long int Arr[], long long int Sub_Arr[], int left,
int mid, int right)
{
int i = left;
int j = mid;
int k = left;
long long int counting = 0;

while ((i <= mid - 1) && (j <= right))
{
if (Arr[i] <= Arr[j])
{
Sub_Arr[k++] = Arr[i++];
}
else
{
Sub_Arr[k++] = Arr[j++];
counting = counting + (mid - i);
}
}

while (i <= mid - 1)
Sub_Arr[k++] = Arr[i++];

while (j <= right)
Sub_Arr[k++] = Arr[j++];

for (i = left; i <= right; i++)
Arr[i] = Sub_Arr[i];

return counting;
}

int main()
{
freopen("inversions.in", "r", stdin);
freopen("inversions.out", "w", stdout);

int n;
cin >> n;
long long int Arr[n];
for(int i = 0; i < n; i++)
{
cin >> Arr[i];
}

cout << Merge__Sort(Arr, n);
return 0;
}
