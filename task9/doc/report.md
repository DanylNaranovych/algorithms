# Практична робота №9. АЛГОРИТМИ ПРОСТИХ ПОШУКІВ

## Вимоги

### 1.1 Розробник

* Наранович Данило Анатолійович;
* студент групи КН-921в;
* 20-05-2022.

### 1.2 Загальне завдання

Набути навичок та закріпити знання при виконанні операцій пошуку.

### 1.3 Індивідуальне завдання

Реалізувати експоненційний та інтерполяційний пошуки у масиві.

## 2 Опис програми

### 2.1 Функціональне призначення

Програма призначена для виявлення різниці між експоненційним та інтерполяційним пошуками у масиві.

Для вхідних даних діють такі *обмеження*:
 - для розміру строк: 2000 символів;

### 2.2 Порівняння методів пошуку

```
Position of the figure 5: 978
Time spent searching exponentially: 2
Number of comparisons: 29
Position of the figure 3: 712
Time spent searching by interpolation method: 2
Number of comparisons: 6
```

### 2.3 Структура проекту

```
task9
├── doc
│   └── report.md
└── src
    ├── main.bin
    └── main.cpp
```

## 3 Блок-схеми

### 3.1 InterpolSearch

![InterpolSearch](/assets/1.png)

### 3.2 ExponentialSearch

![ExponentialSearch](/assets/2.png)

### 3.3 bubble_sort

![bubble_sort](/assets/3.png)

## 4 Варіанти використання

Для демонстрації результатів кожної задачі використовується:

- покрокове виконання програми в утиліті lldb;
- видача результатів у консоль за допомогою функції виводу.

**Варіант використання**: послідовність дій для запуску програми у режимі відлагодження:
- запустити програму у відлагоднику lldb;
- поставити точку зупинки на функції main (строка з `return 0;`);
- запустити програму;
- подивитись результати виконання програми, оглядаючи значення змінної

```
(lldb) b 107
Breakpoint 1: where = main.bin`main + 703 at main.cpp:107:3, address = 0x00000000004018ff
(lldb) r
Process 148707 launched: '/home/kali/algorithms/task9/src/main.bin' (x86_64)
Position of the figure 5: 13
Time spent searching exponentially: 1
Number of comparisons: 11
Position of the figure 3: 8
Time spent searching by interpolation method: 1
Number of comparisons: 4
Process 148707 stopped
* thread #1, name = 'main.bin', stop reason = breakpoint 1.1
    frame #0: 0x00000000004018ff main.bin`main at main.cpp:107:3
   104    cout << "Time spent searching by interpolation method: " << (end2 - start2)
   105         << endl;
   106    cout << "Number of comparisons: " << count << endl;
-> 107    return 0;
   108  }
```

## Висновки
	При виконанні лабораторної роботи були набуті навички та закріплені знання при виконанні операцій пошуку.