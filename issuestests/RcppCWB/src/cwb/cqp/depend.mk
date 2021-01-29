llquery.o: llquery.c ../cl/macros.h ../cl/globals.h ../cl/cl.h cqp.h \
 eval.h ../cl/cdaccess.h regex2dfa.h corpmanag.h ../cl/corpus.h \
 ../cl/bitfields.h context_descriptor.h attlist.h ../cl/attributes.h \
 ../cl/storage.h ../cl/corpus.h symtab.h options.h ../cl/globals.h \
 concordance.h ../cl/class-mapping.h ../cl/attributes.h print-modes.h \
 macro.h variables.h output.h ascii-print.h groups.h
cqp.o: cqp.c ../cl/globals.h ../cl/cl.h ../cl/macros.h ../cl/globals.h \
 cqp.h options.h concordance.h ../cl/corpus.h ../cl/class-mapping.h \
 ../cl/corpus.h ../cl/attributes.h ../cl/storage.h context_descriptor.h \
 attlist.h ../cl/attributes.h print-modes.h corpmanag.h ../cl/bitfields.h \
 output.h symtab.h tree.h eval.h ../cl/cdaccess.h regex2dfa.h ranges.h \
 macro.h targets.h parser.tab.h
cqpcl.o: cqpcl.c cqp.h options.h ../cl/globals.h ../cl/cl.h concordance.h \
 ../cl/corpus.h ../cl/globals.h ../cl/class-mapping.h ../cl/corpus.h \
 ../cl/attributes.h ../cl/storage.h context_descriptor.h attlist.h \
 ../cl/attributes.h print-modes.h corpmanag.h ../cl/bitfields.h
symtab.o: symtab.c ../cl/macros.h ../cl/globals.h ../cl/cl.h symtab.h \
 output.h corpmanag.h ../cl/corpus.h ../cl/bitfields.h cqp.h \
 context_descriptor.h attlist.h ../cl/attributes.h ../cl/storage.h \
 ../cl/corpus.h print-modes.h
eval.o: eval.c ../cl/globals.h ../cl/cl.h ../cl/macros.h ../cl/globals.h \
 ../cl/corpus.h ../cl/attributes.h ../cl/storage.h ../cl/corpus.h \
 ../cl/cdaccess.h ../cl/special-chars.h cqp.h ranges.h eval.h regex2dfa.h \
 corpmanag.h ../cl/bitfields.h context_descriptor.h attlist.h symtab.h \
 options.h concordance.h ../cl/class-mapping.h ../cl/attributes.h \
 print-modes.h output.h tree.h builtins.h matchlist.h
tree.o: tree.c ../cl/macros.h ../cl/globals.h ../cl/cl.h \
 ../cl/attributes.h ../cl/storage.h ../cl/corpus.h cqp.h eval.h \
 ../cl/cdaccess.h regex2dfa.h corpmanag.h ../cl/corpus.h \
 ../cl/bitfields.h context_descriptor.h attlist.h symtab.h options.h \
 ../cl/globals.h concordance.h ../cl/class-mapping.h ../cl/attributes.h \
 print-modes.h treemacros.h tree.h builtins.h matchlist.h
options.o: options.c options.h ../cl/globals.h ../cl/cl.h concordance.h \
 ../cl/corpus.h ../cl/globals.h ../cl/class-mapping.h ../cl/corpus.h \
 ../cl/attributes.h ../cl/storage.h context_descriptor.h attlist.h \
 ../cl/attributes.h print-modes.h corpmanag.h ../cl/bitfields.h cqp.h \
 output.h ../cl/macros.h
corpmanag.o: corpmanag.c ../cl/globals.h ../cl/cl.h ../cl/macros.h \
 ../cl/globals.h ../cl/corpus.h ../cl/attributes.h ../cl/storage.h \
 ../cl/corpus.h ../cl/cdaccess.h ../cl/fileutils.h corpmanag.h \
 ../cl/bitfields.h cqp.h context_descriptor.h attlist.h options.h \
 concordance.h ../cl/class-mapping.h ../cl/attributes.h print-modes.h \
 output.h ranges.h eval.h regex2dfa.h symtab.h
regex2dfa.o: regex2dfa.c ../cl/globals.h ../cl/cl.h ../cl/macros.h \
 ../cl/globals.h eval.h ../cl/cdaccess.h regex2dfa.h cqp.h corpmanag.h \
 ../cl/corpus.h ../cl/bitfields.h context_descriptor.h attlist.h \
 ../cl/attributes.h ../cl/storage.h ../cl/corpus.h symtab.h options.h \
 concordance.h ../cl/class-mapping.h ../cl/attributes.h print-modes.h
