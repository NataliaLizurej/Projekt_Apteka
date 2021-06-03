#include <iostream>
#include <stdlib.h>
#include <string.h>
 

using namespace std;

int liczba;
int status = 0;
string nazwa; 
int id;
int kto; 
string listaPomocnicza[4] = {};
void program();

void wyswietlStatus() {
  if (status == 1) {
    cout <<"Zalogowany jako: ";
    cout << nazwa << endl;
  } else if (status == 0) {
    cout <<"Niezalogowany" << endl;
  }
}

struct Administrator {
  string imie;
  string nazwisko;
  string login;
  string haslo;
};

struct Administrator bazaDanychAdministrator[3] = {};
int indexAdministrator = 1;

void bazaAdministratorow() {
  struct Administrator administrator;

  administrator.imie = "Natalia";
  administrator.nazwisko = "Lizurej";
  administrator.login = "natalia";
  administrator.haslo = "admin000";
  bazaDanychAdministrator[0] = administrator;
}


void logowanieAdministrator() {
  string loginAdmin;
  string hasloAdmin;

  cout <<"                        Logowanie do konta administratora. \n" << endl;
  cout <<"Login: ";
  cin >> loginAdmin;
  cout <<"Haslo: ";
  cin >> hasloAdmin;

  for (int i = 0; i<3; i++) {
    if (bazaDanychAdministrator[i].login == loginAdmin && bazaDanychAdministrator[i].haslo == hasloAdmin) {
      status = 1;
      kto = 1;
      nazwa = loginAdmin;
    }
  } 
  if (status == 1) {
    cout << "Zalogowano." << endl;
    cin >> liczba;
    if (liczba == 0) {
      program();
    }
  } else {
    cout <<"Nieprawidlowy login lub haslo.Sprobuj ponownie. \n\n" << endl;
    logowanieAdministrator();
  }
}

struct Uzytkownik {
  string imie;
  string nazwisko;
  string pesel;
  string telefon;
  string login;
  string haslo;
};

struct Uzytkownik bazaDanychUzytkownik[100] = {};
int indexUzytkownik = 1;

void bazaUzytkownikow() {
   struct Uzytkownik uzytkownik;

    uzytkownik.imie = "Jan";
    uzytkownik.nazwisko = "Kowalski";
    uzytkownik.pesel = "12345678944";
    uzytkownik.telefon = "123456789";
    uzytkownik.login = "janek123";
    uzytkownik.haslo = "jakieshaslo1";
    bazaDanychUzytkownik[0] = uzytkownik;
}

void logowanieUzytkownik() {
  string loginUzytkownik;
  string hasloUzytkownik;

  cout <<"                        Logowanie do konta pacjenta. \n" << endl;
  cout <<"Login: ";
  cin >> loginUzytkownik;
  cout <<"Haslo: ";
  cin >> hasloUzytkownik;

  for (int i = 0; i<100; i++) {
    if (bazaDanychUzytkownik[i].login == loginUzytkownik && bazaDanychUzytkownik[i].haslo == hasloUzytkownik) {
      status = 1;
      kto = 0;
      nazwa = loginUzytkownik;
      id = i;
    }
  } 
  if (status == 1) {
    cout << "Zalogowano." << endl;
    cin >> liczba;
    if (liczba == 0) {
      program();
    }
  } else {
    cout <<"Nieprawidlowy login lub haslo.Sprobuj ponownie. \n\n" << endl;
    logowanieUzytkownik();
  }
}

struct Recepta {
  string wlasciciel;
  string numer;
  string tab[4] = {};
};

struct Recepta bazaDanychRecept[100] = {};
int indexRecepta = 1;

void bazaRecept() {
  struct Recepta recepta;

  recepta.wlasciciel = bazaDanychUzytkownik[0].login;
  recepta.numer = "1234";
  recepta.tab[0] = "ABC";
  recepta.tab[1] = "12dewde3";
  recepta.tab[2] = "XdeedYZ";
  recepta.tab[3] = "Leu8";
  bazaDanychRecept[0] = recepta;
}


