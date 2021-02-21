- [EN description](#en)  
- [TR açıklama](#tr)

## File Tree/Dosya ağacı

* /bin
  - readme.txt
  - Test.exe
* /doc
  - readme.txt
  - Sayilar.txt
* /include
  - ArrayList.hpp
  - CircularDoublyLinkedList.hpp
  - Node.hpp
* /lib
  - ArrayList.o
  - benioku.txt  
  - CircularDoublyLinkedList.o
  - Node.o
* /src
  - ArrayList.cpp
  - CircularDoublyLinkedList.cpp
  - Node.cpp
  - Test.cpp
* makefile

# [EN]
## USAGE
### For Linux
&emsp;&emsp;Makefile file is written compatible with the gcc compiler. In generally, gcc compiler is installed default on Linux. So, if you are using a Linux operating system, just go to the directory of the downloaded repository;

    make

run this command is enough.

### For Windows
&emsp;&emsp; If your computer doesn't have the gcc compiler;

> Mingw: http://www.mingw.org/  
> Mingw Install: https://osdn.net/projects/mingw/releases/  
> Mingw Documentation: http://www.mingw.org/wiki  
> Mingw How to install: https://www.youtube.com/watch?v=QqphmHIYULE 

After installing the gcc compiler without any problems, go to the same directory as your repository and run;

    mingw32-make
    
## How to work ?
&emsp;&emsp;The program reads the information in Sayilar.txt line by line and separates each line from the spaces and reads the whole file on a cell basis. Sayilar.txt contains 250 numbers by default, this number can be increased optionally. Numbers in rows must be separated from each other by spaces;

    1 254 200 100 50 10 20 14 53 23 53 4

!Numbers between 0-254 are accepted for LINUX SYSTEMS. The reason is that the number 255 causes the kernel to crash while being printed on the screen in the Linux system.

&emsp;&emsp;An ArrayList pointer is created that points to the heap region of RAM initially. Starts reading the rows of Sayilar.txt one by one and adds a CDLL pointer to a cell of ArrayList for each row, again pointing to the heap region. It divides each line it reads into cells by means of spaces. It sorts each cells it obtains in the relative list according to the following data;

> The first number is added directly to the list

It compares incoming numbers, starting with the number in the root node, and GCD values with the largest GCD value ever achieved;

> If GCD is small, it continues until the last node. If it reaches the last node, it is added to the end of the list.
> If EBOB is large, the ABSOLUTE MOD value of the two numbers is taken and if the ABSOLUTE MOD value is not 0, go to the left as much as the ABSOLUTE MOD value and add. If it happens to the top of the list when going to the left, it will not move further and will be added to the start of the list. If the ABSOLUTE MOD value is 0, it is added to the right of the node as a new node.

After the balancing is completed, each element of the ArrayList we created at the beginning is written on the screen as separate lines and the Relative List and ArrayList created in the heap regions are completely cleared and the program is terminated.

# [TR]
## KULLANIM
### Linux
&emsp;&emsp;Makefile dosyası gcc derleyicisine uyumlu yazılmıştır. Linux üzerinde gcc genelde otomatik yüklü gelmektedir. Dolayısıyla Linux işletim sistemi kullanıyorsanız yalnızca indirilen deponun dizine gelerek;

    make

komutunu çalıştırmanız yeterlidir.

### Windows
&emsp;&emsp; Bilgisayarınızda gcc derleyicisi kurulu değilse;
> Mingw: http://www.mingw.org/  
> Mingw kurulum dosyası: https://osdn.net/projects/mingw/releases/  
> Mingw dökümantasyon: http://www.mingw.org/wiki  
> Mingw kurulumu: https://www.youtube.com/watch?v=QqphmHIYULE  

gcc derleyicisini sorunsuz bir şekilde kurduktan sonra konsol üzerinden indirdiğiniz deponun seviyesine gelin ve çalıştırın;

> mingw32-make

## NASIL ÇALIŞIR
&emsp;&emsp;Programa verilen Sayılar.txt'nin içerisinde bilgileri satır satır ve her satırı boşluklardan ayırarak hücre bazında okumaya başlar. Sayılar.txt içerisinde her varsayılan olarak 250 sayı barındırır bu sayı isteğe göre arttırılabilir. Satırlar içindeki sayılar birbirlerinden boşluklar aracılığıyla ayrılmalıdır;
    
    1 254 200 100 50 10 20 14 53 23 53 4

!LINUX SİSTEMLER İÇİN 0-254 arası sayılar kabul edilmektedir. Nedeni 255 sayısının Linux sisteminde ekrana yazdırılırken çekirdeğin çökmesine sebep olmasıdır.

&emsp;&emsp;Başlangıçta RAM'in heap bölgesini işaret eden bir ArrayList işaretçisi oluşturulur. Sayilar.txt'nin satırlarını tek tek okumaya başlar ve her satır için ArrayList'in bir hücresine yine heap bölgesini işaret eden Çift Yönlü Bağıl Liste işaretçisi ekler. Okuduğu her satırı boşluklar aracılığıyla hücrelere böler. Elde ettiği her hücreleri bağıl listede aşağıdaki verilere göre sıraya dizer;

> İlk gelen sayıyı direkt listeye ekler  

Gelen sayıları, kök düğümdeki sayıdan başlayarak EBOB değerlerini şimdiye kadar elde edilen en büyük ebob değeriyle karşılaştırır;

> Eğer EBOB küçük ise son düğüme kadar devam eder. Son düğüme gelinirse listenin sonuna eklenir.  
> Eğer EBOB büyük ise iki sayının MUTLAK MOD değeri alınır ve MUTLAK MOD değeri 0 değilse gelen sayı kadar sola gidilir. Sola giderken liste başına gelinirse daha fazla ilerlenmez ve liste başına eklenir. Eğer ki MUTLAK MOD değeri 0 ise düğümün bir sağına yeni düğüm olarak eklenir.

Dengeleme tamamlandıktan sonra başta oluşturduğumuz ArrayList'in her elemanı ayrı ayrı satırlar olarak ekrana yazılır ve heap bölgelerinde oluşturulan Bağıl Liste ve ArrayList tam anlamıyla temizlenerek program sonlanır.
