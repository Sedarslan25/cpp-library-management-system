#include <iostream>
#include <locale>
#include <string>

#define MAX_KITAP_SAYISI 10
#define MAX_UYE_SAYISI 10
#define MAX_KUTUPHANE_SAYISI 10
using namespace std;

class Uye {
protected:
    string isim, soyad;
public:
    // Constructor (Kurucu Fonksiyon)
    Uye(string isim = " ", string soyad = " ") : isim(isim), soyad(soyad) {}

    string getIsim() { return isim; }
    void setIsim(string isim) { this->isim = isim; }

    string getSoyad() { return soyad; }
    void setSoyad(string soyad) { this->soyad = soyad; }

    virtual void bilgileriAl() = 0;
    virtual void uyeYazdir() = 0;
};

class Kitap {
private:
    string isim;
    string yazar;
    string kategori;
    int yayinlamaYili;
public:
    // Constructor (Kurucu Fonksiyon)
    Kitap(string isim = "", string yazar = "", string kategori = "", int yayinlamaYili = 0)
        : isim(isim), yazar(yazar), kategori(kategori), yayinlamaYili(yayinlamaYili) {}

    string getIsim() { return isim; }
    void setIsim(string isim) { this->isim = isim; }

    string getYazar() { return yazar; }
    void setYazar(string yazar) { this->yazar = yazar; }

    string getKategori() { return kategori; }
    void setKategori(string kategori) { this->kategori = kategori; }

    int getYayinlamaYili() { return yayinlamaYili; }
    void setYayinlamaYili(int yayinlamaYili) { this->yayinlamaYili = yayinlamaYili; }

    // Kitap bilgilerini yazdırma fonksiyonu
    void kitapYazdir() {
        cout << "Kitap Adı: " << isim << endl;
        cout << "Yazar: " << yazar << endl;
        cout << "Kategori: " << kategori << endl;
        cout << "Yayınlanma Yılı: " << yayinlamaYili << endl;
    }

    // Kitap bilgilerini topluca ayarlayan fonksiyon
    void setBilgiler(string isim, string yazar, string kategori, int yayinlamaYili) {
        this->isim = isim;
        this->yazar = yazar;
        this->kategori = kategori;
        this->yayinlamaYili = yayinlamaYili;
    }
};

class Ogrenci : public Uye {
private:
    int ogrenciNo;
public:
    Ogrenci(string isim = " ", string soyad = " ", int ogrenciNo = 0) : Uye(isim, soyad), ogrenciNo(ogrenciNo) {}

    void bilgileriAl() override {
        cout << "Ögrenci Adı: ";
        cin.ignore();
        getline(cin, isim);
        cout << "Soyisim: ";
        getline(cin, soyad);
        cout << "Ögrenci No: ";
        cin >> ogrenciNo;
    }

    void uyeYazdir() override {
        cout << "Ögrenci Adı: " << isim << endl;
        cout << "Soyisim: " << soyad << endl;
        cout << "Ögrenci No: " << ogrenciNo << endl;
    }
};

class Personel : public Uye {
private:
    int sicilNo;
public:
    Personel(string isim = " ", string soyad = " ", int sicilNo = 0) : Uye(isim, soyad), sicilNo(sicilNo) {}

    void bilgileriAl() override {
        cout << "Personel Adı: ";
        cin.ignore();
        getline(cin, isim);
        cout << "Soyisim: ";
        getline(cin, soyad);
        cout << "Sicil No: ";
        cin >> sicilNo;
    }

    void uyeYazdir() override {
        cout << "Personel Adı: " << isim << endl;
        cout << "Soyisim: " << soyad << endl;
        cout << "Sicil No: " << sicilNo << endl;
    }
};


class Kutuphane {
private:
    Kitap kitaplar[MAX_KITAP_SAYISI]; // Kitapları tutan dizi
    int kitapSayisi; // Mevcut kitap sayisi
    Uye* uyeler[MAX_UYE_SAYISI]; // Üyeleri tutan dizi
    int uyesayisi; // Mevcut uye sayisi
    Kutuphane* kutuphaneler[MAX_KUTUPHANE_SAYISI]; // Kutuphaneleri tutan dizi
    int kutuphaneSayisi; // Mevcut kutuphane sayisi
    string kutuphaneAdi;
public:
    Kutuphane(string kutuphaneAdi = "") : kitapSayisi(0), uyesayisi(0), kutuphaneSayisi(0), kutuphaneAdi(kutuphaneAdi) {} // Constructor

