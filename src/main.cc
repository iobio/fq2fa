#include <iostream>

#include "SingEndConverter.h"
#include "PairEndConverter.h"

#include "KSeqCpp.h"

using namespace fq2fa;
using YiCppLib::KSeqCpp;

std::ostream& operator<<(std::ostream& out, Converter&& obj) {
	try {
		while(true) {
			KSeqCpp::FastqRecord::u_ptr record = obj.next();
			if(record.get() == nullptr) continue;
			out<<">"<<record->name<<std::endl;
			out<<record->sequence<<std::endl;
		}
	}
	catch (const YiCppLib::Exceptions::EndOfFileException& e) {
		/* ignore */
	}
	catch (const YiCppLib::Exceptions::FileNotOpenException& e) {
		/* ignore */
	}

	return out;
}

int main(int argc, char* argv[]) {

	switch(argc) {
		case 1:
			std::cout<<SingEndConverter();
			break;
		case 2:
			std::cout<<SingEndConverter(argv[1]);
			break;
		case 3:
		default:
			std::cout<<PairEndConverter(argv[1], argv[2]);
			break;
	}

	return 0;
}
