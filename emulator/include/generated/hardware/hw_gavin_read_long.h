//
//	Automatically generated.
//
if (IS_GAVIN(address)) {
	int a = address-ADDR_GAVIN;
	if (HW_IS_GAVIN_READMAU(a)) {
		return Gavin_Read(a,(hwMemory + ADDR_GAVIN - HARDWARE_START),4);
	}
	if (HW_IS_GAVIN_TIMERS(a)) {
		return Gavin_Read(a,(hwMemory + ADDR_GAVIN - HARDWARE_START),4);
	}
}
