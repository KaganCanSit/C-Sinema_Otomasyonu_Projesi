#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

	struct Musteri
	{
		char Salon[50], Film[50];
		int Ucret, Seans, Koltuk;
	}musteri[751];	//3 salon 50 sandalye 5 seans = 3*5*50
	
	
	//Fonksiyonlar
	void LoginHazirlik();
	void Login();
	int AnaMenu();
	void MusteriEkle();
		void SalonSecimi();
		void SeansSec();
		void KoltukSec();
		void Ucret();
		void BiletBilgileri();
	int HasilatDurum();
	void DolulukDurum();
	
	int AnaMenuDon();
	void EkraniTemizle();
	void CikisYap();

	//Global Deðiþkenler
	int KisiTakip=1, Hasilat=0, seanskisi[15];
	
	
int main(void) {

	LoginHazirlik();
	Login();
	
	yeniden:
	switch(AnaMenu())
	{
		case 1:
			MusteriEkle();
			BiletBilgileri();
			KisiTakip += 1;
			switch(AnaMenuDon())
			{
				case 1:
					goto yeniden;
					break;
				case 2:
					exit(1);
					break;
				default:
					CikisYap();
			}
			break;
		case 2:
			printf("Toplam Kazanc Tutari: %d",HasilatDurum());
			switch(AnaMenuDon())
			{
				case 1:
					goto yeniden;
					break;
				case 2:
					exit(1);
					break;
				default:
					CikisYap();
			}
			break;
		case 3:
			DolulukDurum();
			switch(AnaMenuDon())
			{
				case 1:
					goto yeniden;
					break;
				case 2:
					exit(1);
					break;
				default:
					CikisYap();
			}
			break;
		default:
			printf("Hatali Durum. Cikis Yapiliyor.");
			CikisYap();
	}
	
	return 0;
}

//Login.txt oluþturulmasý ve bilgilerin þifreleri halleri yazildi.
void LoginHazirlik()
{
	printf("*********************Kullanici Giris Ekrani**********************\n\n");
	FILE *pLogin;
	pLogin=fopen("login.txt", "w+");
	
	fprintf(pLogin,"%s %s", "tjpjn","k~{t~}");	
	fclose(pLogin);
}
//Þifreli haldeki bilgiler dosyadan okundu. Karþýlaþtýrma yapýldý.
void Login()
{
	FILE *pLogin1;
	pLogin1=fopen("login.txt", "r");
	
	char kullaniciadi[4];
	char sifre[5];	
	printf("Kullanici Adi: ");
	scanf("%s",&kullaniciadi);	//kagan
	printf("Sifre: ");
	scanf("%s",&sifre);			//burkut
	
	int i=0;
	for(i=0;i<4;i++)
		kullaniciadi[i]+=9;
	for(i=0;i<6;i++)
		sifre[i]+=9;
	
	char kullaniciadi1[4];
	char sifre1[5];
	fscanf(pLogin1,"%s %s",&kullaniciadi1,&sifre1);

	if(strcmp(kullaniciadi,kullaniciadi1)==0 && strcmp(sifre,sifre1)==0)
	{
		printf("Kullanici Bilgileriniz Dogrulandi. Giris Yapiyorsunuz.");
		EkraniTemizle();
	}
	else
	{
		printf("Yanlis Kullanici Adi Veya Sifre Girdiniz!");
		CikisYap();
	}
		
	fclose(pLogin1);	
}

int AnaMenu()
{
	int islemsecimi;
	
	printf("************* - GUNYUZU SINEMASI YONETIM SISTEMI - *************\n\n");
	printf("ISLEMLER->\n");
	printf("1 -> SATIS YAP\n");
	printf("2 -> TOPLAM HASILAT DURUMUNU GORUNTULE\n");
	printf("3 -> SEANS - KISI DURUMUNU GORUNTULE\n");
	printf("\nIslem No: ");
	scanf("%d",&islemsecimi);
	if(islemsecimi<0 || islemsecimi>3)
	{
		CikisYap();
	}	
	
	printf("Secilen Isleme Geciliyor.\n");
	EkraniTemizle();
	
	return islemsecimi;
}

