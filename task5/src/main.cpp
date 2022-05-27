#include <cstdlib>
#include <ctime>
#include <iostream>
#define size 20

void gener_array(int arr[size][size]) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if ((i % 2 == 0) && (j % 2 == 0)) {
        arr[i][j] = rand() % 50;
      } else {
        arr[i][j] = 0;
      }
    }
  }
}
void get_vec(int arr[size][size], int vec[size * size / 4]) {
  int temp = 0;
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if ((i % 2 == 0) && (j % 2 == 0)) {
        vec[temp] = arr[i][j];
        temp++;
      }
    }
  }
}
void print_array(int arr[size][size]) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      std::cout << arr[i][j] << "\t";
    }
    std::cout << std::endl;
  }
}
void print_vec(int vec[size * size / 4]) {
  for (int i = 0; i < size * size / 4; i++) {
    std::cout << vec[i] << " ";
  }
  std::cout << std::endl;
}
void print_vec_like_arr(int vec[size * size / 4]) {
  int temp = 0;
  int temp1 = 0;
  if (size % 2 == 0) {
    for (int i = 0; i < size; i++) {
      if (temp % 2 == 0) {
        for (int j = 0; j < size / 2; j++) {
          std::cout << vec[temp1] << "\t"
                    << "0"
                    << "\t";
          temp1++;
        }
        std::cout << std::endl;
      } else {
        for (int j = 0; j < size; j++) {
          std::cout << "0"
                    << "\t";
        }
        std::cout << std::endl;
      }
      temp++;
    }
  } else {
    for (int i = 0; i < size; i++) {
      if (temp % 2 == 0) {
        for (int j = 0; j < size / 2; j++) {
          if (j % 2 != 0) {
            std::cout << "0"
                      << "\t";
          } else {
            std::cout << vec[temp1] << "\t";
			temp1++;
          }
        }
        std::cout << std::endl;
      } else {
        for (int j = 0; j < size; j++) {
          std::cout << "0"
                    << "\t";
        }
        std::cout << std::endl;
      }
      temp++;
    }
  }
}

int main() {
  int arr[size][size];
  int vec[size * size / 4];
  time_t start1, start2, end1, end2;
  gener_array(arr);
  get_vec(arr, vec);
  start1 = clock();
  std::cout << "array:\n";
  print_array(arr);
  end1 = clock();
  std::cout << "Час витрачений на вивід array: " << (end1 - start1)
            << std::endl;
  std::cout << "vector:\n";
  print_vec(vec);
  start2 = clock();
  std::cout << "vector like array:\n";
  print_vec_like_arr(vec);
  end2 = clock();
  std::cout << "Час витрачений на вивід vec: " << (end2 - start2) << std::endl;
  return 0;
}