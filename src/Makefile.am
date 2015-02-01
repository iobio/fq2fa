AM_CPPFLAGS=-I$(top_srcdir)/vendor/YiCppLib/KSeqCpp/src

AM_LDFLAGS=-arch x86_64

noinst_LTLIBRARIES=libfq2fa.la

libfq2fa_la_SOURCES= Converter.h \
					 SingEndConverter.h \
					 SingEndConverter.cc \
					 PairEndConverter.h \
					 PairEndConverter.cc


bin_PROGRAMS=fq2fa
fq2fa_SOURCES=main.cc
fq2fa_LDADD=libfq2fa.la $(top_builddir)/vendor/YiCppLib/KSeqCpp/src/libyi_kseqcpp.la -lz
