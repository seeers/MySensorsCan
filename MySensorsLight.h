


int main(void)
{
	init();
#if defined(USBCON)
	USBDevice.attach();
#endif
	_begin(); // Startup MySensors library
	for(;;) {
		_process();  // Process incoming data
		if (loop) {
			loop(); // Call sketch loop
		}
		if (serialEventRun) {
			serialEventRun();
		}
	}
	return 0;
}