void mojeKontoAdmin () {
  if (status == 1 && kto == 1) {
    cout <<"                          Informacje o Twoim koncie:" << endl;
    cout <<"Imie: ";
    cout << bazaDanychAdministrator[id].imie << endl;
    cout <<"Nazwisko: ";
    cout << bazaDanychAdministrator[id].nazwisko << endl;
    cout <<"Login: ";
    cout << bazaDanychAdministrator[id].login << endl;
    cout <<"Haslo: ";
    cout << bazaDanychAdministrator[id].haslo << endl;
  } else if (status == 1 && kto == 0) {
    cout <<"Jestes zalogowany na koncie pacjenta." << endl;
  } else if (status == 0) {
    cout <<"Aby zobaczyc informacje o swoim koncie, najpierw musisz sie zalogowac." << endl;
  }
   cin >> liczba;
  if (liczba == 0) {
    program();
  }
}

void mojeKontoUzytkownik () {
  if (status == 1 && kto == 0) {
    cout <<"                          Informacje o Twoim koncie:" << endl;
    cout <<"Imie: ";
    cout << bazaDanychUzytkownik[id].imie << endl;
    cout <<"Nazwisko: ";
    cout << bazaDanychUzytkownik[id].nazwisko << endl;
    cout <<"Login: ";
    cout << bazaDanychUzytkownik[id].login << endl;
    cout <<"Haslo: ";
    cout << bazaDanychUzytkownik[id].haslo << endl;
    cout <<"Pesel: ";
    cout <<bazaDanychUzytkownik[id].pesel << endl;
    cout <<"Telefon: ";
    cout << bazaDanychUzytkownik->telefon << endl;
  }  else if (status == 1 && kto == 1) {
    cout <<"Jestes zalogowany na konto administratora." << endl;
  } else if (status == 0) {
    cout <<"Aby zobaczyc informacje o swoim koncie, najpierw musisz sie zalogowac." << endl;
  }
  cin >> liczba;
  if (liczba == 0) {
    program();
  }
}

bool czyIstniejeUzytkownik(string login) {
  for (int i=0; i<sizeof(bazaDanychUzytkownik)/sizeof(bazaDanychUzytkownik[0]); i++) {
    if (bazaDanychUzytkownik[i].login == login) {
      return true;
    } else {
      return false;
    }
  }
}

bool czyPrawidlowyPesel(string pesel) {
   int znaki = pesel.length();
    for (int i=0; i<sizeof(bazaDanychUzytkownik)/sizeof(bazaDanychUzytkownik[0]); i++) {
    if (bazaDanychUzytkownik[i].pesel == pesel && znaki == 11) {
      return true;
    } else {
      return false;
    }
  }
}

bool czyPrawidlowyTelefon(string telefon) {
  int znaki = telefon.length();
  for (int i=0; i<sizeof(bazaDanychUzytkownik)/sizeof(bazaDanychUzytkownik[0]); i++) {
    if (bazaDanychUzytkownik[i].telefon == telefon && znaki == 9) {
      return true;
    } else {
      return false;
    }
  }
}

bool czyPrawdiloweHaslo(string haslo) {
  int znaki = haslo.length();
  if (znaki >= 8) {
    return true;
  } else {
    return false;
  }
}

bool czyIstniejeNumerRecepty(string numer) {
  int znaki = numer.length();
  for (int i=0; i<sizeof(bazaDanychRecept)/sizeof(bazaDanychRecept[0]); i++) {
    if (bazaDanychRecept[i].numer == numer && znaki == 4) {
      return true;
    } else {
      return false;
    }
  }
}

