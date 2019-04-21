#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/** Constantes utilizadas */

#define RAIO_DE_MERCURIO  2439.7E3;// Em m
#define MASSA_DE_MERCURIO  3.285E23; // Em kg
#define GRAVIDADE_DE_MERCURIO  3.7; // Em m/s^2

#define RAIO_DE_VENUS  6051.8E3;
#define MASSA_DE_VENUS  4.867E24;
#define GRAVIDADE_DE_VENUS  8.87; 

#define RAIO_DE_TERRA  6371E3;
#define MASSA_DE_TERRA  5.972E24;
#define GRAVIDADE_DE_TERRA  9.807;

#define RAIO_DE_MARTE  3389.5E3; 
#define MASSA_DE_MARTE  6.4174E23; 
#define GRAVIDADE_DE_MARTE  3.711;

#define RAIO_DE_JUPITER  69911E3;
#define MASSA_DE_JUPITER 1.898E27;
#define GRAVIDADE_DE_JUPITER  24.79;

#define PI 3.14

enum PLANETAS {
    MERCURIO = 1,
    VENUS = 2,
    TERRA = 3,
    MARTE = 4,
    JUPITER = 5,
};

/** Protótipos das funcoes utilizadas */

void apresentaMenu();
void realizaCalculos();
void apresentaResultados();

/** Variaveis utilizadas */

double raio, massa, gravidade; // Contem os valores do planeta selecionado
double alturaDeBurnout, velocidadeInicial;
double momentoPorMassa;
double C;

double velocidadeDeEscape;
double velocidadeCircular;
double altitudeMaxima;
double velocidadeNaAltitudeMaxima;
double periodoDaNave;
double excentricidade;


int main(){
    apresentaMenu();
    realizaCalculos();
    apresentaResultados();
    return 0;
}

void apresentaMenu(){
    int escolha;

    printf("- - - - - Lista de planetas - - - - -\n\n");
    printf("1) Mercurio\n2) Venus\n3) Terra\n4) Marte\n5) Jupiter\n\n");
    printf("Selecione o planeta desejado: ");

    scanf("%d", &escolha);

    switch(escolha){
        case MERCURIO:
            raio = RAIO_DE_MERCURIO;
            massa = MASSA_DE_MERCURIO;
            gravidade = GRAVIDADE_DE_MERCURIO;
            break;
        case VENUS:
            raio = RAIO_DE_VENUS;
            massa = MASSA_DE_VENUS;
            gravidade = GRAVIDADE_DE_VENUS;
            break;
        case TERRA:
            raio = RAIO_DE_TERRA;
            massa = MASSA_DE_TERRA;
            gravidade = GRAVIDADE_DE_TERRA;
            break;
        case MARTE:
            raio = RAIO_DE_MARTE;
            massa = MASSA_DE_MARTE;
            gravidade = GRAVIDADE_DE_MARTE;
            break;
        case JUPITER:
            raio = RAIO_DE_JUPITER;
            massa = MASSA_DE_JUPITER;
            gravidade = GRAVIDADE_DE_JUPITER;
            break;
        default:
            printf("Entrada invalida!\n\n");
            apresentaMenu();
    }
}

void realizaCalculos(){
    alturaDeBurnout = 0.29 * raio + raio; // Altura na qual a gravidade se reduz a 60%

    velocidadeDeEscape = sqrt((2*gravidade*pow(raio,2.0)) / (alturaDeBurnout));
    velocidadeCircular = velocidadeDeEscape / sqrt(2.0);

    /* 
        Numa trajetoria eliptica, a velocidade de lancamento deve estar entre as velocidades circular e de escape.
        Assim, para a simulacao, utilizamos a velocidade de lancamento como a media aritmetica dessas velocidades:
    */

    velocidadeInicial = 0.5 * (velocidadeCircular + velocidadeDeEscape); 

    momentoPorMassa = velocidadeInicial * alturaDeBurnout;

    double GM_H2 = (gravidade * pow(raio, 2.0)) / pow(momentoPorMassa, 2.0); // Valor de GM / h^2

    C = (1.0 / (alturaDeBurnout)) - GM_H2 ; // Constante C

    altitudeMaxima = 1.0 / ( GM_H2 - C);

    velocidadeNaAltitudeMaxima = momentoPorMassa / altitudeMaxima;

    double a = 0.5 * (alturaDeBurnout + altitudeMaxima);
    double b = sqrt(alturaDeBurnout * altitudeMaxima);

    excentricidade = a / b;

    periodoDaNave = ((2.0 * PI * a * b) / momentoPorMassa);
}

void apresentaResultados(){
    printf("\nVelocidade de escape: %.2f m/s\n", velocidadeDeEscape);
    printf("Altitude Maxima: %.2f m\n", altitudeMaxima);
    printf("Velocidade na altitude maxima: %.2f m/s\n", velocidadeNaAltitudeMaxima);
    printf("Periodo de orbita da nave: %.2f s\n", periodoDaNave);
    printf("Valor da excentricidade: %.2f\n\n", excentricidade);
}