output.o: output.c ../cl/globals.h ../cl/cl.h ../cl/corpus.h \
 ../cl/globals.h ../cl/attributes.h ../cl/storage.h ../cl/corpus.h \
 ../cl/cdaccess.h concordance.h ../cl/class-mapping.h ../cl/attributes.h \
 context_descriptor.h attlist.h print-modes.h corpmanag.h \
 ../cl/bitfields.h cqp.h options.h output.h print_align.h ascii-print.h \
 groups.h sgml-print.h html-print.h latex-print.h
ranges.o: ranges.c ../cl/globals.h ../cl/cl.h ../cl/corpus.h \
 ../cl/globals.h ../cl/attributes.h ../cl/storage.h ../cl/corpus.h \
 ../cl/cdaccess.h ../cl/macros.h corpmanag.h ../cl/bitfields.h cqp.h \
 context_descriptor.h attlist.h eval.h regex2dfa.h symtab.h options.h \
 concordance.h ../cl/class-mapping.h ../cl/attributes.h print-modes.h \
 ranges.h output.h matchlist.h
builtins.o: builtins.c ../cl/globals.h ../cl/cl.h ../cl/macros.h \
 ../cl/globals.h ../cl/attributes.h ../cl/storage.h ../cl/corpus.h \
 ../cl/cdaccess.h builtins.h eval.h regex2dfa.h cqp.h corpmanag.h \
 ../cl/corpus.h ../cl/bitfields.h context_descriptor.h attlist.h symtab.h \
 options.h concordance.h ../cl/class-mapping.h ../cl/attributes.h \
 print-modes.h output.h
groups.o: groups.c ../cl/globals.h ../cl/cl.h ../cl/attributes.h \
 ../cl/globals.h ../cl/storage.h ../cl/corpus.h ../cl/cdaccess.h \
 ../cl/macros.h ../cl/binsert.h options.h concordance.h ../cl/corpus.h \
 ../cl/class-mapping.h ../cl/attributes.h context_descriptor.h attlist.h \
 print-modes.h corpmanag.h ../cl/bitfields.h cqp.h html-print.h groups.h \
 output.h ascii-print.h sgml-print.h latex-print.h
targets.o: targets.c ../cl/globals.h ../cl/cl.h ../cl/macros.h \
 ../cl/globals.h ../cl/attributes.h ../cl/storage.h ../cl/corpus.h \
 corpmanag.h ../cl/corpus.h ../cl/bitfields.h cqp.h context_descriptor.h \
 attlist.h eval.h ../cl/cdaccess.h regex2dfa.h symtab.h options.h \
 concordance.h ../cl/class-mapping.h ../cl/attributes.h print-modes.h \
 output.h ranges.h targets.h
matchlist.o: matchlist.c ../cl/macros.h ../cl/globals.h ../cl/cl.h \
 ../cl/attributes.h ../cl/storage.h ../cl/corpus.h ../cl/cdaccess.h \
 matchlist.h output.h corpmanag.h ../cl/corpus.h ../cl/bitfields.h cqp.h \
 context_descriptor.h attlist.h print-modes.h eval.h regex2dfa.h symtab.h \
 options.h ../cl/globals.h concordance.h ../cl/class-mapping.h \
 ../cl/attributes.h
