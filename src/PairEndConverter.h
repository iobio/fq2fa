#ifndef PAIRENDCONVERTER_H
#define PAIRENDCONVERTER_H

#include "Converter.h"
#include "KSeqCpp.h"

#include <map>

using YiCppLib::KSeqCpp;

namespace fq2fa {
	class PairEndConverter : public Converter {
		public:
			PairEndConverter(const char* filename1, const char* filename2);
			KSeqCpp::FastqRecord::u_ptr next() override;

		protected:
			using backlogMap = std::map<const std::string, YiCppLib::KSeqCpp::FastqRecord::u_ptr>;

			YiCppLib::KSeqCpp::u_ptr seqCpp1;
			YiCppLib::KSeqCpp::u_ptr seqCpp2;
			
			KSeqCpp::FastqRecord::u_ptr makeFastaRecord(KSeqCpp::FastqRecord::u_ptr rec);
			KSeqCpp::FastqRecord::u_ptr makeFastaRecord(const KSeqCpp::FastqRecord::u_ptr& rec1, const KSeqCpp::FastqRecord::u_ptr& rec2);
			KSeqCpp::FastqRecord::u_ptr checkBacklog(backlogMap& backlog, std::string name);

			backlogMap backlog1;
			backlogMap backlog2;
	};
}



#endif
