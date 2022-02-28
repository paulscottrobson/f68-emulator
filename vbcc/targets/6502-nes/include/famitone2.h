 // FamiTone2 audio library v1.15 by Shiru 04'17
// vbcc6502 header, '2020 Lazycow

   // reset APU, initialize FamiTone
  // data: Pointer to music data
 // flags: 1 for NTSC mode
//
void ftInit(__reg("r0/r1") void* data, __reg("a") unsigned char flags);

 // init sound effects player, set pointer to data
//
void ftSfxInit(__reg("r0/r1") void* data);

  // play a music in ft format
 // song: Number of subsong
//
void ftMusicPlay(__reg("a") unsigned char song);

 // stop music
//
void ftMusicStop(void);

  // pause and unpause music
 // pause: 0 to play, !=0 to pause
//
void ftMusicPause(__reg("a") unsigned char pause);

   // play ft sound effect on channel 0..3
  //  sound: Number of the sound effect, 0..127
 // channel: FT_SFX_CH0, FT_SFX_CH1, FT_SFX_CH2 or FT_SFX_CH3
//
void ftSfxPlay(__reg("a") unsigned char sound, __reg("r0") unsigned char channel);
	enum { FT_SFX_CH0=0, FT_SFX_CH1=15, FT_SFX_CH2=30, FT_SFX_CH3=45 };

  // play a DPCM sample
 // sample: Number of the sample, 1..63
//
void ftSamplePlay(__reg("a") unsigned char sample);
