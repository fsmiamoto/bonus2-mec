#include <stdio.h>
#include <stdlib.h>

/** Constantes utilizadas */

const double RAIO_DE_MERCURIO = 2439.7E3;// Em m
const double MASSA_DE_MERCURIO = 3.285E23; // Em kg

const double RAIO_DE_VENUS = 6051.8E3;
const double MASSA_DE_VENUS = 4.867E24;

const double RAIO_DE_TERRA = 6371E3;
const double MASSA_DE_TERRA = 5.972E24;

const double RAIO_DE_MARTE = 3389.5E3; 
const double MASSA_DE_MARTE = 6.4174E23; 

const double RAIO_DE_JUPITER = 69911E3;
const double MASSA_DE_JUPITER= 1.898E27;

enum PLANETAS {
    MERCURIO = 1,
    VENUS = 2,
    TERRA = 3,
    MARTE = 4,
    JUPITER = 5,
};

/** Protótipos das funções utilizadas */
int apresentaMenu();

/** Variáveis utilizadas */
double raio, massa;

int main(){
    apresentaMenu();
    return 0;
}

int apresentaMenu(){
    int escolha;

    printf("Selecione o planeta desejado: \n");
    printf("1) Mercurio\n2) Venus\n3) Terra\n4) Marte\n5) Jupiter\n");

    scanf("%d",&escolha);

    switch(escolha){
        case MERCURIO:
            raio = RAIO_DE_MERCURIO;
            massa = MASSA_DE_MERCURIO;
            break;
        case VENUS:
            raio = RAIO_DE_VENUS;
            massa = MASSA_DE_VENUS;
            break;
        case TERRA:
            raio = RAIO_DE_TERRA;
            massa = MASSA_DE_TERRA;
            break;
        case MARTE:
            raio = RAIO_DE_MARTE;
            massa = MASSA_DE_MARTE;
            break;
        case JUPITER:
            raio = RAIO_DE_JUPITER;
            massa = MASSA_DE_JUPITER;
            break;
    }
    return escolha;
}