void MusteriEkle()
{
	SalonSecimi();
	SeansSec();
	KoltukSec();
	Ucret();
}

void SalonSecimi()
{
	int secim;
	printf("SALON SECINIZ\n");
	printf("\n!ONEMLI UYARI: Salon seciminiz film secimizi belirleyecektir.\nSalon secimiz ile birlikte film seciminiz otomatik atanacaktir.\n\n");
	
	printf("1 -> Salon: RED - Film: Tomorrow\n");
	printf("2 -> Salon: GREEN - Film: Heros\n");
	printf("3 -> Salon: BLUE - Film: Loves\n");
	printf("Seciminizin Numarasini Giriniz: ");
	scanf("%d",&secim);
	
	switch(secim)
	{
		case 1:
			printf("Secim Kaydedildi -> \n");
			strcpy(musteri[KisiTakip].Salon, "RED");
			strcpy(musteri[KisiTakip].Film,"Tomorrow");
			break;
		case 2:
			printf("Secim Kaydedildi -> \n");
			strcpy(musteri[KisiTakip].Salon, "GREEN");
			strcpy(musteri[KisiTakip].Film,"Heros");
			break;
		case 3:
			printf("Secim Kaydedildi -> \n");
			strcpy(musteri[KisiTakip].Salon, "BLUE");
			strcpy(musteri[KisiTakip].Film,"Loves");
			break;
		default:
			CikisYap();
	}
	printf("Yapmis Oldugunuz Secim -> Salon: %s Film: %s",musteri[KisiTakip].Salon, musteri[KisiTakip].Film);
	sleep(2);
	printf("\nSalon Secimi Tamamlandi. Bir Sonraki Isleme Geciliyor.\n");	
	EkraniTemizle();
}

void SeansSec()
{  	
	int i=0, j=10;
	
	for(i=1;i<16;i++)
	{
		if(i==1)
			printf("RED SALONUN SEANSLARI\n");
		else if(i==6)
			printf("GREEN SALONUN SEANSLARI\n");
		else if(i==11)
			printf("BLUE SALONUN SEANSLARI\n");

		if(i%6==0)
		{
			j=10;
		}
		printf("%d -> %d:00\n",i,j);
		j+=2;
	}
	
	printf("!Onceden Secmis Oldugunuz Salon(%s)'a Gore Seans Seciniz.\n",musteri[KisiTakip].Salon);	
    
    printf("Katilmak Istediginiz Seansin Numarasini Giriniz: ");
	scanf("%d",&musteri[KisiTakip].Seans);
	seanskisi[(musteri[KisiTakip].Seans)]+=1;
	
	if(strcmp(musteri[KisiTakip].Film,"Tomorrow")==0 && (musteri[KisiTakip].Seans)>0 && (musteri[KisiTakip].Seans)<6)
		printf("\nSeans ve Film Dogrulandi");
	else if(strcmp(musteri[KisiTakip].Film,"Heros")==0 && (musteri[KisiTakip].Seans)>5 && (musteri[KisiTakip].Seans)<11)
		printf("\nSeans ve Film Dogrulandi.");
	else if(strcmp(musteri[KisiTakip].Film,"Loves")==0 && (musteri[KisiTakip].Seans)>10 && (musteri[KisiTakip].Seans)<16)
		printf("\nSeans ve Film Dogrulandi.");
	else
		CikisYap();
		
	printf("\nSeans Seciminiz ->\n");
	printf("Seans: %d\n", musteri[KisiTakip].Seans);
	EkraniTemizle();
}

