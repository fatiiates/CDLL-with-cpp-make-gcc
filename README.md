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

## KULLANIM
### Linux
&emsp;&emsp;Makefile dosyası gcc derleyicisine uyumlu yazılmıştır. Linux üzerinde gcc genelde otomatik yüklü gelmektedir. Dolayısıyla Linux işletim sistemi kullanıyorsanız yalnızca indirilen deponun dizine gelerek;
> make

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
&emsp;&emsp;Programa verilen Sayılar.txt'nin içerisinde bilgileri satır satır ve her satırı boşluklardan ayırarak hücre bazında okumaya başlar. Sayılar.txt içerisinde her varsayılan olarak 250 sayı barındırır bu sayı isteğe göre arttırılabilir. Satırlarda içindeki sayılar birbirlerinden boşluklar aracılığıyla ayrılmalıdır;
> 1 254 200 100 50 10 20 14 53 23 53 4

!LINUX SİSTEMLER İÇİN 0-254 arası sayılar kabul edilmektedir. Nedeni 255 sayısının Linux sisteminde ekrana yazdırılırken çekirdeğin çökmesine sebep olmasıdır.

&emsp;&emsp;Başlangıçta RAM'in heap bölgesini işaret eden bir ArrayList işaretçisi oluşturulur. Sayilar.txt'nin satırlarını tek tek okumaya başlar ve her satır için ArrayList'in bir hücresine yine heap bölgesini işaret eden Çift Yönlü Bağıl Liste işaretçisi ekler. Okuduğu her satırı boşluklar aracılığıyla hücrelere böler. Elde ettiği her hücreleri bağıl listede aşağıdaki verilere göre sıraya dizer;
> İlk gelen sayıyı direkt listeye ekler  

Gelen sayıları, kök düğümdeki sayıdan başlayarak EBOB değerlerini şimdiye kadar elde edilen en büyük ebob değeriyle karşılaştırır;
> Eğer EBOB küçük ise son düğüme kadar devam eder. Son düğüme gelinirse listenin sonuna eklenir.  
> Eğer EBOB büyük ise iki sayının MUTLAK MOD değeri alınır ve MUTLAK MOD değeri 0 değilse gelen sayı kadar sola gidilir. Sola giderken liste başına gelinirse daha fazla ilerlenmez ve liste başına eklenir. Eğer ki MUTLAK MOD değeri 0 ise düğümün bir sağına yeni düğüm olarak eklenir.

Dengeleme tamamlandıktan sonra başta oluşturduğumuz ArrayList'in her elemanı ayrı ayrı satırlar olarak ekrana yazılır ve heap bölgelerinde oluşturulan Bağıl Liste ve ArrayList tam anlamıyla temizlenerek program sonlanır.