concordance.o: concordance.c /usr/include/glib-2.0/glib.h \
 /usr/include/glib-2.0/glib/galloca.h /usr/include/glib-2.0/glib/gtypes.h \
 /usr/lib/x86_64-linux-gnu/glib-2.0/include/glibconfig.h \
 /usr/include/glib-2.0/glib/gmacros.h \
 /usr/include/glib-2.0/glib/gversionmacros.h \
 /usr/include/glib-2.0/glib/garray.h \
 /usr/include/glib-2.0/glib/gasyncqueue.h \
 /usr/include/glib-2.0/glib/gthread.h \
 /usr/include/glib-2.0/glib/gatomic.h /usr/include/glib-2.0/glib/gerror.h \
 /usr/include/glib-2.0/glib/gquark.h /usr/include/glib-2.0/glib/gutils.h \
 /usr/include/glib-2.0/glib/gbacktrace.h \
 /usr/include/glib-2.0/glib/gbase64.h \
 /usr/include/glib-2.0/glib/gbitlock.h \
 /usr/include/glib-2.0/glib/gbookmarkfile.h \
 /usr/include/glib-2.0/glib/gbytes.h \
 /usr/include/glib-2.0/glib/gcharset.h \
 /usr/include/glib-2.0/glib/gchecksum.h \
 /usr/include/glib-2.0/glib/gconvert.h \
 /usr/include/glib-2.0/glib/gdataset.h /usr/include/glib-2.0/glib/gdate.h \
 /usr/include/glib-2.0/glib/gdatetime.h \
 /usr/include/glib-2.0/glib/gtimezone.h /usr/include/glib-2.0/glib/gdir.h \
 /usr/include/glib-2.0/glib/genviron.h \
 /usr/include/glib-2.0/glib/gfileutils.h \
 /usr/include/glib-2.0/glib/ggettext.h /usr/include/glib-2.0/glib/ghash.h \
 /usr/include/glib-2.0/glib/glist.h /usr/include/glib-2.0/glib/gmem.h \
 /usr/include/glib-2.0/glib/gnode.h /usr/include/glib-2.0/glib/ghmac.h \
 /usr/include/glib-2.0/glib/gchecksum.h \
 /usr/include/glib-2.0/glib/ghook.h \
 /usr/include/glib-2.0/glib/ghostutils.h \
 /usr/include/glib-2.0/glib/giochannel.h \
 /usr/include/glib-2.0/glib/gmain.h /usr/include/glib-2.0/glib/gpoll.h \
 /usr/include/glib-2.0/glib/gslist.h /usr/include/glib-2.0/glib/gstring.h \
 /usr/include/glib-2.0/glib/gunicode.h \
 /usr/include/glib-2.0/glib/gkeyfile.h \
 /usr/include/glib-2.0/glib/gmappedfile.h \
 /usr/include/glib-2.0/glib/gmarkup.h \
 /usr/include/glib-2.0/glib/gmessages.h \
 /usr/include/glib-2.0/glib/gvariant.h \
 /usr/include/glib-2.0/glib/gvarianttype.h \
 /usr/include/glib-2.0/glib/goption.h \
 /usr/include/glib-2.0/glib/gpattern.h \
 /usr/include/glib-2.0/glib/gprimes.h /usr/include/glib-2.0/glib/gqsort.h \
 /usr/include/glib-2.0/glib/gqueue.h /usr/include/glib-2.0/glib/grand.h \
 /usr/include/glib-2.0/glib/grcbox.h \
 /usr/include/glib-2.0/glib/grefcount.h \
 /usr/include/glib-2.0/glib/grefstring.h \
 /usr/include/glib-2.0/glib/gmem.h /usr/include/glib-2.0/glib/gmacros.h \
 /usr/include/glib-2.0/glib/gregex.h \
 /usr/include/glib-2.0/glib/gscanner.h \
 /usr/include/glib-2.0/glib/gsequence.h \
 /usr/include/glib-2.0/glib/gshell.h /usr/include/glib-2.0/glib/gslice.h \
 /usr/include/glib-2.0/glib/gspawn.h \
 /usr/include/glib-2.0/glib/gstrfuncs.h \
 /usr/include/glib-2.0/glib/gstringchunk.h \
 /usr/include/glib-2.0/glib/gtestutils.h \
 /usr/include/glib-2.0/glib/gthreadpool.h \
 /usr/include/glib-2.0/glib/gtimer.h \
 /usr/include/glib-2.0/glib/gtrashstack.h \
 /usr/include/glib-2.0/glib/gtree.h \
 /usr/include/glib-2.0/glib/gurifuncs.h \
 /usr/include/glib-2.0/glib/guuid.h /usr/include/glib-2.0/glib/gversion.h \
 /usr/include/glib-2.0/glib/deprecated/gallocator.h \
 /usr/include/glib-2.0/glib/deprecated/gcache.h \
 /usr/include/glib-2.0/glib/deprecated/gcompletion.h \
 /usr/include/glib-2.0/glib/deprecated/gmain.h \
 /usr/include/glib-2.0/glib/deprecated/grel.h \
 /usr/include/glib-2.0/glib/deprecated/gthread.h \
 /usr/include/glib-2.0/glib/glib-autocleanups.h ../cl/globals.h \
 ../cl/cl.h ../cl/macros.h ../cl/globals.h ../cl/corpus.h \
 ../cl/attributes.h ../cl/storage.h ../cl/corpus.h ../cl/cdaccess.h \
 concordance.h ../cl/class-mapping.h ../cl/attributes.h \
 context_descriptor.h attlist.h print-modes.h corpmanag.h \
 ../cl/bitfields.h cqp.h options.h
