#define TRANSMIT_ON 0
#define SENSOR_ON   1
#define RDC         2
#define COMPUTE_ON  0

/* RDC    0: OFF
 *        1: contikimac
 *        2: nullrdc   
 */

#if SENSOR_ON
#define ADC_SENSORS_CONF_ADC3_PIN 2
#define SENSOR_READ_INTERVAL (CLOCK_SECOND * 5)
#else /* SENSOR_ON */
#define ADC_SENSORS_CONF_ADC3_PIN -1
#endif /* SENSOR_ON */

#if TRANSMIT_ON
#define SEND_INTERVAL        (CLOCK_SECOND * 5)
#endif /* TRANSMIT_ON */

#if (RADIO == 1)
#define NETSTACK_CONF_RDC  contikimac_driver
#else  /* (RADIO == 1) */
#define NETSTACK_CONF_RDC  nullrdc_driver
#endif /* (RADIO == 1) */

#define NETSTACK_CONF_MAC  csma_driver
