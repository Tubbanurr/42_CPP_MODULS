# C++ - Module 00: Temeller ve İlk Adımlar

## 📖 Açıklama
Bu modül, C++ dilinin temellerini anlamanızı sağlayacak konuları kapsar. Namespace kullanımı, sınıflar, üye fonksiyonları, giriş/çıkış akışları (`std::cout`, `std::cin`), başlatma listeleri, `static`, `const` gibi kavramlar işlenmektedir.

## 📌 İçerik

### 🔹 **ex00 - Megaphone**
- Komut satırından aldığı girdiyi tamamen büyük harfe çeviren basit bir program.
- Boş giriş olduğunda `* LOUD AND UNBEARABLE FEEDBACK NOISE *` mesajını yazdırır.

### 🔹 **ex01 - My Awesome PhoneBook**
- 80’lerin telefon rehberi tarzında bir program.
- Maksimum **8 kişi** saklanabilir, yeni kişi eklenirse en eski kayıt silinir.

### 🔹 **ex02 - The Job Of Your Dreams**
- Eksik olan bir `Account.cpp` dosyasını `Account.hpp` ve test dosyaları kullanarak yeniden oluşturur.
- Verilen log dosyasındaki çıktıyı analiz ederek eksik kodu tamamlamayı amaçlar.

## ⚙️ Kurallar
- **Derleme:** `c++ -Wall -Wextra -Werror -std=c++98`
- **Kısıtlamalar:** `printf`, `alloc`, `free` gibi C fonksiyonları yasaktır.