void rejestrujPacjenta() {
  struct Uzytkownik uzytkownik;
  string imieUzytk;
  string nazwiskoUzytk;
  string peselUzytk;
  string telefonUzytk;
  string loginUzytk;
  string hasloUzytk;

  if (status == 1 && kto == 1) {
    cout <<"                            Rejestruj pacjenta." << endl;
    cout <<"Wprowadz dane:" << endl;
    cout <<"Imie: ";
    cin >> imieUzytk;
    uzytkownik.imie = imieUzytk;
    cout <<"Nazwisko: ";
    cin >> nazwiskoUzytk;
    uzytkownik.nazwisko = nazwiskoUzytk;
    cout <<"Pesel: ";
    cin >> peselUzytk;
      if (czyPrawidlowyPesel(uzytkownik.pesel)) {
      cout <<"Pesel jest bledny, lub taki pesel istnieje juz w bazie!" << endl;
      cin >> liczba;
      if (liczba == 0) {
        program();
      }
    }
    uzytkownik.pesel = peselUzytk;
    cout <<"Telefon: ";
    cin >> telefonUzytk;
      if (czyPrawidlowyTelefon(uzytkownik.telefon)) {
      cout <<"Numer etelefonu jest bledny, lub taki pesel istnieje juz w bazie!" << endl;
      cin >> liczba;
      if (liczba == 0) {
        program();
      }
    }
    uzytkownik.telefon = telefonUzytk;
    cout <<"Login: ";
    cin >> loginUzytk;
    if (czyIstniejeUzytkownik(uzytkownik.login)) {
      cout <<"Uzytkownik o podanym loginie juz istnieje!" << endl;
      cin >> liczba;
      if (liczba == 0) {
        program();
      }
    }
    uzytkownik.login = loginUzytk;
    cout <<"Haslo: ";
    cin >> hasloUzytk;
      if (czyPrawdiloweHaslo(uzytkownik.haslo)) {
      cout<<"Haslo musi skladac sie z conajmniej 8 znakow!" << endl;
      cin >> liczba;
      if (liczba == 0) {
        program();
      }
    }
    uzytkownik.haslo = hasloUzytk;
    cout << " " << endl;


    bazaDanychUzytkownik[indexUzytkownik] = uzytkownik;
    indexUzytkownik++;
    cout << "Zarejestrowales uzytkownika." << endl;
     cin >> liczba;
      if (liczba == 0) {
        program();
      }
    
  } else {
    cout <<"Brak dostepu, nie masz uprawnien." << endl;
    cin >> liczba;
    if (liczba == 0) {
      program();
    }
  }
}

void wystawRecepte() {
  struct Recepta recepta;
  string wlascicielRecepty;
  string numerRecepty;
  int liczbaLekow;
  string tab[5] = {};
  string nazwaLeku;

  if (status == 1 && kto == 1) {
    cout <<"                            Wprowadz dane, aby wystawic recepte." << endl;
    cout <<"Login pacjenta: ";
    cin >> wlascicielRecepty;
    recepta.wlasciciel = wlascicielRecepty;
    cout <<"Numer recepty: ";
    cin >> numerRecepty;
    if (czyIstniejeNumerRecepty(numerRecepty)) {
      cout<<"Nieprawdilowy numer recepty, lub taki numer juz istnieje w bazie." << endl;
      cin >> liczba;
      if (liczba == 0){
        program();
      }
    }
    recepta.numer = numerRecepty;
    cout <<"Liczba lekow (max.liczba:4): ";
    cin >> liczbaLekow;
    cout <<"Wpisz nazwy lekow (jednowyrazowe): " << endl;


    
    for (int i = 0; i <liczbaLekow; i++) {
        cout << i;
        cout << ". ";
        cin >> nazwaLeku;
        tab[i] = nazwaLeku;
    }

    bazaDanychRecept[indexRecepta] = recepta;
    indexRecepta++;
    
    cin >> liczba;
    if (liczba == 0) {
      program();
    }
    
    
    } else {
      cout <<"Brak dostepu, nie masz uprawnien." << endl;
      cin >> liczba;
      if (liczba == 0) {
        program();
      }
   }
}

