# C++ - Module 04: Polimorfizm, Soyut Sınıflar ve Arayüzler

## 📖 Açıklama
Bu modülde **alt tür polimorfizmi**, **soyut sınıflar** ve **arayüzler (interfaces)** ele alınmaktadır. C++’ta **kalıtım ve polimorfizm** kullanılarak **dinamik davranış** kazandırma ve **interfeys mantığını** kavrama hedeflenmektedir.

## 📌 İçerik

### 🔹 **ex00 - Polymorphism**
- **Temel Polimorfizm:** `Animal` adlı bir **üst sınıf** ve `Dog` ile `Cat` adında iki **türetilmiş sınıf** oluşturulur.
- `makeSound()` fonksiyonu polimorfik şekilde çalışır.
- **Virtual fonksiyonlar** ve **override mantığı** uygulanır.

### 🔹 **ex01 - I don’t want to set the world on fire**
- **Derin kopyalama (deep copy) ve sığ kopyalama (shallow copy) farkları** test edilir.
- `Brain` sınıfı eklenerek `Dog` ve `Cat` nesnelerine **dinamik bellek yönetimi** kazandırılır.

### 🔹 **ex02 - Abstract Class**
- `Animal` sınıfı **artık bir soyut sınıf (abstract class)** olmalı.
- **Soyut sınıflar doğrudan örneklenemez!**

### 🔹 **ex03 - Interface & Recap**
- **Arayüz mantığını** anlamak için `AMateria`, `ICharacter` ve `IMateriaSource` gibi soyut sınıflar tasarlanır.
- `clone()` gibi **saf sanal (pure virtual) fonksiyonlar** kullanılır.

## ⚙️ Kurallar
- **Bellek sızıntılarını önlemek için destructor (yıkıcı fonksiyonlar) kullanılmalı.**
- **Kalıtım ve polimorfizm ilkelerine uygun olmalı.**
- **Soyut sınıflar doğrudan örneklenmemeli.**