parse_actions.o: parse_actions.c parse_actions.h cqp.h corpmanag.h \
 ../cl/corpus.h ../cl/globals.h ../cl/cl.h ../cl/bitfields.h \
 context_descriptor.h attlist.h ../cl/attributes.h ../cl/storage.h \
 ../cl/corpus.h targets.h eval.h ../cl/cdaccess.h regex2dfa.h symtab.h \
 options.h ../cl/globals.h concordance.h ../cl/class-mapping.h \
 ../cl/attributes.h print-modes.h output.h ranges.h ../cl/special-chars.h \
 ../cl/macros.h treemacros.h tree.h builtins.h groups.h variables.h
attlist.o: attlist.c ../cl/macros.h ../cl/globals.h ../cl/cl.h \
 ../cl/corpus.h ../cl/attributes.h ../cl/storage.h ../cl/corpus.h \
 attlist.h
context_descriptor.o: context_descriptor.c ../cl/cl.h ../cl/corpus.h \
 ../cl/globals.h ../cl/cl.h ../cl/attributes.h ../cl/storage.h \
 ../cl/corpus.h ../cl/cdaccess.h ../cl/macros.h context_descriptor.h \
 attlist.h output.h corpmanag.h ../cl/bitfields.h cqp.h print-modes.h \
 options.h ../cl/globals.h concordance.h ../cl/class-mapping.h \
 ../cl/attributes.h
print-modes.o: print-modes.c ../cl/globals.h ../cl/cl.h ../cl/corpus.h \
 ../cl/globals.h ../cl/attributes.h ../cl/storage.h ../cl/corpus.h \
 ../cl/cdaccess.h corpmanag.h ../cl/bitfields.h cqp.h \
 context_descriptor.h attlist.h output.h print-modes.h options.h \
 concordance.h ../cl/class-mapping.h ../cl/attributes.h
ascii-print.o: ascii-print.c ../cl/macros.h ../cl/globals.h ../cl/cl.h \
 ../cl/corpus.h ../cl/attributes.h ../cl/storage.h ../cl/corpus.h \
 ../cl/cdaccess.h ascii-print.h ../cl/bitfields.h corpmanag.h cqp.h \
 context_descriptor.h attlist.h print-modes.h groups.h output.h \
 print_align.h options.h ../cl/globals.h concordance.h \
 ../cl/class-mapping.h ../cl/attributes.h
sgml-print.o: sgml-print.c ../cl/macros.h ../cl/globals.h ../cl/cl.h \
 ../cl/corpus.h ../cl/attributes.h ../cl/storage.h ../cl/corpus.h \
 ../cl/cdaccess.h sgml-print.h ../cl/bitfields.h corpmanag.h cqp.h \
 context_descriptor.h attlist.h print-modes.h groups.h output.h \
 print_align.h options.h ../cl/globals.h concordance.h \
 ../cl/class-mapping.h ../cl/attributes.h
html-print.o: html-print.c html-print.h ../cl/bitfields.h ../cl/globals.h \
 ../cl/cl.h corpmanag.h ../cl/corpus.h cqp.h context_descriptor.h \
 attlist.h ../cl/attributes.h ../cl/storage.h ../cl/corpus.h \
 print-modes.h groups.h output.h ../cl/macros.h ../cl/cdaccess.h \
 options.h ../cl/globals.h concordance.h ../cl/class-mapping.h \
 ../cl/attributes.h print_align.h
latex-print.o: latex-print.c latex-print.h ../cl/bitfields.h \
 ../cl/globals.h ../cl/cl.h corpmanag.h ../cl/corpus.h cqp.h \
 context_descriptor.h attlist.h ../cl/attributes.h ../cl/storage.h \
 ../cl/corpus.h print-modes.h groups.h output.h ../cl/macros.h \
 ../cl/cdaccess.h options.h ../cl/globals.h concordance.h \
 ../cl/class-mapping.h ../cl/attributes.h print_align.h
variables.o: variables.c ../cl/corpus.h ../cl/globals.h ../cl/cl.h \
 ../cl/attributes.h ../cl/storage.h ../cl/corpus.h ../cl/cdaccess.h \
 ../cl/macros.h variables.h output.h corpmanag.h ../cl/bitfields.h cqp.h \
 context_descriptor.h attlist.h print-modes.h options.h ../cl/globals.h \
 concordance.h ../cl/class-mapping.h ../cl/attributes.h
