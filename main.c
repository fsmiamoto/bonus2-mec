#include <stdio.h>
#include <stdlib.h>

/** Constantes utilizadas */

const double RAIO_DE_MERCURIO = 2439.7E3;// Em m
const double MASSA_DE_MERCURIO = 3.285E23; // Em kg
const double GRAVIDADE_DE_MERCURIO = 3.7; // Em m/s^2

const double RAIO_DE_VENUS = 6051.8E3;
const double MASSA_DE_VENUS = 4.867E24;
const double GRAVIDADE_DE_VENUS = 8.87; 

const double RAIO_DE_TERRA = 6371E3;
const double MASSA_DE_TERRA = 5.972E24;
const double GRAVIDADE_DE_TERRA = 9.807;

const double RAIO_DE_MARTE = 3389.5E3; 
const double MASSA_DE_MARTE = 6.4174E23; 
const double GRAVIDADE_DE_MARTE = 3.711;

const double RAIO_DE_JUPITER = 69911E3;
const double MASSA_DE_JUPITER= 1.898E27;
const double GRAVIDADE_DE_JUPITER = 24.79;

enum PLANETAS {
    MERCURIO = 1,
    VENUS = 2,
    TERRA = 3,
    MARTE = 4,
    JUPITER = 5,
};

/** Protótipos das funções utilizadas */

void apresentaMenu();
void calculaVelocidadeDeEscape();
void calculaVelocidadeDeEscape();
void calculaAltitudeMaxima();
void calculaVelocidadeNaAltiudeMaxima();
void calculaPeriodoDaNave();
void calculaExcentricidade();
void apresentaResultados();

/** Variáveis utilizadas */

double raio, massa; // Contém os valores do planeta selecionado
double velocidadeDeEscape;
double altitudeMaxima;
double velocidadeNaAltitudeMaxima;
double periodoDaNave;
double excentricidade;


int main(){
    apresentaMenu();
    // calculaVelocidadeDeEscape();
    // calculaAltitudeMaxima();
    // calculaVelocidadeNaAltiudeMaxima();
    // calculaPeriodoDaNave();
    // calculaExcentricidade();
    // apresentaResultados();
    return 0;
}

void apresentaMenu(){
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
}