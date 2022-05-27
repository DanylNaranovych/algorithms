#include <cstring>
#include <ctime>
#include <iostream>
using namespace std;
const int BlkSize = 8;        // число символів в блоці
typedef struct Block *BlkPtr; // покажчик на блок
struct Block                  // блок
{
  char chFirst, chLast; // номера 1-го і останнього символів
  char StrData[BlkSize]; // символи
  BlkPtr next;           // покажчик на наступний блок
};
BlkPtr NewBlock() {
  BlkPtr curr = new Block; // виділення пам'яті
  curr->next = NULL;       // початкові значення
  curr->chFirst = 0;
  curr->chLast = 7;
  return curr;
}

typedef struct StrNode2 *String2; // тип - СТРОКА ЗМІННОЮ ДОВЖИНИ
struct StrNode2                   // дескриптор рядку
{
  long len;           // довжина рядка
  BlkPtr first, last; // указ.на 1-й і останній блоки
};

String2 NewStr2() {
  String2 str = new StrNode2; // виділення пам'яті для дескриптора
  str->len = 0; // занесення в дескриптор початкових значень
  str->first = str->last = NULL;
  return str;
}

char CompareBlock(String2 s1, String2 s2) {
  char bi1, bi2;
  BlkPtr cp1, cp2;
  cp1 = s1->first;
  cp2 = s2->first;
  bi1 = cp1->chFirst;
  bi2 = cp2->chFirst;
  while (cp1 && cp2) // цикл, поки не буде досягнутий кінець однієї з рядків
  { // якщо соответств. символи не рівні, ф-ція закінчується
    if (cp1->StrData[bi1] > cp2->StrData[bi2])
      return 1;
    else if (cp1->StrData[bi1] < cp2->StrData[bi2])
      return -1;
    bi1++; // до наступного символу в s1
    if (bi1 > cp1->chLast) {
      cp1 = cp1->next;
      bi1 = cp1->chFirst;
    }
    bi2++; // до наступного символу в s2
    if (bi2 > cp2->chLast) {
      cp2 = cp2->next;
      bi2 = cp2->chFirst;
    }
  }
  // ми дійшли до кінця однієї з рядків,
  // рядок меншої довжини вважається меншою
  if (s1->len < s2->len)
    return -1;
  else if (s1->len > s2->len)
    return 1;
  else
    return 0;
}

typedef struct StrNode1 *String1; // тип - СТРОКА ЗМІННОЮ ДОВЖИНИ

struct StrNode1 // дескриптор рядки
{
  unsigned short MaxLen, Len; // максимальна і поточна довжини
  char *str;                  // покажчик на дані рядка
};

// Створення рядка; len - максимальна довжина рядка;

// ф-ція повертає покажчик на дескриптор рядки

String1 NewStr1(int len) {
  String1 s = new StrNode1; // виділення пам'яті для дескриптора
  s->MaxLen = len; // занесення в дескриптор початкових значень
  s->Len = 0;
  s->str = new char[len + 1]; // виділення пам'яті для даних
  cout << "Введите строку" << endl;
  cin >> s->str;
  s->Len = strlen(s->str);
  return s;
}

char CompareVec(String1 s1, String1 s2) {
  int i = 0; // індекс поточного символу
  // цикл, поки не буде досягнутий кінець однієї з рядків
  while (i < s1->Len && i < s2->Len) {
    // якщо i-е символи не рівні, функція закінчується
    if (s1->str[i] > s2->str[i])
      return 1;
    else if (s1->str[i] < s2->str[i])
      return -1;
    i++; // перехід до наступного символу
  }
  // якщо виконання дійшло до цієї точки, то знайдений кінець однієї з
  // рядків, і все порівняні до сих пір символи були рівні;
  // рядок меншої довжини вважається меншою
  if (s1->Len < s2->Len)
    return -1;
  else if (s1->Len > s2->Len)
    return 1;
  else
    return 0;
}

int main() {
  time_t start1, start2, end1, end2;
  int len = 2000;
  String1 str1_1 = new StrNode1;
  str1_1 = NewStr1(len);
  String1 str1_2 = new StrNode1;
  str1_2 = NewStr1(len);
  start1 = clock();
  int rez1 = CompareVec(str1_1, str1_2);
  end1 = clock();
  cout << "Час витрачений на порівняння векторів: " << (end1 - start1) << endl;
  if (rez1 == 0) {
    cout << "s1 = s2" << endl;
  }
  if (rez1 == 1) {
    cout << "s1 > s2" << endl;
  }
  if (rez1 == -1) {
    cout << "s1 < s2" << endl;
  }
  int size = 2000;
  char *temp1 = new char[size];
  char *temp2 = new char[size];
  cout << "Введіть 2 ряди для порівняння" << endl;
  cin >> temp1 >> temp2;
  int count_of_blocs;
  if (size % 8 == 0) {
    count_of_blocs = size / BlkSize;
  } else {
    count_of_blocs = (size / BlkSize) + 1;
  }
  String2 str2_1 = new StrNode2;
  str2_1 = NewStr2();
  String2 str2_2 = new StrNode2;
  str2_2 = NewStr2();
  BlkPtr block1[count_of_blocs];
  BlkPtr block2[count_of_blocs];
  for (int i = 0; i < count_of_blocs; i++) {
    block1[i] = NewBlock();
    block2[i] = NewBlock();
  }
  for (int i = 0; i < count_of_blocs - 1; i++) {
    block1[i]->next = block1[i + 1];
    block2[i]->next = block2[i + 1];
  }
  int t = 0;
  for (int i = 0; i < count_of_blocs; i++) {
    for (int j = 0; j < 7; j++) {
      block1[i]->StrData[j] = temp1[t];
      block2[i]->StrData[j] = temp2[t];
      t++;
    }
  }
  str2_1->first = block1[0];
  str2_1->last = block1[count_of_blocs];
  str2_2->first = block2[0];
  str2_2->last = block2[count_of_blocs];
  str2_1->len = strlen(temp1);
  str2_2->len = strlen(temp2);
  start2 = clock();
  int rez2 = CompareBlock(str2_1, str2_2);
  end2 = clock();
  cout << "Час витрачений на порівняння блоків: " << (end2 - start2) << endl;
  if (rez2 == 0) {
    cout << "s1 = s2" << endl;
  }
  if (rez2 == 1) {
    cout << "s1 > s2" << endl;
  }
  if (rez2 == -1) {
    cout << "s1 < s2" << endl;
  }
  cout << "Обсягом використовуваної пам’яті для порівняння векторів:\n"
       << "\tПерший вектор: " << sizeof(str1_1) << "\n"
       << "\tДругий вектор: " << sizeof(str1_2) << endl;
  cout << "Обсягом використовуваної пам’яті для порівняння блоків:\n"
       << "\tПерший блок: " << sizeof(str2_1) << "\n"
       << "\tДругий блок: " << sizeof(str2_2) << endl;

  return 0;
}