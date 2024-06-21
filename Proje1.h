/*
@file Proje1
@description Bu projede, C programlama dilinde yapılar(struct),işaretçiler(pointers)
ve dinamik bellek lullanarak problem çözme becerimizi geliştirmek amaçlanmıştır.
@assignment Proje1
@date 27.11.2023
@author Şevval Bilğin sevval.bilgin@stu.fsm.edu.tr

*/


typedef struct
{
    char *dersAdi;
    unsigned short int kredi;
    unsigned short int puan;
} Ders;

typedef struct
{
    char *ogrAdi;
    char *ogrSoyadi;
    char *bolumu;
    float ortalama;
    Ders *aldigiDersler;
} Ogrenci;
float derslerinKovaryansiniHesapla(Ders ders1, Ders ders2, int size, Ders *tumdersler);
void dosyayaOgrenciBilgileriYaz(const char* dosyaAdi,Ogrenci ogrenci, int derssayisi);
void ogrenciBilgileriniYazdir(Ogrenci std);
Ders degerlerIleDersDondur(char *dersAdi, unsigned short int kredi, unsigned short int puan);
Ogrenci degerlerIleOgrenciDondur(const char* dosyaAdi,char *ogrAdi, char *ogrSoyadi, char *bolumu, float ortalama, Ders *alinandersler, int dersSayisi);
void ogrenciDizisiBilgileriniYazdir(Ogrenci *std, int ogrenciSayisi, int *dersSayilari);
float dersinAritmetikOrtlamasiniHesapla(char *dersAdi, int size, Ders *dersler);
float dersinStandartSapmasiniHesapla(char *dersAdi, int size, Ders *);
Ogrenci *ogrencileriDosyadanOkuveEkranaYaz(const char *dosyaAdi);
Ogrenci *ortalamadanYuksekAlanOgrencileriDondur(const char*dsoyaAdi,char *dersAdi, int size, Ders *);





