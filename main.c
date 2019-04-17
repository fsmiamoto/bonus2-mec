#include <stdio.h>
#include <stdlib.h>

/** Constantes utilizadas */

const double RAIO_DE_MARTE = 3389.5E3; // Em m
const double MASSA_DE_MARTE = 6.4174E23; // Em kg

const double RAIO_DE_VENUS = 6051.8E3;
const double MASSA_DE_VENUS = 4.867E24;

const double RAIO_DE_JUPITER = 69911E3;
const double MASSA_DE_JUPITER= 1.898E27;

const double RAIO_DE_MERCURIO = 2439.7E3;
const double MASSA_DE_MERCURIO= 3.285E23;

/** Protótipos das funções utilizadas */
int apresentaMenu();


int main(){
    apresentaMenu();
    return 0;
}

int apresentaMenu(){
    int escolha;

    printf("Selecione o planeta desejado: \n");
    printf("1) Mercurio\n2) Venus\n3) Terra\n4) Marte\n5) Jupiter\n");

    scanf("%d",&escolha);
    return escolha;
}