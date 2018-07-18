DEFINES+=PROJECT_CONF_H=\"project-conf.h\"
all: udp-server adc-no2-sensor

CONTIKI_TARGET_SOURCEFILES += adc-no2-sensor.c
CONTIKI = ../..
CONTIKI_WITH_IPV6 = 1
CFLAGS += -DUIP_CONF_ND6_SEND_NA=1
include $(CONTIKI)/Makefile.include
