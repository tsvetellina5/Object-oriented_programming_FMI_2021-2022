# Solid Principles

SOLID е акроним за пет принципа на проектиране, предназначени да направят софтуерния дизайн по-разбираем, гъвкав и поддържащ. <br />
Въпреки че се прилагат за всеки обектно-ориентиран дизайн, принципите SOLID могат също да формират основна философия за гъвкаво развитие.

- Single Responsibility principle
- Open-Closed Principle
- Liskov Substitution Principle
- Interface Segregation Principle
- Dependency Inversion Principle

## Single Responsibility principle
```
A class should have only one reason to change
```

Както подсказва името, той изисква всеки модул, да кажем клас, да носи отговорност за една и само една цел. <br />
Казано по друг начин, класът трябва да има само една "причина" за промяна(под "причина" може да имаме предвид промяна в спецификацията на дадена изискване). <br />
Този принцип позволява да пишем софтуер с висока кохезия и стабилност, тъй като той няма да бъде толкова повлиян с развиването на системата. <br />

```c++
//Example of a Single Responsibility
class DatabaseManager {
public:
   virtual ~DatabaseManager() = default;
   virtual void addUser(string username) = 0;
   virtual vector<string> getAllUsers() = 0;
};

class MyDatabaseManager : public DatabaseManager {
public:
   MyDatabaseManager(Database& database);
   void addUser(string username) override;
   vector<string> getAllUsers() override;
};

class UsernameFormatter {
public:
   virtual ~UsernameFormatter() = default;
   virtual string format(string username) = 0;
   virtual string getReadableName(string input) = 0;
};
```

## Open-Closed Principle
```
Software entities should be open for extension, but closed for modification
```

Вместо да променяме съществуващ код, трябва да го разширяваме.
Това може да се реализира чрез използването на абстрактни класове(интерфейси).

## Liskov Substitution Principle

## Interface Segregation Principle

Класове с точно и ясно предназначение - специфични класове/методи.
Трябва да избягваме класове/методи, които да правят "всичко".

## Dependency Inversion Principle
