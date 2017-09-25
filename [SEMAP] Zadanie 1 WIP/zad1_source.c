#include <stdio.h>
#include <stdlib.h>

int main() {
	/* [scenar] - pre pocet scenarov, [cena] - jednotlive ceny vzdy pre najviac jeden scenar, [i] - pomocna */
	int cisloScenara, pocetCien, i;

	scanf("%d", &cisloScenara);

	while (cisloScenara > 0) {
		// Zistenie poctu cien s ktorymi budeme pracovat
		scanf("%d", &pocetCien);

		// Alokovanie dostatku miesta pre vsetky ceny
		int *ceny = (int*)calloc(pocetCien, sizeof(int));

		// Postupne ulozenie cien aktualneho scenara
		for (i = 0; i < pocetCien; i++)
			scanf("%d", &ceny[i]);
		//
		int kupnaCena, predajnaCena, zisk = 0, boolNakupene = 0, v = 1;

		for (i = 0; i < pocetCien; i++)
		{
			if (boolNakupene == 1 && i + 1 >= pocetCien)
			{
				predajnaCena = ceny[i];
				zisk += predajnaCena - kupnaCena;
				boolNakupene = 0;
				continue;
			}
			if (!boolNakupene)
			{
				if (i == 0)
				{
					kupnaCena = ceny[0];
					boolNakupene = 1;
					printf("Kupil som prvy :%d %d\n", i, ceny[i]);
					continue;
				}
				else if (ceny[i] < ceny[i + 1])//&& (i+1<n) 
				{
					boolNakupene = 1;
					kupnaCena = ceny[i];
					continue;
				}
			}
			else
			{
				if (ceny[i + 1] >= ceny[i])
					continue;
				else
				{
					predajnaCena = ceny[i];
					zisk += predajnaCena - kupnaCena;
					boolNakupene = 0;
					printf("Predal som\n");
				}
			}
			v++;
			//printf("Vykonal sa:%d nakup\n", v);
		}
		printf("Vykonalo sa:%d nakupov\n", v);
		printf("Zisk je: %d\n", zisk);
		cisloScenara--;
	}

	return 0;
}