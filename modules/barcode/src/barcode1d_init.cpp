#include "precomp.hpp"

using namespace cv;
using namespace barcode;

//Detector
Ptr<Barcode1D> Barcode1d::create(const String& locator_type)
{
  return Algorithm::create<Barcode1d> ("Barcode1d." + locator_type);
}

///Giving AlgorithmInfo for various barcode detectors
//zxing AlgorithmInfo

CV_INIT_ALGORITHM(ZXING_WRAP, "Barcode1d.ZXING_WRAP",
//		  obj.info()->addParam(obj,"readerType",obj.readerType);
		  obj.info()->addParam(obj,"decode_hints",obj.decode_hints));


//////////////////////////////initModule function////////////////////

bool cv::barcode::initModule_barcode1d(void)
{
	bool all = true;
	all &= !ZXING_WRAP_info_auto.name().empty();

	return all;
}