void KoltukSec()
{
	int *koltukptr;
	koltukptr=&musteri[KisiTakip].Koltuk;
	
	yeniden:  
	
	printf("KOLTUK SECIMI ->\n");
	printf("!UYARI: Koltuk numaralari 0-50 degerleri aralariginda olmalidir.\n\n");
	printf("Koltuk Numarasi Seciminizi Belirtiniz:");
	scanf("%d",koltukptr);
	printf("Koltuk: %d\n", *koltukptr);
	
	int i=0, j=0;
	for(i=1;i<KisiTakip;i++)
	{
		if(strcmp(musteri[i].Salon,musteri[KisiTakip].Salon)==0 && musteri[i].Koltuk==*koltukptr)
		{
			printf("Secmek Istediginiz Koltuk Dolu. Yeniden Deneyiniz.");
			EkraniTemizle();
			goto yeniden;
		}
		else
		{
			printf("\nKoltuk Seciminiz ->\n");
    		printf("Koltuk: %d", *koltukptr);
    		break;
		}
	}
	EkraniTemizle();
}

void Ucret()
{
	int secim;
	printf("Bilet Tipini Seciniz->\n");
	printf("1 -> TAM BILET 30TL\n");
	printf("2 -> OGRENCI BILETI 20TL\n");
	scanf("%d",&secim);
	
	if(secim<1 || secim>2)
		CikisYap();
	else if(secim==1)
		musteri[KisiTakip].Ucret=30;
	else
		musteri[KisiTakip].Ucret=20;
	
	//Toplam Hasýlat Ýçin Her Bir Kiþi Ýçin Global Tanýmli Deðiþkenimizi Arttýrýyoruz.
	Hasilat+=musteri[KisiTakip].Ucret;
	EkraniTemizle();
}
void BiletBilgileri()
{
	printf("BILET BILGILERI ->\n\n");
	printf("Secilen Salon: %s - Secilen Film: %s\n",musteri[KisiTakip].Salon,musteri[KisiTakip].Film);
	printf("Secilen Seans: %d - Secilen Koltuk: %d\n",musteri[KisiTakip].Seans,musteri[KisiTakip].Koltuk);
	printf("Bilet Ucreti: %d\n\n",musteri[KisiTakip].Ucret);
}

int HasilatDurum()
{
	FILE *kazanc;
	kazanc=fopen("hasilat.txt","w+");
	if(kazanc==NULL)
	{
		printf("'hasilat.txt' dosyasini acamadik. Cikis yapiliyor.");
		CikisYap();
	}
	
	fprintf(kazanc,"%d",Hasilat);
	fclose(kazanc);
	return Hasilat;
}

void DolulukDurum()
{
	
	FILE *pYaz;
	pYaz=fopen("DolulukDurum.txt","w+");
	if(pYaz==NULL)
	{
		printf("Dosyaya Ulasilamadi. Cikis Yapiliyor.\n");
		exit(1);
	}
	
	//seanskisi[];
	
	int j=0;
	for(j=0;j<16;j++)
	{	
		switch (j)
		{
			case 1:
				printf("RED SALON\n");
				fprintf(pYaz,"%s","RED SALON");
				break;
			case 6:
				printf("GREEN SALON\n");
				fprintf(pYaz,"%s","GREEN SALON");
				break;
			case 11:
				printf("BLUE SALON\n");
				fprintf(pYaz,"%s","BLUE SALON");
				break;
				
		}
		if(seanskisi[j]>0)
		{
			printf("%d.Seans -> %d Kisi Dolu\n",j,seanskisi[j]);
			fprintf(pYaz,"%d %s %d %s",j,".Seans -> ",seanskisi[j], "Kisi Dolu\n");	
		}
	}
	fclose(pYaz);
}

int AnaMenuDon()
{
	int secim;
	printf("\nAna Menuye Donmek Icin 1, Cikmak Icin 2 Giriniz: ");
	scanf("%d",&secim);
	return secim;
}

void EkraniTemizle()
{
	sleep(2);
	system("CLS");
}
	
void CikisYap()
{
	printf("\nYanlis Sayi Degeri Girdiniz.Programdan Cikis Yapiliyor");
	sleep(2);
	exit(1);
}


