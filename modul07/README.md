# Modul07 - C++ Templates

## 📌 Proje Hakkında
**Modul07**, C++ dilinde **şablonlar (templates)** konseptini anlamanızı sağlayacak bir dizi alıştırma içermektedir. Bu modül, C++98 standardını kullanarak nesne yönelimli programlamaya (OOP) giriş yapmanızı hedefler.

## 📂 Proje Yapısı

Bu modül üç temel egzersizden oluşmaktadır:

- **`ex00/`** - `whatever.hpp` ile temel şablon fonksiyonlarını uygular:
  - `swap`: İki değeri yer değiştirir.
  - `min`: Küçük olan değeri döndürür.
  - `max`: Büyük olan değeri döndürür.
- **`ex01/`** - `iter.hpp` ile **iter** fonksiyonunu uygular:
  - Bir dizinin tüm elemanlarına belirli bir işlemi uygular.
- **`ex02/`** - `Array.hpp` ve `Array.tpp` ile dinamik dizi sınıfı uygular:
  - Varsayılan, parametreli ve kopya kurucular içerir.
  - Elemanlara `[]` operatörü ile erişim sağlar.
  - Hatalı indeks erişimlerinde **exception** fırlatır.

Her egzersiz kendi **`Makefile`** dosyasına sahiptir, bu sayede bağımsız olarak derlenebilir.

## 🚀 Kurulum ve Çalıştırma

### 1️⃣ Derleme
Her egzersizi derlemek için ilgili klasöre giderek şu komutu çalıştırabilirsiniz:
```sh
make
```

### 2️⃣ Çalıştırma
Derleme tamamlandıktan sonra, oluşturulan yürütülebilir dosyayı şu şekilde çalıştırabilirsiniz:
```sh
./<program_adı>
```
Örneğin `ex00` için:
```sh
cd ex00
make
./ex00
```

## 🛠 Kullanım
Proje, **C++98** standardına uygundur ve aşağıdaki derleyici bayrakları ile derlenmelidir:
```sh
c++ -Wall -Wextra -Werror -std=c++98
```

### 🎯 Önemli Kurallar
- **STL kullanımı yasaktır.** (std::vector, std::list, std::map vb. dahil değildir.)
- **Memory leak olmamalıdır.** `new` operatörü ile tahsis edilen bellek `delete` ile temizlenmelidir.
- **C fonksiyonları (printf, malloc, free) kullanılamaz.**
- **using namespace std; kullanımı yasaktır.**

## 📚 C++ Template Öğrenme Rehberi
Şablonlar, C++'ın en güçlü özelliklerinden biridir ve **tür bağımsız kod** yazmanıza olanak tanır. Aşağıdaki temel konular, modülde karşılaşacağınız şablonlarla ilgili temel bilgileri içerir:

### ✨ Temel Şablon Kullanımı
```cpp
template <typename T>
T add(T a, T b) {
    return a + b;
}
```
Yukarıdaki şablon fonksiyon, verilen iki değeri toplar ve aynı türde döndürür.

### 🌀 Şablonun Derleme Aşaması
C++ derleyicisi, şablonları **derleme zamanında** genişletir ve tür belirlemeyi otomatik olarak yapar. Bu nedenle, şablon fonksiyonlar header dosyalarında tanımlanmalıdır.

### 🏗 Sınıf Şablonları
```cpp
template <typename T>
class Box {
private:
    T value;
public:
    Box(T val) : value(val) {}
    T getValue() { return value; }
};
```
Sınıf şablonları, farklı veri türleriyle çalışabilen nesneler oluşturmanıza yardımcı olur.

### 🔄 İteratörler ve Şablon Kullanımı
**ex01**'de kullanılan `iter` fonksiyonu, her eleman için bir işlem yapmayı sağlar:
```cpp
template <typename T, typename Func>
void iter(T *array, size_t size, Func function) {
    for (size_t i = 0; i < size; i++) {
        function(array[i]);
    }
}
```
Bu fonksiyon, herhangi bir türdeki dizinin tüm elemanlarını gezer ve verilen fonksiyonu uygular.

## ✅ Testler
Her egzersizi test etmek için ilgili `main.cpp` dosyası çalıştırılabilir. Eğer derleme hatası alırsanız, kodunuzu **C++98** standardına göre derlediğinizden emin olun.

---
Bu modül sayesinde **C++ şablonlarıyla nasıl çalışacağınızı** öğreneceksiniz! 🚀
