#include <cstring>
#include <iostream>
using namespace std;
int size = 2;

struct Factory {
  string first_depart;
  string second_depart;
  struct Team *t;
};
struct Team {
  string first_emp;
  string second_emp;
};

void insert_team(struct Factory *f, size_t pos, struct Team *t) {
  struct Team *new_array = new Team[size + 1];
  if (pos > size) {
    pos = size;
  }
  memcpy(new_array, f->t,
         pos * sizeof(struct Team)); // beware of internal dynamic arrays within
                                     // Te s t E l e m e n
  memcpy(new_array + pos, t, sizeof(struct Team));
  memcpy(new_array + pos + 1, f->t + pos, (size - pos) * sizeof(struct Team));
  // delete[] f->t;
  f->t = new_array;
  size++;
}
void del_team(struct Factory *f, size_t index) {
  Team *st = new Team[size - 1];
  memcpy(st, f->t, sizeof(Team) * index);
  memcpy(st + index, (f->t + index + 1), sizeof(Team) * (size - index - 1));
  // delete[] f->t;
  f->t = st;
  size--;
}
void print_sublist(struct Team *t) {
  cout << "\tSublist Team:"
       << "\nFirst employee:\t"
       << "\t" << t->first_emp << "\nSecond employee:\t" << t->second_emp
       << endl;
}
void print_list(struct Factory *f) {
  cout << "\tList Factory:"
       << "\nFirst department:\t" << f->first_depart << "\nSecond department:\t"
       << f->second_depart << endl;
  for (int i = 0; i < size; i++) {
    cout << "First and second employee from struct number: " << i << endl;
    print_sublist(&f->t[i]);
  }
}
void del_list(struct Factory *f) { delete f; }

int main() {
  struct Team t[size];
  struct Factory f;
  for (int i = 0; i < size; i++) {
    cout << "Enter first and second employee for struct number: " << i << endl;
    cin >> t[i].first_emp >> t[i].second_emp;
  }
  for (int i = 0; i < size; i++) {
    cout << "Enter first and second department:" << endl;
    cin >> f.first_depart >> f.second_depart;
  }
  f.t = t;
  print_list(&f);
  struct Team temp;
  temp.first_emp = "abrakadabra";
  temp.second_emp = "asd";
  print_sublist(&temp);
  cout << "\tAdding an element" << endl;
  insert_team(&f, 1, &temp);
  print_list(&f);
  cout << "\tDeleting an element" << endl;
  del_team(&f, 2);
  print_list(&f);

  return 0;
}