void numeryDoRecept() {
  int x = 0;
  for (int i = 0; i < sizeof(bazaDanychRecept) / sizeof(bazaDanychRecept[0]); i++) {
    if (bazaDanychRecept[i].wlasciciel == nazwa) {
      cout << bazaDanychRecept[i].numer << endl;
      listaPomocnicza[x] = bazaDanychRecept[i].numer;
      x++;
    }
  } 
}

void pomocniczaRecepty(string h) {
  for (int i = 0; i < sizeof(bazaDanychRecept) / sizeof(bazaDanychRecept[0]); i++){
    if (bazaDanychRecept[i].numer == h){
      for (int x = 0; x < sizeof(bazaDanychRecept[i].tab) / sizeof(bazaDanychRecept[i].tab[0]); x++) {
        cout << bazaDanychRecept[i].tab[x] << endl;
      }
    }
  }
}

void listaLekow(string recepta) {
string h;

 for (int i = 0; i < sizeof(listaPomocnicza) / sizeof(listaPomocnicza[0]); i++) {
   if (listaPomocnicza[i] == recepta) {
     h = recepta;
     pomocniczaRecepty(h);
     cin >> liczba;
     if (liczba == 0) {
       program();
     }
   } else {
     cout <<"Zly numer recepty." << endl;
     cin >> liczba;
     if (liczba == 0) {
       program();
     }
   }
 }
}

void ostatecznaLista(string o) {
  int l;
  for (int i = 0; i < sizeof(bazaDanychRecept) / sizeof(bazaDanychRecept[0]); i++) {
    if (bazaDanychRecept[i].numer == o) {
      l = i;
    }
  }
   for (int x = 0; x < sizeof(bazaDanychRecept[l].tab) / sizeof(bazaDanychRecept[l].tab[0]); x++){
        cout << bazaDanychRecept[l].tab[x] << endl;
  }
}


void wyswietlRecepty() {
  int pomocnicza = 0;
  int k;
  int ilosc = 0;
  string nr;

  if (status == 1 && kto == 0) {
    for (int i = 0; i < sizeof(bazaDanychRecept) / sizeof(bazaDanychRecept[0]); i++) {
      if (bazaDanychRecept[i].wlasciciel == nazwa) {
        ilosc++;
        pomocnicza = 1;
        k = i;
      }
    }  
    if (pomocnicza == 1) {
      cout <<" " << endl;
      cout <<"Ilosc wystawionych recept: ";
      cout << ilosc << endl;
      numeryDoRecept();
      cout << "Wpisz numer recepty, aby zobaczyc szczegoly: " << endl;
      cin >> nr;
      ostatecznaLista(nr);

      cin >> liczba;
      if (liczba == 0) {
        program();
      }
    } else {
      cout <<"Nie masz recept." << endl;
      cin >> liczba;
      if (liczba == 0) {
        program();
      }
    }
  } else {
    cout <<"Brak dostepu, nie masz uprawnien." << endl;
    cin >> liczba;
    if (liczba == 0){
      program();
    }
  }
}


void menu() {
  cout <<" * * *        *        * * *     * * *     * * *      *    *        *      " << endl;
  cout <<" *          *   *      *    *      *       *          *  *        *   *    " << endl;
  cout <<" * * *     * * * *     * * *       *       * * *      * *        * * * *   " << endl;
  cout <<" *         *     *     *           *       *          *  *       *     *   " << endl;
  cout <<" * * *     *     *     *           *       * * *      *    *     *     * \n" << endl;

  wyswietlStatus();
  cout <<"                                1.Administrator                             " << endl;
  cout <<"                                2.Pacjent                                   " << endl;
  cout <<"                                3.Wyloguj                                   " << endl;
  cout <<"                                4.Wyjscie                                   " << endl;
  cout <<"*Jesli chcesz powrocic do menu z danego miejsca, wybierz 0.                 " << endl;
}


