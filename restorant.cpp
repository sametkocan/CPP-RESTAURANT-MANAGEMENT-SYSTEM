#include<iostream>
#include<vector>
#include<string>
#include<cctype>//toupper fonksiyonu icin gerekli kutuphane.
using namespace std;

class URUN
{
	int id;
	
public:
	string ad;
	float fiyat;
	float stok;
	URUN(int no,string nm,float fyt,float stk):id(no),ad(nm),fiyat(fyt),stok(stk){}
};

class MASA
{
public:
	bool doluMu;
	int numara;
	int kisi;
	double Hesap;
	vector<URUN> siparisler;
	MASA(bool dlmu=0,int num=0,int msfr=0,double hsp=0):doluMu(dlmu),numara(num),kisi(msfr),Hesap(hsp){}
};

void MenuGoster (const vector<URUN>& urunler) 
{
	cout << "~~~~~~ RESTORAN MENUSU ~~~~~~\n";
	for (int i = 0; i < urunler.size(); i++)
	{
		cout << urunler[i].ad << " : " << urunler[i].fiyat << " TL" << endl;
	}
}

void siparisAL(MASA& masa,vector<URUN>& menu)
{
	while (true)
	{
		bool bulunduMu = 0;
		char secim;
		string yemekadi;
		float adet;
		cout << "Ne Alirdiniz?\n";
		getline(cin, yemekadi);

		size_t ilkHarf = yemekadi.find_first_not_of(" \t\r\n"); //bastaki bosluklari gecerek ilk harfin adresini dondurur.
		if (ilkHarf != string::npos)
		{
			yemekadi.erase(0, ilkHarf); //0 dan ilk harfe kadar bosluklarý keser
			yemekadi.erase(yemekadi.find_last_not_of(" \t\r\n") + 1); //sondan harfe denk gelene kadar bosluklarý siler.
		}

		for (int i = 0; i < yemekadi.length(); i++)
		{
			yemekadi[i] = toupper(yemekadi[i]);//yemek adi tamamen buyuk harfe cevrilir hatayý onlemek icin alýnan ufak bir onlem.
		}

		cout << "Kac Tane Alirdiniz?\n";
		cin >> adet;
		cin.ignore();

		for (int i = 0; i < menu.size(); i++)
		{
			if (yemekadi == menu.at(i).ad)
			{
				masa.doluMu = true;
				menu.at(i).stok -= adet;
				masa.Hesap += menu.at(i).fiyat * adet;
				bulunduMu = 1;
				break;
			}
		}
		if (!bulunduMu)
		{
			cout << "Boyle Bir Urunumuz Bulunmamaktadir\n";
		}

		cout << "Baska Bir Isteginiz Var Mi?(E-H)\n";
		cin >> secim;
		cin.ignore();
		if (secim != 'E' && secim != 'e')
		{
			break;
		}
	}
}

template<typename T>//sadece int degil float veya baska sayýsal veri tipleri icin ayný fonku bidaha yazmamak icin template kullandýk.
T sayiAl(string msg) //kullanici sayý yerine harf girerse diye hazýrlandý kontrol kodudur.
{
	T girdi;
	while (true)
	{
		cout << msg;
		cin >> girdi;

		if (cin.fail())
		{
			cin.clear();//hata bayragi kaldýrmak icin!
			cin.ignore(10000, '\n');
			cout << "Hata! Lutfen Sadece Sayi Giriniz\n\n";
		}
		else
		{
			cin.ignore();
			return girdi;
		}
	}
}

