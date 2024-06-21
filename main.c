/*
@file Proje1
@description Bu projede, C programlama dilinde yapılar(struct),işaretçiler(pointers)
ve dinamik bellek lullanarak problem çözme becerimizi geliştirmek amaçlanmıştır.
@assignment Proje1
@date 27.11.2023
@author Şevval Bilğin sevval.bilgin@stu.fsm.edu.tr

*/

#include <stdio.h>
#include "Proje1.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    //karışıklık olmaması için tüm isterleri sırayla yazdım
    // test sırasında yine sırayla gerekli olanları açacağım.

    //  İster 1
    /*
    Ders ders1 = degerlerIleDersDondur("bp3", 6, 30);
    printf("Ders Adi: %s\n", ders1.dersAdi);
    printf("Ders kredisi: %hu\n", ders1.kredi);
    printf("Ders Puani : %hu\n", ders1.puan);
    free(ders1.dersAdi);
   */
    // ister 2
    /*
        int dersSayisi = 3;
        Ders ders1 = degerlerIleDersDondur("calculus", 6, 30);
        Ders ders2 = degerlerIleDersDondur("discrete", 3, 80);
          Ders ders3 = degerlerIleDersDondur("bp3", 6, 80);
        Ders *dersler = (Ders *)malloc(sizeof(Ders) * dersSayisi);
        dersler[0] = ders1;
        dersler[1] = ders2;
        dersler[2] = ders3;
        Ogrenci o1 = degerlerIleOgrenciDondur(argv[1],"ali", "bilgin", "bilgisayar", 70, dersler,dersSayisi);
        ogrenciBilgileriniYazdir(o1);
        free(o1.ogrAdi);
        free(o1.ogrSoyadi);
        free(o1.bolumu);
        free(o1.aldigiDersler);
    */
    // İster 3 oldu
    /*
      int dersSayisi = 2;
      Ders ders1 = degerlerIleDersDondur("Matematik", 3, 20);
      Ders ders2 = degerlerIleDersDondur("Turkce", 5, 40);
      Ders *dersler = (Ders *)malloc(sizeof(Ders) * dersSayisi);
      dersler[0] = ders1;
      dersler[1] = ders2;
      Ogrenci o1 = degerlerIleOgrenciDondur(argv[1],"sevval", "bilgin", "yazilim", 80, dersler, dersSayisi);
      ogrenciBilgileriniYazdir(o1);
      free(dersler);
  */
    // İster 4 oldu
    /*
    int ogrenciSayisi = 3;
    int ilkOgrenciDersSayisi = 2;
    int ikinciOgrenciDersSayisi = 3;
    Ders ders1 = degerlerIleDersDondur("Matematik", 3, 20);
    Ders ders2 = degerlerIleDersDondur("Turkce", 5, 40);
    Ders ders3 = degerlerIleDersDondur("Sosyal", 4, 60);
    Ders *dersler1 = (Ders *)malloc(sizeof(Ders) * ilkOgrenciDersSayisi);
    Ders *dersler2 = (Ders *)malloc(sizeof(Ders) * ikinciOgrenciDersSayisi);

    dersler1[0] = ders1;
    dersler1[1] = ders2;
    dersler2[0] = ders1;
    dersler2[1] = ders2;
    dersler2[2] = ders3;
    int *dersSayilari = (int *)malloc(sizeof(int) * (ogrenciSayisi));
    dersSayilari[0] = ilkOgrenciDersSayisi;
    dersSayilari[1] = ikinciOgrenciDersSayisi;
    dersSayilari[2]=ikinciOgrenciDersSayisi;

    Ogrenci o1 = degerlerIleOgrenciDondur(argv[1],"sevval", "bilgin", "yazilim", 80.0, dersler1, ilkOgrenciDersSayisi);
    Ogrenci o2 = degerlerIleOgrenciDondur(argv[1],"hey", "mutlu", "bilgisayar", 50.0, dersler2, ikinciOgrenciDersSayisi);
    Ogrenci o3 = degerlerIleOgrenciDondur(argv[1],"hilal", "yildiz", "bilgisayar", 59.0, dersler2, ikinciOgrenciDersSayisi);
    Ogrenci *ogrenciler = (Ogrenci *)malloc(sizeof(Ogrenci) * ogrenciSayisi);

    ogrenciler[0] = o1;
    ogrenciler[1] = o2;
    ogrenciler[2]=o3;


    ogrenciDizisiBilgileriniYazdir(ogrenciler, ogrenciSayisi, dersSayilari);



    free(dersler1);
    free(dersler2);
    free(ogrenciler);
    */
    // ister 5 oldu
    /*
          Ders ders1 = degerlerIleDersDondur("Sosyal", 3, 20);
            Ders ders2 = degerlerIleDersDondur("Sosyal", 3, 50);
            Ders ders3 = degerlerIleDersDondur("Matematik", 4, 89);
            Ders ders4 = degerlerIleDersDondur("Sosyal", 3, 70);
            Ders ders5 = degerlerIleDersDondur("Turkce", 6, 23);
            int dersSayisi = 5;
            Ders *dersler = (Ders *)malloc(sizeof(Ders) * dersSayisi);
            dersler[0] = ders1;
            dersler[1] = ders2;
            dersler[2] = ders3;
            dersler[3] = ders4;
            dersler[4] = ders5;
            float ortalama = dersinAritmetikOrtlamasiniHesapla("Sosyal", dersSayisi, dersler);
            //46.666668 çıkmalı ekrana
            printf("%f", ortalama);
         */
    // ister 6 standart sapma hesaplama
    /*
      Ders ders1 = degerlerIleDersDondur("Sosyal", 3, 20);
      Ders ders2 = degerlerIleDersDondur("Sosyal", 3, 50);
      Ders ders3 = degerlerIleDersDondur("Matematik", 4, 89);
      Ders ders4 = degerlerIleDersDondur("Sosyal", 3, 70);
      Ders ders5 = degerlerIleDersDondur("Matematik", 6, 23);
      int dersSayisi = 5;
      Ders *dersler = (Ders *)malloc(sizeof(Ders) * dersSayisi);
      dersler[0] = ders1;
      dersler[1] = ders2;
      dersler[2] = ders3;
      dersler[3] = ders4;
      dersler[4] = ders5;
      //float standartSapma = dersinStandartSapmasiniHesapla("Sosyal", dersSayisi, dersler);//25.166115 yazmalı
      float standartSapma = dersinStandartSapmasiniHesapla("Matematik", dersSayisi, dersler);//46.669048 yazmalı

       printf("%f", standartSapma);
  */
    // ister 7 kovaryans hehsabı
    /*
      Ders ders1 = degerlerIleDersDondur("Sosyal", 3, 20);
      Ders ders2 = degerlerIleDersDondur("Sosyal", 3, 50);
      Ders ders3 = degerlerIleDersDondur("Matematik", 4, 89);
      Ders ders4 = degerlerIleDersDondur("Sosyal", 3, 70);
      Ders ders5 = degerlerIleDersDondur("Matematik", 6, 23);
      Ders ders6 = degerlerIleDersDondur("Matematik", 6, 60);
      int dersSayisi = 6;
      Ders *dersler = (Ders *)malloc(sizeof(Ders) * dersSayisi);
      dersler[0] = ders1;
      dersler[1] = ders2;
      dersler[2] = ders3;
      dersler[3] = ders4;
      dersler[4] = ders5;
      dersler[5] = ders6;
      int kovaryans = derslerinKovaryansiniHesapla(ders1, ders3, dersSayisi, dersler);
      //-448 çıkmalı
      printf("%d", kovaryans);
  */
    // ister 8
    /*
            Ders ders1 = degerlerIleDersDondur("Sosyal", 3, 20);
            Ders ders2 = degerlerIleDersDondur("Sosyal", 3, 50);
            Ders ders3 = degerlerIleDersDondur("Matematik", 4, 89);
            Ders ders4 = degerlerIleDersDondur("Turkce", 3, 70);
            Ders ders5 = degerlerIleDersDondur("Turkce", 6, 23);
            int dersSayisi=5;
            Ders *dersler=(Ders*)malloc(sizeof(Ders)*dersSayisi);
            dersler[0]=ders1;
            dersler[1]=ders2;
            dersler[2]=ders3;
            dersler[3]=ders4;
            dersler[4]=ders5;

Ogrenci *o=ortalamadanYuksekAlanOgrencileriDondur("ogrenciler.txt","Turkce",dersSayisi,dersler);
printf("%s",o[0].ogrAdi);*/
    // ister 9
    /*
    Ders ders1 = degerlerIleDersDondur(argv[1],"Matematik", 3, 20);
    Ders ders2 = degerlerIleDersDondur(argv[1],"Turkce", 5, 40);
    Ders ders3 = degerlerIleDersDondur(argv[1],"Sosyal", 4, 60);
    Ders *dersler1 = (Ders *)malloc(sizeof(Ders) * 3);
    dersler1[0] = ders1;
    dersler1[1] = ders2;
    dersler1[2] = ders3;
    Ogrenci o1 = degerlerIleOgrenciDondur("Hayri", "Atli", "Edebiyat", 67.2, dersler1, 3);
    dosyayaOgrenciBilgileriYaz(o1,3);
    */
    // ister 10

    // printf("%s\n%s",argv[0],argv[1]);
    //Ogrenci *ogrenciler = ogrencileriDosyadanOkuveEkranaYaz(argv[1]);
    //printf(ogrenciler[0].ogrAdi);
    return 0;
}