    void kitapEkle() {
        if (kitapSayisi < MAX_KITAP_SAYISI) {
            string isim, yazar, kategori;
            int yayinlanmaYili;

            cout << "Kitap Adı: ";
            cin.ignore();
            getline(cin, isim);
            cout << "Yazar: ";
            getline(cin, yazar);
            cout << "Kategori: ";
            getline(cin, kategori);
            cout << "Yayınlanma Yılı: ";
            cin >> yayinlanmaYili;

            kitaplar[kitapSayisi].setBilgiler(isim, yazar, kategori, yayinlanmaYili);
            kitapSayisi++;
            cout << "Kitap eklendi." << endl;
        }
        else {
            cout << "Kutuphaneye daha fazla kitap eklenemez." << endl;
        }
    }

    void kitaplariListele() {
        if (kitapSayisi == 0) {
            cout << "Kutuphanede hiç kitap yok." << endl;
        }
        else {
            for (int i = 0; i < kitapSayisi; i++) {
                kitaplar[i].kitapYazdir();
                cout << endl;
            }
        }
    }

    void kitapSil(string isim) {
        for (int i = 0; i < kitapSayisi; i++) {
            if (kitaplar[i].getIsim() == isim) {
                for (int j = i; j < kitapSayisi - 1; j++) {
                    kitaplar[j] = kitaplar[j + 1];
                }
                kitapSayisi--;
                cout << "Kitap silindi." << endl;
                return;
            }
        }
        cout << "Kitap bulunamadı." << endl;
    }

    void uyeEkle(int tur) {
        if (uyesayisi < MAX_UYE_SAYISI) {
            Uye* yeniUye;
            if (tur == 1) {
                yeniUye = new Personel();
            }
            else if (tur == 2) {
                yeniUye = new Ogrenci();
            }
            else {
                cout << "Geçersiz uye turu." << endl;
                return;
            }

            yeniUye->bilgileriAl();
            uyeler[uyesayisi] = yeniUye;
            uyesayisi++;
            cout << "Uye eklendi." << endl;
        }
        else {
            cout << "Kutuphaneye daha fazla uye eklenemez." << endl;
        }
    }

    void uyeleriListele() {
        if (uyesayisi == 0) {
            cout << "Kutuphanede hiç uye yok." << endl;
        }
        else {
            for (int i = 0; i < uyesayisi; i++) {
                uyeler[i]->uyeYazdir();
                cout << endl;
            }
        }
    }

    void uyeSil(string isim) {
        for (int i = 0; i < uyesayisi; i++) {
            if (uyeler[i]->getIsim() == isim) {
                delete uyeler[i];
                for (int j = i; j < uyesayisi - 1; j++) {
                    uyeler[j] = uyeler[j + 1];
                }
                uyesayisi--;
                cout << "Uye silindi." << endl;
                return;
            }
        }
        cout << "Uye bulunamadı." << endl;
    }

    void kutuphaneEkle(string kutuphaneAdi) {
        if (kutuphaneSayisi < MAX_KUTUPHANE_SAYISI) {
            kutuphaneler[kutuphaneSayisi] = new Kutuphane(kutuphaneAdi);
            kutuphaneSayisi++;
            cout << kutuphaneAdi << " kutuphanesi eklendi." << endl;
        }
        else {
            cout << "Daha fazla kutuphane eklenemez." << endl;
        }
    }

    void kutuphaneleriListele() {
        if (kutuphaneSayisi == 0) {
            cout << "Hiç kutuphane yok." << endl;
        }
        else {
            for (int i = 0; i < kutuphaneSayisi; i++) {
                cout << kutuphaneler[i]->kutuphaneAdi << endl;
            }
        }
    }

    void kutuphaneSil(string kutuphaneAdi) {
        for (int i = 0; i < kutuphaneSayisi; i++) {
            if (kutuphaneler[i]->kutuphaneAdi == kutuphaneAdi) {
                delete kutuphaneler[i];
                for (int j = i; j < kutuphaneSayisi - 1; j++) {
                    kutuphaneler[j] = kutuphaneler[j + 1];
                }
                kutuphaneSayisi--;
                cout << kutuphaneAdi << " kutuphanesi silindi." << endl;
                return;
            }
        }
        cout << "Kutuphane bulunamadı." << endl;
    }