int main()
{
	int kisi,secim,id;
	string ad;
	float fiyat,adet;

	vector<URUN> urunler;
	// 1. ÇORBALAR (ID: 100-199 arasý olsun)
	urunler.push_back(URUN(101, "EZOGELIN CORBASI", 150.0, 50));
	urunler.push_back(URUN(102, "MERCIMEK CORBASI", 120.0, 50));
	urunler.push_back(URUN(103, "KELLEPACA CORBASI", 220.0, 30));
	urunler.push_back(URUN(104, "ISKEMBE CORBASI", 200.0, 30));
	// 2. ANA YEMEKLER (ID: 200-299)
	urunler.push_back(URUN(201, "KEBAP", 350.0, 40));
	urunler.push_back(URUN(202, "LAHMACUN", 120.0, 100));
	urunler.push_back(URUN(203, "KARNIYARIK", 250.0, 25));
	urunler.push_back(URUN(204, "PIRINC PILAVI", 120.0, 60));
	urunler.push_back(URUN(205, "MANTI", 240.0, 35));
	urunler.push_back(URUN(206, "BIBER DOLMASI", 50.0, 40));
	// 3. ÝÇECEKLER (ID: 300-399)
	urunler.push_back(URUN(301, "TENEKE KOLA", 70.0, 80));
	urunler.push_back(URUN(302, "TENEKE FANTA", 70.0, 80));
	urunler.push_back(URUN(303, "TENEKE MEYVESUYU", 60.0, 60));
	urunler.push_back(URUN(304, "TENEKE SOGUKCAY", 60.0, 60));
	urunler.push_back(URUN(305, "BUYUK AYRAN", 45.0, 100));
	urunler.push_back(URUN(306, "KUCUK AYRAN", 25.0, 100));
	// 4. TATLILAR (ID: 400-499)
	urunler.push_back(URUN(401, "BAKLAVA", 150.0, 30));
	urunler.push_back(URUN(402, "KUNEFE", 180.0, 20));
	urunler.push_back(URUN(403, "KADAYIF", 130.0, 25));
	urunler.push_back(URUN(404, "SUTLAC", 150.0, 25));

	MenuGoster(urunler);

	vector<MASA> masalar;
	for (int i = 1; i <= 20; i++) 
	{
		masalar.push_back(MASA(false, i, 0, 0)); 
	}
	
	while (true)
	{
		secim = sayiAl<int>("\n1. SIPARIS AL\t2.MASALARI GOR\t3.HESAP KES\t4.URUN EKLE\t5.Dukkani Kapat\n");
		switch (secim)
		{
				
		case 1:
		{
			int masaNum;
			masaNum = sayiAl<int>("Hangi Masaya Oturacaksiniz(1-20): ");
			while (masalar.at(masaNum - 1).doluMu)
			{
				cout << masaNum << " Numarali Masamiz Doludur.\n";
				masaNum = sayiAl<int>("Baska Bir Masa Soyleyebilir Misiniz ? \n");
			}
			siparisAL(masalar.at(masaNum - 1), urunler);
			break;
		}
		case 2:
		{
			for (int i = 0; i < masalar.size(); i++)
			{
				cout << "MASA " << i+1;
				if (masalar.at(i).doluMu)
					cout << " Dolu";
				else
					cout << " Bos";

				cout << "\tHesap" << masalar.at(i).Hesap << "TL\n";
			}
			break;
		}
		case 3:
		{
			int arananSayi;
			arananSayi = sayiAl<int>("Kac Numarali Masanin Hesabi Sorgulaniyor?(1-20)");
			cout << "Hesap: " << masalar.at(arananSayi-1).Hesap << "TL\n";
			masalar.at(arananSayi-1).doluMu = false;
			masalar.at(arananSayi - 1).Hesap = 0;
			masalar.at(arananSayi - 1).siparisler.clear();
			break;
		}
		case 4:
		{
			while (true)
			{
				char secim2;
				id = sayiAl<int>("Eklenecek Urunun ID numarasini Giriniz\n");
				cout << "Eklenecek Urunun Adini Giriniz\n";
				getline(cin, ad);
				fiyat=sayiAl<float>("Eklenecek Urunun Fiyatini Giriniz\n");
				adet = sayiAl<float>("Eklenecek Urunun Stok Adedini Giriniz\n");
				urunler.push_back(URUN(id, ad, fiyat, adet));
				cout << "Urun Basari Ile Eklendi...\nBaska Bir Urun Eklenecek Mi(E-H)";
				cin >> secim2;
				cin.ignore();
				if (secim2 != 'E' && secim2 != 'e')
					break;
			}
			break;
		}
		case 5:
		{
			cout << "Dukkan Kapatiliyor,Iyi Gunler...\n";
			return 0;
		}
		default:
		{
			cout << "Gecersiz Islem Girisi Tekrar Deneyin\n";
			break;
		}

		}
	}
	return 0;
}