#include <stdio.h>
#include <stdlib.h>
void fgetAnswers(){ 
    FILE *b;
	FILE *hata;
	int Numara,soru_numarasi,i,kacirilan_soru[45]; 
	char cevap_anaht[45],cevap[45];
	b=fopen("examdat.txt","r"); // dosyan�n okunmas� (read=dosyay� okuma)
	hata=fopen("report.txt","w"); // dosyaya yazma (writing=dosya yazma i�lemi)
	if(b==NULL){ //Hen�z de�eri atanmam�� olan ya da hi�bir de�ere sahip olmayan �eyleri ifade etmek i�in kulland�k.
		printf("Dosya okunmadi");
	}
	else{
	    fscanf(b,"%d %s",&soru_numarasi,&cevap_anaht); //%d=integer(tam sayi) %s=string(karakter) demektir.
			// dosyanin ilk k�sm�n�n bast�r�lmas�
		fprintf(hata,"Exam Report\n");
		fprintf(hata,"puan");
		for(i=0;i<soru_numarasi;i++){
			fprintf(hata,"%d",i+1); // soru numaralar�n� yazan d�ng�.
		}
		fprintf(hata,"\ncevap");
		for(i=0;i<soru_numarasi;i++){ //// for d�ng�s� =i de�erini 0 ata i soru numarasi k���k olana kadar i yi birer birer artt�r.
			fprintf(hata,"%c",cevap_anaht[i]); // cevap anahtar�n� yazan d�ng�.
		}
		fprintf(hata,"\n\n  total_puan(%c)\n"); 
		while(fscanf(b,"%d %s",&Numara,cevap)!=EOF) // verilerin okunmas� EOF kullanmam�z�n sebebi dosyan�n bitti�i haberini vermesidir.
		{
			double total_puan=0; //double �eklinde total_puan� atama i�lemi yapt�k..
			for(i=0;i<soru_numarasi;i++){
		        if(cevap_anaht[i]==cevap[i])
					total_puan++; 
				else
					kacirilan_soru[i]+=1; // ka� ki�inin soruyu ka��rd��� i�lemi.
			}
			int not=(double)100/soru_numarasi * total_puan; // Y�zdesel total puan� verir.
			fprintf(hata,"%d\n",Numara,not); // dosyaya ��rencinin notunu yazd�rma i�ine yarar.
		}
		fprintf(hata,"\n");
		fprintf(hata,"soru");
		for(i=0;i<soru_numarasi;i++){
	        fprintf(hata,"%d",i+1); // soru numaras� 
		}
		fprintf(hata,"\n");
		fprintf(hata,"kacirilan_soru");
		for(i=0;i<soru_numarasi;i++){
		    fprintf(hata,"%d",kacirilan_soru[i]); // ka��r�lan_soru say�s�n� vermektedir.
		}
		printf("Report.txt adli dosya olusturuldu...");
	}
	fclose(b); //fclose=dosyay� kapama i�lemi i�in kullan�l�r. FIlE*b yi kapatt�k.
	fclose(hata); // FILE*hata 
	}
int main(){
	int n;
	printf("Lutfen Baslamak icin bir rakam giriniz:");
	scanf("%d",&n);	
	fgetAnswers(); //Fonksiyon i�lemini kapad�k.
	return 0;
	}
