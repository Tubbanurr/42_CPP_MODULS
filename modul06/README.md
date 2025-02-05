# 🚀 C++ - Module 06

## **Scalar Types, Type Casting & Runtime Type Identification**

Bu modülde, **C++'ta temel veri türleri, explicit type casting (açık tip dönüşümü) ve runtime type identification (çalışma zamanı tür belirleme)** gibi konular ele alınacaktır.

---

## 📌 **Genel Kurallar**

- Kodunuzu `derleyicisiyle` bayraklarıyla derleyin.
- **C++98** standardı kullanılmalıdır (\`\` ile uyumlu olmalıdır).
- **Kütüphane Kullanımı:**
  - **STL kullanımı yasaktır (vector, list, map vb.).**
  - **Boost ve C++11 özellikleri yasaktır.**
  - `printf()`, `alloc()`, `free()` gibi C fonksiyonları yasaktır.
  - `using namespace` kullanımı yasaktır.
- **Bellek yönetimine dikkat edin!** **Heap tahsis ettiğiniz her nesneyi uygun şekilde temizleyin** (`delete`).
- **Kodunuzu anlaşılır ve okunabilir hale getirin.** Peer değerlendirmesinde puan kaybetmemek için kodu **temiz ve okunaklı** yazın.

---

## **📂 İçindekiler**

- [EX00 - Scalar Type Conversion](#ex00---scalar-type-conversion)
- [EX01 - Serialization](#ex01---serialization)
- [EX02 - Runtime Type Identification](#ex02---runtime-type-identification)

---

## **EX00 - Scalar Type Conversion**

📌 **ScalarConverter** sınıfını oluşturun. Bu sınıf:

- **Özel sayı değerlerini** (`+inf`, `-inf`, `nan`, `+inff`, `-inff`, `nanf`) tanıyabilmeli.
- **Yalnızca **``** yaparak** nesne oluşturulmasını engelleyin.
- **Veri türü dönüşümlerini (**`**, **`**, **``**) gerçekleştirmeli.**
- **Güvenli dönüşüm için ****\`\`**** kullanılmalıdır.**

📌 **Özel Sayılar & IEEE 754**

- `+inf`, `-inf` ve `nan` **double** türü içindir.
- `+inff`, `-inff`, `nanf` **float** türü içindir.
- **Sonsuzluk (**`**) ve tanımsızlık (**`**)** kavramları **IEEE 754 kayan noktalı sayı standardına** dayanmaktadır.

**🚀 Örnek Kullanım**

```cpp
ScalarConverter::convert("42.0f");  // float dönüşümü yapar
ScalarConverter::convert("nan");    // Geçersiz sayı olarak işler
ScalarConverter::convert("+inf");   // Pozitif sonsuzluğu tanır
```

---

## **EX01 - Serialization**

📌 **Veri Serileştirme (Serialization)**

- **Bir veri yapısını (**`**) **`\*\* türüne çevirerek serileştirme yapın.\*\*
- **Daha sonra bunu tekrar ****\`\`**** olarak geri çevirerek deserializasyon yapın.**
- **Güvenli dönüşüm için ****\`\`**** kullanılmalıdır.**

📌 \`\`\*\* Nedir?\*\*

- **Pointer'ları güvenli bir şekilde tamsayıya çeviren özel bir türdür.**
- **Platform bağımsızdır.** 32-bit sistemde `uint32_t`, 64-bit sistemde `uint64_t` olarak çalışır.
- **Pointer değerlerini kayıpsız taşımak için kullanılır.**

**🚀 Örnek Kullanım**

```cpp
struct Data {
    std::string name;
    int age;
};

uintptr_t raw = Serializer::serialize(&data);
Data* deserialized = Serializer::deserialize(raw);
```

---

## **EX02 - Runtime Type Identification**

📌 **Gerçek Türü Belirleme**

- **Polimorfizm kullanarak** bir nesnenin **gerçek türünü belirleyin.**
- \`\`\*\* ile güvenli tür dönüşümleri yapın.\*\*
- **Başarısız dönüşümlerde ****\`\`**** hatası fırlatılmalıdır.**
- **Hem **``** parametreleriyle çalışabilmelidir.**

**🚀 Örnek Kullanım**

```cpp
class Base { virtual ~Base() {} };
class Derived : public Base {};

Base* b = new Derived();
Derived* d = dynamic_cast<Derived*>(b);
if (d)
    std::cout << "Derived'e başarıyla dönüştürüldü!" << std::endl;
```

---



