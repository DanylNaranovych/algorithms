#include <fstream>
#include <iostream>
using namespace std;
void Init(void);
int Insert(int Area_code, int adr);
int Search(int Area_code);
void Print(struct Town *t);
void ReadFromFile(struct Town *t);
#define N 3 //кількість записів у таблиці
#define EMPTY -1

struct Town {
  int adr;
  int Area_code;
  string Name;
  int Square;
  double Populace;
};

Town hashTabl[N]; //хеш-таблиця

int Area_codes[N] = {1, 2, 3};

int main(void) {
  int i, Area_code, res;
  ReadFromFile(hashTabl);
  Init();
  cout << "\nArea_codes -> ";
  for (i = 0; i < N; i++)
    cout << Area_codes[i] << " ";
  for (i = 0; i < N; i++)
    Insert(Area_codes[i], i);
  cout << "\nHashed table \n Area_code - adr \n ";
  for (i = 0; i < N; i++)
    cout << " " << hashTabl[i].Area_code << " - " << hashTabl[i].adr << "\n";
  cout << " Input searched Area_codes (Area_code < 0 - exit) -> ";
  cin >> Area_code;
  while (Area_code >= 0) {
    res = Search(Area_code);
    if (res == EMPTY)
      cout << " not search \n";
    else {
      cout << "\n";
      Print(&hashTabl[res]);
    }
    cout << " Input searched Area_codes (Area_code < 0 - exit) -> ";
    cin >> Area_code;
  }
  return 0;
}

int Hash(int Area_code) //функція хешування
{
  return (Area_code % N);
}

void Init(void) //ініціалізація хеш-таблиці
{
  for (int i = 0; i < N; i++)
    hashTabl[i].adr = EMPTY;
}

int Insert(int Area_code, int adr) //додавання ключа у хеш-таблицю
{
  int addr, a1;
  addr = Hash(Area_code);
  if (hashTabl[addr].adr != EMPTY) {
    a1 = addr;
    do {
      addr = Hash(addr + 1);
    } while (!((addr == a1) || (hashTabl[addr].adr == EMPTY)));
    if (hashTabl[addr].adr != EMPTY)
      return 0;
  }
  hashTabl[addr].Area_code = Area_code;
  hashTabl[addr].adr = adr;
  return 1;
}

int Search(int Area_code) //функція пошуку ключа
{
  int addr, a1;
  addr = Hash(Area_code);
  if (hashTabl[addr].adr == EMPTY)
    return EMPTY; //місце вільне – ключа немає в таблиці
  else if (hashTabl[addr].Area_code == Area_code)
    return hashTabl[addr].adr; //ключ знайдений на своєму місці
  else //місце зайняте іншим ключем
  {
    a1 = Hash(addr + 1);
    //Пошук, поки не знайдений ключ чи не зроблене повне обертання
    while ((hashTabl[a1].Area_code != Area_code) && (a1 != addr))
      a1 = Hash(a1 + 1);
    if (hashTabl[a1].Area_code != Area_code)
      return EMPTY;
    else
      return hashTabl[a1].adr;
  }
}
void Print(struct Town *t) {
  cout << "Name of sity: " << t->Name << "\nSquare of sity: " << t->Square
       << "\nPopulace of sity: " << t->Populace << endl;
}
void ReadFromFile(struct Town *t) {
  ifstream in("/home/kali/algorithms/task10/assets/input.txt");
  for (int i = 0; i < N; i++) {
    in >> t[i].Name >> t[i].Square >> t[i].Populace;
  }
}