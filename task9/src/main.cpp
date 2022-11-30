#define N 10000
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;
int count = 0;

void bubble_sort(int arr[]) {
  int temp;
  for (int i = 0; i < N - 1; i++) {
    for (int j = 0; j < N - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}
int ExponentialSearch(int arr[], int key) {
  int i = 1; // визначення інтервалу в якому ключ
  while (i < N && arr[i] < key) {
    count++;
    i *= 2;
  }
  int m,
      b = i / 2,
      e = (i + 1 < N) ? i + 1
                      : N; // початкові значення кордонів знайденого інтервалу
  while (b <= e) // поки інтервал звузиться до 0
  {
    count++;
    m = (b + e) / 2; //середина інтервалу
    if (arr[m] >= key) {
      count++;
      e = m - 1;
    } else {
      count++;
      b = m + 1;
    }
  }
  if (arr[b] == key) {
    count++;
    return b;
  } else {
    count++;
    return -1;
  }
}
int InterpolSearch(int arr[], int key) {
  int m, b = 0, e = N - 1;
  while (arr[b] <= key && arr[e] >= key) {
    count++;
    m = b + ((key - arr[b]) * (e - b)) / (arr[e] - arr[b]);
    if (arr[m] < key) {
      count++;
      b = m + 1;
    } else {
      if (arr[m] > key) {
        count++;
        e = m - 1;
      } else {
        count++;
        return m;
      }
    }
  }
  if (arr[b] == key) {
    count++;
    return b;
  } else {
    count++;
    return -1;
  }
}

int main() {
  srand((unsigned)time(NULL));
  int arr[N];
  for (int i = 0; i < N; i++) {
    arr[i] = rand() % 50;
  }
  bubble_sort(arr);
  time_t start1, start2, end1, end2;
  start1 = clock();
  int rez1 = ExponentialSearch(arr, 5);
  end1 = clock();
  if (rez1 == -1) {
    cout << "There is no number 5 in the array" << endl;
  } else {
    cout << "Position of the figure 5: " << rez1 << endl;
  }
  cout << "Time spent searching exponentially: " << (end1 - start1) << endl;
  cout << "Number of comparisons: " << count << endl;
  count = 0;
  start2 = clock();
  int rez2 = InterpolSearch(arr, 3);
  end2 = clock();
  if (rez2 == -1) {
    cout << "There is no number 3 in the array" << endl;
  } else {
    cout << "Position of the figure 3: " << rez2 << endl;
  }
  cout << "Time spent searching by interpolation method: " << (end2 - start2)
       << endl;
  cout << "Number of comparisons: " << count << endl;
  return 0;
}