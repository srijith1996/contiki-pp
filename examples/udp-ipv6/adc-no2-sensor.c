/*---------------------------------------------------------------------------*/
#include <stdio.h>
#include "cpu.h"
#include "contiki.h"
#include "dev/leds.h"
#include "dev/adc-sensors.h"
#include "dev/adc-zoul.h"
#include "dev/zoul-sensors.h"
#include "lib/sensors.h"
#include "dev/sys-ctrl.h"
#include "no2-sensor.h"

#if SENSOR_ON


#define DEBUG DEBUG_PRINT
#include "net/ip/uip-debug.h"
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
PROCESS(adc_no2_sensor_process, "ADC NO2 sensor process");

/*---------------------------------------------------------------------------*/
static struct etimer et;

static struct no2_data no2_data;
static uint32_t sample_count;
/*---------------------------------------------------------------------------*/
PROCESS_THREAD(adc_no2_sensor_process, ev, data)
{
  PROCESS_BEGIN();
  PRINTF("Enter ADC NO2 process \n");  
    
	sample_count = 0;  

  /* Use pin number not mask, for example if using the PA5 pin then use 2 */
  adc_zoul.configure(SENSORS_HW_INIT, NO2_ADC_PIN1 + NO2_ADC_PIN2);

  /* And periodically poll the sensor */
  while(1) {
    etimer_set(&et, SENSOR_READ_INTERVAL);
    PROCESS_WAIT_EVENT_UNTIL(etimer_expired(&et));
    
    sample_count++;
		no2_data.sample_count = sample_count;
    PRINTF("Sample count %ld, ", sample_count); 

    no2_data.no2_1 = adc_zoul.value(NO2_ADC_PIN1);
    no2_data.no2_1 /= (4096/3300);
		no2_data.no2_1 >>= 3;
    PRINTF("NO2 op1 %d, ", no2_data.no2_1); 
    
    no2_data.no2_2 = adc_zoul.value(NO2_ADC_PIN2);
    no2_data.no2_2 /= (4096/3300); 
		no2_data.no2_2 >>= 3;
    PRINTF("NO2 op2 %d\n", no2_data.no2_2);

  }
  PROCESS_END();
}
/*---------------------------------------------------------------------------*/
#endif /* SENSOR_ON */
/**
 * @}
 * @}
 */
