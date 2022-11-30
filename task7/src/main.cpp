#include <iostream>
using namespace std;
#define size 10

struct Deq {
  int storage[size];
  int act_size = 0, start = 0, end = size - 1;
};
void print_deq(struct Deq d) {
  cout << "Our deq:" << endl;
  for (int i = 0; i < size; i++) {
    cout << "[" << i << "] " << d.storage[i] << endl;
  }
}
void bring(struct Deq d) {
  int temp;
  cout << "Enter the number in the deck:" << endl;
  cin >> temp;
  if (d.storage[d.end] == 0) {
    int temp_arr[size];
    for (int i = 0; i < d.end; i++) {
      temp_arr[i + 1] = d.storage[i];
    }
    temp_arr[d.start] = temp;
    for (int i = 0; i < size; i++) {
      d.storage[i] = temp_arr[i];
    }
  } else {
    int temp_arr[d.end];
    for (int i = 0; i < d.end; i++) {
      temp_arr[i] = d.storage[i];
    }
    d.storage[d.start] = d.storage[d.end];
    for (int i = 1; i < d.end; i++) {
      d.storage[i + 1] = temp_arr[i];
    }
    d.storage[d.start + 1] = temp;
  }
  print_deq(d);
  d.act_size++;
}

int main() {
  struct Deq d;
  for (int i = 0; i < size; i++) {
    d.storage[i] = 0;
  }
  d.storage[d.end] = 1;
  d.act_size++;
  bring(d);
  cout << d.storage[d.end] << endl;
  d.start++;
  bring(d);
  if (d.act_size == size) {
    cout << "deq is full!" << endl;
  }

  return 0;
}