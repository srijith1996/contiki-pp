#define TRANSMIT_ON 0
#define SENSOR_ON   0
#define RDC         0
#define COMPUTE_ON  1

/* RDC    0: OFF
 *        1: contikimac
 *        2: nullrdc   
 */

#if SENSOR_ON
#define ADC_SENSORS_CONF_ADC3_PIN 2
#define SENSOR_READ_INTERVAL (CLOCK_SECOND * 1)
#else /* SENSOR_ON */
#define ADC_SENSORS_CONF_ADC3_PIN -1
#endif /* SENSOR_ON */

#if TRANSMIT_ON
#define SEND_INTERVAL        (CLOCK_SECOND * 1)
#endif /* TRANSMIT_ON */

#if COMPUTE_ON
#define COMP_INTERVAL         (CLOCK_SECOND * 1)
#endif /* COMPUTE_ON */

#if (RDC == 2)
#define NETSTACK_CONF_RDC  nullrdc_driver
#else  /* (RDC == 2) */
#define NETSTACK_CONF_RDC  contikimac_driver
#endif /* (RDC == 2) */

#define NETSTACK_CONF_MAC  csma_driver
