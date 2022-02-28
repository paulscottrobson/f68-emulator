//
//	Automatically generated.
//
if (IS_GAVIN(address)) {
	int a = address-ADDR_GAVIN;
	if (HW_IS_GAVIN_RTC(a)) {
		return Gavin_Read(a,(hwMemory + ADDR_GAVIN - HARDWARE_START),1);
	}
	if (HW_IS_GAVIN_INTERRUPTCTRL(a)) {
		return Gavin_Read(a,(hwMemory + ADDR_GAVIN - HARDWARE_START),1);
	}
	if (HW_IS_GAVIN_READPS2(a)) {
		return Gavin_Read(a,(hwMemory + ADDR_GAVIN - HARDWARE_START),1);
	}
}
