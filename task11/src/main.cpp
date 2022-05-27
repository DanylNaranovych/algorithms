#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;
#define N 20
int temp = 0;

void SelectionSort(int a[]) {
  int i, j, nMin, min;
  for (i = 0; i < N; i++) {
    temp++;
    nMin = i;
    min = a[i];
    for (j = i + 1; j < N; j++) { // цикл вибору найменшого елемента
      if (a[j] < min) {
        nMin = j;   // індекс найменшого елемента
        min = a[j]; // значення найменшого елемента
        temp++;
      }
      temp++;
    }
    a[nMin] = a[i];
    a[i] = min; // міняємо місцями найменший з a
  }
}
void BubblePlaseSort(int a[]) {
  int c, n = N;
  do {
    c = 0;
    for (int i = 0; i < n; i++) {
      if (a[i - 1] > a[i]) {
        swap(a[i - 1], a[i]);
        c = i;
        temp++;
      }
      temp++;
    }
    n = c;
    temp++;
  } while (n != 0);
}

int main() {
  int arr1[N], arr2[N];
  time_t start1, start2, end1, end2;
  cout << "\tElements arr1 before sorting:" << endl;
  for (int i = 0; i < N; i++) {
    arr1[i] = rand() % 1000;
    cout << arr1[i] << ' ';
  }
  cout << endl;
  start1 = clock();
  SelectionSort(arr1);
  end1 = clock();
  cout << "\tElements arr1 after sorting:" << endl;
  for (int i = 0; i < N; i++)
  {
      cout << arr1[i] << ' ';
  }
  cout << endl;
  cout << "Time spent on exchange sorting by sampling: " << (end1 - start1) << endl;
  cout << "Number of comparisons: " << temp << endl;
  temp = 0;
  cout << "\tElements arr2 before sorting:" << endl;
  for (int i = 0; i < N; i++) {
    arr2[i] = rand() % 1000;
    cout << arr2[i] << ' ';
  }
  cout << endl;
  start2 = clock();
  BubblePlaseSort(arr2);
  end2 = clock();
  cout << "\tElements arr2 after sorting:" << endl;
  for (int i = 0; i < N; i++)
  {
      cout << arr2[i] << ' ';
  }
  cout << endl;
  cout << "Time is spent on bubble sorting with memorizing the location of the last permutation: " << (end2 - start2) << endl;
  cout << "Number of comparisons: " << temp << endl;

  return 0;
}