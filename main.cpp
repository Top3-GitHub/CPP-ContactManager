#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <regex>

using namespace std;

// Struktura reprezentująca kontakt
struct Kontakt {
    string imie;
    string numerTelefonu;
    string email;
};

// Funkcja do wyświetlania menu
void wyswietlMenu() {
    cout << "\n========== Menedżer Kontaktów ==========\n";
    cout << "1. Dodaj nowy kontakt\n";
    cout << "2. Wyświetl wszystkie kontakty\n";
    cout << "3. Wyszukaj kontakt po imieniu\n";
    cout << "4. Usuń kontakt po imieniu\n";
    cout << "5. Wyjdź\n";
    cout << "=======================================\n";
    cout << "Wybierz opcję: ";
}

// Funkcja do sprawdzania numeru telefonu
bool sprawdzNumerTelefonu(const string& numer) {
    // Sprawdza, czy numer zawiera wyłącznie cyfry i ma długość co najmniej 9 znaków
    return regex_match(numer, regex("\\d{9,}"));
}

// Funkcja do sprawdzania poprawności e-maila
bool sprawdzEmail(const string& email) {
    // Lista akceptowanych domen
    vector<string> dozwoloneDomeny = {"@gmail.com", "@yahoo.com", "@outlook.com"};
    for (const auto& domena : dozwoloneDomeny) {
        if (email.size() >= domena.size() &&
            email.substr(email.size() - domena.size()) == domena) {
            return true;
        }
    }
    return false;
}

// Funkcja do dodawania kontaktu
void dodajKontakt(vector<Kontakt>& kontakty) {
    Kontakt nowyKontakt;
    cout << "Podaj imię: ";
    cin.ignore();
    getline(cin, nowyKontakt.imie);

    // Pobieranie i walidacja numeru telefonu
    do {
        cout << "Podaj numer telefonu (min. 9 cyfr): ";
        getline(cin, nowyKontakt.numerTelefonu);
        if (!sprawdzNumerTelefonu(nowyKontakt.numerTelefonu)) {
            cout << "Nieprawidłowy numer telefonu. Spróbuj ponownie.\n";
        }
    } while (!sprawdzNumerTelefonu(nowyKontakt.numerTelefonu));

    // Pobieranie i walidacja adresu e-mail
    do {
        cout << "Podaj email (np. @gmail.com, @yahoo.com, @outlook.com): ";
        getline(cin, nowyKontakt.email);
        if (!sprawdzEmail(nowyKontakt.email)) {
            cout << "Nieprawidłowy email. Spróbuj ponownie.\n";
        }
    } while (!sprawdzEmail(nowyKontakt.email));

    kontakty.push_back(nowyKontakt);
    cout << "Kontakt został dodany pomyślnie!\n";
}

// Funkcja do wyświetlania wszystkich kontaktów
void wyswietlKontakty(const vector<Kontakt>& kontakty) {
    if (kontakty.empty()) {
        cout << "Brak kontaktów do wyświetlenia.\n";
        return;
    }
    cout << "\n===== Kontakty =====\n";
    for (const auto& kontakt : kontakty) {
        cout << "Imię: " << kontakt.imie << "\n";
        cout << "Telefon: " << kontakt.numerTelefonu << "\n";
        cout << "Email: " << kontakt.email << "\n";
        cout << "--------------------\n";
    }
}

// Funkcja do wyszukiwania kontaktu po imieniu
void wyszukajKontakt(const vector<Kontakt>& kontakty) {
    string szukaneImie;
    cout << "Podaj imię do wyszukania: ";
    cin.ignore();
    getline(cin, szukaneImie);
    bool znaleziono = false;
    for (const auto& kontakt : kontakty) {
        if (kontakt.imie == szukaneImie) {
            cout << "Znaleziono kontakt!\n";
            cout << "Imię: " << kontakt.imie << "\n";
            cout << "Telefon: " << kontakt.numerTelefonu << "\n";
            cout << "Email: " << kontakt.email << "\n";
            znaleziono = true;
            break;
        }
    }
    if (!znaleziono) {
        cout << "Nie znaleziono kontaktu.\n";
    }
}

// Funkcja do usuwania kontaktu po imieniu
void usunKontakt(vector<Kontakt>& kontakty) {
    string imieDoUsuniecia;
    cout << "Podaj imię do usunięcia: ";
    cin.ignore();
    getline(cin, imieDoUsuniecia);
    auto it = remove_if(kontakty.begin(), kontakty.end(), [&](const Kontakt& kontakt) {
        return kontakt.imie == imieDoUsuniecia;
    });
    if (it != kontakty.end()) {
        kontakty.erase(it, kontakty.end());
        cout << "Kontakt został pomyślnie usunięty!\n";
    } else {
        cout << "Nie znaleziono kontaktu.\n";
    }
}

// Funkcja główna
int main() {
    vector<Kontakt> kontakty;
    int wybor;
    do {
        wyswietlMenu();
        cin >> wybor;
        switch (wybor) {
            case 1:
                dodajKontakt(kontakty);
                break;
            case 2:
                wyswietlKontakty(kontakty);
                break;
            case 3:
                wyszukajKontakt(kontakty);
                break;
            case 4:
                usunKontakt(kontakty);
                break;
            case 5:
                cout << "Zamykanie programu...\n";
                break;
            default:
                cout << "Nieprawidłowa opcja. Spróbuj ponownie.\n";
        }
    } while (wybor != 5);

    return 0;
}
