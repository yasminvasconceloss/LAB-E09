#include <stdio.h>

/* Definição dos sensores (cada bit é um sensor) */
#define SENSOR_TEMP       (1 << 0)  /* Bit 0 */
#define SENSOR_UMIDADE    (1 << 1)  /* Bit 1 */
#define SENSOR_PRESSAO    (1 << 2)  /* Bit 2 */
#define SENSOR_LUMINOS    (1 << 3)  /* Bit 3 */
#define SENSOR_MOVIMENTO  (1 << 4)  /* Bit 4 */
/* Bits 5 a 7: reservados (não usar) */

/* Funções inline com ponteiros */
static inline void ligar_sensor(unsigned char *reg, unsigned char sensor) {
    *reg |= sensor;
}

static inline void desligar_sensor(unsigned char *reg, unsigned char sensor) {
    *reg &= (unsigned char)~sensor;
}

static inline int verificar_sensor(const unsigned char *reg, unsigned char sensor) {
    return (*reg & sensor) ? 1 : 0;
}

int main(void) {
    unsigned char SENSOR_REG = 0; /* Registrador de 8 bits */

    /* Ligar temperatura e movimento */
    ligar_sensor(&SENSOR_REG, SENSOR_TEMP);
    ligar_sensor(&SENSOR_REG, SENSOR_MOVIMENTO);

    /* Desligar temperatura */
    desligar_sensor(&SENSOR_REG, SENSOR_TEMP);

    /* Verificar pressão e exibir resultado */
    if (verificar_sensor(&SENSOR_REG, SENSOR_PRESSAO)) {
        printf("Sensor de PRESSAO esta LIGADO\n");
    } else {
        printf("Sensor de PRESSAO esta DESLIGADO\n");
    }

    return 0;
}