/*
@file Proje1
@description Bu projede, C programlama dilinde yapılar(struct),işaretçiler(pointers)
ve dinamik bellek lullanarak problem çözme becerimizi geliştirmek amaçlanmıştır.
@assignment Proje1
@date 27.11.2023
@author Şevval Bilğin sevval.bilgin@stu.fsm.edu.tr

*/
#include <stdio.h>
#include <stdlib.h>
#include "Proje1.h"
#include <math.h>
#include <string.h>
// sınav notu o dersin ortalamasından yüksek olan ogrencileri döndürür
Ogrenci *ortalamadanYuksekAlanOgrencileriDondur(const char *dosyaAdi, char *dersAdi, int size, Ders *tumdersler)
{
    // dersin ortalamasını aldım
    float ortalama = dersinAritmetikOrtlamasiniHesapla(dersAdi, size, tumdersler);
    // dosya açtım ve okunabilir olup olmadığını kontrol ettim
    FILE *dosya = fopen(dosyaAdi, "r");
    if (dosya == NULL)
    {
        printf("Dosya acilamadi: %s\n", dosyaAdi);
        return NULL;
    }

    char satir[200];
    int satirSayisi = 0;
    Ogrenci *ogrenciler = (Ogrenci *)malloc(0);
    // satır sayısını buldum
    while (fgets(satir, sizeof(satir), dosya) != NULL)
    {
        satirSayisi++;
    }
    // pointerı dosyanın başına taşıdım
    fseek(dosya, 0, SEEK_SET);

    int yeni_ogr_konumu = 0;
    int i = 0;
    // satır satır dolaşmaya başladım
    for (i = 0; i < satirSayisi; i++)
    {
        fgets(satir, sizeof(satir), dosya);
        // sırayla dosyadaki değerleri uygun biçimdei değerlere atadım

        char *ogr_adi = strtok(satir, "&");

        char *ogr_soyadi = strtok(NULL, "&");
        char *ogr_bolumu = strtok(NULL, "&");
        float ortalama1 = atof(strtok(NULL, "&"));
        int j = 0;
        for (j = 0; j < 10; j++)
        {

            char *token = strtok(NULL, "&");
            // satırda istenen dersin adını görünce bloğa girer
            if (token != NULL && strcmp(token, dersAdi) == 0)
            {

                unsigned short int kredi = atoi(strtok(NULL, "&"));

                unsigned short int puan = atoi(strtok(NULL, "&"));
                int yeni_ogrenci_sayisi = 1;
                // satırdaki puan ortalamadan büyükse ogrenciler arrayinin boyutunu dinamik olarak arttırır
                //  ve yeni konuma bu öğrenciyi atar
                if (puan > ortalama)
                {
                    ogrenciler = (Ogrenci *)realloc(ogrenciler, yeni_ogrenci_sayisi * sizeof(Ogrenci));
                    yeni_ogrenci_sayisi++;

                    strcpy(ogrenciler[yeni_ogr_konumu].aldigiDersler[j].dersAdi, token);
                    strcpy(ogrenciler[yeni_ogr_konumu].ogrAdi, ogr_adi);
                    strcpy(ogrenciler[yeni_ogr_konumu].ogrSoyadi, ogr_soyadi);
                    strcpy(ogrenciler[yeni_ogr_konumu].bolumu, ogr_bolumu);
                    ogrenciler[yeni_ogr_konumu].ortalama = ortalama1;
                    ogrenciler[yeni_ogr_konumu].aldigiDersler[j].kredi = kredi;
                    ogrenciler[yeni_ogr_konumu].aldigiDersler[j].puan = puan;
                    break;
                }
            }
        }

        yeni_ogr_konumu++;
    }

    fclose(dosya);
    // öğrencileri döndürür
    return ogrenciler;
}
// dosyadan okunan öğrencileri arraye atar ya da arraye attıklarını ekrana yazar.
// görmek istersiniz diye iki işlemi ayır ayrı yaptım. test esnasında birini kapayıp diğerini açacağım.
// arraye atamadım ancak okumayı yaptım.
Ogrenci *ogrencileriDosyadanOkuveEkranaYaz(const char *dosyaAdi)
{ // dosyayı okuma modunda açtım
    FILE *dosya = fopen(dosyaAdi, "r");
    // dosyanın varlığını kontorl ettim
    if (dosya == NULL)
    {
        printf("Dosya acilamadi: %s\n", dosyaAdi);
        return NULL;
    }
    char satir[200];
    int satirSayisi = 0;
    // öğrencileri atacağım arrayi dinamik olarak oluşturdum
    Ogrenci *ogrenciler = (Ogrenci *)malloc(0);
    // satır sayısını buldum
    while (fgets(satir, sizeof(satir), dosya) != NULL)
    {
        satirSayisi++;
        ogrenciler = (Ogrenci *)realloc(ogrenciler, satirSayisi * sizeof(Ogrenci));
    }
    fseek(dosya, 0, SEEK_SET); // Dosyanın başına döndüm
    int i = 0;
    // satır sayısı kadar öğrenci olduğundan ve öğrenci formatı:
    // hilal&yildiz&bilgisayar&59.000000&Matematik&3&20&Turkce&5&40&Sosyal&4&60&
    // olduğundan & tokenine göre ayırdım ve atamaları yaptım.
    for (i = 0; i < satirSayisi; i++)
    {
        fgets(satir, sizeof(satir), dosya);
        char *token = strtok(satir, "&");
        // ogrenciler[i].ogrAdi = token;

        printf("Adi: %s ", token);

        // ogrenciler[i].ogrSoyadi = strtok(NULL, "&");
        printf("Soyadi: %s ", strtok(NULL, "&"));

        // ogrenciler[i].bolumu = strtok(NULL, "&");
        printf("Bolumu: %s ", strtok(NULL, "&"));
        // ogrenciler[i].ortalama = atof(strtok(NULL, "&"));

        printf("Ortalamasi: %f\n", atof(strtok(NULL, "&")));
        int j = 0;
        for (j = 0; j < 10; j++)
        {
            token = strtok(NULL, "&");
            if (token != NULL)
            {

                // ogrenciler[i].aldigiDersler[j].dersAdi = token;

                printf("Ders Adi:%s ", token);
                // ogrenciler[i].aldigiDersler[j].kredi = atoi(strtok(NULL, "&"));

                printf("Kredi: %-2d ", atoi(strtok(NULL, "&")));
                // ogrenciler[i].aldigiDersler[j].puan = atoi(strtok(NULL, "&"));
                printf("Not:%f\n", atof(strtok(NULL, "&")));
            }
        }
        printf("\n");
        // strcpy(ogrenciler[i].bolumu,strtok(NULL, "&") );
        // ogrenciler[i].ortalama = atof( strtok(NULL, "&"));
    }

    for (int i = 0; i < satirSayisi; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            free(ogrenciler[i].aldigiDersler[j].dersAdi);
        }
    }

    free(ogrenciler);
    fclose(dosya);

    return ogrenciler;
}
// kovaryans formülü
// Σ(Xi − Xortalama)(Yi − Yortalama)/n-1

