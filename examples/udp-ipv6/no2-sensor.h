/*
 * Change hardware pin configuration for
 * NO2 sensor here
 */
#if SENSOR_ON

#define NO2_ADC_PIN1	ZOUL_SENSORS_ADC1
#define NO2_ADC_PIN2	ZOUL_SENSORS_ADC3

/*
 * structure of output from NO2 sensor
 */
struct no2_data {
  uint16_t no2_1;
  uint16_t no2_2;
  uint32_t sample_count;
};

#endif /* SENSOR_ON */
