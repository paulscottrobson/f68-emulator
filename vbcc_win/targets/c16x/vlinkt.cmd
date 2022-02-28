
MEMORY
{
iram: org = 0xf000, l = 0x1000
nram : org = 0xe000, l = 0x1000
nrom : org = 0x200, len = 0x10000
fram: org = 0x123456, len=0x100000
from: org = 0x345678, len=0x100000

ivec0: org=0x0, len=4
ivec1: org=0x4, len=4
ivec2: org=0x8, len=4
ivec3: org=0xc, len=4
ivec4: org=0x10, len=4
ivec5: org=0x14, len=4
ivec6: org=0x18, len=4
ivec7: org=0x1c, len=4
ivec8: org=0x20, len=4
ivec9: org=0x24, len=4
ivec10: org=0x28, len=4
ivec11: org=0x2c, len=4
ivec12: org=0x30, len=4
ivec13: org=0x34, len=4
ivec14: org=0x38, len=4
ivec15: org=0x3c, len=4
ivec16: org=0x40, len=4
ivec17: org=0x44, len=4
ivec18: org=0x48, len=4
ivec19: org=0x4c, len=4
ivec20: org=0x50, len=4
ivec21: org=0x54, len=4
ivec22: org=0x58, len=4
ivec23: org=0x5c, len=4
ivec24: org=0x60, len=4
ivec25: org=0x64, len=4
ivec26: org=0x68, len=4
ivec27: org=0x6c, len=4
ivec28: org=0x70, len=4
ivec29: org=0x74, len=4
ivec30: org=0x78, len=4
ivec31: org=0x7c, len=4
ivec32: org=0x80, len=4
ivec33: org=0x84, len=4
ivec34: org=0x88, len=4
ivec35: org=0x8c, len=4
ivec36: org=0x90, len=4
ivec37: org=0x94, len=4
ivec38: org=0x98, len=4
ivec39: org=0x9c, len=4
ivec40: org=0xa0, len=4
ivec41: org=0xa4, len=4
ivec42: org=0xa8, len=4
ivec43: org=0xac, len=4
ivec44: org=0xb0, len=4
ivec45: org=0xb4, len=4
ivec46: org=0xb8, len=4
ivec47: org=0xbc, len=4
ivec48: org=0xc0, len=4
ivec49: org=0xc4, len=4
ivec50: org=0xc8, len=4
ivec51: org=0xcc, len=4
ivec52: org=0xd0, len=4
ivec53: org=0xd4, len=4
ivec54: org=0xd8, len=4
ivec55: org=0xdc, len=4
ivec56: org=0xe0, len=4
ivec57: org=0xe4, len=4
ivec58: org=0xe8, len=4
ivec59: org=0xec, len=4
ivec60: org=0xf0, len=4
ivec61: org=0xf4, len=4
ivec62: org=0xf8, len=4
ivec63: org=0xfc, len=4
ivec64: org=0x100, len=4
ivec65: org=0x104, len=4
ivec66: org=0x108, len=4
ivec67: org=0x10c, len=4
ivec68: org=0x110, len=4
ivec69: org=0x114, len=4
ivec70: org=0x118, len=4
ivec71: org=0x11c, len=4
ivec72: org=0x120, len=4
ivec73: org=0x124, len=4
ivec74: org=0x128, len=4
ivec75: org=0x12c, len=4
ivec76: org=0x130, len=4
ivec77: org=0x134, len=4
ivec78: org=0x138, len=4
ivec79: org=0x13c, len=4
ivec80: org=0x140, len=4
ivec81: org=0x144, len=4
ivec82: org=0x148, len=4
ivec83: org=0x14c, len=4
ivec84: org=0x150, len=4
ivec85: org=0x154, len=4
ivec86: org=0x158, len=4
ivec87: org=0x15c, len=4
ivec88: org=0x160, len=4
ivec89: org=0x164, len=4
ivec90: org=0x168, len=4
ivec91: org=0x16c, len=4
ivec92: org=0x170, len=4
ivec93: org=0x174, len=4
ivec94: org=0x178, len=4
ivec95: org=0x17c, len=4


}


