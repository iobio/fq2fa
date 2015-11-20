#include "PairEndConverter.h"

using namespace fq2fa;
using YiCppLib::KSeqCpp;

PairEndConverter::PairEndConverter(const char* filename1, const char* filename2) :
	seqCpp1(KSeqCpp::u_ptr(new KSeqCpp(filename1))),
	seqCpp2(KSeqCpp::u_ptr(new KSeqCpp(filename2)))
{

}

KSeqCpp::FastqRecord::u_ptr PairEndConverter::next() {
	KSeqCpp::FastqRecord::u_ptr headRec1;
	KSeqCpp::FastqRecord::u_ptr headRec2;

	bool hasHeadRec1 = true;
	bool hasHeadRec2 = true;

	try {
		headRec1 = seqCpp1->nextRecord();
		
		auto bklgRec = checkBacklog(backlog2, headRec1->name);
		if(bklgRec.get() != nullptr)
			return makeFastaRecord(headRec1, bklgRec);
	}
	catch(const YiCppLib::Exceptions::EndOfFileException& e) {
		hasHeadRec1 = false;
	}

	try {
		headRec2 = seqCpp2->nextRecord();

		if(hasHeadRec1) {
			if(headRec1->name == headRec2->name)
				return makeFastaRecord(headRec1, headRec2);
			else {
				backlog1[headRec1->name] = std::move(headRec1);

				auto bklgRec = checkBacklog(backlog1, headRec2->name);
				if(bklgRec.get() != nullptr)
					return makeFastaRecord(bklgRec, headRec2);
				else {
					backlog2[headRec2->name] = std::move(headRec2);
					return KSeqCpp::FastqRecord::u_ptr(nullptr);
				}
			}	
		}
		else {
			auto bklgRec = checkBacklog(backlog1, headRec2->name);
			if(bklgRec.get() != nullptr)
				return makeFastaRecord(bklgRec, headRec2);
			else
				return makeFastaRecord(std::move(headRec2));
		}
	}
	catch(const YiCppLib::Exceptions::EndOfFileException& e) {
		
		if(hasHeadRec1) return makeFastaRecord(std::move(headRec1));

		if(backlog1.begin() != backlog1.end()) {
			auto bklgRec = std::move(backlog1.begin()->second);
			backlog1.erase(backlog1.begin());
			return makeFastaRecord(std::move(bklgRec));
		}
		else if(backlog2.begin() != backlog2.end()){
			auto bklgRec = std::move(backlog2.begin()->second);
			backlog2.erase(backlog2.begin());
			return makeFastaRecord(std::move(bklgRec));
		}
		else
			throw e;
	}
}

KSeqCpp::FastqRecord::u_ptr PairEndConverter::checkBacklog(backlogMap& backlog, std::string name) {
	backlogMap::iterator it = backlog.find(name);

	if(it != backlog.end()) {
		KSeqCpp::FastqRecord::u_ptr record = std::move(it->second);
		backlog.erase(it);
		return record;
	}

	return KSeqCpp::FastqRecord::u_ptr(nullptr);
}

KSeqCpp::FastqRecord::u_ptr PairEndConverter::makeFastaRecord(KSeqCpp::FastqRecord::u_ptr rec) {
	return rec;
}

KSeqCpp::FastqRecord::u_ptr PairEndConverter::makeFastaRecord(const KSeqCpp::FastqRecord::u_ptr& rec1, const KSeqCpp::FastqRecord::u_ptr& rec2) {
    return KSeqCpp::FastqRecord::u_ptr(new KSeqCpp::FastqRecord {
            .name = rec1->name,
            .comment = "",
            .sequence = rec1->sequence + "+" + rec2->sequence,
            .quality = ""
            });
}
