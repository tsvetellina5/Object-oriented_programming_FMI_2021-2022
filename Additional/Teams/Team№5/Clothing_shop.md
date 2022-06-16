# Clothing Shop

Да се напише програма, която имитира база от данни на магазин за дрехи. За целта е необходимо да се реализират класовете, показани на следната UML клас диаграма:

![Uml_clothibg_shop](https://user-images.githubusercontent.com/97393225/173221235-7c51f44f-12dd-4195-8b6d-a83960c9fa43.jpg)

1. ClothingItem (abstract class) със следните член-данни:
 - Name(dress, trousers, shirt, ect.)
 - Type(casual, sportswear, couture)
 - Size
 - Gender
 - Price
 - Number available.

2. Casual(derived from ClothingItem);

3. SportsWear(derived from ClothingItem);
 - sport it is suitable for.

4. Couture/Designer's(derived from ClothingItem);
 - designer.

5. Clothing Container;

6. Clothing Shop;
 - Shop name
 - Address
 - Profit
 - Clothing Items - списък от налични дрехи
 - Sold log - списък от всички продадени дрехи.
 - Минимални функционалности:
 - - AddClothingItem
 - - DeleteClothingItem - mark it as sold;
 - - List available items;
 - - List sold items;
 - - Export sold log
 - - Display - извежда информация за магазина (име, адрес, печалба).
  	
Да се реализират подходящи член-функции/методи.

# Документация:
[Идея-за-проект.docx](https://github.com/DaniellaGeorgieva/Object-oriented_programming_FMI_2021-2022/files/8923114/-.-.docx)

# Разработили проекта:
 - Таня Илиева
 - Калина Боева
 - Даниела Георгиева