void administrator() {
  wyswietlStatus();
  cout <<"                               Panel administratora.                        " << endl;
  cout <<"1.Zaloguj.                                                                  " << endl;
  cout <<"2.Moje konto.                                                               " << endl;
  cout <<"3.Rejestruj pacjenta.                                                       " << endl;
  cout <<"4.Wystaw recepte.                                                           " << endl;
 
  cin >> liczba;

  if (liczba == 0) {
    program();
  }
  else if (liczba == 1 && status == 0) {
    logowanieAdministrator();
  }
  else if (liczba == 1 && status == 1) {
    cout <<"Aby sie zalogowac, musisz wylogowac sie z aktualnego konta." << endl;
    cin >> liczba;
    if (liczba == 0) {
      program();
    }
  } else if (liczba == 2 && status == 1) {
    mojeKontoAdmin();
  } else if (liczba == 2 && status == 0) {
    mojeKontoAdmin();
  } else if (liczba == 3 && status == 1) {
    rejestrujPacjenta();
  } else if (liczba == 3 && status == 0) {
    rejestrujPacjenta();
  } else if (liczba == 4 && status == 1) {
    wystawRecepte();
  } else if (liczba == 4 && status == 0) {
    wystawRecepte();
  }
}


void pacjent() {
  wyswietlStatus();
  cout <<"                               Panel pacjenta.                              " << endl;
  cout <<"1.Zaloguj.                                                                  " << endl;
  cout <<"2.Moje konto.                                                               " << endl;
  cout <<"3.Moje recepty.                                                             " << endl;
  
  cin >> liczba;

   if (liczba == 0) {
    program();
  }
  else if (liczba == 1 && status == 0) {
    logowanieUzytkownik();
  }
  else if (liczba == 1 && status == 1) {
    cout <<"Aby sie zalogowac, musisz wylogowac sie z aktualnego konta." << endl;
    cin >> liczba;
    if (liczba == 0) {
      program();
    }
  }
  else if (liczba == 2 && status == 1) {
    mojeKontoUzytkownik();
  }
  else if (liczba == 2 && status == 0) {
   mojeKontoUzytkownik();
  } else if (liczba == 3 && status == 0) {
    wyswietlRecepty();
  } else if (liczba == 3 && status == 1) {
    wyswietlRecepty();
  }
}

void wylogujSie() {
  if (status == 0) {
    cout <<"Aby sie wylogowac, musisz byc zalogowany." << endl;
    cin >> liczba;
    if (liczba == 0) {
      program();
    }
  } else {
    status = 0;
    cout <<"Zostales wylogowany." << endl;
  }
  cin >> liczba;
    if (liczba == 0) {
      program();
  }
}


void wyjscie() {
  wyswietlStatus();
  cout <<"                               Czy na penwo chcesz zakonczyc program?       " << endl;
  cout <<"1.Tak, zakoncz program.                                                     " << endl;
  cout <<"2.Nie, wroc do menu startowego.                                             " << endl;

  cin >> liczba;

  if (liczba == 1) {
    exit(1);
  }
  else {
    program();
  }
  
}


void program() {
  cout << "\n\n\n" << endl;
  menu();
  cin >> liczba;
  cout << "\n\n" << endl; 
  
  if (liczba == 1) {
    administrator();
  }
  else if (liczba == 2) {
    pacjent();
  }
  else if (liczba == 3) {
    wylogujSie();
  }
  else if (liczba == 4) {
    wyjscie();
  }
  else {
    cout <<" Wprowadz poprawna liczbe. \n" << endl;
  }
}


int main() {
    bazaAdministratorow();
    bazaUzytkownikow();
    bazaRecept();
    program();
    return 0;
}

