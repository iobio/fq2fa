#include "SingEndConverter.h"

using namespace fq2fa;
using YiCppLib::KSeqCpp;

SingEndConverter::SingEndConverter(const char* filename) :
	seqCpp(KSeqCpp::u_ptr(new KSeqCpp(filename)))
{

}

KSeqCpp::FastqRecord::u_ptr SingEndConverter::next() {
	return seqCpp->nextRecord();
}
