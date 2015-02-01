#ifndef CONVERTER_H
#define CONVERTER_H

#include <string>
#include <memory>

#include "KSeqCpp.h"

namespace fq2fa {
	
	class Converter {
		public:
			virtual YiCppLib::KSeqCpp::FastqRecord::u_ptr next() = 0;
	};

	
};

#endif
