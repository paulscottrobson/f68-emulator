#!/bin/zsh

export VBCC=/opt/vbcc
export PATH=$VBCC/bin:$PATH
export DEVA2560=~/dev/bbedit-workspace-a2560

cd $DEVA2560/lib_text

#vc +/opt/vbcc/config/a2560-s28 -o text.s28 main.c general.c general_a2560.c lib_text.c lib_text_test.c
#vc +/opt/vbcc/config/a2560-s28 -o text.s28 test3.c general.c general_a2560.c

#vc +/opt/vbcc/config/a2560-s28-micah -o text.s28 main.c general.c general_a2560.c lib_text.c lib_text_test.c
#vc +/opt/vbcc/config/a2560-s28-micah -o text.s28 main.c general.c general_a2560.c lib_text.c

vc +/opt/vbcc/config/a2560-s28-micah -o text.s28 main.c lib_general.c lib_general_a2560.c lib_text.c lib_text_test.c
#vc +/opt/vbcc/config/a2560-s19-micah -o text.s19 main.c lib_general.c lib_general_a2560.c lib_text.c lib_text_test.c
#vc +/opt/vbcc/config/a2560-s37-micah -o text.s37 main.c lib_general.c lib_general_a2560.c lib_text.c lib_text_test.c
#vc +/opt/vbcc/config/a2560-ihex-micah -o text.ihex main.c lib_general.c lib_general_a2560.c lib_text.c lib_text_test.c

# -lm
# -lmieee
 
# no tests
#vc +/opt/vbcc/config/aos68k -o build_vbcc/wb2k about_window.c app.c dict.c dict_entry.c file.c file_mover.c folder.c file_type.c file_type_db.c general.c general_amiga.c icon.c info_file.c info_panel.c label.c list.c list_panel.c menu.c mouse.c localize.c prefs.c status_window.c window.c -g -lauto -lamiga -prof -lmieee -stack-check

# with tests
#vc +/opt/vbcc/config/aos68k -o build_vbcc/wb2k about_window.c app.c dict.c dict_entry.c file.c file_mover.c folder.c file_type.c file_type_db.c general.c general_amiga.c icon.c info_file.c info_panel.c label.c list.c list_panel.c menu.c mouse.c localize.c prefs.c status_window.c window.c dict_test.c file_type_db_test.c icon_test.c prefs_test.c -g -lauto -lamiga -prof -lmieee -stack-check

# make binary with srec. eg
/usr/local/Homebrew/bin/srec_cat text.s28 -Motorola -address-length=3 -o text.bin -binary

# delete s28, no longer need it
#rm text.s28

# convert binary to intel. eg
#/usr/local/Homebrew/bin/srec_cat text.bin -binary -offset 0x20000 -o text.hex.wrong -intel
/usr/local/Homebrew/bin/srec_cat text.bin -binary -o text.hex.wrong -intel

# delete binary, no longer need it
rm text.bin

# process with perl
perl -i -0777 -pe 's/\n/__EOF__/g' "$DEVA2560/lib_text/text.hex.wrong"
perl -i -0777 -pe 's/^.+?(:02[0-9A-F]+__EOF__:200000004FF90005000041F9)/\1/g' "$DEVA2560/lib_text/text.hex.wrong"
perl -i -0777 -pe 's/__EOF__/\n/g' "$DEVA2560/lib_text/text.hex.wrong"
mv text.hex.wrong text.hex

# now file has no extra junk, but it's at 0x0000, needs to be at 0x20000
# run srec cat again, intel to intel, setting an offset of 20k:
#/usr/local/Homebrew/bin/srec_cat text.hex.wrong -intel -offset 0x20000 -o text.hex -intel

# delete hex with wrong address, no longer need it
#rm text.hex.wrong

# move hex to morfe folder for running with morfe
mv text.hex ../morfe/

# blu's code to execute from user space (load hex stub_user.hex; set pc 50000; quit)
vasmm68k_mot -Fsrec -o stub_user.srec $DEVA2560/m68k-misc/stub_user.asm
/usr/local/Homebrew/bin/srec_cat stub_user.srec -o stub_user.hex -intel
mv stub_user.hex ../morfe/


# cd $DEVA2560/f68-emulator/emulator/
# nohup ./f68 $DEVA2560/lib_text/text.s28 &

#./f68 $DEVA2560/lib_text/text.s19
#./f68 $DEVA2560/lib_text/text.s37
#./f68 $DEVA2560/lib_text/text.ihex


echo "VBCC build script complete\n"
