#include <stdio.h>
#include <stdlib.h>

int main() {
    int yas, cinsiyet, AktiviteSecim, Amac;
    float kilo, boy, bmh, GunlukKalori, HedefKalori;

    printf("DIYET VE KALORI HESAPLAMA\n");

    // Girdiler
   // printf("Cinsiyetinizi giriniz: (Erkek icin 1, Kadin icin 2) ");
    //scanf("%d", &cinsiyet);
    printf("Yasinizi giriniz: ");
    scanf("%d", &yas);
    printf("Kilonuzu giriniz (kg): ");
    scanf("%f", &kilo);
    printf("Boyunuzu giriniz (cm): ");
    scanf("%f", &boy);

    // Bazal Metabolizma hesaplama
    do {
        printf("Cinsiyet giriniz (Erkek icin 1, Kadin icin 2):");
        scanf("%d", &cinsiyet);

        if (cinsiyet != 1 && cinsiyet != 2) {
            printf("\n        Hata!!\n\nLutfen tekrar deneyin.\n");
        }

    } while (cinsiyet != 1 && cinsiyet != 2);

    if (cinsiyet == 1) 
        {bmh = 66.47 + (13.75 * kilo) + (5.003 * boy) - (6.755 * yas);}
    
    else if(cinsiyet == 2) 
        {bmh = 655.1 + (9.563 * kilo) + (1.850 * boy) - (4.676 * yas);}


    // Aktivite Duzeyini belirleme
    printf("\n\nAktivite Duzeyi:\n");
    printf("1-)Dusuk       (Masa basi is, ev hayati)\n");
    printf("2-)Az Aktif    (Haftada 1-2 gun spor)\n");
    printf("3-)Aktif       (Haftada 3-5 gun spor)\n");
    printf("4-)Cok Aktif   (Haftada 6-7 gun agir spor)\n");
    printf("5-)Extreme     (Profesyonel Sporcu/Agir is)\n\n\n");
    printf("Aktivite düzeyinizi seçin: ");
    scanf("%d", &AktiviteSecim);

    switch(AktiviteSecim) {
        case 1:  
            GunlukKalori = bmh * 1.2; 
            break;
        case 2:  
             GunlukKalori = bmh * 1.375; 
             break;
        case 3:  
             GunlukKalori = bmh * 1.55; 
             break;
        case 4:  
             GunlukKalori = bmh * 1.725; 
             break;
        case 5:
             GunlukKalori = bmh * 2;     
        default: 
             GunlukKalori = bmh * 1.2;
    }

    // Amac Belirleme
    printf("Diyet yampaktaki amaciniz nedir?\n");
    printf("1-)Kilo Vermek\n");
    printf("2-)Kilomu korumak\n");
    printf("3-)Kilo almak\n");
    scanf("%d", &Amac);

    if (Amac == 1)
    { HedefKalori = GunlukKalori * 0.8;}      
    
    else if (Amac == 3)
    { HedefKalori = GunlukKalori * 1.2; }
    
    else 
    { HedefKalori = GunlukKalori;}                          

    // Gram hesabı
     float protein, yag, karbonhidrat;
     
    protein = (HedefKalori * 0.3) / 4;
    yag = (HedefKalori * 0.2) / 9;
    karbonhidrat = (HedefKalori * 0.5) / 4;

    // Sonuc
    printf("SONUCLAR\n\n");
    printf("Bazal Metabolizmaniz: %.2f kcal\n", bmh);
    printf("Gunluk Yakilan Kalori: %.2f kcal\n", GunlukKalori);
    printf("Hedeflenilen Gunluk Kalori: %.2f kcal\n", HedefKalori);

    printf("Gunluk Makro Besin İhtiyaci\n");
    printf("Protein: %.2f gr\n", protein);
    printf("Yag: %.2f gr\n", yag);
    printf("Karbonhidrat: %.2f gr\n", karbonhidrat);

    return 0;
}