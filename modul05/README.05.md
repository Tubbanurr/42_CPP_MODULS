# C++ - Module 05: İstisnalar ve Tekrar Kullanılabilirlik

## 📖 Açıklama
Bu modülde **istisna yönetimi (exception handling)** ve **tekrar kullanılabilir sınıflar** tasarlama ele alınmaktadır. C++’ta **hata yakalama mekanizmaları**, `try-catch` blokları ve **istisna sınıfları (exception classes)** üzerinde durulmaktadır.

## 📌 İçerik

### 🔹 **ex00 - Mommy, when I grow up, I want to be a bureaucrat!**
- `Bureaucrat` sınıfı oluşturulur.
- **Derecelendirme (Grade) mekanizması** eklenir.
- **İstisnalar (Exceptions):**
  - `GradeTooHighException`
  - `GradeTooLowException`

### 🔹 **ex01 - Form up, maggots!**
- `Form` sınıfı tasarlanır.
- **İmza (sign) gereksinimleri** eklenir.
- `Bureaucrat`, bir `Form` nesnesini imzalayabilir veya hata fırlatabilir.

### 🔹 **ex02 - No, you need form 28B, not 28C...**
- `Form` sınıfı artık **soyut sınıf (abstract class)** olarak güncellenir.
- **Özel form türleri** eklenir:
  - `ShrubberyCreationForm` (Dosyaya ASCII ağaç çizer)
  - `RobotomyRequestForm` (50% ihtimalle başarılı olur)
  - `PresidentialPardonForm` (Af ilan eder)

### 🔹 **ex03 - At least this beats coffee-making**
- `Intern` sınıfı oluşturulur.
- `Intern::makeForm()` fonksiyonu ile **dinamik form üretimi** yapılır.
- **İstisnalar (Exceptions) kullanılarak hatalar yakalanır.**

## ⚙️ Kurallar
- **İstisnalar doğru şekilde kullanılmalı ve hatalar `try-catch` ile yakalanmalı.**
- **Soyut sınıflar doğrudan örneklenmemeli.**
- **Bellek yönetimi dikkatlice yapılmalı.**
- **Özel form türleri uygun şekilde türetilmeli.**
