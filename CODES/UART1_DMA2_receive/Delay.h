#if !defined(DELAY)
#define DELAY

void SytemClock_Configuration(void);
void TimerSetup(void);
void Delay_us (uint16_t time);
void Delay_ms (uint16_t time);

#endif 
