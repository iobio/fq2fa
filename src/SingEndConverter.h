#ifndef SINGENDCONVERTER_H
#define SINGENDCONVERTER_H

#include "Converter.h"
#include "KSeqCpp.h"

namespace fq2fa {
	class SingEndConverter : public Converter {
		public:
            SingEndConverter();
			SingEndConverter(const char* filename);
			YiCppLib::KSeqCpp::FastqRecord::u_ptr next() override;

		protected:
			YiCppLib::KSeqCpp::u_ptr seqCpp;
	};
}



#endif
