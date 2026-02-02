#include <stdio.h>
#include <string.h>

#define MAX_PRODUKTU 100
#define NAZEV_DELKA 50

typedef struct {
    char nazev[NAZEV_DELKA];
    float cena;
    int kusy;
} Produkt;

Produkt sklad[MAX_PRODUKTU];
int pocetProduktu = 0;


void vypisProduktu() {
    if (pocetProduktu == 0) {
        printf("Sklad je prazdny.\n");
        return;
    }

    printf("\nINDEX | NAZEV | CENA | KUSY\n");
    for (int i = 0; i < pocetProduktu; i++) {
        printf("%d | %s | %.2f | %d\n",
               i, sklad[i].nazev, sklad[i].cena, sklad[i].kusy);
    }
}

void pridatProdukt() {
    if (pocetProduktu >= MAX_PRODUKTU) {
        printf("Sklad je plny!\n");
        return;
    }

    printf("Zadej nazev produktu: ");
    scanf(" %49[^\n]", sklad[pocetProduktu].nazev);

    printf("Zadej cenu: ");
    scanf("%f", &sklad[pocetProduktu].cena);

    printf("Zadej pocet kusu: ");
    scanf("%d", &sklad[pocetProduktu].kusy);

    pocetProduktu++;
    printf("Produkt byl pridan.\n");
}

void hledatPodleNazvu() {
    char hledanyNazev[NAZEV_DELKA];
    printf("Zadej cely nazev produktu: ");
    scanf(" %49[^\n]", hledanyNazev);

    for (int i = 0; i < pocetProduktu; i++) {
        if (strcmp(sklad[i].nazev, hledanyNazev) == 0) {
            printf("Nalezen: [%d] %s | %.2f | %d\n",
                   i, sklad[i].nazev, sklad[i].cena, sklad[i].kusy);
            return;
        }
    }

    printf("Produkt nebyl nalezen.\n");
}

void hledatPodleCeny() {
    float od, doo;
    printf("Zadej cenu od: ");
    scanf("%f", &od);
    printf("Zadej cenu do: ");
    scanf("%f", &doo);

    for (int i = 0; i < pocetProduktu; i++) {
        if (sklad[i].cena >= od && sklad[i].cena <= doo) {
            printf("[%d] %s | %.2f | %d\n",
                   i, sklad[i].nazev, sklad[i].cena, sklad[i].kusy);
        }
    }
}

void detailProduktu() {
    int index;
    printf("Zadej index produktu: ");
    scanf("%d", &index);

    if (index < 0 || index >= pocetProduktu) {
        printf("Neplatny index.\n");
        return;
    }

    printf("\nDETAIL PRODUKTU:\n");
    printf("Nazev: %s\n", sklad[index].nazev);
    printf("Cena: %.2f\n", sklad[index].cena);
    printf("Kusy: %d\n", sklad[index].kusy);
}

void odstranitProdukt() {
    int index;
    printf("Zadej index produktu k odstraneni: ");
    scanf("%d", &index);

    if (index < 0 || index >= pocetProduktu) {
        printf("Neplatny index.\n");
        return;
    }

    for (int i = index; i < pocetProduktu - 1; i++) {
        sklad[i] = sklad[i + 1];
    }

    pocetProduktu--;
    printf("Produkt odstranen.\n");
}

void upravitProdukt() {
    int index;
    printf("Zadej index produktu k uprave: ");
    scanf("%d", &index);

    if (index < 0 || index >= pocetProduktu) {
        printf("Neplatny index.\n");
        return;
    }

    printf("Novy nazev: ");
    scanf(" %49[^\n]", sklad[index].nazev);

    printf("Nova cena: ");
    scanf("%f", &sklad[index].cena);

    printf("Novy pocet kusu: ");
    scanf("%d", &sklad[index].kusy);

    printf("Produkt upraven.\n");
}

// ================= MAIN =================

int main() {
    char volba;

    do {
        printf("\n===== MENU =====\n");
        printf("A - Pridat produkt\n");
        printf("V - Vypsat produkty\n");
        printf("N - Hledat podle nazvu\n");
        printf("C - Hledat podle ceny\n");
        printf("D - Detail produktu\n");
        printf("O - Odstranit produkt\n");
        printf("U - Upravit produkt\n");
        printf("X - Konec\n");
        printf("Volba: ");
        scanf(" %c", &volba);

        switch (volba) {
            case 'A': pridatProdukt(); break;
            case 'V': vypisProduktu(); break;
            case 'N': hledatPodleNazvu(); break;
            case 'C': hledatPodleCeny(); break;
            case 'D': detailProduktu(); break;
            case 'O': odstranitProdukt(); break;
            case 'U': upravitProdukt(); break;
            case 'X': printf("Ukoncuji program.\n"); break;
            default: printf("Neplatna volba.\n");
        }
    } while (volba != 'X');
    return 0;
};