print_align.o: print_align.c ../cl/cl.h ../cl/corpus.h ../cl/globals.h \
 ../cl/cl.h ../cl/attributes.h ../cl/storage.h ../cl/corpus.h \
 ../cl/cdaccess.h ../cl/macros.h concordance.h ../cl/class-mapping.h \
 ../cl/attributes.h context_descriptor.h attlist.h print-modes.h \
 corpmanag.h ../cl/bitfields.h cqp.h options.h ../cl/globals.h \
 ascii-print.h groups.h output.h html-print.h sgml-print.h latex-print.h
macro.o: macro.c macro.h options.h ../cl/globals.h ../cl/cl.h \
 concordance.h ../cl/corpus.h ../cl/globals.h ../cl/class-mapping.h \
 ../cl/corpus.h ../cl/attributes.h ../cl/storage.h context_descriptor.h \
 attlist.h ../cl/attributes.h print-modes.h corpmanag.h ../cl/bitfields.h \
 cqp.h output.h hash.h eval.h ../cl/cdaccess.h regex2dfa.h symtab.h \
 ranges.h targets.h parser.tab.h ../cl/macros.h
hash.o: hash.c
table.o: table.c ../cl/globals.h ../cl/cl.h table.h corpmanag.h \
 ../cl/corpus.h ../cl/globals.h ../cl/bitfields.h cqp.h \
 context_descriptor.h attlist.h ../cl/attributes.h ../cl/storage.h \
 ../cl/corpus.h
server.o: ../CQi/server.c ../CQi/server.h ../CQi/../cl/cl.h \
 ../CQi/../cqp/corpmanag.h ../CQi/../cqp/../cl/corpus.h \
 ../CQi/../cqp/../cl/globals.h ../CQi/../cqp/../cl/cl.h \
 ../CQi/../cqp/../cl/bitfields.h ../CQi/../cqp/cqp.h \
 ../CQi/../cqp/context_descriptor.h ../CQi/../cqp/attlist.h \
 ../CQi/../cqp/../cl/attributes.h ../CQi/../cqp/../cl/storage.h \
 ../CQi/../cqp/../cl/corpus.h ../CQi/auth.h ../CQi/cqi.h \
 ../CQi/../cl/macros.h ../CQi/../cl/globals.h ../CQi/../cqp/options.h \
 ../CQi/../cqp/../cl/globals.h ../CQi/../cqp/concordance.h \
 ../CQi/../cqp/../cl/class-mapping.h ../CQi/../cqp/../cl/attributes.h \
 ../CQi/../cqp/print-modes.h ../CQi/../cqp/corpmanag.h \
 ../CQi/../cqp/parse_actions.h ../CQi/../cqp/targets.h \
 ../CQi/../cqp/eval.h ../CQi/../cqp/../cl/cdaccess.h \
 ../CQi/../cqp/regex2dfa.h ../CQi/../cqp/symtab.h ../CQi/../cqp/options.h \
 ../CQi/../cqp/output.h ../CQi/../cqp/ranges.h ../CQi/../cqp/hash.h
auth.o: ../CQi/auth.c ../CQi/auth.h ../CQi/../cl/macros.h \
 ../CQi/../cl/globals.h ../CQi/../cl/cl.h
parser.tab.o: parser.tab.c ../cl/globals.h ../cl/cl.h \
 ../cl/special-chars.h ../cl/globals.h ../cl/attributes.h ../cl/storage.h \
 ../cl/corpus.h ../cl/macros.h cqp.h options.h concordance.h \
 ../cl/corpus.h ../cl/class-mapping.h ../cl/attributes.h \
 context_descriptor.h attlist.h print-modes.h corpmanag.h \
 ../cl/bitfields.h ranges.h eval.h ../cl/cdaccess.h regex2dfa.h symtab.h \
 output.h treemacros.h tree.h builtins.h groups.h targets.h variables.h \
 parse_actions.h ../CQi/auth.h macro.h
lex.yy.o: lex.yy.c ../cl/globals.h ../cl/cl.h ../cl/macros.h \
 ../cl/globals.h cqp.h corpmanag.h ../cl/corpus.h ../cl/bitfields.h \
 context_descriptor.h attlist.h ../cl/attributes.h ../cl/storage.h \
 ../cl/corpus.h eval.h ../cl/cdaccess.h regex2dfa.h symtab.h options.h \
 concordance.h ../cl/class-mapping.h ../cl/attributes.h print-modes.h \
 tree.h output.h ranges.h macro.h targets.h parser.tab.h
