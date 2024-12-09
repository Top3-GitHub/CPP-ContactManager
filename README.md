
# 📋 Projekt: Menedżer Kontaktów

## 📖 Opis projektu
Menedżer Kontaktów to aplikacja konsolowa napisana w języku C++. Pozwala użytkownikom zarządzać listą kontaktów, umożliwiając:
- Dodawanie nowych kontaktów.
- Wyświetlanie wszystkich kontaktów.
- Wyszukiwanie kontaktów po imieniu.
- Usuwanie kontaktów po imieniu.

Aplikacja przechowuje kontakty w pamięci programu i działa w terminalu.

---

## 🎮 Jak działa aplikacja?

### 1. Dodawanie kontaktu
- Użytkownik jest proszony o podanie:
  - Imienia.
  - Numeru telefonu (minimum 9 cyfr, tylko cyfry).
  - Adresu e-mail (musi kończyć się jedną z dozwolonych domen: `@gmail.com`, `@yahoo.com`, `@outlook.com`).
- Po wprowadzeniu danych kontakt zostaje zapisany w liście kontaktów.

### 2. Wyświetlanie kontaktów
- Program wyświetla wszystkie zapisane kontakty w czytelnym formacie:
  - Imię
  - Numer telefonu
  - E-mail

### 3. Wyszukiwanie kontaktów
- Użytkownik podaje imię, a program wyszukuje i wyświetla pasujący kontakt.
- Jeśli kontakt nie istnieje, użytkownik otrzymuje stosowny komunikat.

### 4. Usuwanie kontaktów
- Użytkownik podaje imię kontaktu, który chce usunąć.
- Program usuwa kontakt z listy, jeśli taki istnieje.

---

## 🛠️ Technologie użyte w projekcie
- **C++**: Podstawowy język programowania użyty do budowy aplikacji.
- **Standard Template Library (STL)**: Do zarządzania listą kontaktów (wektor).

---

## 📂 Struktura projektu
```
├── main.cpp       # Kod źródłowy programu
├── README.md      # Dokumentacja projektu
```

---

## ✨ Funkcje do rozbudowy w przyszłości
- Zapis i odczyt kontaktów z pliku.
- Możliwość edycji istniejących kontaktów.
- Obsługa większej liczby pól (np. adres zamieszkania).
- Graficzny interfejs użytkownika (GUI).