    ~Kutuphane() {
        for (int i = 0; i < uyesayisi; i++) {
            delete uyeler[i];
        }
        for (int i = 0; i < kutuphaneSayisi; i++) {
            delete kutuphaneler[i];
        }
    }
};

int main() {
    // Turkçe karakter destegini ayarla
    locale::global(locale(""));

    Kutuphane kutuphane;

    int secim;
    int kutuphaneSecim;
    int uyesecim = 0;

    string kutuphaneadi;
    string kutuphaneAdi;
    string silinecekKitapAdi;
    string silinecekUyeIsim;

    cout << "                                              KUTUPHANE YÖNETIM SISTEMI                " << endl;
    string kullaniciAdi = "admin";
    string sifre = "1234";

    string girilenKullaniciAdi;
    string girilenSifre;

    do {
	    cout << "Kullanici adi: ";
	    cin >> girilenKullaniciAdi;
	    cout << "Şifre: ";
	    cin >> girilenSifre;
	
	    if (girilenKullaniciAdi == kullaniciAdi && girilenSifre == sifre) {
	        cout << "Giriş Başarili, Hoşgeldiniz " << kullaniciAdi << endl;
	        break;
	    }
	    else {
	        cout << "Hatali kullanici adi veya şifre. Lutfen tekrar deneyin." << endl;
	    }
    } while (1 == 1);

    do {
        cout << "1. Kutuphaneleri listele" << endl;
        cout << "2. Kutuphane ekle" << endl;
        cout << "3. Kutuphane sil" << endl;
        cout << "0. Çikiş" << endl;
        cout << "Seciminiz: ";
        cin >> secim;

        switch (secim) {
        case 1:
            kutuphane.kutuphaneleriListele();

            cout << "kutuphane ile ilgili işlem yapmak icin kutuphane secin: " << endl;
            cin >> kutuphaneadi;
            cout << "1. Kitaplari listele" << endl;
            cout << "2. Kitap ekle" << endl;
            cout << "3. Kitap sil" << endl;
            cout << "4. Uyeleri listele" << endl;
            cout << "5. Uye ekle" << endl;
            cout << "6. Uye sil" << endl;
            cout << "0. Geri" << endl;
            cout << "Seciniz: ";
            cin >> kutuphaneSecim;

            switch (kutuphaneSecim) {
                
            case 1:
                // Kitaplari listele
                kutuphane.kitaplariListele();
                break;
            case 2:
                // Kitap ekle
                kutuphane.kitapEkle();
                break;
            case 3:
                // Kitap sil
                cout << "Silmek istediginiz kitabin adini girin: ";
                cin.ignore();
                getline(cin, silinecekKitapAdi);
                kutuphane.kitapSil(silinecekKitapAdi);
                break;
            case 4:
                // Uyeleri listele
                kutuphane.uyeleriListele();
                break;
            case 5:
                // Uye ekle
                cout << "1. Personel ekle" << endl;
                cout << "2. Ögrenci ekle" << endl;
                cin >> uyesecim;
                kutuphane.uyeEkle(uyesecim);
                break;
            case 6:
                // Uye sil
                cout << "Silmek istediğiniz uyenin ismini girin: ";
                cin.ignore();
                getline(cin, silinecekUyeIsim);
                kutuphane.uyeSil(silinecekUyeIsim);
                break;
            case 0:
                break;
            default:
                cout << "Gecersiz secim!" << endl;
                break;
            }
            break;
        case 2:
            cout << "Kutuphanenin adi: ";
            cin.ignore();
            getline(cin, kutuphaneAdi);
            kutuphane.kutuphaneEkle(kutuphaneAdi);
            break;
        case 3:
            cout << "Silmek istediğiniz kutuphane adini girin: ";
            cin.ignore();
            getline(cin, kutuphaneAdi);
            kutuphane.kutuphaneSil(kutuphaneAdi);
            break;
        case 0:
            cout << "Programdan cikiliyor..." << endl;
            break;
        default:
            cout << "Gecersiz secim!" << endl;
            break;
        }
    } while (secim != 0);

    return 0;
}


