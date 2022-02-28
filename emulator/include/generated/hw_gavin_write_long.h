//
//	Automatically generated.
//
if (IS_GAVIN(address)) {
	int a = address-ADDR_GAVIN;
	if (HW_IS_GAVIN_TIMERS(a)) {
		if(Gavin_Write(a,(hwMemory + ADDR_GAVIN - HARDWARE_START),value,4)) return;
	}
}