SECTIONS
{
	.vecinclude (NOLOAD): { *(.vecinclude) }

	.ivec0: { *(.ivec0) } > ivec0
	.ivec1: { *(.ivec1) } > ivec1
	.ivec2: { *(.ivec2) } > ivec2
	.ivec3: { *(.ivec3) } > ivec3
	.ivec4: { *(.ivec4) } > ivec4
	.ivec5: { *(.ivec5) } > ivec5
	.ivec6: { *(.ivec6) } > ivec6
	.ivec7: { *(.ivec7) } > ivec7
	.ivec8: { *(.ivec8) } > ivec8
	.ivec9: { *(.ivec9) } > ivec9
	.ivec10: { *(.ivec10) } > ivec10
	.ivec11: { *(.ivec11) } > ivec11
	.ivec12: { *(.ivec12) } > ivec12
	.ivec13: { *(.ivec13) } > ivec13
	.ivec14: { *(.ivec14) } > ivec14
	.ivec15: { *(.ivec15) } > ivec15
	.ivec16: { *(.ivec16) } > ivec16
	.ivec17: { *(.ivec17) } > ivec17
	.ivec18: { *(.ivec18) } > ivec18
	.ivec19: { *(.ivec19) } > ivec19
	.ivec20: { *(.ivec20) } > ivec20
	.ivec21: { *(.ivec21) } > ivec21
	.ivec22: { *(.ivec22) } > ivec22
	.ivec23: { *(.ivec23) } > ivec23
	.ivec24: { *(.ivec24) } > ivec24
	.ivec25: { *(.ivec25) } > ivec25
	.ivec26: { *(.ivec26) } > ivec26
	.ivec27: { *(.ivec27) } > ivec27
	.ivec28: { *(.ivec28) } > ivec28
	.ivec29: { *(.ivec29) } > ivec29
	.ivec30: { *(.ivec30) } > ivec30
	.ivec31: { *(.ivec31) } > ivec31
	.ivec32: { *(.ivec32) } > ivec32
	.ivec33: { *(.ivec33) } > ivec33
	.ivec34: { *(.ivec34) } > ivec34
	.ivec35: { *(.ivec35) } > ivec35
	.ivec36: { *(.ivec36) } > ivec36
	.ivec37: { *(.ivec37) } > ivec37
	.ivec38: { *(.ivec38) } > ivec38
	.ivec39: { *(.ivec39) } > ivec39
	.ivec40: { *(.ivec40) } > ivec40
	.ivec41: { *(.ivec41) } > ivec41
	.ivec42: { *(.ivec42) } > ivec42
	.ivec43: { *(.ivec43) } > ivec43
	.ivec44: { *(.ivec44) } > ivec44
	.ivec45: { *(.ivec45) } > ivec45
	.ivec46: { *(.ivec46) } > ivec46
	.ivec47: { *(.ivec47) } > ivec47
	.ivec48: { *(.ivec48) } > ivec48
	.ivec49: { *(.ivec49) } > ivec49
	.ivec50: { *(.ivec50) } > ivec50
	.ivec51: { *(.ivec51) } > ivec51
	.ivec52: { *(.ivec52) } > ivec52
	.ivec53: { *(.ivec53) } > ivec53
	.ivec54: { *(.ivec54) } > ivec54
	.ivec55: { *(.ivec55) } > ivec55
	.ivec56: { *(.ivec56) } > ivec56
	.ivec57: { *(.ivec57) } > ivec57
	.ivec58: { *(.ivec58) } > ivec58
	.ivec59: { *(.ivec59) } > ivec59
	.ivec60: { *(.ivec60) } > ivec60
	.ivec61: { *(.ivec61) } > ivec61
	.ivec62: { *(.ivec62) } > ivec62
	.ivec63: { *(.ivec63) } > ivec63
	.ivec64: { *(.ivec64) } > ivec64
	.ivec65: { *(.ivec65) } > ivec65
	.ivec66: { *(.ivec66) } > ivec66
	.ivec67: { *(.ivec67) } > ivec67
	.ivec68: { *(.ivec68) } > ivec68
	.ivec69: { *(.ivec69) } > ivec69
	.ivec70: { *(.ivec70) } > ivec70
	.ivec71: { *(.ivec71) } > ivec71
	.ivec72: { *(.ivec72) } > ivec72
	.ivec73: { *(.ivec73) } > ivec73
	.ivec74: { *(.ivec74) } > ivec74
	.ivec75: { *(.ivec75) } > ivec75
	.ivec76: { *(.ivec76) } > ivec76
	.ivec77: { *(.ivec77) } > ivec77
	.ivec78: { *(.ivec78) } > ivec78
	.ivec79: { *(.ivec79) } > ivec79
	.ivec80: { *(.ivec80) } > ivec80
	.ivec81: { *(.ivec81) } > ivec81
	.ivec82: { *(.ivec82) } > ivec82
	.ivec83: { *(.ivec83) } > ivec83
	.ivec84: { *(.ivec84) } > ivec84
	.ivec85: { *(.ivec85) } > ivec85
	.ivec86: { *(.ivec86) } > ivec86
	.ivec87: { *(.ivec87) } > ivec87
	.ivec88: { *(.ivec88) } > ivec88
	.ivec89: { *(.ivec89) } > ivec89
	.ivec90: { *(.ivec90) } > ivec90
	.ivec91: { *(.ivec91) } > ivec91
	.ivec92: { *(.ivec92) } > ivec92
	.ivec93: { *(.ivec93) } > ivec93
	.ivec94: { *(.ivec94) } > ivec94
	.ivec95: { *(.ivec95) } > ivec95

	.ncdata: { *(.ncdata) } > nrom
        .text : { *(.text) } > nrom
        .fcdata: { *(.fcdata) } > from
        .hcdata: { *(.hcdata) } > from
	.ndata: { *(.ndata) } > nram AT> from
	.nbss: { *(.nbss) } > nram
	.rbanks: { *(.rbanks) } > iram
        .fdata: { *(.fdata) } > fram AT> from
        .hdata: { *(.hdata) } > fram AT> from
        .fbss: { *(.fbss) } > fram
	.hbss: { *(.hbss) } > fram



	/* for initialization of near data */
        __NDS = ADDR(.ndata);
	__NDE = __NDS + SIZEOF(.ndata);
	__NDI = LOADADDR(.ndata);
	
	__FDS = ADDR(.fdata);
	__FDE = ADDR(.fdata) + (SIZEOF(.fdata)+1)/2*2 + SIZEOF(.hdata);
	__FDI = LOADADDR(.fdata);

	__NBS = ADDR(.nbss);
	__NBE = ADDR(.nbss) + SIZEOF(.nbss);
	
	__FBS = ADDR(.fbss);
	__FBE = ADDR(.fbss) + (SIZEOF(.fbss)+1)/2*2 + SIZEOF(.hbss);

}

