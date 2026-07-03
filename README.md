# 🍽️ Restoran Yönetim Sistemi (Restaurant Management System)

Nesne yönelimli programlama (OOP) prensipleri kullanılarak C++ ile geliştirilmiş, kurşun geçirmez girdi doğrulamasına sahip dinamik bir restoran adisyon ve yönetim sistemi.

## 🚀 Öne Çıkan Özellikler

* **Gelişmiş Girdi Doğrulaması (Input Validation):** Şablon (Template) tabanlı `sayiAl` fonksiyonu sayesinde, kullanıcı sayı yerine harf girse bile konsol kilitlenmez, hatayı absorbe eder.
* **Akıllı Sipariş Eşleştirme (Trim & Case Insensitivity):** Kullanıcı sipariş girerken başta/sonda gereksiz boşluklar bıraksa veya küçük harf kullansa bile (`  kebap  ` gibi), sistem otomatik olarak girdiyi temizler, büyük harfe çevirir ve menüyle kusursuz eşleştirir.
* **Esnek Porsiyonlama Sistemi:** Stok ve porsiyon adetleri `float` tabanlıdır. Bu sayede müşteriler yarım (0.5) oder 1.5 porsiyon sipariş verebilir, hesap ve stok takibi kusursuz hesaplanır.
* **Dinamik Masa ve Menü Yönetimi:** Vektörler (`std::vector`) kullanılarak masaların doluluk oranı ve güncel hesap durumu anlık olarak takip edilir.

## 🛠️ Kullanılan Teknolojiler
* **Dil:** C++
* **Yapılar:** Object-Oriented Programming (Classes), Vectors, Templates, String Manipulation (`<cctype>`)