float derslerinKovaryansiniHesapla(Ders ders1, Ders ders2, int size, Ders *tumdersler)
{ // kovaryans tanimi gereği iki dersin de ortalamasına ihtiyacım var
    float ortalamaders1 = dersinAritmetikOrtlamasiniHesapla(ders1.dersAdi, size, tumdersler);
    float ortalamaders2 = dersinAritmetikOrtlamasiniHesapla(ders2.dersAdi, size, tumdersler);
    // tüm dersler arasından sadece ihtiyacım olanların bulunacağı iki pointer oluşturdum
    Ders *yenidersler1 = (Ders *)malloc(0);
    Ders *yenidersler2 = (Ders *)malloc(0);
    int derssayisi1 = 0;
    int derssayisi2 = 0;
    int i = 0;
    int j = 0;
    float sum = 0;
    float kovaryans = 0;
    for (i = 0; i < size; i++)
    {
        // ders1 için yenidersler1'i elemanlarla doldurdum
        if (strcmp(tumdersler[i].dersAdi, ders1.dersAdi) == 0)
        {
            derssayisi1++;
            yenidersler1 = (Ders *)realloc(yenidersler1, sizeof(Ders) * derssayisi1);
            yenidersler1[derssayisi1 - 1] = tumdersler[i];
        }
    }
    for (j = 0; j < size; j++)
    {
        // ders2 için yenidersler2'yi elemanlarla doldurdum
        if (strcmp(tumdersler[j].dersAdi, ders2.dersAdi) == 0)
        {
            derssayisi2++;
            yenidersler2 = (Ders *)realloc(yenidersler2, sizeof(Ders) * derssayisi2);
            yenidersler2[derssayisi2 - 1] = tumdersler[j];
        }
    }
    int k = 0;
    // kovaryans tanımı gereği iki veri setinin ve veri sayısının aynı olması gerekir.
    // bunun kontrolünü yaptım
    if (derssayisi1 == derssayisi2)
    {
        // formüledeki adım adım toplamayı yaptım
        for (k = 0; k < derssayisi1; k++)
        {
            sum += (yenidersler1[k].puan - ortalamaders1) * (yenidersler2[k].puan - ortalamaders2);
        }

        // formüldeki /n-1 kısmı 
        kovaryans = sum / derssayisi1-1;

        return kovaryans;
    }
    else
    {
        printf("Ayni sayida ders girmelisiniz!!");
        return -1;
    }
}
// standart sapma formülü
// √Σ((Xi-Xortalama)²)/n-1)
float dersinStandartSapmasiniHesapla(char *dersAdi, int size, Ders *dersler)
{
    float sum = 0;
    float standartSapma = 0;
    // standart sapma formülü ortalmaya ihtiyaç duyar
    float ortalama = dersinAritmetikOrtlamasiniHesapla(dersAdi, size, dersler);

    int i = 0;
    int derssayisi = 0;
    Ders *yeniDersler = (Ders *)malloc(0);
    for (i = 0; i < size; i++)
    { // tüm dersler arasından ihtiyacım olanları yeni bir arraye atadım
        if (strcmp(dersler[i].dersAdi, dersAdi) == 0)
        {
            derssayisi++;
            yeniDersler = (Ders *)realloc(yeniDersler, sizeof(Ders) * derssayisi);
            yeniDersler[derssayisi - 1] = dersler[i];
        }
    }
    int j = 0;
    for (j = 0; j < derssayisi; j++)
    {
        float puan = (float)yeniDersler[j].puan;
        // formülde ihtiyaç olduğundan karelerinin toplamını aldım
        sum += powf((puan - ortalama), 2.0);
    }
    // n-1'e bölerek staandart sapmayı buldum
    standartSapma = sqrtf(sum / (float)(derssayisi - 1));
    return standartSapma;
} // hem öğrenci arrayi için hem de her öğrencinin dersler arrayleri için
// arraylerin sonunu bilebeilmek için size değişkenine ihtiyacım var,
// bunları parametre olarak aldım
void ogrenciDizisiBilgileriniYazdir(Ogrenci *std, int ogrenciSayisi, int *dersSayilari)
{
    int i = 0;
    for (i = 0; i < ogrenciSayisi; i++)
    { // std arrayi üzerined gezinerek bilgilerini yazdırdım

        printf("\n %d. ogrenci:\n", i + 1);
        printf("Ogrencinin Adi: %s\n", std[i].ogrAdi);
        printf("Ogrencinin Soyadi: %s\n", std[i].ogrSoyadi);
        printf("Ogrencinin Bolumu: %s\n", std[i].bolumu);

        int j = 0;
        printf("ders sayisi:%d ", dersSayilari[i]);
        for (j = 0; j < dersSayilari[i]; j++)
        { // her std üyesine ait aldigidersler arrayinin üyelerinin bilgilerini yazdırdım

            printf("%s", std[i].aldigiDersler[j].dersAdi);

            printf(" %hu kredili, %hu puan\n", std[i].aldigiDersler[j].kredi, std[i].aldigiDersler[j].puan);
        }
    }
}
// aritmetik ortalama formülü
//  Σ(Xi)/n
// tüm dersleri içeren dersler arrayli için
//  dinamik dizinin sonunu bilebeilmek için size değişkenine ihtiyacım var.
// bunu parametre olarak aldım
float dersinAritmetikOrtlamasiniHesapla(char *dersAdi, int size, Ders *dersler)
{
    int derssayisi = 0;
    int i = 0;
    float sum = 0;
    for (i = 0; i < size; i++)
    {

        if (strcmp(dersler[i].dersAdi, dersAdi) == 0)
        {

            derssayisi++;
            sum += dersler[i].puan;
        }
    }
    if (derssayisi == 0)
    {
        printf(" %s dersi bulunamadi.\n", dersAdi);
        return -1;
    }
    return sum / derssayisi;
}
// her öğrencinin dersler arrayi üzerinde işlem yapmak için derssayisina ihtiyacım var parametre olarak aldım.
void dosyayaOgrenciBilgileriYaz(const char *dosyaAdi, Ogrenci ogrenci, int derssayisi)
{
    // dosyayı moduyla açtım ve açılıp açılmadığjını kontrol etitm
    FILE *dosyaOgrenciler = fopen(dosyaAdi, "w");

    if (dosyaOgrenciler == NULL)
    {
        printf("dosyaOgrenciler acma hatasi");
    }
    // dosyaya bilgileri okuması kolay olması için
    //& tokeniyle ayırt edilebilecek şekilde yazdırdım
    fprintf(dosyaOgrenciler, "%s&", ogrenci.ogrAdi);
    fprintf(dosyaOgrenciler, "%s&", ogrenci.ogrSoyadi);
    fprintf(dosyaOgrenciler, "%s&", ogrenci.bolumu);
    fprintf(dosyaOgrenciler, "%f&", ogrenci.ortalama);
    int i = 0;

    for (i = 0; i < derssayisi; i++)
    {
        fprintf(dosyaOgrenciler, "%s&%hu&%hu&", ogrenci.aldigiDersler[i].dersAdi, ogrenci.aldigiDersler[i].kredi, ogrenci.aldigiDersler[i].puan);
    }
    fprintf(dosyaOgrenciler, "\n");
    // dosyayı kapadım
    fclose(dosyaOgrenciler);
}
// verilen öğrencinin bilgilerini yazar
void ogrenciBilgileriniYazdir(Ogrenci std)
{
    printf("Ogrencinin Adi: %s \n", std.ogrAdi);
    printf("Ogrencinin Soyadi: %s \n", std.ogrSoyadi);
    printf("Ogrencinin Bolumu: %s \n", std.bolumu);
    printf("Ogrencinin Ortalamasi: %f \n", std.ortalama);
    printf("Ogrencinin Aldigi Dersler: \n");

    int i = 0;
    while (std.aldigiDersler[i].dersAdi != NULL)
    { // kredi ve puan değişkenleri unsigned short int olduğundan %hu ile yazdırdım
        printf("%s, %hu kredili, %hu puan\n", std.aldigiDersler[i].dersAdi, std.aldigiDersler[i].kredi, std.aldigiDersler[i].puan);
        i++;
    }
}
// verilen parametreler ile ders dondurur
Ders degerlerIleDersDondur(char *dersAdi, unsigned short int kredi1, unsigned short int puani)
{
    Ders ders;
    ders.dersAdi = (char *)malloc(sizeof(char) * 256);
    // char arraylerinde içeriklerini atamak için strcpy kullandım
    strcpy(ders.dersAdi, dersAdi);
    ders.kredi = kredi1;
    ders.puan = puani;
    return ders;
} // verilen değerler ile öğrenci döndürür.
// her oluşan öğrenci aynı zamanda dosyaya yazılır bu sebeple dosyaAdi değişkenine de ihtiyacım var
Ogrenci degerlerIleOgrenciDondur(const char *dosyaAdi, char *ogrAdi, char *ogrSoyadi, char *bolumu, float ortalama1, Ders *parametreDersler, int dersSayisi)
{
    Ogrenci ogrenci;
    ogrenci.ogrAdi = (char *)malloc(sizeof(char) * 256);
    strcpy(ogrenci.ogrAdi, ogrAdi);

    ogrenci.ogrSoyadi = (char *)malloc(sizeof(char) * 256);
    strcpy(ogrenci.ogrSoyadi, ogrSoyadi);

    ogrenci.bolumu = (char *)malloc(sizeof(char) * 256);
    strcpy(ogrenci.bolumu, bolumu);

    ogrenci.ortalama = ortalama1;

    ogrenci.aldigiDersler = (Ders *)malloc(sizeof(Ders) * dersSayisi);
    for (int i = 0; i < dersSayisi; i++)
    {

        ogrenci.aldigiDersler[i] = parametreDersler[i];
    }
    dosyayaOgrenciBilgileriYaz(dosyaAdi, ogrenci, dersSayisi);
    return ogrenci;
}