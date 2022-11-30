# Практична робота №8. СПИСКИ

## Вимоги

### 1.1 Розробник

* Наранович Данило Анатолійович;
* студент групи КН-921в;
* 18-05-2022.

### 1.2 Загальне завдання

Набути навичок та закріпити знання при виконанні операцій на мультисписках та нелінійних списках.

### 1.3 Індивідуальне завдання

розробити програму, що створює список списків (Список: Відділи підприємств; Підсписок: Прізвища співробітників відділу).

## 2 Опис програми

### 2.1 Функціональне призначення

Програма призначена для створення списку списків.

Для вхідних даних діють такі *обмеження*:
 - для кількості під списків: 2;

### 2.2 Структура проекту

```
task8
├── doc
│   └── report.md
└── src
    ├── main.bin
    └── main.cpp
```

## 3 Блок-схеми

### 3.1 PrintSublist

![PrintSublist](/assets/2.png)

### 3.2 PrintList

![PrintList](/assets/1.png)

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
(lldb) b 79
Breakpoint 1: where = main.bin`main + 808 at main.cpp:79:3, address = 0x0000000000401a68
(lldb) r
Process 144460 launched: '/home/kali/algorithms/task8/src/main.bin' (x86_64)
Enter first and second employee for struct number: 0
asd
qwe
Enter first and second employee for struct number: 1
qwe
asd
Enter first and second department:
sdf
wer
Enter first and second department:
wer
sdf
        List Factory:
First department:       wer
Second department:      sdf
First and second employee from struct number: 0
        Sublist Team:
First employee:         asd
Second employee:        qwe
First and second employee from struct number: 1
        Sublist Team:
First employee:         qwe
Second employee:        asd
        Sublist Team:
First employee:         abrakadabra
Second employee:        asd
        Adding an element
        List Factory:
First department:       wer
Second department:      sdf
First and second employee from struct number: 0
        Sublist Team:
First employee:         asd
Second employee:        qwe
First and second employee from struct number: 1
        Sublist Team:
First employee:         abrakadabra
Second employee:        asd
First and second employee from struct number: 2
        Sublist Team:
First employee:         qwe
Second employee:        asd
        Deleting an element
        List Factory:
First department:       wer
Second department:      sdf
First and second employee from struct number: 0
        Sublist Team:
First employee:         asd
Second employee:        qwe
First and second employee from struct number: 1
        Sublist Team:
First employee:         abrakadabra
Second employee:        asd
Process 144460 stopped
* thread #1, name = 'main.bin', stop reason = breakpoint 1.1
    frame #0: 0x0000000000401a68 main.bin`main at main.cpp:79:3
   76     del_team(&f, 2);
   77     print_list(&f);
   78  
-> 79     return 0;
   80   }
```

## Висновки
	При виконанні лабораторної роботи були набуті практичні навички та закріплені знання при виконанні операцій на мультисписках та нелінійних списках.